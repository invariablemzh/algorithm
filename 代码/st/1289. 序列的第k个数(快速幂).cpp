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

const int mod = 200907;

LL qmul(LL a, LL k, LL b)
{
    LL res = 0;
    while (k)
    {
        if (k & 1) res = (res + a) % b;
        a = (a + a) % b;
        k >>= 1;
    }
    return res;
}

LL qmi(LL a, LL k, LL b)
{
    LL res = 1;
    while (k)
    {
        if (k & 1) res = qmul(res, a, b);
        a = qmul(a, a, b);
        k >>= 1;
    }
    return res;
}

void solve(){
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    ll res = 0;
    if(2*b==a+c){
        ll d = b - a;
        res = (a + (k - 1) * d) % mod;
    }
    else{
        res = qmi(b/a,k-1,mod);
        res = qmul(res,a,mod);
    }
    cout << res << '\n';
}

int main(){
    FAST 
    int T = 1; 
    cin >> T;
    while(T--) solve(); 
}