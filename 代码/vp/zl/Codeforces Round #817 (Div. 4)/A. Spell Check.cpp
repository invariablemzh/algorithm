#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

string s = "Timur";
bool st[10];

void solve(){
    memset(st,false,sizeof(st));
    int n; cin >> n;
    string str; cin >> str;
    if(n!=5){
        cout << "NO" << '\n';
        return;
    }
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            if(str[i]==s[j]) st[j] = true;
        }
    }
    bool flag = true;
    for(int i = 0;i<n;i++){
        if(!st[i]) flag = false;
    }
    if(flag) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main(){
    FAST
    int T; cin >> T;
    while(T--) solve();

}