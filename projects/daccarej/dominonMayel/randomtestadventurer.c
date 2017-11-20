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

  int n, i, j, p, deck_treasures, pre_count, post_count, hand_count;
  struct gameState G;
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

  printf("****** Begin Random Test Adventurer*****\n");
  // Iterate to the number of desired tests.
  for (n = 0; n < 100000; n++){
      //declare variables.
      deck_treasures = 0;
      pre_count = 0;
      post_count = 0;
      initializeGame(2, k, 10, &G);
      p = rand() % 2;
		  G.whoseTurn = p;
      G.handCount[p] = 5;
      G.deckCount[p] = 10;

      //Generate Random Hand.
  		for(j = 0; j < G.handCount[p]; j++){
        if(j == 0){
          //Add adventurer to hand.
          G.hand[p][j] = adventurer;
        }
        else{
            G.hand[p][j] = rand() % CARD_COUNT;
            //count amount of treasures in current hand.
            if(G.hand[p][j] >= copper && G.hand[p][j] <= gold){
              pre_count++;	}
        }
  		}
      //Add all Copper treasure cards to deck
      for(j = 0; j < G.deckCount[p]; j++){
          G.deck[p][j] = copper;
      }

      // playCard following print all the cards in your hand.
      // printf ("\nTest Case Number: %d\n", n);
      // printf("Deck count : %d\n", G.deckCount[p]);
      // printf("Precount Treasures in Hand.= %d\n", pre_count);
      playCard(0, -1, -1, -1, &G);
      //printHand(p, &G);

      //count amount of treasures in current hand after adventurer card is played.
      for(j = 0; j < G.handCount[p]; j++){
			     if(G.hand[p][j] >= copper && G.hand[p][j] <= gold)
					      post_count++;
		  }

      // printf("Postcount Treasures in Hand.= %d\n", post_count);

      //Because the deck is all treasures we know that every handcount should
      //have a handcount of + 2 when using Adventurer. To check if there is any bugs we compare the
      //old count of treasures in hand to the new count. Where we should have a
      //difference of 2 extra treasure cards in our hand after playing adventurer.
      //Because my REFACATORED Adventurer cards has a bug of adding 3 cards to the deck
      //out test will test if 3 cards are being added to the our hand instead of the 2.

      //NOTE: Because i introduced a bug in my adventurer to add 3 cards to our hand
      //instead of the 2 we will check where the difference between post and pre is 3
      //and not 2. If the difference is off(not = 3 or the treasure cards added after adventurer)
      //I throw and error.

      if(post_count - pre_count != 2){
        printf("\nERROR\n");
        return 0;
      }
  }
  printf("\nTEST Passed\n");
  printf("****** END Random Test Adventurer*****\n");

}
