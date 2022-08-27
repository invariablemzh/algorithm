#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10, M = N * 2;
const ll mod = 998244353;

int a[N],b[N],s[M];
// int mp1[N],mp2[N],mp3[M];
ll f[N][N];
// vector<int> v1[N];
// vector<int> v2[N];


void solve(){
    // memset(f,0,sizeof(f));
    int n; scanf("%d",&n);
    for(int i = 1;i<=n;i++) {
        scanf("%d",&a[i]);
        // mp1[a[i]] = i;
    }
    for(int i = 1;i<=n;i++) {
        scanf("%d",&b[i]);
        // mp2[b[i]] = i;
    }
    for(int i = 1;i<=n*2;i++) {
        scanf("%d",&s[i]);
        // mp3[s[i]] = i;
    }
    // for(int i = 1;i<=n*2;i++){
    //     if(mp1[s[i]]) {
    //         v1[mp1[s[i]]].push_back(i);
    //         // cout<<mp1[s[i]]<<' '<<i<<endl;
    //     }
    //     // if(mp2[s[i]]) {
    //     //     v2[mp2[s[i]]].push_back(i);
    //     //     // cout<<mp2[s[i]]<<' '<<i<<endl;
    //     // }
    // }
    // for(int i = 1;i<=n;i++){
    //     if(mp3[s[i]]){
    //         v2[mp3[s[i]]].push_back(i);
    //     }
    // }
    
    f[0][0] = 1;
    for(int i = 1;i<=2*n;i++){
        for(int j = 0;j<=n;j++){
            if(a[j]==s[i]&&j) f[i][j] += f[i-1][j-1];
            if(b[i-j]==s[i]&&i-j) f[i][j] += f[i-1][j];
        }
    }
    printf("%d\n",f[2*n][n]);
}

int main(){
    int T; scanf("%d",&T);
    while(T--) solve();
}