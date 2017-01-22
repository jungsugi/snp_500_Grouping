#include<iostream>
#include<cstdio>

using namespace std;

int N,S;
int node[20];
int cnt, cur_sum;

void dfs(int node_n){ //노드 번호
	if(node_n == N) return;  //마지막 노드 다음노드면 return
	if(cur_sum + node[node_n] == S) cnt++;	//현재 노드가 포함됬을때, 합과 같다면 카운트 증가. 	
	
	dfs(node_n+1);	//현재 노드를 포함시키지 않고 다음 노드로  -> 리턴됬을때 자기값을 가지고 있어야함.
	
	cur_sum += node[node_n];  //현재 노드를 포함
	dfs(node_n+1);
	
	cur_sum -= node[node_n];  //전역변수 이므로 다시 현재 노드를 빼 줘야함.(리턴 됬을때 다시 자기 값을 가지고 있어야함)
	
}

int main(){
	scanf("%d %d",&N,&S); //N 과 S 입력 받음
	for(int i=0; i<N; i++){
		scanf("%d",&node[i]);
	}
	dfs(0);
	cout << cnt;		
	return 0;
}
