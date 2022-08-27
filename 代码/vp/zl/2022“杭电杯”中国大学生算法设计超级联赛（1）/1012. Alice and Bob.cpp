#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];

void solve(){
    int n; scanf("%d",&n);
    for(int i = 0;i<=n;i++) scanf("%d",&a[i]);
    for(int i = n;i>=1;i--){
        a[i-1] += a[i] / 2; 
    }
    if(a[0]) puts("Alice");
    else puts("Bob");
}

int main(){
    int T; scanf("%d",&T);
    while(T--) solve();
}