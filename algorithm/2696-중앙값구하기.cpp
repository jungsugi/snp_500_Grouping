#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		vector<int> v;
		int n;
		scanf("%d",&n);
		int num;
		for(int i=0; i<n; i++){
			scanf("%d",&num);
			v.push_back(num);
		}
	
		printf("%d\n",n/2+1);
		for(int i=0; i<v.size(); i+=2){
			priority_queue<int> q;
			for(int j=0; j<=i; j++){
				q.push(v[j]);
			}
			int size = q.size();
			for(int k=0; k< size/2; k++){
				q.pop();
			}
			printf("%d ",q.top());
		}printf("\n");
	}
	
	return 0;
}