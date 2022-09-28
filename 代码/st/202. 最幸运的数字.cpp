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

ll gcd(ll a, ll b){
    return b ? gcd(b, a % b) : a;
}

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

ll phi(ll x){
    ll res = x;
    for (ll i = 2; i <= x / i; i ++ )
        if (x % i == 0){
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    if (x > 1) res = res / x * (x - 1);
    return res;
}

int main(){
    FAST 
    ll L;
    int T = 1;
    while(cin >> L, L){
        ll d = gcd(L,8);
        ll c = 9 * L / d;
        ll res = 1e18;
        if((c % 2 == 0)||(c % 5 == 0)) res = 0;
        else{
            ll ph = phi(c);
            for(ll i = 1;i<=ph/i;i++){
                if(ph%i==0){
                    if(qmi(10,i,c)==1) res = min(res,i);
                    if(qmi(10,ph/i,c)==1) res = min(res,ph/i);
                }
            }
        }
        cout << "Case " << T++ << ": " << res << '\n';
    }

}