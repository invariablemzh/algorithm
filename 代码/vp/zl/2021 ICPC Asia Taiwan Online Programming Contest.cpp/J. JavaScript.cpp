#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

void solve(){
    string a,b;
    cin >> a >> b;
    bool flag = true;
    for(int i = 0;i<a.length();i++){
        if(a[i]<='9'&&a[i]>='0');
        else flag = false;
    }
    for(int i = 0;i<b.length();i++){
        if(b[i]<='9'&&b[i]>='0');
        else flag = false;
    }
    if(!flag){
        cout << "NaN" << '\n';
    }
    else{
        int x = 0, y = 0;
        for(int i = 0;i<a.length();i++){
            x *= 10;
            x += a[i] - '0';
        }
        for(int i = 0;i<b.length();i++){
            y *= 10;
            y += b[i] - '0';
        }
        cout << x - y << '\n';
    }
}

int main(){
    FAST
    int T = 1;
    // cin >> T;
    while(T--) solve();
    
}