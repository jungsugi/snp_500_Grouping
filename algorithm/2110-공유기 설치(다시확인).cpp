#include<cstdio>
#include<algorithm>
using namespace std;
int n, c, a[200000];
int main() {
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n);
    int low = 1, up = 1e9, mid;  //up=1000000000
    while (low <= up) {
        mid = (low + up)/2;
        int cnt = 1, t = a[0];
        for (int i=1; i<n; i++){
			if (a[i] - t >= mid){
				t = a[i];
				cnt++;
			}
		}
        (cnt < c) ? (up = mid - 1) : (low = mid + 1);
    }
    printf("%d", up);
    return 0;
}