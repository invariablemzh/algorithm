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

const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], ne[M], w[M], idx;
int color[N];

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

bool dfs(int u, int c, int mid){
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i]){
        if(mid >= w[i]) continue;
        int j = e[i];
        if (!color[j]){
            if (!dfs(j, 3 - c, mid)) return false;
        }
        else if (color[j] == c) return false;
    }
    return true;
}

bool check(int mid){
    memset(color,0,sizeof(color));
    for(int i = 1;i<=n;i++){
        if(!color[i]){
            if(!dfs(i,1,mid)) return false;
        }
    }
    return true;
}

void solve(){
    memset(h,-1,sizeof(h));
    cin >> n >> m;
    while(m--){
        int a,b,w;
        cin >> a >> b >> w;
        add(a,b,w), add(b,a,w);
    }
    int l = 0, r = 1e9;
    while(l<r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}

int main(){
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve(); 
}