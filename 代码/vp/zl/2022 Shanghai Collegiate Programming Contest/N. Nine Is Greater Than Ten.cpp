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

void solve(){
    string a,b;
    cin >> a >> b;
    if(a>b){
        cout << a << ">" << b << '\n';
    }
    else if(a==b){
        cout << a << "=" << b << '\n';
    }
    else if(a<b){
        cout << a << "<" << b << '\n';
    }
}

int main(){
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve(); 
}