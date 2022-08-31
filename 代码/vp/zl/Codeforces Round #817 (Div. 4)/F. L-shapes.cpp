#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
typedef pair<int,int> PII;

const int N = 60;
int n,m;
char s[N][N];
int id[N][N], idx;

int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,-1,0,1,-1,1,-1,1};

int bfs(int x,int y){
    queue<PII> q;
    q.push({x,y});
    int cnt = 0;
    id[x][y] = ++ idx;
    while(q.size()){
        PII t = q.front(); q.pop();
        cnt++;
        int x = t.first, y = t.second;
        for(int i = 0;i<4;i++){
            int a = x + dx[i], b = y + dy[i];
            if(a<1||a>n||b<1||b>m||s[a][b]=='.'||id[a][b]) continue;
            id[a][b] = idx;
            q.push({a,b});
        }
    }
    return cnt;
}

bool check(int x,int y){
    for(int i = 0;i<8;i++){
        int a = x + dx[i], b = y + dy[i];
        if(a<1||a>n||b<1||b>m||s[a][b]=='.') continue;
        if(id[a][b]!=id[x][y]) return false;
    }
    return true;
}

void solve(){
    memset(id,0,sizeof(id));
    cin >> n >> m;
    for(int i = 1;i<=n;i++) cin >> s[i] + 1;
    bool flag = true;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s[i][j]=='*'&&!id[i][j]&&bfs(i,j)!=3){
                flag = false;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s[i][j]=='.') continue;
            if(!check(i,j)) {
                // cout << i << ' ' << j << endl;
                flag = false;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s[i][j]=='.') continue;
            if(i+2<=n&&s[i+1][j]=='*'&&s[i+2][j]=='*') flag = false;
            if(j+2<=m&&s[i][j+1]=='*'&&s[i][j+2]=='*') flag = false;
        }
    }
    
    if(flag) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main(){
    FAST
    int T; cin >> T;
    while(T--) solve();

}