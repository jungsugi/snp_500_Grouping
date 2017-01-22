#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	string s;
	string ss;
	cin >> s;
	
	int sum =0;
	bool check_0 = false;
	char c[100000];
	
	for(int i=0; i<s.size(); i++){
		c[i] = s[i];
		sum += s[i] - '0';
		if(s[i] == '0') check_0 = true;
	}

	if(sum % 3 ==0 && check_0==true){
		sort(c, c+s.size());
		for(int i=s.size()-1;i>=0; i--){
			ss.push_back(c[i]);
		}
		cout << ss;
	}
	else cout<<"-1";
	
	return 0;
}