#include <bits/stdc++.h>
using namespace std;
const int N = 110, M = 1 << 10;

int n,m;
int f[2][M][M];
int g[N],cnt[N];
vector<int> state;

bool check(int state){
    for(int i = 0;i<m;i++){
        if((state>>i&1)&&((state>>i+1&1)||(state>>i+2&1)))
            return false;
    }
    return true;
}

int count(int state){
    int res = 0;
    for(int i = 0;i<m;i++){
        if(state>>i&1) res++;
    }
    return res;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<m;j++){
            char c; cin>>c;
            g[i] += (c=='H') << j;
        }
    }
    for(int i = 0;i<1<<m;i++){
        if(check(i)){
            state.push_back(i);
            cnt[i] = count(i);
        }
    }
    for(int i = 1;i<=n+2;i++){
        for(int j = 0;j<state.size();j++){
            for(int k = 0;k<state.size();k++){
                for(int u = 0;u<state.size();u++){
                    int a = state[j], b = state[k], c = state[u];
                    if(a&b||b&c||a&c) continue;
                    if(g[i]&b||g[i-1]&a||g[i-2]&c) continue;
                    f[i&1][j][k] = max(f[i&1][j][k],f[i-1&1][u][j] + cnt[b]);
                }
            }
        }
    }
    printf("%d\n",f[n+2&1][0][0]);
}