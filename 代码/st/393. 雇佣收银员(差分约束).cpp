#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0); 

typedef long long ll;
const int N = 30, M = 100;
int n,m1,m2;
int h[N],e[M],ne[M],w[M],idx;
int dist[N],cnt[N];
bool st[N];
int r[N],num[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void build(int c){
    memset(h,-1,sizeof(h));
    idx = 0;
    add(0,24,c), add(24,0,-c);
    for(int i = 1;i<=24;i++) {
        add(i,i-1,-num[i]);
        add(i-1,i,0);
    }
    for(int i = 1;i<=7;i++) add(i+16,i,r[i]-c);
    for(int i = 8;i<=24;i++) add(i-8,i,r[i]);
}

bool spfa(int c){
    build(c);
  	memset(dist, -0x3f, sizeof dist);
    memset(cnt, 0, sizeof cnt);
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
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= 25) return false;
                if (!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return true;
}

void solve(){
    for(int i = 1;i<=24;i++) cin >> r[i];
    cin >> n;
    memset(num,0,sizeof(num));
    for(int i = 1;i<=n;i++){
        int t; cin >> t;
        num[t+1] ++;
    }
    bool success = false;
    for(int i = 0;i<=1000;i++){
        if(spfa(i)){
            cout << i << '\n';
            success = true;
            break;
        }
    }
    if(!success) cout << "No Solution" << '\n';
}

int main(){
    FAST
    int T = 1;
    cin >> T;
    while(T--) solve();
}