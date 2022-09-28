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

ll exgcd(ll a, ll b, ll &x, ll &y){
    if (!b){
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

void solve(){
    ll x,y,m,n,L,a,b;
    cin >> a >> b >> m >> n >> L;
    ll d = exgcd(m-n,-L,x,y);
    // cout << x << ' ' << y << '\n';
    if((b-a)%d){
        cout << "Impossible" << '\n';
        return;
    }
    else{
        ll t = abs(L / d);
        x = (b - a) / d * x;
        cout << (x % t + t) % t << '\n';
    }
}

int main(){
    FAST 
    ll T = 1; 
    // cin >> T;
    while(T--) solve(); 
}