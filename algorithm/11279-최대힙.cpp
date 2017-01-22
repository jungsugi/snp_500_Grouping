#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
int N;
priority_queue<int> max_heap;

int main(){
	scanf("%d",&N);
	int n;
	while(N--){
		scanf("%d",&n);
		if(n){
			max_heap.push(n);	
		}else{
			if(max_heap.size() == 0) printf("0\n");
			else{
				printf("%d\n",max_heap.top());
				max_heap.pop();				
			}
		}
	}
	return 0;
}