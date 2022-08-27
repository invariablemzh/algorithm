#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 100010;
typedef long long ll;
const double eps = 1e-8;
const int mod = 1e9+7;

int p;

int qmi(int a,int b,int p){
	int res = 1 % p;
	while(b){
		if(b&1) res = (ll)res * a % p;
		a = (ll) a * a % p;
		b>>=1;
	}
	return res;
}

int C(int a,int b){
	if(b>a) return 0;
	int res = 1;
	for(int i = 1, j = a;i<=b;i++,j--){
		res = (ll)res * j % p;
		res = (ll)res * qmi(i,p-2,p) % p;
	}
	return res;
}

int lucas(ll a,ll b){
	if(a<p&&b<p) return C(a,b);
	return (ll)C(a%p,b%p) * lucas(a/p,b/p) % p;
}


int main(){
	int n; scanf("%d",&n);
	while(n--){
		ll a, b;
		scanf("%lld%lld%d",&a,&b,&p);
		printf("%d\n",lucas(a,b));
	}
}