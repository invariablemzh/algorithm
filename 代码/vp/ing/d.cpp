// Problem: Average Replacement
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/contest/problem?cid=1053&pid=1004
// Memory Limit: 524288 MB
// Time Limit: 6000 ms

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
#define pll pair<ll, ll>
#define ls first
#define rs second
#define Endl '\n'
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int maxn = 1e6 + 3;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double inf = 1e20;

using namespace std;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

template <class T> void Memset(T &v, ll n)
{
    for (int i = 0; i <= n; i++)
        v[i] = 0;
}
ll ksm(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
ll n, m, opt, k;
double a[maxn];
ll pre[maxn], cnt[maxn], sum[maxn];
void init()
{
    for (int i = 1; i < maxn; i++)
    {
        pre[i] = i;
    }
}
ll find(ll a)
{
    if (pre[a] != a)
    {
        return pre[a] = find(pre[a]);
    }
    return a;
}
void join(ll a, ll b)
{
    ll fa = find(a), fb = find(b);
    if (fa != fb)
    {
        pre[fa] = fb;
        cnt[fb] += cnt[fa];
        sum[fb] += sum[fa];
    }
}
void solve()
{
    scanf("%lld%lld",&n,&m);
	init();
	for(int i=1;i<=n;i++)
	{
        scanf("%lf",&a[i]);
        sum[i] = a[i];
        cnt[i] = 1;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
        scanf("%d%d",&u,&v);
		join(u,v);
	}
    for(int i = 1;i<=n;i++){
        int t = find(i);
        printf("%.6lf\n",sum[t] / (double)cnt[t]);
    }
}
int main()
{
    ll t = 1; scanf("%lld",&t);
    while (t--)
    {
        solve();
    }
    return 0;
}