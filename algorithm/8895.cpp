#include <iostream> 
using namespace std; 

long long d[21][21][21]; 

int main() { 
     d[1][1][1] = 1LL; 
     for (int i=2; i<=20; i++) { 
         for (int j=1; j<=20; j++) { 
             for (int k=1; k<=20; k++) { 
                 d[i][j][k] = d[i-1][j-1][k] + d[i-1][j][k-1] + d[i-1][j][k] * (i-2); 
             } 
         } 
     } 
     int t; 
     cin >> t; 
     while (t--) { 
         int n, l, r; 
         cin >> n >> l >> r; 
         cout << d[n][l][r] << '\n'; 
     } 
     return 0; 
 } 
