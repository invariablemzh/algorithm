#include <bits/stdc++.h>
using namespace std;
const int N = 30, M = 100;

int V1,V2,n;
int f[N][M];


int main(){
    memset(f,0x3f,sizeof(f));
    f[0][0] = 0;
    cin >> V1 >> V2 >> n;
    for(int i = 1;i<=n;i++){
        int v1,v2,w;
        cin >> v1 >> v2 >> w;
        for(int j = V1;j>=0;j--){
            for(int k = V2;k>=0;k--){
                f[j][k] = min(f[j][k],f[max(j-v1,0)][max(k-v2,0)] + w);
            }
        }
    }
    cout<<f[V1][V2]<<endl;
}