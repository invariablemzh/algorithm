#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

typedef pair<int,int> PII;
#define x first
#define y second
const int N = 510;
int n, k, r, c;
char s[N][N];
bool st[N][N];

void solve(){
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    int t = (r + c) % k;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            s[i][j] = '.';
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if((i+j)%k==t) s[i][j] = 'X';
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cout << s[i][j];
        }
        cout << '\n';
    }
}

int main(){
    FAST
    int T = 1;
    cin >> T;
    while(T--) solve();
    
}