#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
int R,C;
char c[20][20];
int Max_cnt;

bool In_array(char input, vector<int> cur_compose){  //�迭���Ұ� �迭�� �ִ���Ȯ��
	for(int i=0; i< cur_compose.size(); i++){
		if(cur_compose[i] == input){
			return true;
		}
	}
	return false;
}

void ABC(vector<int> cur_compose, int cur_g, int cur_s, int cnt){ //���籸�����ĺ�,���� ��ġ(����,����)
	if(In_array(c[cur_s][cur_g], cur_compose)){  //���� ��ġ�� ������ ��ġ�� return
		return;
	}
	//���� ��ġ�� ���� �ִ� ��ġ�̸�,

	if(!In_array(c[cur_s][cur_g], cur_compose)){  //�߰��� �ȵ� ���Ͷ��
		cur_compose.push_back(c[cur_s][cur_g]);  //���ݱ��� �̵��� ���� ���� ��ġ �߰�
	}
		
	cnt++;  //������ Ƚ�� ������Ű��
	if(Max_cnt < cnt) Max_cnt = cnt;  //�ִ� �������̸� Max�� ����.	

	if(cur_g + 1 <= C-1)	ABC(cur_compose, cur_g+1, cur_s, cnt);
	if(cur_g - 1 >= 0)	ABC(cur_compose, cur_g-1, cur_s, cnt);
	if(cur_s + 1 <= R-1)	ABC(cur_compose, cur_g, cur_s+1, cnt);
	if(cur_s - 1 >= 0)	ABC(cur_compose, cur_g, cur_s-1, cnt);

}


int main(){
	scanf("%d %d",&R,&C);  //R-����, C-����
	vector<int> cur_compose;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> c[i][j];
		}
	}

	ABC(cur_compose, 0, 0, 0);
	cout << Max_cnt <<endl;
 
	return 0;
}