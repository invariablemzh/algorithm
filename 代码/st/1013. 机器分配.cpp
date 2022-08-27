#include <bits/stdc++.h>
using namespace std;
const int N = 20;

int n,m;
int f[N][N], w[N][N], way[N];

int main(){
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin >> w[i][j];
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=m;j++){
            for(int k = 0;k<=j;k++){
                f[i][j] = max(f[i][j], f[i-1][j-k] + w[i][k]);
            }
        }
    }
    cout << f[n][m] << endl;

    int j = m;
    for(int i = n;i>=1;i--){
        for(int k = 0;k<=j;k++){
            if(f[i][j] == f[i-1][j-k] + w[i][k]){
                way[i] = k;
                j -= k;
                break;
            }
        }
    }
    for(int i = 1;i<=n;i++)
        cout<<i<<' '<<way[i]<<endl;

}