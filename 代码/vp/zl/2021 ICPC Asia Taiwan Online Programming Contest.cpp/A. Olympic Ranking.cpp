#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

void solve(){
    int n; cin >> n;
    int a = 0, b = 0, c = 0;
    string str;
    for(int i = 1;i<=n;i++){
        int x,y,z;
        string t;
        cin >> x >> y >> z;
        cin.get();
        getline(cin,t);
        if(i==1) str = t;
        if(x>a){
            a = x, b = y, c = z;
            str = t;
        }
        else if(x==a){
            if(y>b){
                a = x, b = y, c = z;
                str = t;
            }
            else if(y==b){
                if(z>c){
                    a = x, b = y, c = z;
                    str = t;
                }
            }
        }
    }
    cout << str << '\n';
}

int main(){
    FAST
    int T = 1;
    // cin >> T;
    while(T--) solve();
    
}