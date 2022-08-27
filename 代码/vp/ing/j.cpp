#include <bits/stdc++.h>
using namespace std;

void solve(){
    double a,b;
    scanf("%lf%lf",&a,&b);
    double y = a / b;
    // double x = 180.0 - 2 * y;
    double w = 2 * y;
    if(360.0/w==(int)360.0/w) printf("%.0lf\n",360.0 / w - 1);
    else puts("-1");
}

int main(){
    int T; scanf("%d",&T);
    while(T--) solve();
}