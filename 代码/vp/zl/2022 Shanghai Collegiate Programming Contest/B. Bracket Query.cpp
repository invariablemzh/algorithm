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

const int N = 6010;
string str;
int a[N],b[N];  //a左括号,b右括号

void solve(){
    int n,q;
    cin >> n >> q;
    for(int i = 0;i<n;i++) str[i] = '(';
    for(int i = n;i<2*n;i++) str[i] = ')';
    for(int i = 0;i<n;i++) b[i] = n;
    for(int i = n;i<2*n-1;i++) b[i] = i + 1;
    for(int i = 1;i<n;i++) a[i] = i - 1; 
    for(int i = n;i<2*n;i++) a[i] = n - 1;
    bool flag = true;
    while(q--){
        int l,r,c;
        cin >> l >> r >> c;
        int d = r - l + 1;  
        if(d - c >= 0 && (d - c) % 2 == 0 && (d + c) % 2 == 0){
            int x = (d + c) / 2;
            int y = (d - c) / 2;
            if(x > y){
                
            }
        }
        else{
            flag = false;
            break;
        }
    }
    if(!flag) cout << "?" << '\n';
    else cout << "!" << str << '\n';
}

int main(){
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve(); 
}