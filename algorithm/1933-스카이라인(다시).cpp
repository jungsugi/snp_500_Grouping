#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

priority_queue<int,int> q[100000];

int main(){
	int N;
	int min_L=1000000002, max_R=0;
	scanf("%d", &N);
	while(N--){
		int L,H,R;
		scanf("%d %d %d",&L,&H,&R);
		if(min_L>L) min_L = L;
		if(max_R<R) max_R = R;
		for(int i=L; i<=R; i++){
			q[i].push(H,R);	
		}
	}
	return 0;
}