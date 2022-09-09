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

void solve(){
    int n; cin >> n;
    if(n%2==0){
        for(int i = n-2;i>=2;i--){
            cout << i << ' ';
        }
        cout << 1 << ' ';
        cout << n - 1 << ' ' << n << '\n';
    }
    else{
        cout << n - 1 << ' ';
        for(int i = n - 3;i>=2;i--){
            cout << i << ' ';
        }
        cout << 1 << ' ';
        cout << n - 2 << ' ' << n << '\n';
    }
    
}

int main(){
    FAST
    int T = 1;
    cin >> T;
    while(T--) solve();
    
}