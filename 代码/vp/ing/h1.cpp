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

const int maxn = 1e7 + 3;
const ll mod = 998244353;
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
ll phi[maxn], prime[maxn], rongchi[maxn][2], n, m, opt, k;
int cnt = 0;
bool is_prime[maxn];
vector<ll> pri;
void pre()
{
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[1] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            prime[++cnt] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++)
        {
            is_prime[i * prime[j]] = 0;
            if (i % prime[j])
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            else
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
        }
    }
}
void get_prime(ll x)
{
    pri.clear();
    for (ll i = 1; i * i <= x && i <= cnt; i++)
    {
        if (x % prime[i] == 0)
        {
            pri.emplace_back(prime[i]);
            while (x % prime[i] == 0)
            {
                x /= prime[i];
            }
        }
    }
    if (x != 1)
    {
        pri.emplace_back(x);
    }
}
ll calc(ll x)
{
    ll sz = pri.size();
    ll res = 0;
    for (int i = 1; i < 1 << sz; i++)
    {
        ll t = 1, s = 0;
        ll len = log2(i);
        // cout << len << Endl;
        t = rongchi[i - (1 << (len))][0] * pri[len];
        s = rongchi[i - (1 << (len))][1] + 1;
        if (t > n)
        {
            t = -1;
        }
        else
        {
            rongchi[i][0] = t;
            rongchi[i][1] = s;
        }
        if (t != -1)
        {
            if (s % 2)
                res = (res + n / t - x / t + mod) % mod;
            else
                res = (res - n / t + x / t + mod) % mod;
        }
        // cout << i << " " << t << " " << res << Endl;
    }
    return res;
}
void solve()
{
    cin >> n >> m;
    pre();
    ll u, v, ans, tmp;
    rongchi[0][0] = 1;
    rongchi[0][1] = 0;
    while (m--)
    {
        ans = 0;
        cin >> u >> v;
        if (gcd(u, v) == 1)
        {
            cout << "1 1" << Endl;
            continue;
        }
        tmp = lcm(u, v);
        get_prime(tmp);
        if (tmp >= n)
        {
            // cout << calc() << Endl;
            ans = n - calc(0);
        }
        else
        {
            ans = phi[tmp];
            ans += n - tmp - calc(tmp);
        }
        cout << "2 " << ans << Endl;
    }
}
int main()
{
    // FAST
    ll t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}