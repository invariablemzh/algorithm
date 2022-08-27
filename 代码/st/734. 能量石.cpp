#include <bits/stdc++.h>
using namespace std;
const int N = 110, M = 10010;

int f[N][M];

struct Stones{
    int s,e,l;
    bool operator<(const Stones &W) const{
        return s * W.l < W.s * l;
    }
}stones[N];

void solve(){
    memset(f,-0x3f,sizeof(f));
    f[0][0] = 0;
    int n,m = 0;
    cin >> n;
    for(int i = 1;i<=n;i++){
        int s,e,l;
        cin >> s >> e >> l;
        stones[i] = {s,e,l};
        m += s;
    }
    sort(stones+1,stones+n+1);
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=m;j++){
            f[i][j] = f[i-1][j];
            if(j>=stones[i].s){
                int s = stones[i].s, e = stones[i].e, l = stones[i].l;
                f[i][j] = max(f[i][j],f[i-1][j-s] + max(0,e - l * (j-s)));
            }
        }
    }
    int res = 0;
    for(int i = 0;i<=m;i++) res = max(res,f[n][i]);
    cout << res << endl;
}

int main(){
    int T; cin >> T;
    for(int i = 1;i<=T;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }  
}