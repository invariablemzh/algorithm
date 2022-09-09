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
const int N = 110;
int cnt[N];

void solve(){
    int n; cin >> n;
    int t = 0, p = 0;
    for(int i = 1;i<=n;i++) {
        cin >> cnt[i];
        if(t<cnt[i]){
            t = cnt[i];
            p = i;
        }
    }
    cout << p << '\n';
    
}

int main(){
    FAST
    int T = 1;
    cin >> T;
    while(T--) solve();
}