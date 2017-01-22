#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int M_input[100001];
int N_input[100001];

bool binary_search_(int l_idx, int r_idx, int value){
	int m_idx = (l_idx + r_idx)/2;
	if(N_input[m_idx]==value){
		return true;
	}
	if(r_idx - l_idx <= 0 ) return false;
	else{
		if(value < N_input[m_idx]){
			return binary_search_(l_idx, m_idx-1, value);
		}
		else{
			return binary_search_(m_idx+1, r_idx, value);
		}
	}	
}

int main(){
	int N,M;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&N_input[i]);
	}
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		scanf("%d",&M_input[i]);
	}
	sort(N_input, N_input+N);

	for(int i=0;i<M;i++){
		if(binary_search_(0,N-1,M_input[i]) == true) printf("1\n");
		else printf("0\n");
	}

	return 0;
}