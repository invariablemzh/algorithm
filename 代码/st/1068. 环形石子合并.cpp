#include <bits/stdc++.h>
using namespace std;
const int N = 410;

int n;
int w[N],s[N];
int f[N][N],g[N][N];

int main(){
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> w[i];
        w[i+n] = w[i];
    }
    memset(f,-0x3f,sizeof(f));
    memset(g,0x3f,sizeof(g));
    for(int i = 1;i <= 2 * n;i++)   s[i] += s[i-1] + w[i];
    for(int len = 1;len<=n;len++){
        for(int l = 1;l + len - 1<=2*n;l++){
            int r = l + len - 1;
            if(l==r) f[l][r] = g[l][r] = 0;
            for(int k = l;k<=r;k++){
                f[l][r] = max(f[l][r], f[l][k] + f[k+1][r] + s[r] - s[l-1]);
                g[l][r] = min(g[l][r], g[l][k] + g[k+1][r] + s[r] - s[l-1]);
            }
        }
    }
    int res1 = 0x3f3f3f3f, res2 = -0x3f3f3f3f;
    for(int i = 1;i<=n;i++){
        res1 = min(g[i][i+n-1],res1);
        res2 = max(f[i][i+n-1],res2);
    }
    cout<<res1<<endl<<res2<<endl;
}