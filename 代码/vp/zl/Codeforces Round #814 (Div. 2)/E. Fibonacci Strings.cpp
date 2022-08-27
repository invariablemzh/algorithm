#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 110;
typedef long long ll;
typedef pair<int,int> PII;
#define x first
#define y second
int n;
ll fib[N], sum[N];
int a[N];
set<PII,greater<PII>> s;

void solve(){
    s.clear();
    cin >> n;
    ll tmp = 0;
    for(int i = 1;i<=n;i++) {
        cin >> a[i];
        tmp += a[i];
        s.emplace(a[i],i);
    }
    int tt = lower_bound(sum,sum+51,tmp) - sum;
    if(sum[tt]!=tmp) {
        puts("NO");
        return;
    }
    int pos = -1;    
    while(tt>=0){
        if(s.empty()){
            puts("NO");
            return;
        }
        PII t;
        if(s.begin()->y != pos) {
            t = *s.begin();
            s.erase(s.begin());
        }
        else{
            if(s.size()==1){
                puts("NO");
                return;
            }
            else{
                t = *next(s.begin());
                s.erase(next(s.begin()));
            }
        }
        t.x -= fib[tt--];
        if(t.x<0){
            puts("NO");
            return;
        }
        if(t.x>0) s.insert(t);
        pos = t.y;
    }
    if(s.empty()) puts("YES");
    else puts("NO");
}

int main(){
    fib[0] = fib[1] = 1;
    sum[0] = 1, sum[1] = 2;
    for(int i = 2;i<=50;i++) {
        fib[i] = fib[i-1] + fib[i-2];
        sum[i] += sum[i-1] + fib[i];
    }
    int T; scanf("%d",&T);
    while(T--) solve();
}