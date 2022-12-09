#include <compare>
#include <fstream>
#include <iostream>
#include <string>

/*
a = Rock      b = Paper    c = Sci



x = Rock   y = Paper    z = Sci




*/
int main() {
  std::ifstream file("text.txt");

  std::string line;
  int winCounter = 0;
  int tieCounter = 0;
  int Sciss = 0;
  int Paper = 0;
  int Rock = 0;
  int Score = 0;

  while (file >> line) {
    if (line == "A") {
      file >> line;
      if (line == "X") {
        Sciss++;
      }
      if (line == "Y") {
        Rock++;
        tieCounter++;
      }
      if (line == "Z") {
        Paper++;
        winCounter++;
      }
    }
    if (line == "B") { // paper
      file >> line;
      if (line == "X") { // lose
        Rock++;
      }
      if (line == "Y") { // tie
        Paper++;
        tieCounter++;
      }
      if (line == "Z") { // win
        Sciss++;
        winCounter++;
      }
    }
    if (line == "C") { // Sciss
      file >> line;
      if (line == "X") {
        Paper++;
      }
      if (line == "Y") {
        Sciss++;
        tieCounter++;
      }
      if (line == "Z") {
        Rock++;
        winCounter++;
      }
    }
  }
  Score = (tieCounter * 3) + (winCounter * 6) + (Sciss * 3) + (Paper * 2) +
          (Rock * 1);

  std::cout << "The results of the game was:\n" << Score << "\n";

  return 0;
}

// x = lose
// y = draw
// z = win