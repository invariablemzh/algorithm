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
const int N = 1000010, mod = 1e9 + 7;

int primes[N], cnt;
bool st[N];

void get_primes(int n){
    for (int i = 2; i <= n; i ++ ){
        if (st[i]) continue;
        primes[cnt ++ ] = i;
        for (int j = i + i; j <= n; j += i)
            st[j] = true;
    }
}



void solve(){
    int n; cin >> n;
    get_primes(n);
    ll res = 1;
    for(int i = 0;i<cnt;i++){
        int p = primes[i];
        int s = 0;
        for(int j = n;j;j/=p) s += j / p;
        res = (res * (2 * s + 1)) % mod;
    }
    cout << res << '\n';
}

int main(){
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve(); 
}