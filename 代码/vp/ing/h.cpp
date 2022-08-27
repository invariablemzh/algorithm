#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000010, mod = 998244353;

int n,m;
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
                euler[t] = (euler[i] * primes[j]) % mod;
                break;
            }
            euler[t] = (euler[i] * (primes[j] - 1)) % mod;
        }
    }
}



int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    scanf("%d%d",&n,&m);
    get_eulers(n);
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        if(gcd(l,r)==1) puts("1 1");
        else{
            int t = gcd(l,r);
            ll res = euler[l/t*r];
            
        }
    }
}