#include <bits/stdc++.h>
using namespace std;
const int M = 30010;

int n,m;
int f[M];

int main(){
    cin >> m >> n;
    for(int i = 1;i<=n;i++){
        int v,w;
        cin >> v >> w;
        for(int j = m;j>=v;j--){
            f[j] = max(f[j],f[j-v] + v * w);
        }
    }
    cout << f[m] << endl;
}