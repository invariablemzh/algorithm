#include <bits/stdc++.h>
using namespace std;
const int N = 1010, mod = 1e9 + 7;

int n,m;
int f[N], g[N];

int main(){
    cin >> n >> m;
    memset(f,-0x3f,sizeof(f));
    f[0] = 0, g[0] = 1;
    for(int i = 1;i<=n;i++){
        int v,w;
        cin >> v >> w;
        for(int j = m;j>=v;j--){
            int maxv = max(f[j],f[j-v] + w);
            int cnt = 0;
            if(maxv==f[j]) cnt += g[j];
            if(maxv==f[j-v]+w) cnt += g[j-v];
            f[j] = maxv, g[j] = cnt % mod;
        }
    }
    int res = 0;
    for(int i = 0;i<=m;i++) res = max(f[i],res);

    int ans = 0;
    for(int i = 0;i<=m;i++){
        if(res==f[i]){
            ans = (ans + g[i]) % mod;
        }
    }
    cout << ans << endl;

}