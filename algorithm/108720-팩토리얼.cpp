#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	string s;

	long long result = 1;

	for(int i=n;i>=1;i--){
		result *= i;
	}
	s =	to_string(result);
	cout << s;
	

	return 0;
}