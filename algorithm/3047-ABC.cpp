#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int n[3];
char c[3];
void pri(char c[],int idx){
	if(c[idx] == 'A') printf("%d ", n[0]); 
	else if(c[idx] == 'B') printf("%d ", n[1]);
	else if(c[idx] == 'C') printf("%d ", n[2]);
	if(idx == 2) return;
	else pri(c,idx+1);
}

int main(){
	for(int i=0; i<3; i++){
		cin >> n[i];
	}sort(n,n+3);
	for(int i=0; i<3; i++){
		cin >> c[i];
	}
	pri(c,0);
	return 0;
}