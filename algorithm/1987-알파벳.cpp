#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
int R,C;
char c[20][20];
int Max_cnt;

bool In_array(char input, vector<int> cur_compose){  //배열원소가 배열에 있는지확인
	for(int i=0; i< cur_compose.size(); i++){
		if(cur_compose[i] == input){
			return true;
		}
	}
	return false;
}

void ABC(vector<int> cur_compose, int cur_g, int cur_s, int cnt){ //현재구성알파벳,현재 위치(가로,세로)
	if(In_array(c[cur_s][cur_g], cur_compose)){  //현재 위치가 못가는 위치면 return
		return;
	}
	//현재 위치가 갈수 있는 위치이면,

	if(!In_array(c[cur_s][cur_g], cur_compose)){  //추가가 안된 벡터라면
		cur_compose.push_back(c[cur_s][cur_g]);  //지금까지 이동한 벡터 현재 위치 추가
	}
		
	cnt++;  //움직인 횟수 증가시키고
	if(Max_cnt < cnt) Max_cnt = cnt;  //최대 움직임이면 Max값 수정.	

	if(cur_g + 1 <= C-1)	ABC(cur_compose, cur_g+1, cur_s, cnt);
	if(cur_g - 1 >= 0)	ABC(cur_compose, cur_g-1, cur_s, cnt);
	if(cur_s + 1 <= R-1)	ABC(cur_compose, cur_g, cur_s+1, cnt);
	if(cur_s - 1 >= 0)	ABC(cur_compose, cur_g, cur_s-1, cnt);

}


int main(){
	scanf("%d %d",&R,&C);  //R-가로, C-세로
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