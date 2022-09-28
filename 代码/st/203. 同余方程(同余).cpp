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

int exgcd(int a, int b, int &x, int &y){
    if (!b){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

void solve(){
    int a,b;
    cin >> a >> b;
    int x,y;
    int d = exgcd(a,b,x,y);
    cout << (x%b+b)%b << '\n';
}

int main(){
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve(); 
}