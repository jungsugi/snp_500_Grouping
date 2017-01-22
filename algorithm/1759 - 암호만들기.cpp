#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

int L,C;
char m[15]; // 3~15개의 문자

void backtracking(string cur_s, int node_num, int m_count, int j_count){ //노드 번호, 모음갯수, 자음갯수
	if(m_count + j_count == L){  // 포함개수가 L개이고 모음 1개이상, 자음 2개이상이면,
		if(m_count >= 1 && j_count >=2){
			sort(cur_s.begin(), cur_s.end());  //sorting해서 return한다.
			cout << cur_s << endl;
			return;	
		}
	}

	
	for(int i = node_num+1; i<C; i++){
		string cur_string = cur_s+m[i];
		if(m[i] == 'i' || m[i] == 'o' || m[i] == 'a' || m[i] == 'e' || m[i] == 'u'){ 
			backtracking(cur_string, i, m_count+1, j_count);
		}else{
			backtracking(cur_string, i, m_count, j_count+1);
		}
	}
}


int main(){
	scanf("%d %d",&L,&C);

	for(int i=0; i<C; i++){
		cin >> m[i];
	}

	string cur_s;
	sort(m,m+C);  //sorting해서 return한다.
	backtracking(cur_s, -1, 0, 0); //시작 이전 노드 부터 시작 --> 위코드 보고 이해

	return 0;
}