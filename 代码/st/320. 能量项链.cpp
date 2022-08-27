#include <bits/stdc++.h>
using namespace std;
const int N = 210;

int n;
int w[N];
int f[N][N];

int main(){
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> w[i];
        w[n + i] = w[i];
    }
    for(int len = 3;len<=n+1;len++){
        for(int l = 1;l+len-1<=2*n;l++){
            int r = l+len-1;
            if(l==r) f[l][r] = 0;
            for(int k = l+1;k<r;k++){
                f[l][r] = max(f[l][r],f[l][k] + f[k][r] + w[l] * w[k] * w[r]);
            }
        }
    }
    int res = 0;
    for(int i = 1;i<=n;i++) res = max(res,f[i][i+n]);
    cout<<res<<endl;
}
