#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

map<string,int> mp1;
map<string,int> mp2;
map<string,int> mp3;

void solve(){
    mp1.clear();
    mp2.clear();
    mp3.clear();
    int n; cin >> n;
    string str;
    for(int i = 1;i<=n;i++){
        cin >> str;
        mp1[str] = 1;
    }
    for(int i = 1;i<=n;i++){
        cin >> str;
        mp2[str] = 2;
    }
     for(int i = 1;i<=n;i++){
        cin >> str;
        mp3[str] = 3;
    }

    int p1 = 0, p2 = 0, p3 = 0;
    for(auto t : mp1){
        string str = t.first;
        if(!mp2.count(str)&&!mp3.count(str)) p1 += 3;
        else if(!mp2.count(str)||!mp3.count(str)) p1 += 1; 
    }
    for(auto t : mp2){
        string str = t.first;
        if(!mp1.count(str)&&!mp3.count(str)) p2 += 3;
        else if(!mp1.count(str)||!mp3.count(str)) p2 += 1; 
    }
    for(auto t : mp3){
        string str = t.first;
        if(!mp2.count(str)&&!mp1.count(str)) p3 += 3;
        else if(!mp2.count(str)||!mp1.count(str)) p3 += 1; 
    }
    cout << p1 << ' ' << p2 << ' ' << p3 << '\n';
}

int main(){
    FAST
    int T; cin >> T;
    while(T--) solve();
}