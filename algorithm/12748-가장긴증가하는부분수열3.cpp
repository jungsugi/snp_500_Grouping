#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int  N;
int D[1000];
int main(){
	scanf("%d", &N);
	int cnt=0;
	int value;
	for(int i=0;i<N; i++){	
		scanf("%d",&value);
		int idx = lower_bound(D, D+cnt, value) - D;  
		//원래는 Iterator사용 해야되는데 , '-배열(시작주소)' 을 해줌으로써 idx를 구할수 있다.
		if(idx == cnt){
			cnt ++;
		}D[idx] = value;
	}

	cout << cnt<< endl;
	
	return 0;
}