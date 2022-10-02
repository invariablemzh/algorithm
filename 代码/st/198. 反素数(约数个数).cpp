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

int n;
int maxd, number;
int primes[] = {2,3,5,7,11,13,17,19,23};

void dfs(int u,int last,int p,int s){
    if(s > maxd || s == maxd && p < number){
        maxd = s;
        number = p;
    }
    if(u==9) return;
    for(int i = 1;i<=last;i++){
        if((ll)primes[u] * p > n) break;
        p *= primes[u];
        dfs(u+1,i,p,s*(i+1));
    }
}

void solve(){
    cin >> n;
    dfs(0,30,1,1);
    cout << number << '\n';
}

int main(){
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve(); 
}