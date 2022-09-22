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
const int N = 1010;

int primes[N], cnt;
int euler[N];
bool st[N];

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
}

void solve(){
    int n; cin >> n;
    cout << n << ' ';
    ll res = 0;
    for (int i = 1; i <= n; i ++ ) res += euler[i];
    cout << res * 2 + 1 << '\n';
}

int main(){
    FAST 
    int T = 1; cin >> T;
    get_eulers(1000);
    // cin >> T;
    for(int i = 1;i<=T;i++){
        cout << i << ' ';
        solve(); 
    } 
}