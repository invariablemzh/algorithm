#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
typedef long long ll;

const int N = 2e5 + 10;
char s[N];
int a[N];
bool st[N];

void solve(){
    memset(st,false,sizeof(st));
    int n; cin >> n;
    cin >> s + 1;
    ll res = 0;
    for(int i = 1;i<=n;i++){
        if(s[i]=='R') {
            a[i] = n - i;
            res += a[i];
        }
        else {
            a[i] = i - 1;
            res += a[i];
        }
    }

    int k = 0;
    int l = 1, r = n;
    while(l<=r){
        if(l<=n-r+1){
            if(!st[l]&&s[l]=='L'){
                k++;
                res += n-l-a[l];
                cout << res << ' ';
            }
            st[l] = true;
            l++;
        }
        else{
            if(!st[r]&&s[r]=='R'){
                k++;
                res += r-1-a[r];
                cout << res << ' ';
            }
            st[r] = true;
            r--;
        }
    }
    for(int i = k+1;i<=n;i++){
        cout << res << ' ';
    }
    cout << '\n';
}

int main(){
    FAST
    int T; cin >> T;
    while(T--) solve();

}