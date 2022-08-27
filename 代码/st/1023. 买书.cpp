#include <bits/stdc++.h>
using namespace std;
const int N = 1010;

int n;
int f[N];
int s[4] = {10,20,50,100};

int main(){
    scanf("%d",&n);
    f[0] = 1;
    for(int i = 0;i<4;i++){
        for(int j = s[i];j<=n;j++){
            f[j] += f[j-s[i]];
        }
    }
    printf("%d\n",f[n]);
}
