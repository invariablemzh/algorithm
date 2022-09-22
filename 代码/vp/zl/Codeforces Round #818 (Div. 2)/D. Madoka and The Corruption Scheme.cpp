#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#define x first 
#define y second
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 100010, mod = 1e9 + 7;
int fact[N], infact[N];


int qmi(int a, int k, int p){
    int res = 1;
    while (k){
        if (k & 1) res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}

void solve(){
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i ++ ){
        fact[i] = (ll)fact[i - 1] * i % mod;
        infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
    int n,k;
    cin >> n >> k;
    ll res = 0;
    for(int i = 0;i<=min(n,k);i++){
        res = (res + (ll)fact[n] % mod * infact[n-i] % mod * infact[i] % mod) % mod;
    }
    cout << res << '\n';
}

int main(){
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve(); 
}