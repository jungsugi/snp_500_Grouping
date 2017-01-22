#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int namu[1000000];
int sum[1000000];
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=0; i<N; i++){
		cin>>namu[i];
	}
	sort(namu,namu+N);  //입력받은 나무 정렬
	int idx_size = N-1;
	int sum_count=0;
	for(int i=idx_size; i>=1; i--){ //범위찾기
		sum[idx_size-i] = namu[i]-namu[i-1];
		sum_count++;
	}
	int total_sum=0;
	if(sum_count ==0){
		cout << M;
	}else{
		for(int i=0; i<sum_count; i++){
			if(total_sum + (sum[i]*(i+1)) == M){
				cout << namu[i];
				break;
			}
			else if(total_sum + sum[i]*(i+1) < M){
				total_sum += sum[i]*(i+1);
				continue;
			}else{
				int count=0;
				for(int j=i; j<=sum[i]+i;j++){
					count++;
					total_sum += (i+1);
					if(total_sum >= M){
						cout << namu[N-i-1] - count;
						break;
					}
				}break;
			}
		}
	}
	
	return 0;
}