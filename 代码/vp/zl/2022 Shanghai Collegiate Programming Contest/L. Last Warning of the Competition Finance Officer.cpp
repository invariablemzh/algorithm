#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<ll,ll> PII;
#define x first 
#define y second
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 2e5 + 10;
const ll mod = 998244353;

ll b[N], ne[N];
vector<PII> a[N];
void kmp(string p,string s,int score){
    for (int i = 2, j = 0; i < p.length(); i ++ ){
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j ++ ;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i < s.length(); i ++ ){
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++ ;
        if (j == p.length() - 1){
            // cout << i << '\n';
            b[i] = (b[i] + score) % mod;
            a[i].push_back({i-p.length()+2,score});
            // cout << i-p.length()+2 << '\n';
            j = ne[j];
        }
    }
}

void solve(){
    string str; cin >> str;
    str = " " + str;
    // cout << str<< '\n';
    // cout << str.length();
    int n; cin >> n;
    for(int i = 1;i<=n;i++){
        string s; cin >> s;
        s = " " + s;
        int score; cin >> score;
        kmp(s,str,score);
    }
    // for(int i = 1;i<str.length();i++){
    //     cout << b[i] << '\n';
    // }
    ll res = 1;
    for(int i = 1;i<str.length();i++){
        res = (res + b[i]) % mod;
        for(auto t : a[i]){
            // cout << t << '\n';
            res = (res + (b[t.first-1] % mod * t.second % mod) % mod) % mod;
        }
        cout << (res + mod) % mod << ' ';
    }
    cout << '\n';
}

int main(){
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve(); 
}