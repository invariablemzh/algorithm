#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;


ll qmi(int a, int b, int p){
    ll res = 1;
    while (b){
        if (b & 1) res = res * a % p;
        a = a * (ll)a % p;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    ll ans = (n-m) * qmi(2,mod-2,mod) % mod;
    printf("%lld\n",ans);
}

int main(){
    int T; scanf("%d",&T);
    while(T--) solve();
}