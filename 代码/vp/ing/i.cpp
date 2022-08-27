#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
#define x first
#define y second
const int N = 100010, INF = 0x3f3f3f3f;

PII q[N],p[N];

bool cmp(PII a, PII b){
    return a.y < b.y;
}

void solve(){
    int cnt = 0;
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++) {
        scanf("%d%d",&q[i].x,&q[i].y);
    }
    sort(q+1,q+n+1,cmp);
    for(int i = 1;i<=n;i++){
        int x = q[i].x, y = q[i].y;
        // int kk = lower_bound(q,q+n,x)-q;
        int l = 0, r = cnt;
        while(l<r){
            int mid = l + r >> 1;
            if(q[mid].x>=x) r = mid;
            else l = mid + 1;
        }
        int kk = r;
        while (kk < cnt && (q[kk].y==k||q[kk].x<x)) kk ++ ;
        if (kk == cnt) {
            q[cnt].x = y;
            q[cnt++].y=1;
            q[cnt].x = INF;
        }
        else q[kk].y++;
    }
    printf("%d\n",cnt);
}

int main(){
    int T; scanf("%d",&T);
    while(T--) solve();
}