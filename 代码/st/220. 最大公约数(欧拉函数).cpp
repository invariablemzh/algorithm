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
const int N = 10000010;

int primes[N], cnt;
int euler[N];
bool st[N];
ll s[N];

void get_eulers(int n){
    euler[1] = 1;
    for (int i = 2; i <= n; i ++ ){
        if (!st[i]){
            primes[cnt ++ ] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j ++ ){
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0){
                euler[t] = euler[i] * primes[j];
                break;
            }
            euler[t] = euler[i] * (primes[j] - 1);
        }
    }
    for(int i = 1;i<=n;i++) s[i] = s[i-1] + euler[i];
}

void solve(){
    int n; cin >> n;
    get_eulers(n);
    ll res = 0;
    for(int i = 0;i<cnt;i++){
        int p = primes[i];
        res += (s[n/p]-1) * 2 + 1;
    }
    cout << res << '\n';
}

int main(){
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve();
}