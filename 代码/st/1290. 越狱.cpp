#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
#define x first 
#define y second
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int mod = 100003;

LL qmi(ll a, ll b, ll p){
    LL res = 1 % p;
    while (b){
        if (b & 1) res = res * a % p;
        a = a * (LL)a % p;
        b >>= 1;
    }
    return res;
}

void solve(){
    ll n,m;
    cin >> m >> n;
    ll res = 0;
    res += qmi(m,n,mod);
    res -= (m * qmi(m-1,n-1,mod)) % mod;
    res = (res + mod) % mod;
    cout << res << '\n';
}

int main(){
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve(); 
}