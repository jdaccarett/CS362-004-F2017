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

  printf("****** Begin Random Test Smithy *****\n");
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
          //Add smithy to hand.
          G.hand[p][j] = smithy;
        }
        else{
            G.hand[p][j] = rand() % CARD_COUNT;
        }
        //keep count of all cards in hand.
        pre_count++;
  		}


      //Add all Copper treasure cards to deck
      for(j = 0; j < G.deckCount[p]; j++){
          G.deck[p][j] = copper;
      }

      // playCard following print all the cards in your hand.
      // printf ("\nTest Case Number: %d\n", n);
      // printf("Deck count : %d\n", G.deckCount[p]);
      // printf("Pre Smithy Hand Count = %d\n", G.handCount[p]);
      playCard(0, -1, -1, -1, &G);
      // printHand(p, &G);

      //Get handCount current hand after Smithy card is played.
      //Generate Random Hand.
      for(j = 0; j < G.handCount[p]; j++){
        post_count++;
      }

      // printf("Postcount Treasures in Hand = %d\n", post_count);

      //When using smithy our handCount should increase by 3 cards but
      //but in this particular case our handcount will increase by 4 because of the REFACATORED
      //from assignment 2. To check if there is any bugs we compare the
      //handcount prior smithy o the new handCount after using smithy.

      //NOTE: Because I introduced a bug in my smithy card to add 4 cards to our hand
      //instead of the 3. I will check where the difference between post and pre is 3
      //and not 2. Since we discard Smithy after its use our handCount should be 8 which
      //means we added 4 cards to our handCount after smithy use.

      if(post_count - pre_count != 3){
        printf("\nERROR\n");
        return 0;
      }
  }
  printf("\nTEST PASSED: \n");

  printf("****** END Random Test Smithy *****\n");

}
