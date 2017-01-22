#include<iostream>
#include<cstdio>
#include<queue>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
priority_queue<int, vector<int> , greater<int> > min_heap;
int main(){
    int t, N;
    scanf("%d", &N);
    while(N--){
        scanf("%d",&t);
        min_heap.push(t);
    }
    int sum = 0;
    while(min_heap.size()>1){
        int a=0, b=0;
        a = min_heap.top(); min_heap.pop();
        b = min_heap.top(); min_heap.pop();
        sum += a+b;
        min_heap.push(a+b);
    }
    printf("%d",sum);
    return 0;
}


