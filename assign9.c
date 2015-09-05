/*    
Marvin Vilaysack

Assignment #8

CSCI 1111

                                         */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 52


char suits [4][9] = { "Hearts",
                      "Diamonds",
                      "Clubs",
                      "Spades" };
void displayCard(int i);
int dealCard(int cards[], int numOfCards);
void shuffleDeck(int cards[ ], int size);
int valCard(int i);
int scoreHand(int hand[], int hand_Card[]);
int checkAce(int hand[]);
void deck_pre(void);


struct Hand
{
	  int hand_card[3];
	  int  blackjackVal[3];
};
 

int main( )
{
	

	  struct Hand Hand1;
	  struct Hand Hand2;
	  int i;
	  static int deck = 52;
	  int cards[52];  	
	  int count= 0;
	  srand(time(NULL)); 
	  int card;
	  int score1, score2;
	  

   /* ---- initializes deck ------ */
  
	for(i=0; i < SIZE; i++){  // set array of cards, with values 0 - 52

 		cards[i] = i;
	}
	/* ------ shuffles deck -----*/
	shuffleDeck(cards, SIZE); 

	

	int j;
		for (j = 0; j < 2; j++){
			
			for(i=0; i < 3 && deck > 0; i++){
				card = dealCard(cards, --deck); // deals card
				if (j == 0){
					Hand1.hand_card[i] = card; //printf("blackjackVal[%d] = %d\n", i, valCard(card));
					Hand1.blackjackVal[i] =  valCard(card);
				}
				else{
					
					Hand2.hand_card[i] = card;// printf("2nd blackjackVal[%d] = %d\n", i, valCard(card));
					Hand2.blackjackVal[i] =  valCard(card);
				}

				
				count++;
				
		}

	
}



	
	/*test array, remmeber to remove */
/*	int test_array[3] = {0, 4, 14};
	int test_bj[3] = {11, 5, 5};
	*/
	
	printf("\n");
	printf("First Hand: \n ---------\n");

//	score1 = scoreHand(test_bj, test_array);
	score1 = scoreHand(Hand1.blackjackVal, Hand1.hand_card); //remember to insert back
	printf("First Hand Score Value = %d\n", score1);
	
	printf("Second Hand:\n ---------\n" ); // turn back on later

 	score2 = scoreHand(Hand2.blackjackVal, Hand2.hand_card);
	printf("Second Hand Score Value = %d\n", score2);
	

	printf("\n \n\nResult: \n ------\n");
			if (score1 <= 21 && score1 > score2){
			printf("First hand wins\n");
			}
			else if (score2 <= 21 && score2> score1){
				printf("Second hand wins\n");
			}
			else{
				printf("Both lose/tie\n");
			}


  return 0;
}



void displayCard(int i){ //deals card
    



			if (i% 13 == 0){
		    
		    	printf("\tAce of %s value = 11 or 1\n", suits[i/13]);
			}
		
			else if (i % 13 == 10){
				printf("\tJack of %s value = 10\n", suits[i/13]);
			}
			else if (i % 13 == 11){
				printf("\tQueen of %s value = 10\n", suits[i/13]);
			}
			else if (i % 13 == 12){
				printf("\tKing of %s value = 10\n", suits[i/13]);
			}
			else{
				printf("\t%d of %s value = %d\n", (i % 13) + 1 , suits[i/13], (i % 13) + 1);
			}

	return;
}
int dealCard(int cards[], int numOfCards){ // deals card

	return cards[--numOfCards];

}
 

void shuffleDeck(int cards[ ], int size) //shuffles deck
{
  int cardVal, pos, i;
  
  for(i = 0; i < size; i++){
	    pos = rand( ) % size;
	    cardVal = cards[i];
	    cards[i] = cards[pos];   
	    cards[pos] = cardVal;   

  }
  return;
}
int valCard(int i){
	int value;
			if (i% 13 == 0){
		    
		    	return  11;
			}
		
			else if (i % 13 == 10){
				return  10; 
			}
			else if (i % 13 == 11){
				return  10; 
			}
			else if (i % 13 == 12){
				return  10; 
			}
			else{
				return  (i % 13) + 1 ;
			}
	
	
}
int scoreHand(int hand[], int hand_Card[]){

	int firstVal = hand[0];
	int secVal = hand[1];
	int thirdValue = hand[2];
	int thirdValAdded;

	int i;
	int size;

	int first_finalVal;
	int second_finalVal;		
	int addedValue = firstVal + secVal; //sums first and 2nd element
	
	
	if (addedValue < 21){
		thirdValAdded = addedValue + thirdValue;
		size = 3;
		if(thirdValAdded < 21){ //checks if added Third Valueadded exceeds 21

		first_finalVal = thirdValAdded;
		//	printf("first_finalVal (first pass)value:  %d\n", first_finalVal);

		}else
			{
				size  = 2;
			first_finalVal = addedValue;
			//	printf("first_finalVal (2 pass)value:  %d\n", first_finalVal);

			//	return  addedValue; //dont return either, do later*/	
			}
	}

	 printf("\n\n");
/*	 printf("First Value: %d\n", firstVal);
	 printf("Second Value: %d\n", secVal);
	 printf("Third value:  %d\n", thirdValue);
		*/
printf("\n");



			//check for aces, replaces element with 1
	if (checkAce(hand) == 1)
	{


		int possible_thirdValAdded;
		int possible_addedVal;
		firstVal = hand[0]; 
		secVal = hand[1]; 
		thirdValue = hand[2];   
		int size;
		
		possible_addedVal  = firstVal + secVal; 
			// second checks
		if (possible_addedVal < 21)
		
			{
				size = 3;
				possible_thirdValAdded = possible_addedVal + thirdValue;

				
				if(possible_thirdValAdded <= 21)
				{ //checks if added Third Valueadded exceeds 21
	
				second_finalVal = possible_thirdValAdded;
				
				//	printf("second_finalVal (first pass)value:  %d\n", second_finalVal);
	
			
				}
				
				else	{
					size = 2;
					second_finalVal =  possible_addedVal;
				//	printf("second_finalVal (2 pass)value:  %d\n", second_finalVal);
					
					}
			}
	
			
	}
	for (i = 0; i < size; i++){
		displayCard(hand_Card[i]);
		
	} //displays after

	 printf("\n\n");
	 printf("First Value: %d\n", firstVal);
	 printf("Second Value: %d\n", secVal);
	 printf("Third value:  %d\n\n", thirdValue);



	int finalVal;
	if ((first_finalVal <= 21) && (first_finalVal > second_finalVal)){

		return first_finalVal; 
	}
	else{
		
				printf("test: %d\n", second_finalVal);
		return second_finalVal;
	}

return ;


}





int checkAce(int hand[]){
	int i;
		for (i = 0; i < 3; i++){
			
			if (hand[i] == 11){
				hand[i] = 1;
				return 1;
			}
			else
			return 0;
		}

}

