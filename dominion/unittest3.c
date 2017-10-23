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

  printf ("\n****** Start Function Test: whoseTurn( ) *****\n");

  // //Test : buyCard with zero coins in state.
  printf("\n******** Test WhoseTurn for player 1 ********\n");
  state.whoseTurn = 1;
  int test1 = whoseTurn(&state);
  if(test1 == 1){
    printf("Test Passed\n");
  }
  else{
    printf("Test Failed\n");
  }

  // //Test : buyCard with zero coins in state.
  printf("\n******** Test WhoseTurn for wrong player ********\n");
  state.whoseTurn = -1;
  int test2 = whoseTurn(&state);
  if(test2 == 1){
    printf("Test Passed\n");
  }
  else{
    printf("Test Failed\n\n");
  }

  printf ("\n****** End Function Test: whoseTurn( ) *****\n");

}
