#include <stdio.h>
#define MATCH +1
#define MISMATCH -1
#define INDEL -2
#define N 6
#define F_L 6
#define S_L 4

int max(int,int,int);

/*
* Example of Global Alignment using Neddlman-Wunsch algorithm 
*/
int main(){
	//structure used
	char first_seq[] = "CAAGAC";
	char second_seq[] = "GAAC";
	int dynamic[S_L+1][F_L+1];


  dynamic[0][0] = 0;
	//initialization of dynamic matrix
	for(int i = 1; i < F_L+1; i++){
		dynamic[0][i] = dynamic[0][i-1] + INDEL;
	}

  for(int i = 1; i < S_L+1; i++){
    	dynamic[i][0] =dynamic[i-1][0] + INDEL;
  }

	for(int i = 1; i < S_L+1; i++){ //first sequence
		for(int j = 1; j < F_L+1; j++){ //second sequence
			if(second_seq[i-1] == first_seq[j-1])
				dynamic[i][j] = max(dynamic[i - 1][j - 1] + MATCH, dynamic[i-1][j] + INDEL, dynamic[i][j-1]+INDEL);
			else 
				dynamic[i][j] = max(dynamic[i - 1][j - 1] + MISMATCH, dynamic[i-1][j] + INDEL, dynamic[i][j-1]+INDEL);

		}
	}

  printf("Aligment lenght of %s and %s is: %d", first_seq, second_seq, dynamic[S_L][F_L]);

}

int max(int a, int b, int c){

	if(a > b){
		if(a > c){
			return a;
		}
		else 
			return c;
	}
	else 
		if(b > c){
			return b;
		}else 
			return c;

}