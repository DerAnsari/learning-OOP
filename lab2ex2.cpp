#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

class TicTacToe {

private:
  int board[3][3];

public:
  TicTacToe() {
    for (int i{0}; i < 3; i++) {
      for (int j{0}; j < 3; j++) {
        board[i][j] = 0;
      }
    }
  }

  void clearBoard() {
    for (int i{0}; i < 3; i++) {
      for (int j{0}; j < 3; j++) {
        board[i][j] = 0;
      }
    }
  }

  void to_string() const {
    cout << "\n  0   1   2" << endl;
    for (int i = 0; i < 3; i++) {
      cout << i << " ";
      for (int j = 0; j < 3; j++) {

        if (board[i][j] == 1)
          cout << "X";
        else if (board[i][j] == 2)
          cout << "O";
        else
          cout << " ";

        if (j < 2)
          cout << " | ";
      }
      if (i < 2)
        cout << "\n  ----------";
      cout << endl;
    }
    cout << endl;
  }

  int gameStatus() const {

    for (int i{0}; i < 3; i++) {
      if (board[i][0] != 0 && board[i][0] == board[i][1] &&
          board[i][1] == board[i][2])
        return board[i][0];

      if (board[0][i] != 0 && board[0][i] == board[1][i] &&
          board[1][i] == board[2][i])
        return board[0][i];
    }

    if (board[0][0] != 0 && board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
      return board[0][0];
    if (board[0][2] != 0 && board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
      return board[0][2];

    bool emptySpace = false;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == 0)
          emptySpace = true;
      }
    }

    return emptySpace ? 0 : 3;
  }

  int move(int player, int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == 0) {
      board[row][col] = player;
      return true;
    }
    return false;
  }

  void autoMove(int player) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == 0) {
          board[i][j] = player;
          return;
        }
      }
    }
  }
};

int main() {
  TicTacToe game;
  int currentPlayer = 1;
  int status = 0;

  cout << "Welcome to Tic-Tac-Toe!" << std::endl;

  while ((status = game.gameStatus()) == 0) {
    int row, col;

    game.to_string();

    std::cout << "Player " << currentPlayer << " move: enter row and column: ";

    while (!(std::cin >> row >> col) || !game.move(currentPlayer, row, col)) {
      std::cout << "Invalid move! Try again (row col): ";
      std::cin.clear();
      std::string dummy;
      std::getline(std::cin, dummy);
    }

    currentPlayer = (currentPlayer == 1) ? 2 : 1;
  }

  game.to_string();

  if (status == 1) {
    std::cout << "Player 1 wins!" << std::endl;
  } else if (status == 2) {
    std::cout << "Player 2 wins!" << std::endl;
  } else if (status == 3) {
    std::cout << "It's a draw!" << std::endl;
  }

  return 0;
}
