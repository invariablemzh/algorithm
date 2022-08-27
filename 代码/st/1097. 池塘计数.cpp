#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = N * N;
typedef pair<int,int> PII;
#define x first
#define y second

int n,m;
char mp[N][N];
bool st[N][N];
PII q[M];

void bfs(int x,int y){
    q[0] = {x,y};
    st[x][y] = true;
    int hh = 0, tt = 0;
    while(hh<=tt){
        PII t = q[hh++];
        for(int i = t.x-1;i<=t.x+1;i++){
            for(int j = t.y-1;j<=t.y+1;j++){
                if(i==x&&j==y) continue;
                if(i<0||i>=n||j<0||j>=m) continue;
                if(st[i][j]||mp[i][j]=='.') continue;
                st[i][j] = true;
                q[++tt] = {i,j};
            }
        } 
    }
}

int main(){
    scanf("%d%d",&n,&m);
    getchar();
    for(int i = 0;i<n;i++) scanf("%s",mp[i]);
    int cnt = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(mp[i][j]=='W'&&!st[i][j]){
                bfs(i,j);
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
}