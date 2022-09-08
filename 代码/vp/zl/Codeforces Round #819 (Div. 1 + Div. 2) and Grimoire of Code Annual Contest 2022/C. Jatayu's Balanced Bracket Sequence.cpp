#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 1e5 + 10;
char s[N];
int p[N],cnt[N];
int sl[N],sr[N];
int q[N];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}



void solve(){
    int n; cin >> n;
    for (int i = 1; i <= n; i ++ ){
        p[i] = i;
        cnt[i] = 1;
        q[i] = 0;
    }
    cin >> s + 1;
    int l = 0, r = 0;
     for(int i = 1;i<=2*n;i++){
        if(s[i]=='('){
            stk.push(i);
            q[++l] = i;
        }
        else{
            int rr = i - l;
            int a = stk.top(); stk.pop();
            q[++t] = 
            int b = i;
            a = find(a), b = find(b);
            if (a != b){
                p[a] = b;
                cnt[b] += cnt[a];
            }
        }
    }
    int res = 0;
    for(int i = 1;i<=n;i++){
        if(p[i]==i) res ++;
    }
    cout << res << '\n';
}

int main(){
    FAST
    int T = 1;
    cin >> T;
    while(T--) solve();
}