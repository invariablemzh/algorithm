#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
typedef long long ll;

const int N = 1010;
ll s[N][N];

void solve(){
    memset(s,0,sizeof(s));
    int n,q;
    cin >> n >> q;
    for(int i = 1;i<=n;i++){
        int x,y; 
        cin >> x >> y;
        s[x][y] += x * y;
    }
    for (int i = 1; i <= 1000; i ++ )
        for (int j = 1; j <= 1000; j ++ )
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    while(q--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x2 --, y2 --, x1 ++, y1 ++;
        cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] << '\n';
    }
}

int main(){
    FAST
    int T; cin >> T;
    while(T--) solve();

}