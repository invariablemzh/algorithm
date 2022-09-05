#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0); 

typedef pair<int,int> PII;
typedef long long ll;
const int N = 50010, M = 3 * N + 10;
int n;
int h[N],e[M],ne[M],w[M],idx;
int dist[N];
bool st[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa(){
  	memset(dist, -0x3f, sizeof dist);
    // memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);
    stack<int> q;
    st[0] = true;
    dist[0] = 0;
    q.push(0);
    while (q.size()){
        int t = q.top();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if (dist[j] < dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                // cnt[j] = cnt[t] + 1;
                // if (cnt[j] >= n + 1) return true;
                if (!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}

void solve(){
    memset(h,-1,sizeof(h));
    cin >> n;
    for(int i = 1;i<N;i++){
        add(i-1,i,0);
        add(i,i-1,-1);
    }
    for(int i = 1;i<=n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a ++, b ++;
        add(a - 1,b,c);
    }
    spfa();
    cout << dist[50001] << '\n';
}

int main(){
    FAST
    int T = 1;
    // cin >> T;
    while(T--) solve();
}