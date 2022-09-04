#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 1010, M = 5010;
int n,m;
int wf[N], cnt[N];
int h[N], e[M], ne[M], w[M], idx;
double dist[N];
bool st[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool check(double mid){
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
            if (dist[j] > dist[t] + w[i] * mid - wf[t]){
                dist[j] = dist[t] + w[i] * mid - wf[t];
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



int main(){
    memset(h,-1,sizeof(h));
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++) scanf("%d",&wf[i]);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    double l = 0, r = 1000;
    while(r-l>1e-4){
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    printf("%.2lf\n",l);
}