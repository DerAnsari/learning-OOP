import spotipy
from spotipy.oauth2 import SpotifyOAuth

# --- CONFIGURATION ---
# Replace these with your actual details from the Spotify Developer Dashboard
CLIENT_ID = '61c031fbeb1e41c2973aa1fd2d906f1d'
CLIENT_SECRET = 'c9f09762c0884b1fb5177da44b780e5a'
REDIRECT_URI = 'http://127.0.0.1:8888/callback'
PLAYLIST_ID = '3r1friPXX1pKQA7GswGYMe'

# The priority artists in order (Top to Bottom)
PRIORITY_ARTISTS = ['Mili', 'Yorushika', 'Tayori', 'Zutomayo']

def get_all_playlist_tracks(sp, playlist_id):
    """Fetches every track in the playlist, handling pagination."""
    tracks = []
    results = sp.playlist_items(playlist_id)
    tracks.extend(results['items'])
    while results['next']:
        results = sp.next(results)
        tracks.extend(results['items'])
    return tracks

def sort_key(item):
    """
    Defines the sorting logic:
    1. Priority Artists (Mili, Yorushika, etc.)
    2. Artist Name (alphabetical)
    3. Album Name
    4. Track Name
    """
    if not item or not item['track']:
        return (999, "", "", "")
    
    # Get primary artist name
    artist_name = item['track']['artists'][0]['name']
    track_name = item['track']['name']
    album_name = item['track']['album']['name']
    
    # Custom Priority Check
    try:
        # If artist is in our list, priority is their index (0, 1, 2...)
        priority = PRIORITY_ARTISTS.index(artist_name)
    except ValueError:
        # Otherwise, they get a lower priority (comes after the list)
        priority = len(PRIORITY_ARTISTS)
        
    # Returns a tuple that Python uses for multi-level sorting
    return (priority, artist_name.lower(), album_name.lower(), track_name.lower())

def main():
    if 'YOUR_' in CLIENT_ID or 'YOUR_' in PLAYLIST_ID:
        print("Error: Please update the configuration section with your API keys and Playlist ID.")
        return

    # Initialize Spotify client with modify permissions
    scope = "playlist-modify-public playlist-modify-private"
    sp = spotipy.Spotify(auth_manager=SpotifyOAuth(
        client_id=CLIENT_ID,
        client_secret=CLIENT_SECRET,
        redirect_uri=REDIRECT_URI,
        scope=scope
    ))

    print(f"Accessing playlist: {PLAYLIST_ID}")
    items = get_all_playlist_tracks(sp, PLAYLIST_ID)
    
    if not items:
        print("No tracks found in the playlist.")
        return

    print(f"Found {len(items)} tracks. Sorting...")
    # Perform the sort based on our custom rule
    sorted_items = sorted(items, key=sort_key)
    sorted_uris = [item['track']['uri'] for item in sorted_items if item['track']]

    print("Updating playlist order on Spotify...")
    # Spotify API limits: We replace the first 100, then add the rest in chunks
    # This is often safer/faster than moving items one-by-one
    sp.playlist_replace_items(PLAYLIST_ID, sorted_uris[:100])
    
    for i in range(100, len(sorted_uris), 100):
        sp.playlist_add_items(PLAYLIST_ID, sorted_uris[i:i+100])

    print("Success! Your playlist has been bundled by artist with your custom priorities at the top.")

if __name__ == "__main__":
    main()
