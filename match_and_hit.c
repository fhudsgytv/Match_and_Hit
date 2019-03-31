/******************************************************************************
*
* File name: match_and_hit.c
*
* Author:  therodyhk
*          therodyhk@gmail.com
*
******************************************************************************/

/*-----------------------------------------------------------------------------
   Include files
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*=============================================================================
  Constants and definitions
=============================================================================*/
#define N_DIGITS 4
#define MAX_QUERIES 12


/*=============================================================================
  Forward function declarations
=============================================================================*/
int isvalid(int n);
int choose_N(void);
int matches(int N, int M);
int hits(int N, int M);


// Define the main function
int main(){

  srand(time(0));

  int match, hit, numOfR = 1;
  int compChoice = choose_N(), humanChoice;


  printf(" ***Welcome to the MATCH and HIT game***\n\n");
  printf("The computer has selected a 4-digit number.\n");
  printf("Try to deduce it in %d rounds of queries.\n\n", MAX_QUERIES);


  // get user input
do{
  printf("Round #%d\n", numOfR);
  printf("Please enter your query (%d digits): ", N_DIGITS);
  int x = scanf(" %d", &humanChoice);
  char c = getchar();


  numOfR++;

  while(1){

    while (c != '\n'){
      c = getchar();
    }

    if (x == 1) {
      if (!isvalid(humanChoice)){
        printf("Invalid number. Please try again!\n");
      }
      else{
        break;
      }
    }

    if(x == 0){
        printf("Invalid query. Please try again!\n");
    }

    printf("Please enter your query (%d digits): ", N_DIGITS);
    x = scanf(" %d", &humanChoice);
    c = getchar();
  }


    match = matches(compChoice, humanChoice);

    hit = hits(compChoice, humanChoice);


    // give the output
    printf("-> %d %s and %d %s\n\n", match, (match == 1) ? "match" : "matches", hit, (hit == 1) ? "hit" : "hits");


    if (match == N_DIGITS){
      printf("**********************************\n");
      printf("CONGRATULATIONS! You won the game!\n");
      printf("**********************************\n");
      return 0;
    }

  } while(numOfR != MAX_QUERIES + 1);

  if (numOfR == MAX_QUERIES + 1){
    printf("*********************************\n");
    printf("Sorry, out of queries. Game over!\n");
    printf("*********************************\n");
  }

  return 0;
}



/*=============================================================================
  Function definitions
=============================================================================*/
int isvalid(int n){
  int numArray[N_DIGITS];
  int i, j, count = 0;


  for (i = 0; i < N_DIGITS; i++){ // store the user input into an array
    numArray[i] = n % 10;
    n = n / 10;

    count++;
    if (n == 0){
      break;
    }
  }


  for(i = 0; i < N_DIGITS; i++){ // check whether numbers are in the range {1,2,3,4,5,6,7,8,9}
    if (numArray[i] <= 0){
      return 0;
    }
  }


  for (i = 0; i < N_DIGITS; i++){   // check whether there is repeated value in the array
    for (j = i+1; j < N_DIGITS; j++){
      if (numArray[i] == numArray[j]){
        return 0;
      }
    }
  }


  if (count < N_DIGITS || n != 0){   // check whether the input number has N digits
    return 0;
  }

  return 1;
}



int choose_N(void){
  int a, b, c, d, num = 0;

  do{

    a = rand() % 9 + 1;
    a = a * 1000;

    b = rand() % 9 + 1;
    b = b * 100;

    c = rand() % 9 + 1;
    c = c * 10;

    d = rand() % 9 + 1;


    if(N_DIGITS == 4){
      num = a + b + c + d;
    }
    else if(N_DIGITS == 3){
      num = b + c + d;
    }
    else if(N_DIGITS == 2){
      num = c + d;
    }
    else if(N_DIGITS == 1){
      num = d;
    }


  } while(isvalid(num) != 1);

  return num;
}


int matches(int N, int M){

  int arrayM[N_DIGITS], arrayN[N_DIGITS];
  int i, matchValue = 0;

  for(i = 0; i < N_DIGITS; i++){
    arrayM[i] = M % 10;
    M /= 10;
  }

  for(i = 0; i < N_DIGITS; i++){
    arrayN[i] = N % 10;
    N /= 10;
  }

  for(i = 0; i < N_DIGITS; i++){
    if (arrayN[i] == arrayM[i]){
      matchValue++;
    }
  }

  return matchValue;
}



int hits(int N, int M){
  int arrayM[N_DIGITS], arrayN[N_DIGITS];
  int i, j, hitValue = 0;

  for(i = 0; i < N_DIGITS; i++){
    arrayM[i] = M % 10;
    M /= 10;
  }

  for(i = 0; i < N_DIGITS; i++){
    arrayN[i] = N % 10;
    N /= 10;
  }


  for(i = 0; i < N_DIGITS; i++) {
      if(arrayM[i] != arrayN[i]) {
        for (j = 0; j < N_DIGITS; j++) {
          if (arrayM[i] == arrayN[j]){
            hitValue++;
          }
        }
      }
    }

  return hitValue;
}

/******************************************************************************
                                End of file
******************************************************************************/
