#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
typedef long long ll;

void solve(){
    int n; cin >> n;
    ll sum = 0;
    int t1 = n / 3;
    sum +=  t1 * 3;
    int t2 = n / 2;
    sum += (t2 - t1) * 2;
    sum += n - t2;
    sum += n / 3 + n / 2;
    cout << sum << '\n';
    
}

int main(){
    FAST
    int T = 1;
    cin >> T;
    while(T--) solve();
    
}