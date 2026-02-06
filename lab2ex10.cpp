#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

class FootballTeam {
  int goals;
  int points;
  string teamName;

public:
  FootballTeam() {
    teamName = "Unknown";
    goals = 0;
    points = 0;
  }

  FootballTeam(string teamName, int goals, int points) {
    this->teamName = teamName;
    this->goals = goals;
    this->points = points;
  }

  void setTeamName(string name) { this->teamName = name; }

  string getTeamName() { return this->teamName; }

  void addGoals(int g) { this->goals += g; }

  void updatePoints(int p) { this->points += p; }

  void displayStatus() {
    cout << "Team: " << this->teamName << " | Goals: " << this->goals
         << " | Points: " << this->points << endl;
  }

  FootballTeam operator+(const FootballTeam &other) {
    FootballTeam temp;
    temp.teamName = this->teamName + " & " + other.teamName;
    temp.points = this->points + other.points;
    temp.goals = this->goals + other.goals;
    return temp;
  }

  friend void comparePerformance(const FootballTeam &t1,
                                 const FootballTeam &t2);
};

void comparePerformance(const FootballTeam &t1, const FootballTeam &t2) {
  cout << "\n--- Performance Comparison ---" << endl;
  if (t1.goals > t2.goals) {
    cout << t1.teamName << " performed better with " << t1.goals << " goals!"
         << endl;
  } else if (t2.goals > t1.goals) {
    cout << t2.teamName << " performed better with " << t2.goals << " goals!"
         << endl;
  } else {
    cout << "Both teams performed equally with " << t1.goals << " goals."
         << endl;
  }
}

int main() {
  FootballTeam teamA("Real Madrid", 3, 9);
  FootballTeam teamB("FC Barcelona", 2, 6);

  teamA.displayStatus();
  teamB.displayStatus();

  comparePerformance(teamA, teamB);

  FootballTeam mergedTeam = teamA + teamB;
  cout << "\nMerged Statistics:" << endl;
  mergedTeam.displayStatus();

  cout << "\nEnd of Main Simulation." << endl;
  return 0;
}
