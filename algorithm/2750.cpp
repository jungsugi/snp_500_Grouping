#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	vector<int> v;	
	for(int i=0; i<N; i++){
		int n;
		scanf("%d",&n);
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	for(int i=0;i<v.size(); i++){
		printf("%d\n",v[i]);
	}


	return 0;
}