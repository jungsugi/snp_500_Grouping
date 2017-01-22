#include<iostream>
#include<cstdio>

using namespace std;
int n;
int forest[501][501];
int D[501][501];
const int move_r[4]={1,0,-1,0};  //아래,오른,위,왼
const int move_c[4]={0,1,0,-1};
int maxs;

void find_way(int cur_r, int cur_c){
	int v=0;
	int next_r;
	int next_c;
	for(int i=0; i<=3; i++){
		next_r = cur_r+move_r[i];  //다음 row
		next_c = cur_c+move_c[i];  //다음 col

		if(next_r <0 || next_r >=n || next_c <0 || next_c >= n)	continue; //범위를 벗어나는 값이면 계속
		
		if(forest[next_r][next_c] < forest[cur_r][cur_c]){
			if(D[next_r][next_c]==0) find_way(next_r,next_c);
			if(v<D[next_r][next_c]) v=D[next_r][next_c];
		}
	}
	D[cur_r][cur_c] = v+1;
	if(maxs < D[cur_r][cur_c]) maxs = D[cur_r][cur_c];
}

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d",&forest[i][j]);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(D[i][j] == 0) find_way(i,j);
		}
	}
	printf("%d",maxs);
	
    return 0;
}
