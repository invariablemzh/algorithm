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
ll q[N];

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
    ll n,k,s;
    cin >> n >> k >> s;
    ll res = (n - 1) * n / 2;
    res = s - res;
    ll x, y;
    ll d = exgcd(k+1,n,y,x);
    // cout << k + 1 << ' ' << n << ' ' << y << ' ' << x << '\n';
    if(res % d){
        cout << "-1" << '\n';
        return;
    }
    y *= res / d, x *= res / d;
    // cout << x << ' ' << y << '\n';
    ll t = abs((k+1) / d);
    // cout << t << '\n';
    y = (y % t + t) % t;
    x = (res - (k+1) * y) / n;
    cout << x << ' ' << y << '\n';
    // cout << res << '\n';    
    
    for(int i = 1;i<=n;i++){
        q[i] = i + x - 1;
    }
    bool flag = false;
    if(y<=n){
        flag = true;
        for(int i = 1;i<=y;i++){
            q[i] += (1 + k);
        }
    }
    else{
        ll t = 1;
        y -= 1;
        for(int i = 1;i<n;i++){
            t ++;
            y -= t;
            if(y%t==0){
                flag = true;
                break;
            }
        }
        ll len = y / t;
        // cout << len << endl;
        for(int i = 1;i<=len;i++){
            q[i] += t * (k + 1);
        }
        t --;
        for(int i = len+1;i<=n;i++){
            q[i] += t * (k + 1);
            t --;
        }
    }
    if(!flag) {
        cout << "-1" << '\n';
        return;
    }
    for(int i = 1;i<=n;i++){
        cout << q[i] << ' ';
    }
    cout << '\n';
}

int main(){
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve(); 
}