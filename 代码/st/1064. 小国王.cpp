#include <bits/stdc++.h>
using namespace std;
const int N = 12, M = 1 << 10, K = 120;

int n,m;
int f[N][K][M];
int cnt[M];
vector<int> state;
vector<int> head[M];

bool check(int state){
    for(int i = 0;i<n;i++){
        if((state>>i&1)&&(state>>i+1&1)){
            return false;
        }
    }
    return true;
}

int count(int state){
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(state>>i&1) cnt++;
    }
    return cnt;
}



int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i<1<<n;i++){
        if(check(i)){
            state.push_back(i);
            cnt[i] = count(i);
        }
    }
    for(int i = 0;i<state.size();i++){
        for(int j = 0;j<state.size();j++){
            int a = state[i], b = state[j];
            if((a&b)==0&&check(a|b)){
                head[i].push_back(j);
            }
        }
    }
    
    f[0][0][0] = 1;
    for(int i = 1;i<=n+1;i++){
        for(int j = 0;j<=m;j++){
            for(int a = 0;a<state.size();a++){
                for(int b : head[a]){
                    int c = cnt[state[a]];
                    if(j>=c) f[i][j][a] += f[i-1][j-c][b];
                }
            }
        }
    }
    printf("%d\n",f[n+1][m][0]);
}