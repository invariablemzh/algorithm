#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 510;
int n,m;
ll f[N][N];

void solve(){
    cin >> n >> m;
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=n;j++){
            if(i==j) f[i][j] = 0;
            else f[i][j] = 1e18;
        }
    }

    vector<tuple<int,int,int>> ed;
    while(m--){
        int a,b,w;
        cin >> a >> b >> w;
        ed.push_back(make_tuple(a,b,w));
        f[a][b] = f[b][a] = 1ll;
    }
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    ll res = 1e18;
    for(auto x : ed){
        int u = get<0>(x);
        int v = get<1>(x);
        int w = get<2>(x);
        res = min(res, (ll) w * (f[1][u] + f[n][v] + 1));
        res = min(res, (ll) w * (f[1][v] + f[n][u] + 1));
        for (int i = 1; i <= n; ++i) {
            res = min(res, (ll) w * (f[v][i] + 1 + f[i][1] + f[i][n] + 1));
            res = min(res, (ll) w * (f[u][i] + 1 + f[i][1] + f[i][n] + 1));
        }
    }
    cout << res << '\n';
}

int main(){
    FAST 
    int T = 1; 
    cin >> T;
    while(T--) solve(); 
}