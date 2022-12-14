#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
typedef long long ll;

int n,s;
ll t[N],c[N],f[N];
int q[N];

int main(){
    scanf("%d%d",&n,&s);
    for(int i = 1;i<=n;i++){
        scanf("%lld%lld",&t[i],&c[i]);
        t[i] += t[i-1];
        c[i] += c[i-1];
    }
    
    int hh = 0, tt = 0;
    q[0] = 0;
    for(int i = 1;i<=n;i++){
        int l = hh, r = tt;
        while(l<r){
            int mid = l + r >> 1;
            if(f[q[mid+1]] - f[q[mid]] > (t[i] + s) * (c[q[mid+1]] - c[q[mid]])) r = mid;
            else l = mid + 1;
        }
        int j = q[r];
        f[i] = f[j] - (t[i] + s) * c[j] + t[i] * c[i] + s * c[n];
        while(hh<tt&&(double)(f[q[tt]] - f[q[tt - 1]]) * (c[i] - c[q[tt - 1]]) >= (double)(f[i] - f[q[tt-1]]) * (c[q[tt]] - c[q[tt - 1]])) tt--;
        q[++tt] = i;
    }
    printf("%lld\n",f[n]);
}