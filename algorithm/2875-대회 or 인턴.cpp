#include<iostream>
#include<cstdio>

using namespace std;

int N,M,K;
int max_cnt;

void find(int cur_women, int cur_man, int team_cnt){
	if(cur_man < 1 || cur_women < 2) return;	//남여가 부족해서 팀을 만들수가 없음
	else{//현재 남자 여자의 수를 줄여서 한팀을 만들고 인원수를 줄임
		while(cur_man >= 1 && cur_women >= 2){
			cur_man -=1;   
			cur_women -=2;
			team_cnt++;
		} 	
	}
	if(team_cnt > max_cnt) max_cnt = team_cnt;

}

int main(){
	scanf("%d %d %d",&N,&M,&K);		//n,m,k명
	for(int i=0; i<=K; i++){
		find(N-i, M-(K-i), 0);
	}
	cout << max_cnt;

	return 0;
}