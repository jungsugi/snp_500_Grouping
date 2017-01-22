#include<iostream>
#include<cstdio>

using namespace std;

int N,M,K;
int max_cnt;

void find(int cur_women, int cur_man, int team_cnt){
	if(cur_man < 1 || cur_women < 2) return;	//������ �����ؼ� ���� ������� ����
	else{//���� ���� ������ ���� �ٿ��� ������ ����� �ο����� ����
		while(cur_man >= 1 && cur_women >= 2){
			cur_man -=1;   
			cur_women -=2;
			team_cnt++;
		} 	
	}
	if(team_cnt > max_cnt) max_cnt = team_cnt;

}

int main(){
	scanf("%d %d %d",&N,&M,&K);		//n,m,k��
	for(int i=0; i<=K; i++){
		find(N-i, M-(K-i), 0);
	}
	cout << max_cnt;

	return 0;
}