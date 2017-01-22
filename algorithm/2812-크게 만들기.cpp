#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

char n[500000];
vector<char> v;

int main(){
	int N,K;  
	scanf("%d %d", &N, &K);	//k와 n입력받기
	
	for(int i=0; i<N; i++){
		cin>>n[i];
	}
	sort(n,n+N);
	for(int i=K; i<N; i++){
		v.push_back(n[i]);
	}
	if(v.size() !=0 ){
		for(int i=v.size()-1; i>=0; i--){
			cout << v[i];
		}
	}else{
		cout << "";
	}

	return 0;
}