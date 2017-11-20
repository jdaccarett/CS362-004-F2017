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

  printf ("\n****** Start Card Test: Smithy *****\n");


  initializeGame(2, k, 10, &state);
  state.hand[0][0] = smithy;

  int oldHandCnt = state.handCount[currentPlayer];


  playCard(0, -1, -1, -1, &state);

  int newHandCnt = state.handCount[currentPlayer];

  printf("OLD HANDCOUNT = %d\n", oldHandCnt);
  printf("NEW HANDCOUNT = %d\n", newHandCnt);


  if(newHandCnt == 8){
    printf("Test Passed: Smithy successfuly added 3 cards to your hand.\n");

  }
  else{
    printf("Test Failed: Smithy adds 3 cards to your hand for a hand count of 7.\nInstead we have a hand count of: %d.\n", state.handCount[currentPlayer]);
  }

  printf ("\n****** End Card Test: Smithy *****\n");

	return 0;
}
