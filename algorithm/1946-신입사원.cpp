#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int n;  //test case
	scanf("%d",&n);
	int cnt;
	
	for(int i=0; i<n; i++){
		vector<pair<int, int> > sinip;
		cnt = 0;
		int m;  //신입사원수
		scanf("%d",&m);
		for(int j=0; j<m; j++){
			int a,b;
			scanf("%d %d",&a,&b);
			sinip.push_back(make_pair(a,b));
		}
		sort(sinip.begin(), sinip.end());  //first기준으로 sorting
		
		for(int i=0; i<sinip.size(); i++){
			if(i>0){
				for(int j=i-1; j>=0; j--){
					if(sinip[j].second < sinip[i].second){
						cnt++;	///break횟수 새기
						break;
					}
				}
			}
		}		
		cout << m - cnt << endl;

	}
	return 0;
}