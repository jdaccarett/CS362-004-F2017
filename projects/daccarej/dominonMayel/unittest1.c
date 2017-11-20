#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// FUNCTIONS PROTOTYPE
int testUpdateCoin(int correctAmnt, char* treasureCard);

// MAIN
int main (int argc, char** argv){

  printf ("\n****** Start Function Test: updateCoins() *****\n");

  //Test copper
  testUpdateCoin(10, "copper");
  //Test silver
  testUpdateCoin(20, "silver");
  //Test gold
  testUpdateCoin(30, "gold");
  //Test for no treasure cards are in deck
  testUpdateCoin(0, "zero");

  printf ("\n****** End Function Test: updateCoins() *****\n");
}

/****************************************************************/
/* Name:                testUpdateCoin
*/
/* Param 1: correctAmnt (correct sum of treasure card passed)
/* Param 2: treasureCard (string of what treasure card to check)
/* Description: iterates a full deck of cards and assigns the
/* passed treasure card. Checks if correctAmnt equal acutal Amnt.
/****************************************************************/
int testUpdateCoin(int correctAmnt, char* treasureCard){
  //initialize variables
  struct gameState state;
  state.coins = 0;
  /* Assing players deck of 10 cards to be all copper cards */
  printf("\nTesting for %s Treasure card\n\n",treasureCard);
  for(int i = 0; i < 10; i++){
    //COPPER
    if((strcmp (treasureCard, "copper") == 0)){
      state.hand[0][i] = copper;
    }
    //SILVER
    if((strcmp (treasureCard, "silver") == 0)){
      state.hand[0][i] = silver;
    }
    //GOLD
    if((strcmp (treasureCard, "gold") == 0)){
      state.hand[0][i] = gold;
    }
  }

  //CHECK IF CORRECT AMOUNT IS SAME AS ACTUAL AMOUNT
  updateCoins(0,&state,0);
  if(state.coins == correctAmnt) {
    printf("%s Treasure Cards = TEST PASSED\n\n",treasureCard);
  }
  else {
    printf("%s Treasure Cards = TEST FAILED\n", treasureCard);
    printf("Coins = %d and they should = to %d\n\n",state.coins, correctAmnt);
  }

  return 0;
}
