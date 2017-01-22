#include<iostream>
#include<cstdio>
using namespace std;
int T; //자두가 떨어지는 순간(1<= 1000)
int W; //자두가 움직이는 횟수(1<= 30)
int throw_pos[1000];  //자두가 떨어지는 순서-> 1 or 2
int D[1001][31][3];  // i=초, j=움직인횟수, k=내위치(1 or 2)
int main(){
	scanf("%d %d",&T,&W);
	for(int i=1; i<=T; i++){
		scanf("%d",&throw_pos[i]);  
	}

	if(throw_pos[1] == 1){
		D[1][0][1]=1; //처음위치에서는 '1'이 됨
		D[1][1][2]=0;
	}else{
		D[1][0][1]=0;
		D[1][1][2]=1;
	}

	int k=0; 
	for(int i=2; i<=T; i++){  // T초
		for(int j=0; j<=W; j++){  //움직인횟수는 T초보다 작아야됨 
			if(i-1<j) continue;  //i-1이 움직인 횟수보다 적으면 안됨.
			if(j%2 == 0){  //짝
				k=1; //현재위치
				D[i][j][k] = D[i-1][j][k];
				if(j>=1 && D[i][j][k] < D[i-1][j-1][k+1]) D[i][j][k] = D[i-1][j-1][k+1];
				if(throw_pos[i]==k) D[i][j][k]+=1;
			}else{ //홀
				k=2;  //현재위치
				D[i][j][k] = D[i-1][j][k];
				if(j>=1 && D[i][j][k] < D[i-1][j-1][k-1]) D[i][j][k] = D[i-1][j-1][k-1];
				if(throw_pos[i]==k) D[i][j][k] +=1;
			}
		}
	}
	int maxs=D[T][0][1];
	for(int i=0; i<=W; i++){
		if(maxs < D[T][i][1]) maxs = D[T][i][1];
		if(maxs < D[T][i][2]) maxs = D[T][i][2];
	}
	cout << maxs << endl;
	return 0;
}