#include<vector>
#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &k, &n);
    vector<int> v(n);
    for(int i=0; i<n; ++i) scanf("%d", &v[i]);
    
    int ret = 0, idx = 0;
    vector<bool> pluged(101, false);
    int curK = 0, lastPush = v.front();
    for(int i=0; i<n; ++i){
        if(pluged[v[i]]) continue;
        curK += 1;
        if(curK > k){
            vector<int> lastUse(101, n);
            int cand = -1, maxD = -1;
            for(int j=0; j<i; ++j){
                if(!pluged[v[j]]) continue;
                for(int k=i+1; k<n; ++k){
                    if(v[j] == v[k]){
                        lastUse[v[j]] = k;
                        break;
                    }
                }
                if(maxD < lastUse[v[j]]){
                    maxD = lastUse[v[j]];
                    cand = v[j];
                }
            }
            if(cand == -1) cand = lastPush;
            //printf("push:%d, then pop: %d\n", v[i], cand);
            ret += 1;
            pluged[cand] = false;
        }
        lastPush = v[i];
        pluged[v[i]] = true;
    }
    printf("%d", ret);
    return 0;
}