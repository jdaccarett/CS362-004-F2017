#include "dominion.h"
#include "interface.c"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char** argv)	{


  struct gameState state;
  int currentPlayer = 0;

  int* k = malloc(10 * sizeof(int));
  k[0] = adventurer;
  k[1] = gardens;
  k[2] = minion;
  k[3] = village;
  k[4] = embargo;
  k[5] = mine;
  k[6] = cutpurse;
  k[7] = baron;
  k[8] = tribute;
  k[9] = smithy;

  printf ("\n****** Start Card Test: Adventurer *****\n");

  initializeGame(2, k, 10, &state);
  state.hand[0][0] = adventurer;

  printHand(0, &state);

  int oldHandCnt = state.handCount[currentPlayer] - 1; //-1 to account discarding adventurer after we play it.

  // adventurer card has a bug that reveals 3 treasure cards instead of 2 and add them to your hand.
  // to unit test this i check hand count before playing adventurer which yields a handcount of 5
  // after we play adventurer we should have 2 more cards in our hand which is a sum of 6 since we discarded adventurer.
  // To test if we passed or fail I check if handCount of 4(accounting for adventurer discard)has a remainder of 2 when compared to the new handCount.
  // if we have a remainder of 3 cards than we know that adventurer indeed has a bug.
  playCard(0, -1, -1, -1, &state);
  int newHandCnt = state.handCount[currentPlayer];

  if((newHandCnt % oldHandCnt) == 3){
    printf("Test Failed: Adventurer reveals 2 treasure cards and adds 2 cards to your hand.\nWe should have a handcount of 6. Instead our handcount is : %d.\n", state.handCount[currentPlayer]);
  }
  else{
    printf("Test Passed: hand count is  %d.\n", state.handCount[currentPlayer]);
  }

  printf ("\n****** End Card Test: Adventurer *****\n");


	return 0;
}
