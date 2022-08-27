#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;


int main(){
    scanf("%lld",&n);
    ll res = 0;
    if(n % 2){
        for(int i = 2;i<=n/i;i++){
            if(n%i==0){
                n -= i;
                break;
            } 
        }
        if(n%2) res++;
        else res = n / 2 + 1;
    }
    else res = n / 2;
    printf("%lld\n",res);
}