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
  int cutpurse_card = 21;
  state.hand[0][0] = cutpurse;

  //Holds coin amount before using cutpurse card
  int coinsBefore = state.coins;

  printf ("\n****** Start Card Test: Cutpurse *****\n");

  cardEffect(cutpurse_card, -1, -1, -1, &state, 0, 0);

  //Holds coin amount after using cutpurse card
  int coinsAfter = state.coins;

  if((coinsAfter - coinsBefore) == 2){
    printf("Test Passed\n\n");
  }
  else{
    printf("Test Failed: we should only gain + 2 coins.\nInstead we are gaining + %d coins.\n\n", (coinsAfter - coinsBefore));
  }

  printf ("\n****** End Card Test: Cutpurse *****\n");

	return 0;
}
