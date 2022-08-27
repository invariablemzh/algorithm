#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
#define x first
#define y second

int a[N], b[N];
vector<int> vec[N];
int q[N];
int l[N],r[N];
queue<int> ql, qr;  //id

vector<int> get_divisors(int x){
    vector<int> res;
    for (int i = 1; i <= x / i; i ++ )
        if (x % i == 0){
            res.push_back(i);
            if (i != x / i) res.push_back(x / i);
        }
    sort(res.begin(), res.end());
    return res;
}


void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++) {
        l[i] = r[i] = i;
        scanf("%d",&a[i]);
        vec[i] = get_divisors(a[i]);
    }
    for(int i = 1;i<=n-1;i++) scanf("%d",&b[i]);
    int hh = 1, tt = 0;
    for(int i = 1;i<=n;i++){
        bool flag = false;
        for(int j = tt;j>=hh;j--){
            for(auto t : vec[j]){
                if(t==b[i-1]){
                    flag = true;
                    r[j] = i;
                    break;
                }
            }
        }
        if(!flag) hh = tt-1;
        q[++tt] = i;
    }
    for(int i = 1;i<=n;i++){
        printf("%d ",r[i]);
    }
    puts("");
    
    for(int i = n;i>=1;i--){
        qr.push(i);
        while(qr.size()){
            int t = qr.front();
            if(r[i]>=t) {
                r[i] = max(r[i],r[t]);
                break;
            }
            else qr.pop();
            
        }
    }
    for(int i = 1;i<=n;i++){
        printf("%d ",r[i]);
    }
    puts("");
    

    hh = 1, tt = 0;
    for(int i = n;i>=1;i--){
        q[++tt] = i;
        bool flag = false;
        for(int j = tt;j>=hh;j--){
            for(auto t : vec[n-j+1]){
                if(t==b[i]){
                    flag = true;
                    l[n-j+1] = i;
                    break;
                }
            }
        }
        if(!flag) hh = tt-1;
    }

    for(int i = 1;i<=n;i++){
        printf("%d ",l[i]);
    }
    puts("");

    for(int i = 1;i<=n;i++){
        ql.push(i);
        while(ql.size()){
            int t = ql.front();
            if(l[i]<=t) {
                l[i] = min(l[i],l[t]);
                break;
            }
            else ql.pop();
        }
    }
    // for(int i = 1;i<=n;i++){
    //     printf("%d ",l[i]);
    // }
    // puts("");

    for(int i = 1;i<=n;i++){
        cout << l[i] <<' '<< r[i] << endl;
    }

    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(r[x]>=y||x<=l[y]) puts("YES");
        else puts("NO");
    }

    while(ql.size()) ql.pop();
    while(qr.size()) qr.pop();

} 

int main(){
    int T; scanf("%d",&T);
    while(T--) solve();
}