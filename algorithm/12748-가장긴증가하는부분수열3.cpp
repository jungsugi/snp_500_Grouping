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
		//������ Iterator��� �ؾߵǴµ� , '-�迭(�����ּ�)' �� �������ν� idx�� ���Ҽ� �ִ�.
		if(idx == cnt){
			cnt ++;
		}D[idx] = value;
	}

	cout << cnt<< endl;
	
	return 0;
}