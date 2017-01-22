#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int D[1000];
int input[1000];
int max_idx;
vector<int> v[1000];
int main(){
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&input[i]);
	
	for(int i=0;i<n;i++){
		int smaller_cnt=0;
		for(int j=0; j<i; j++){
			if(input[i] > input[j]){
				if(smaller_cnt <= D[j]){
					if(smaller_cnt == D[j]){
						if(v[i][v[i].size()-1] > input[j]){
							v[i].pop_back();
							v[i].push_back(input[j]);
						}
					}else{
						v[i].push_back(input[j]);
					}
					smaller_cnt = D[j];
				}
			}
		}
		D[i] = smaller_cnt+1;
		if(D[i] > D[max_idx]) max_idx=i;
	}


	cout << D[max_idx] << endl;	
	for(int i=0; i< v[max_idx].size(); i++){
		cout << v[max_idx][i] << " ";
	}cout << input[max_idx] << endl;
	
	return 0;
}