#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

int n,m;

void solve(){
    cin >> n >> m;
    if(n>m||(n%2==0&&(m-n)%2)) cout << "No" << '\n';
    else{
        cout << "Yes" << '\n';
        if(n%2){
            int t = m - n;
            cout << t + 1 << ' ';
            for(int i = 1;i<=n-1;i++) cout << 1 << ' ';
            cout << '\n';
        }
        else{
            int t = (m - n) / 2;
            cout << 1 + t << ' ';
            cout << 1 + t << ' ';
            for(int i = 1;i<=n-2;i++) cout << 1 << ' ';
            cout << '\n';
        }

    }
}

int main(){
    FAST
    int T = 1;
    cin >> T;
    while(T--) solve();
    
}