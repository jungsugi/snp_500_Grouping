#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int D[1000][1000];
string s1,s2;

int main(){
	cin >> s1;
	cin >> s2;
	for(int i=1; i<s1.size(); i++){
		int count =0	;
		for(int j=1; j<s2.size(); j++){
			if(s1[i] == s2[j]){  //같고, 전 인덱스보다 맨마지막보다 작다면,
				if(j==0) count =1;
				else if(D[i-1][j-1] <= D[i-1][s2.size()-1]){
					count = D[i-1][j-1] + 1;
				}
			}else{  //같지 않다면,
				if(j==0) count = D[i-1][0];
				else count = max(D[i][j-1],D[i-1][j]);	
			}
			D[i][j] = count;
		}
	}
	
	printf("%d",D[s1.size()-1][s2.size()-1]);
	return 0;
}