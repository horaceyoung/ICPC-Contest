//alphabet - DP
#include<iostream>
using namespace std;

int alphabet(char a[]){
	int lis[51];
	lis[0] = 1;
	int size = 1;
	for(int j = 1; a[j] <= 'z' && a[j] >='a'; j++){
		lis[j] = 1;
		size ++;
		for(int k = 0; k < j; k++){
			if(a[j] > a[k]){
				if(lis[j] < lis[k] + 1)
					lis[j] = lis[k] + 1;
			}
				
		}
	}
	int mx = 0;
	for(int i=0; i < size; i++){
		if(lis[i]>mx)
			mx = lis[i];
	}
	mx = 26-mx;
	cout << mx << endl;
}

int main(){
	char al[51];
	char temp;
	int i = 0;
	do{
		temp = getchar();
		al[i] = temp;
		i++;
	}while(temp <= 'z' && temp >='a');
	
	
	alphabet(al);
	
	return 0;
}
