#include <bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 30;
int n,m;
int d[N][N];
bool st[N];

void floyd(){
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                d[i][j] |= d[i][k] && d[k][j];
            }
        }
    }
}

int get_type(){
    for(int i = 0;i<n;i++){
        if(d[i][i]) return 2;
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(!d[i][j]&&!d[j][i]){
                return 0;
            }
        }
    }
    return 1;
}

char get_min(){
    for(int i = 0;i<n;i++){
        if(!st[i]){
            bool flag = true;
            for(int j = 0;j<n;j++){
                if(!st[j]&&d[j][i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                st[i] = true;
                return 'A' + i;
            }
        }
    }
}

int main(){
    while(cin >> n >> m, n||m){
        memset(d,0,sizeof(d));
        string str;
        int t = 0, type = 0;
        for(int i = 1;i<=m;i++){
            cin >> str;
            int a = str[0] - 'A', b = str[2] - 'A';
            if(!type){
                d[a][b] = 1;
                floyd();
                type = get_type();
                if(type) t = i;
            }
        }
        if(type==2) cout << "Inconsistency found after " << t << " relations." << endl;
        else if(!type) cout << "Sorted sequence cannot be determined."<<endl;
        else{
            memset(st,false,sizeof(st));
            cout << "Sorted sequence determined after "<< t <<" relations: ";
            for(int i = 0;i<n;i++) cout << get_min();
            cout << "." << endl;
        }
    }
}