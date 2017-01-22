#include<iostream>
#include<cstdio>

using namespace std;
int input[200];
int D[200];
int maxs;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0; i<n;i++){
		scanf("%d",&input[i]);
	}
	D[0]=1;
	for(int i=1; i<n; i++){
		D[i]=1;
		for(int j=0; j<i; j++){
			if(input[j] < input[i] && D[i]<=D[j]) D[i] = D[j]+1;
		}
		if(maxs < D[i]) maxs=D[i];
	}
	cout << n - maxs;


	return 0;
}