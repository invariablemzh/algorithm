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

int n;
int r1, c1, r2, c2, r3, c3, r, c;
int x,y;

void solve(){
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
    cin >> x >> y;
    if(r1==r2) r = r3;
    if(r2==r3) r = r1;
    if(r1==r3) r = r2;
    if(c1==c2) c = c3;
    if(c2==c3) c = c1;
    if(c1==c3) c = c2;
    if(r==2&&c==2&&min({r1,r2,r3})==1&&min({c1,c2,c3})==1){
        if(x==1||y==1) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    else if(r==n-1&&c==n-1&&max({r1,r2,r3})==n&&max({c1,c2,c3})==n){
        if(x==n||y==n) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    else if(r==2&&c==n-1&&min({r1,r2,r3})==1&&max({c1,c2,c3})==n){
        if(x==1||y==n) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    else if(r==n-1&&c==2&&max({r1,r2,r3})==n&&min({c1,c2,c3})==1){
        if(x==n||y==1) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    else if(r%2==x%2&&c%2==y%2){
        cout << "NO" << '\n';
    }
    else{
        cout << "YES" << '\n';
    }
}

int main(){
    FAST 
    int T = 1; 
    cin >> T;
    while(T--) solve(); 
}