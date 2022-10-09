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

ll find(ll n){
    ll res = 0;
    for(int x = 0; x <= 2; x ++){
        ll l = 0, r = 2e9 + 10;
        while(l<r){
            ll mid = l + r + 1 >> 1;
            if(mid * (mid + x) > n) r = mid - 1;
            else l = mid;
        }
        res += l;
    } 
    return res;
}

void solve(){
    ll l,r;
    cin >> l >> r;
    cout << find(r) - find(l-1) << '\n';
}

int main(){
    FAST 
    int T = 1; 
    cin >> T;
    while(T--) solve(); 
}