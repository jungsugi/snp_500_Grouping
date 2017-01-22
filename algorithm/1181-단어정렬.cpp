#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct sort_abc{
    bool operator()(const std::pair<int,string> &left, const std::pair<int,string> &right) {
        return left.second < right.second;
    }
};

int main(){
	int n;
	vector<pair<int,string> >v;
	scanf("%d",&n);
	for(int i=0; i<n; i++){  //ют╥б.
		string s;
		cin >> s;
		v.push_back(make_pair(s.size(),s));
	}
	sort(v.begin(), v.end(), sort_abc());
	sort(v.begin(), v.end());

	string pre;
	for(int i=0; i<v.size(); i++){
		if(i!=0){
		string a=v[i-1].second;
		string b=v[i].second;
			if(a.compare(b)==0){
				continue;
			}
		}
		cout << v[i].second << endl;
	}
	return 0;
}