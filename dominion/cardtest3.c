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

  printf ("\n****** Start Card Test: Village *****\n");

  initializeGame(2, k, 10, &state);
  state.hand[0][0] = village;

  int oldHandCnt = state.handCount[currentPlayer] - 1; //-1 to account discarding adventurer after we play it.
  int oldActions = state.numActions; //-1 to account discarding adventurer after we play it.

  playCard(0, -1, -1, -1, &state);

  int newHandCnt = state.handCount[currentPlayer];
  int newActions = state.numActions; //-1 to account discarding adventurer after we play it.
  int cardsAdded = newHandCnt - oldHandCnt;

  if((newHandCnt == 5) && (newActions == 2)){
    printf("Test Passed: cards added is %d. and numActions added is %d\n",cardsAdded, newActions);
  }
  else{
    printf("Test Failed: Village adds +1 cards to your hand and + 2 actions.\nWe should have a handcount of 5. Instead our handcount is : %d.\nWe should have an action # of 2. Instead our action # is %d\n",newHandCnt, newActions);
  }

  printf ("\n****** End Card Test: Village *****\n");

	return 0;
}
