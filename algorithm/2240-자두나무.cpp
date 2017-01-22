#include<iostream>
#include<cstdio>
using namespace std;
int T; //�ڵΰ� �������� ����(1<= 1000)
int W; //�ڵΰ� �����̴� Ƚ��(1<= 30)
int throw_pos[1000];  //�ڵΰ� �������� ����-> 1 or 2
int D[1001][31][3];  // i=��, j=������Ƚ��, k=����ġ(1 or 2)
int main(){
	scanf("%d %d",&T,&W);
	for(int i=1; i<=T; i++){
		scanf("%d",&throw_pos[i]);  
	}

	if(throw_pos[1] == 1){
		D[1][0][1]=1; //ó����ġ������ '1'�� ��
		D[1][1][2]=0;
	}else{
		D[1][0][1]=0;
		D[1][1][2]=1;
	}

	int k=0; 
	for(int i=2; i<=T; i++){  // T��
		for(int j=0; j<=W; j++){  //������Ƚ���� T�ʺ��� �۾ƾߵ� 
			if(i-1<j) continue;  //i-1�� ������ Ƚ������ ������ �ȵ�.
			if(j%2 == 0){  //¦
				k=1; //������ġ
				D[i][j][k] = D[i-1][j][k];
				if(j>=1 && D[i][j][k] < D[i-1][j-1][k+1]) D[i][j][k] = D[i-1][j-1][k+1];
				if(throw_pos[i]==k) D[i][j][k]+=1;
			}else{ //Ȧ
				k=2;  //������ġ
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