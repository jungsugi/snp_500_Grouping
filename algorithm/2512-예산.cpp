#include<iostream>
#include<cstdio>
#include<algorithm>
#define Max 1000000000
using namespace std;
int deposit[10000];
int N,M;
bool com(int middle){
	int sum=0;
	int cnt=0;
	for(int i=0;i<N;i++){
		if(sum+deposit[i] <= M){
			cnt++;
			sum +=deposit[i];
		}else{
			if(sum + middle <=M){
				cnt++;
				sum += middle;
			}else return false;
		}
	}
	if(cnt>=N) return true;
	else return false;
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
			cin >> deposit[i];
	}
	scanf("%d",&M);
	sort(deposit,deposit+N);
	int left=1;
	int right= Max;
	int middle=0;
	while(left<=right){
		middle = (left+right)/2;
		int sum=0;
		int cnt=0;	
		bool pos = com(middle);
		if(pos) left = middle+1;
		else right = middle-1;
	}
	cout << middle;
		
	return 0;
}