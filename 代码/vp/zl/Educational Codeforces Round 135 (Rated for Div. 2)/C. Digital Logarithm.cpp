#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#define x first 
#define y second
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

int n;
map<int,int> mp1;
map<int,int> mp2;

void solve(){
    mp1.clear(), mp2.clear();
    cin >> n;
    for(int i = 1;i<=n;i++){
        int x; cin >> x;
        mp1[x]++;
    }

    int res = 0;
    for(int i = 1;i<=n;i++){
        int x; cin >> x;
        if(mp1[x]) {
            mp1[x]--;
        }
        else{
            if(x<10) {
                mp2[x]++;
            }
            else{
                x = log10(x) + 1;
                mp2[x]++;
                res++;
                while(mp2[x]&&mp1[x]){
                    mp2[x]--;
                    mp1[x]--;
                }
                
            }
        }
    }
    // cout << res << endl;
    for(auto t : mp1){
        if(!t.y) continue;
        // cout << t.x << ' ' << t.y << ' ';
        int x = t.x, y = t.y;
        if(x>=10){
            mp1[x]-=y;
            x = log10(x) + 1;
            mp1[x]+=y;
            res+=y;
            while(mp2[x]&&mp1[x]){
               mp2[x]--;
               mp1[x]--;
            }
        }
        // cout << res << '\n';
    }

    for(auto t : mp1){
        if(t.x==1||!t.y) continue;
        // cout << t.x << ' ' << t.y << '\n';
        res += t.y;
    }

    for(auto t : mp2){
        if(t.x==1||!t.y) continue;
        // cout << t.x << ' ' << t.y << '\n';
        res += t.y;
        // cout << t.x << ' ' << t.y << ' '<<res<<'\n';
    }
    cout << res << '\n';
}

int main(){
    FAST
    int T = 1;
    cin >> T;
    while(T--) solve();
    
}