#include "dominion.h"
#include "interface.c"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#define CARD_COUNT treasure_map

int main(int argc, char** argv)	{

  int n, i, j, currentPlayer, deck_treasures, pre_Coin_count, post_Coin_count, hand_count;
  struct gameState G;
  int cutpurse_card = 21;
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

  int counterPassed = 0;
  int counterFailed = 0;


  printf("****** Begin Random Test Cutpurse *****\n");
  // Iterate to the number of desired tests.
  for (n = 0; n < 100000; n++){
      //declare variables.
      deck_treasures = 0;
      pre_Coin_count = 0;
      post_Coin_count = 0;
      initializeGame(2, k, 10, &G);
      currentPlayer = rand() % 2;
		  G.whoseTurn = currentPlayer;
      G.handCount[currentPlayer] = 5;
      G.deckCount[currentPlayer] = 10;

      //Generate Random Hand.
  		for(j = 0; j < G.handCount[currentPlayer]; j++){
        if(j == 0){
          //Add smithy to hand.
          G.hand[currentPlayer][j] = cutpurse;
        }
        else{
            G.hand[currentPlayer][j] = rand() % CARD_COUNT;
        }
  		}

      //Add all Copper treasure cards to deck
      for(j = 0; j < G.deckCount[currentPlayer]; j++){
          G.deck[currentPlayer][j] = copper;
      }

      // playCard following print all the cards in your hand.
      // printf ("\nTest Case Number: %d\n", n);
      // printf("Deck count : %d\n", G.deckCount[currentPlayer]);

      //Holds coin amount before using cutpurse card
      int coinsBefore = G.coins;
      // printf("Pre Smithy Coin Count = %d\n", coinsBefore);

      // Play cutpurse_card
      playCard(0, -1, -1, -1, &G);
      // printHand(currentPlayer, &G);

      //Holds coin amount after using cutpurse card
      int coinsAfter = G.coins;
      // printf("Post Smithy Coin Count = %d\n", coinsAfter);

      // Test if updateCoins in FUNCTION : cutpurse is working correctly
      if(coinsAfter - coinsBefore != 2){
        printf("\nTest Failed: we should only gain + 2 coins(with REFACATOR).\nWe gained + %d coins.\n\n", (coinsAfter - coinsBefore));
        counterFailed++;
      }
      if(coinsAfter - coinsBefore == 2){
        printf("\nTest Passed: we should only gain + 2 coins(with REFACATOR).\nWe gained + %d coins.\n\n", (coinsAfter - coinsBefore));
        printf("\n****** END Random Test Adventurer*****\n");
        counterPassed++;
      }

  }
  printf("TEST FAILED COUNTER = %d\n", counterFailed);
  printf("TEST PASSED COUNTER = %d\n", counterPassed);
  printf("****** END Random Test Cutpurse *****\n");

}
