#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	
	int time[1001];

	for(int i=0; i<n; i++){
		scanf("%d",&time[i]);
	}

	sort(time, time + n);
	long long sum =0;
	long long pre =0;
	for(int i=0; i<n; i++){ 
		pre += time[i];
		sum += pre;
	}
	printf("%lld",sum);
	return 0;
}