#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
#define x first 
#define y second
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

bool st[10][10];
int cnt[10],backup[10];
bool gd[10];

bool check(int x,int y,int z){
    memcpy(cnt,backup,sizeof(backup));
    if(x<=9) {
        cnt[0] --, cnt[x] --;
        if(st[0][0]) return false;
        if(st[1][x]) return false;
    }
    else{
        cnt[x/10] --;
        cnt[x%10] --;
        if(st[0][x/10]) return false;
        if(st[1][x%10]) return false;
    }
    if(y<=9) {
        cnt[0] --, cnt[y] --;
        if(st[3][0]) return false;
        if(st[4][y]) return false;
    }
    else {
        cnt[y/10] --;
        cnt[y%10] --;
        if(st[3][y/10]) return false;
        if(st[4][y%10]) return false;
    }
    if(z<=9) {
        cnt[0] --, cnt[z] --;
        if(st[6][0]) return false;
        if(st[7][z]) return false;
    }
    else{
        cnt[z/10] --;
        cnt[z%10] --;
        if(st[6][z/10]) return false;
        if(st[7][z%10]) return false;
    }
    for(int i = 0;i<10;i++){
        if(cnt[i]>0) return false;
        if(cnt[i]!=0&&gd[i]) return false;
    }
    return true;
}

void solve(){
    string s,p;
    cin >> s >> p;
    for(int i = 0;i<s.length();i++){
        if(i==2||i==5) continue;
        if(p[i]=='G'){
            if(i<2) {
                for(int j = 0;j<=9;j++){
                    if((s[i]-'0')!= j){
                        st[i][j] = true;
                    }
                }
            }
            else if(i>=3&&i<=4) {
                for(int j = 0;j<=9;j++){
                    if((s[i]-'0')!= j){
                        st[i][j] = true;
                    }
                }
            }
            else if(i>=6) {
                for(int j = 0;j<=9;j++){
                    if((s[i]-'0')!= j){
                        st[i][j] = true;
                    }
                }
            }
            cnt[s[i]-'0']++;
        }
        else if(p[i]=='P') {
            st[i][s[i]-'0'] = true;
            cnt[s[i]-'0'] ++;
        }
        else if(p[i]=='B') {
            st[i][s[i]-'0'] = true;
            gd[s[i]-'0'] = true;
        }
    }
    // for(int i = 0;i<10;i++){
    //     for(int j = 0;j<10;j++)
    //         cout << st[i][j] << ' ';
    //     cout << '\n';
    // }
    // cout << a << ' ' << b << ' ' << c << '\n';
    memcpy(backup,cnt,sizeof(cnt));
    int res = 0;
    for(int i = 0;i<=99;i++){
        for(int j = 0;j<=99;j++){
            int k = i + j;
            if(k>=100) continue;
            if(check(i,j,k)){
                res ++;
            }
        }
    }
    cout << res <<'\n';
    for(int i = 0;i<=99;i++){
        for(int j = 0;j<=99;j++){
            int k = i + j;
            if(k>=100) continue;
            if(check(i,j,k)){
                res ++;
                if(i<=9&&j<=9&&k<=9) cout << "0" << i << "+0" << j << "=0" << k <<'\n';
                else if(i<=9&&j<=9) cout << "0" << i << "+0" << j << "=" << k <<'\n';
                else if(i<=9) cout << "0" << i << "+" << j << "=" << k <<'\n';
                else if(j<=9) cout << i << "+0" << j << "=" << k <<'\n';
                else  cout << i << "+" << j << "=" << k <<'\n';
            }
        }
    }
    
}

int main(){
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve(); 
}