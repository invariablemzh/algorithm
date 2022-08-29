#include<bits/stdc++.h> 
using namespace std;
const int N = 1e6 + 10, mod = 998244353;
typedef long long ll;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

int n;
int p[N];
int h[N], e[N], ne[N], w[N], idx;
int dep[N], gl[N], sum[N];
int dout[N];

int qmi(int a, int b, int p){
    ll res = 1;
    while (b){
        if (b & 1) res = res * a % p;
        a = a * (ll)a % p;
        b >>= 1;
    }
    return res % p;
}

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u,int fa,int depth){
    dep[u] = depth;
    for(int i = h[u];~i;i=ne[i]){
        int j = e[i];
        sum[u] = (sum[u] + w[i]) % mod;
        if(j==fa) continue;
        dfs(j,u,depth+1);
    }
}

void dfs2(int u,int fa){
    int res = (p[u] % mod + sum[u] % mod) % mod;
    for(int i = h[u];~i;i=ne[i]){
        int j = e[i];
        if(j==fa) continue;
        dfs2(j,u);
        res = (res + w[i] * gl[j] % mod) % mod;
    }
    if(dout[u]){
        gl[u] = res * qmi(sum[u],mod-2,mod) % mod;
    }

}

int main(){
    FAST
    memset(h,-1,sizeof(h));
    cin >> n;
    for(int i = 1;i<=n;i++) cin >> p[i];
    for(int i = 2;i<=n;i++){
        int a,b;
        cin >> a >> b;
        add(a,i,b);
        dout[a] ++;
    }
    dfs(1,-1,0);
    dfs2(1,-1);
    cout << gl[1] << endl;
    return 0;
}