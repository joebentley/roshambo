
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define bool type
typedef enum { false, true } bool;

typedef enum {
  ROCK,
  PAPER,
  SCISSORS
} EMove;

typedef enum {
  WIN,
  LOSE,
  DRAW
} EOutcome;

EMove GetMove() {
  // Loop until valid number input
  for(;;) {
    // '1' - '0' = 1, converts char to int
    int c = getchar() - '0';
    
    // consume newline
    getchar();
    
    switch (c) {
      case 1:
        return ROCK;
      case 2:
        return PAPER;
      case 3:
        return SCISSORS;
      default:
        printf("\nPlease select a number between 1 and 3\n>");
        break;
    }
  }
}

// Randomly generate a new move
EMove RandomMove() {
  // get random int between 1 and 3, this WILL have skew
  int r = rand() % 3 + 1;

  switch (r) {
    case 1:
      return ROCK;
    case 2:
      return PAPER;
    case 3:
      return SCISSORS;
    default:
      // Will never reach here
      return -1;
  }

}


EOutcome Beats(EMove move1, EMove move2) {
  // Check if they draw
  if (move1 == move2) {
    return DRAW;
  }
  
  // Check if move1 will beat move2
  if ((move1 == PAPER && move2 == ROCK) ||
      (move1 == SCISSORS && move2 == PAPER) ||
      (move1 == ROCK && move2 == SCISSORS))
  {
    // move1 wins
    return WIN;
  } else {
    // move2 wins
    return LOSE;
  }
}

char* MoveToString(EMove move) {
  switch (move) {
    case ROCK:
      return "rock";
    case PAPER:
      return "paper";
    case SCISSORS:
      return "scissors";
  }
}


int main(int argc, char* argv[]) {
  // generate seed
  srand(time(NULL));

  int player_score = 0;
  int opp_score = 0;

  for(;;) {
    printf("\nTake your move:\n1: Rock\n2: Paper\n3: Scissors\n>");

    EMove move = GetMove();
    EMove opp_move = RandomMove();

    // Print player's move
    printf("\nYou chose %s\n", MoveToString(move));

    // Print opponent's move
    printf("\nOpponent chose %s\n", MoveToString(opp_move));


    EOutcome outcome = Beats(move, opp_move);
    
    if (outcome == WIN) {
      printf("\nYou win!\n");
      player_score++;
    } else if (outcome == LOSE) {
      printf("\nYou lose...\n");
      opp_score++;
    } else if (outcome == DRAW) {
      printf("\nYou drew\n");
    }

    // Show scores
    printf("\nYour score: %d\n", player_score);
    printf("\nOpponent's score: %d\n", opp_score); 
  }
}

