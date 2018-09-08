#include<iostream>

using namespace std;

int main(){
	int R, S, K;
	cin >> R >> S >> K;
	char temp;
	char window_shortcut[R-2][S-2];
	char window[R][S];
	for(int i = 0; i < R; i++){
		for(int j = 0; j < S; j++){
			cin >> temp;
			window[i][j] = temp;
			if ( i > 0 && j > 0 && i < R-1 && j < S-1){
				window_shortcut[i-1][j-1] = temp;				
			}				
		}
	}
	int num = 0, mx = 0;
	int row = 0, col = 0;
	for(int i = 0; i < R-K+1; i++){
		for(int j = 0; j < S-K+1; j++){
			num = 0;
			for(int m = i; m < i+K-2; m++){
				for(int p = j; p < j+K-2; p++){
					if(window_shortcut[m][p] == '*')
						num++;
				}				
			}
			if(num > mx){
				mx = num;
				row = i;
				col = j;
			}
				
		}
		
	}
	
	cout << mx <<endl;
	// i, j is the upper left vertex of the paizi
	for(int i = 0; i<R; i++){
		for(int j = 0; j<S; j++){
			if(i == row){
				if(j==col || j ==col+K-1)
					cout << '+';
				else if(j > col && j < col+K-1)
					cout << '-';
				else
					cout << window[i][j];
			}
			else if( i == row + K - 1){
				if(j==col || j ==col+K-1)
					cout << '+';
				else if(j > col && j < col+K-1)
					cout << '-';
				else
					cout << window[i][j];
			}
			else{
				if((j==col && i > row && i < row+K-1) || (j==col + K - 1 && i > row && i < row+K-1))
					cout << '|';
				else
					cout << window[i][j];
			}
		}
		cout << endl;
	}


	return 0;
}
