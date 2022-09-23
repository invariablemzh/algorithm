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

const int N = 1e5 + 10;
int primes[N], cnt;
bool st[N];

void get_primes(int n){
    for (int i = 2; i <= n; i ++ ){
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ ){
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void solve(){
    int n; cin >> n;
    get_primes(n+1);
    if(n<=2) cout << "1" << '\n';
    else cout << "2" << '\n';
    for(int i = 2;i<=n+1;i++){
        if(!st[i]) cout << 1 << " ";
        else cout << 2 << " ";
    }
}

int main(){
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve(); 
}