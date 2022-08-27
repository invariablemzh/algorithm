#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

string str[N];
bool st[N];

int main(){
    int n; scanf("%d",&n);
    for(int i = 0;i<n;i++){
        cin >> str[i];
        st[str[i][0]-'A'] = true;
    }
    bool res = false;
    for(int i = 0;i<n;i++){
        bool flag = true;
        for(int j = 0;j<str[i].length();j++){
            if(!st[str[i]-'A']) {
                flag = false;
                break;
            }
        }
        if(flag) res = true;
    }
    if(res) puts("Y");
    else puts("N");
}