#include<iostream>
#include<cstdio>
using namespace std;
int N,M;
int lesson[100000];
int main(){
	int left=0;
	int right=1000000000;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		cin >> lesson[i];
		if (lesson[i] > left) left = lesson[i];
	}
	while(left <= right){
		int mid = (left+right)/2;
		int cnt=1;
		int sum=0;
		for(int i=0; i<N; i++){
			if(sum+lesson[i] > mid ){
				sum=0;
				cnt++;
			}
			sum+=lesson[i];	
		}
		(cnt > M)? left=mid+1 : right=mid-1;	
	}
	cout<<left;
}