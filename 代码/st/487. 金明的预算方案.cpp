#include <bits/stdc++.h>
using namespace std;
const int N = 70, M = 32010;
typedef pair<int,int> PII;

int m,n;
int f[M];
PII master[N];
vector<PII> servant[N];


int main(){
    cin >> m >> n;
    for(int i = 1;i<=n;i++){
        int v,p,q;
        cin >> v >> p >> q;
        p *= v;
        if(!q) master[i] = {v,p};
        else servant[q].push_back({v,p});
    }
    for(int i = 1;i<=n;i++){
        // if(master[i].first)
        for(int j = m;j>=0;j--){
            for(int u = 0;u<1<<servant[i].size();u++){
                int v = master[i].first, w = master[i].second;
                for(int k = 0;k<servant[i].size();k++){
                    if(u>>k&1){
                        v += servant[i][k].first;
                        w += servant[i][k].second;
                    }
                }
                if(j>=v) f[j] = max(f[j],f[j-v]+w);
            }
        }
    }
    cout<<f[m]<<endl;
}