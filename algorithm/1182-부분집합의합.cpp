#include<iostream>
#include<cstdio>

using namespace std;

int N,S;
int node[20];
int cnt, cur_sum;

void dfs(int node_n){ //��� ��ȣ
	if(node_n == N) return;  //������ ��� �������� return
	if(cur_sum + node[node_n] == S) cnt++;	//���� ��尡 ���ԉ�����, �հ� ���ٸ� ī��Ʈ ����. 	
	
	dfs(node_n+1);	//���� ��带 ���Խ�Ű�� �ʰ� ���� ����  -> ���ω����� �ڱⰪ�� ������ �־����.
	
	cur_sum += node[node_n];  //���� ��带 ����
	dfs(node_n+1);
	
	cur_sum -= node[node_n];  //�������� �̹Ƿ� �ٽ� ���� ��带 �� �����.(���� ������ �ٽ� �ڱ� ���� ������ �־����)
	
}

int main(){
	scanf("%d %d",&N,&S); //N �� S �Է� ����
	for(int i=0; i<N; i++){
		scanf("%d",&node[i]);
	}
	dfs(0);
	cout << cnt;		
	return 0;
}
