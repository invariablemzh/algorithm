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

int cnt[30];
int n,k;
string str;

void solve(){
   for(int i = 0;i<26;i++){
       cnt[i] = 0;
   }
    cin >> n >> k;
    int len = n / k;
    cin >> str;
    for(int i = 0;i<n;i++){
        int t = str[i]-'a';
        cnt[t] ++;
    }
    // for(int i = 0;i<26;i++) cout << cnt[i] << '\n';
    int pos = 0;
    for(int i = 0;i<26;i++){
        if(cnt[i]==0){
            pos = i - 1;    
            break;
        }     
    }  
    // cout << pos << '\n';
    
    while(k--){
        for(int i = 0;i<26;i++){
            if(cnt[i]==0){
                pos = i - 1;    
                break;
            }     
        }
        pos = min(pos,len-1);
        if(pos<0){
            cout << 'a';
            continue;
        }
        if(cnt[pos]>0){
            char s = 'a' + pos +  1;  
            cout << s;
            int tmp = pos;
            for(int i = pos;i>=0;i--) cnt[i] --;
        }
        
    }
    cout << '\n';
}

int main(){
    FAST 
    int T = 1; 
    cin >> T;
    while(T--) {
        solve(); 
        // cout << '\n';
    }
}