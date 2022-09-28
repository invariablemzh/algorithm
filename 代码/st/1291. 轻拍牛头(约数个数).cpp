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
const int N = 1000010;
int a[N],s[N],cnt[N];

void solve(){
    int n; cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
        cnt[a[i]] ++;
    }
    for(int i = 1;i<N;i++){
        for(int j = i;j<N;j+=i){
            s[j] += cnt[i];
        }
    }
    for(int i = 1;i<=n;i++){
        cout << s[a[i]] - 1 << '\n';
    }
}

int main(){
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve(); 
}