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
typedef pair<int,int> PII;

int n, m;
PII match[N][N];
bool g[N][N], st[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

bool find(int x,int y){
    for(int i = 0;i<4;i++){
        int a = x + dx[i], b = y + dy[i];
        if(a>=1&&a<=n&&b>=1&&b<=n&&!st[a][b]&&!g[a][b]){
            st[a][b] = true;
            PII t = match[a][b];
            if(t.x==-1||find(t.x,t.y)){
                match[a][b] = {x,y};
                return true;
            }
        }
    }
    return false;
}

void solve(){
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        g[a][b] = true;
    }
    memset(match,-1,sizeof(match));
    int res = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if((i+j)%2&&!g[i][j]){
                memset(st,false,sizeof(st));
                if(find(i,j)) res ++;
            }
        }
    }
    cout << res << '\n';
}

int main(){
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve(); 
}