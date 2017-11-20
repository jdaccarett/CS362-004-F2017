#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// MAIN
int main (int argc, char** argv){

  struct gameState state;
  int test;
  int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};


  printf("\n******* Testing initializeGame() by passing numPlayers from 0 - 6 *******\n");
  printf("\nnumPlayers 0, 1 and 6 should fail");
  printf("\nnumPlayers 2, 3 and 4 should Pass\n\n");

  for (int x = 0 ; x <= 6 ; ++x)	{
      test = initializeGame(x, k, 5, &state);
      printf("\nTesting initializeGame with %d # of players",x);
      if(test == 0){

          printf("\nTest: Passed\n");

      }
      else{
        printf("\nTest: Failed\n");
      }

  }
  printf("\n******* End Testing initializeGame() *******\n");
  return 0;

}
