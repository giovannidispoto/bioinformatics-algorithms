#include <stdio.h>
#define MATCH +1
#define MISMATCH -1
#define INDEL -2
#define N 10

int max(int,int,int);

/*
* Example of Global Alignment using Neddlman-Wunsch algorithm 
*/
int main(){
	//structure used
	char[] first_seq = "";
	char[] second_seq = "";
	int[N][N] dynamic;
	int i, j;
	int computation;

	//score
	int match = MATCH;
	int mismatch = MISMATCH;
	int indel = INDEL;


	//initialization of dynamic matrix
	for(int i = 0; i < N; i++){
		dynamic[0][i] = indel;
		dynamic[i][0] = indel;
	}

	for(int i = 1; i < N; i++){ //first sequence
		for(int j = 1; j < N; j++){ //second sequence
			if(first_seq[i] == first_seq[j])
				dynamic[i][j] = max(dynamic[i - 1][j - 1] + MATCH, dynamic[i-1][j] + INDEL, dynamic[i][j-1]+INDEL);
			else 
				dynamic[i][j] = max(dynamic[i - 1][j - 1] + MATCH, dynamic[i-1][j] + INDEL, dynamic[i][j-1]+INDEL);

		}
	}

	printf("Result: %d", dynamic[N-1][N-1]);


}

int max(int a, int b, int c){

	if(a > b){
		if(b > c){
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