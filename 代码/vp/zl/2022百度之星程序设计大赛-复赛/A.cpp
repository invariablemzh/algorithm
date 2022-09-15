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
int a[N];

void solve(){
    int n; cin >> n;
    for(int i = 1;i<=n;i++) cin >> a[i];
    ll res = 0;
    for(int i = 1;i<=n;i++){
        res += a[i];
    }
    cout << res << '\n';
}

int main(){
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve(); 
}