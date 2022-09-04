#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 510, M = 5210;
int n, m1, m2;
int h[N], w[M], e[M], ne[M], idx;
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

bool spfa(){
  	memset(dist, 0, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);
    queue<int> q;
    for (int i = 1; i <= n; i ++ ){
        st[i] = true;
        q.push(i);
    }
    while (q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if (dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;
                if (!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

void solve(){
    memset(h, -1, sizeof h);
    idx = 0;
    cin >> n >> m1 >> m2;
    while(m1--){
        int a, b, c;
        cin >> a >> b >> c;
        add(a,b,c), add(b,a,c);
    }
    while(m2--){
        int a, b, c;
        cin >> a >> b >> c;
        add(a,b,-c);
    }
    if(spfa()) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main(){
    FAST
    int T = 1;
    cin >> T;
    while(T--) solve();
    
}