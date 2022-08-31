#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
typedef pair<int,int> PII;

void solve(){
    int n; cin >> n;
    if(n%4==0){
        for(int i = 0;i<n;i++){
            cout << i << ' ';
        }
    }
    else if (n==5){
		cout<<"2 0 4 5 3";
	}
    else if(n%4==1){
        for (int i = 1; i < n-5; i++) {
            cout << i << ' ';
        }
		cout<<1073741824<<' '; 
		cout<<1610612736<<' '; 
    	cout<<536870912<<' '; 
		cout<<1048576<<' '; 
		cout<<524288<<' '; 
		cout<<1572864<<' ';
    }
    else if(n%4==2){
        for(int i = 1;i<n-2;i++) {
            cout << i << ' ';
        }
        cout<<1073741824<<' ';
        cout<<1610612736<<' ';
        cout<<536870912<<' ';
    }
    else if(n%4==3){
        for(int i = 1;i<=n;i++){
            cout << i << ' ';
        }
    }
    cout << '\n';
}

int main(){
    FAST
    int T; cin >> T;
    while(T--) solve();

}