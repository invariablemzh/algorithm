#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0); 

typedef long long ll;
const int N = 1e5 + 10, M = 3e5 + 10;
int n,m1,m2;
int h[N],e[M],ne[M],w[M],idx;
int dist[N],cnt[N];
bool st[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa(int sz){
  	memset(dist, 0x3f, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);
    stack<int> q;
    for (int i = 1; i <= sz; i ++ ){
        st[i] = true;
        dist[i] = 0;
        q.push(i);
    }
    while (q.size()){
        int t = q.top();
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
    memset(h,-1,sizeof(h));
    cin >> n >> m1 >> m2;
    while(m1--){
        int a,b,l;
        cin >> a >> b >> l;
        if(a>b) swap(a,b);
        add(a,b,l);
    }
    while(m2--){
        int a,b,d;
        cin >> a >> b >> d;
        if(a>b) swap(a,b);
        add(b,a,-d);
    }
    for(int i = 1;i<n;i++) add(i+1,i,0);
    if(spfa(n)) cout << "-1" << '\n';
    else{
        spfa(1);
        if(dist[n]==0x3f3f3f3f) cout << "-2" << '\n';
        else cout << dist[n] << '\n';
    }
}

int main(){
    FAST
    int T = 1;
    // cin >> T;
    while(T--) solve();
}