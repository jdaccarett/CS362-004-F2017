#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


// FUNCTIONS PROTOTYPE
int testBuyCard(int coinsAvail, int numBuys, int supplyCount, int cardToBuy);

// MAIN
int main (int argc, char** argv){

  printf ("\n****** Start Function Test: buyCard( ) *****\n");


  // //Test : buyCard with zero coins in state.
  printf("\n******** Test buying card with Zero Coins ********\n");
  testBuyCard(0, 1, 1, silver);

  //Test : buying a cards with with exact coins needed to buy such card.
  printf("\n******** Test buying gold card with exact Coins ********\n");
  testBuyCard(6, 1, 1, gold);

  printf ("\n****** End Function Test: buyCard( ) *****\n");


}

/****************************************************************/
/* Name:                testBuyCard
*/
/* Param 1: coin available to your disposal
/* Param 2: number of buys available
/* Param 1: number of cards available for purchase
/* Param 2: Which card to buy (silver, gold ect..)
/* Description: Returns false for failed test and true for passed test.
/****************************************************************/
int testBuyCard(int coinsAvail, int numBuys, int supplyCount, int cardToBuy){
  //initialize variables
  int test;
  struct gameState state;
  state.coins = coinsAvail;
  state.numBuys = numBuys;
  state.supplyCount[cardToBuy] = supplyCount;
  state.phase = 1;
  state.whoseTurn = 1;

  test = buyCard(cardToBuy, &state);
  printf("TEST: %d\n",test);
  if(test == 0){
    return 0;
    printf("Test: Passed\n");
  }else{
    return -1;
    printf("Test: Failed\n");
  }
}
