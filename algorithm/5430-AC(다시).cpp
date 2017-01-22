#include<iostream>
#include<cstdio>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);

	while(N--){
		int cnt=0;
		int num=0;
		string s;
		deque<int> d; //덱
		cin >> s;
		int n; char c;
		scanf("%d\n[",&n);	//엔터 입력과 '['까지 씹음.
		if(n != 0){
			while(1){  //입력
				c = getchar();
				if(c >= '0' && c<='9'){ //숫자면,ㄷㄷ
					cnt++;
					if(cnt==1) num = c-'0';
					else if(cnt==2) num = c-'0'+ num*10;
					else if(cnt==3) num = 100;
				}else{  //숫자가 아니면
					d.push_back(num);
					cnt=0; num=0;
					if(c == ']') break;
				}
			}
		}
		bool front=true; 
		bool end=false;
		bool error = false;
		for(int i=0; i<s.size(); i++){  //실제로 제거
			if(s[i] =='D'){
				if(d.size() > 0){
					if(front) d.pop_front();		
					else d.pop_back();
				}else{
					error = true;
					printf("error\n");
					break;			
				}
			}
			else if(s[i] =='R'){  //reverse;
				if(front){ front=false; end=true;}
				else{ front=true; end=false;}
			}
		}

		if(!error){
			printf("[");
			if(end) reverse(d.begin(), d.end());
			for(int i=0; i<d.size(); i++){
				printf("%d",d[i]);
				if(i == d.size()-1){
					break;
				}else{
					printf(",");
				}
			}
			printf("]\n");
		}
	}	

	return 0;
}