#include<bits/stdc++.h>
using namespace std;
const int N = 700, M = 100010;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

int n;
int h[N],e[M],ne[M],w[M],idx;
double dist[N];
int cnt[N];
bool st[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool check(double mid){
  	memset(dist, 0, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);
    queue<int> q;
    for (int i = 0; i < 676; i ++ ){
        st[i] = true;
        q.push(i);
    }
    int count = 0;
    while (q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if (dist[j] > dist[t] + mid - w[i]){
                dist[j] = dist[t] + mid - w[i];
                cnt[j] = cnt[t] + 1;
                if(++count>10000) return true;
                if (cnt[j] >= 676) return true;
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
    FAST
    while(cin >> n, n){
        memset(h,-1,sizeof(h));
        idx = 0;
        string s;
        for(int i = 1;i<=n;i++) {
            cin >> s;
            if(s.length()>=2){
                int t1 = (s[0] - 'a') * 26 + (s[1] - 'a');
                int t2 = (s[s.length()-2] - 'a') * 26 + s[s.length()-1] - 'a';
                add(t1,t2,s.length());
            }
        }
        if(!check(0)) {
            cout << "No solution" << '\n';
            continue;
        }
        double l = 0, r = 1000;
        while(r - l > 1e-4){
            double mid = (l + r) / 2;
            if(check(mid)) l =  mid;
            else r = mid;
        }
        cout << r << endl;
    }
}