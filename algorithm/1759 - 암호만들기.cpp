#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

int L,C;
char m[15]; // 3~15���� ����

void backtracking(string cur_s, int node_num, int m_count, int j_count){ //��� ��ȣ, ��������, ��������
	if(m_count + j_count == L){  // ���԰����� L���̰� ���� 1���̻�, ���� 2���̻��̸�,
		if(m_count >= 1 && j_count >=2){
			sort(cur_s.begin(), cur_s.end());  //sorting�ؼ� return�Ѵ�.
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
	sort(m,m+C);  //sorting�ؼ� return�Ѵ�.
	backtracking(cur_s, -1, 0, 0); //���� ���� ��� ���� ���� --> ���ڵ� ���� ����

	return 0;
}