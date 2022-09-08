#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 2010;
int n;
int a[N];

void solve(){
    cin >> n;
    int maxx = -1000;
    for(int i = 1;i<=n;i++) {
        cin >> a[i];   
    }
    for(int i = 2;i<=n;i++){
        maxx = max(maxx,a[i-1]-a[i]);
    }
    maxx = max(maxx,a[n]-a[1]);

    for(int i = 2;i<=n;i++){
        maxx = max(maxx,a[i]-a[1]);
    }
    for(int i = 1;i<=n-1;i++){
        maxx = max(maxx,a[n]-a[i]);
    }
    cout << maxx << '\n';
}

int main(){
    FAST
    int T = 1;
    cin >> T;
    while(T--) solve();
    
}