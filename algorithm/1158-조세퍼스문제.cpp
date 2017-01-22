#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
queue<int> q;

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=1; i<=N; i++){
		q.push(i);
	}
	int first=0;
	while(q.size()){
		if(first==0){
			printf("<"); first++;
		}
		for(int i=1; i<M; i++){
			q.push(q.front()); //뒤로 넣고
			q.pop(); //앞으로 빼고 반복
		}
		printf("%d",q.front());
		q.pop();
		if(q.size()!=0) printf(", ");
		else printf(">");
	}
	return 0;	
}