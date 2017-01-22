#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>

using namespace std;
/*
struct down_sort{
	bool operator()(const char &left, const char &right){
		return left > right;
	}
};

int	main(){
	string s;
	char c[1000000000];
	cin >> s;
	for(int i=0; i<s.size(); i++){
		c[i] = s[i];
	}
	int size = s.size();
	sort(c, c+size);

	for(int i=0; i<s.size(); i++){
		printf("%c",c[i]);
	}

	return 0;
}*/

#include <stdio.h>
#include <string.h>

int main(){
    char str[13] = " ", temp; //13자리수(10억)
	int i, j, length;
	gets(str);
	length = strlen(str);
	for(i = 0; i < length; i++){
		for(j = 0; j < length; j++){		
			if(str[i] > str[j]){
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}	
	puts(str);
}