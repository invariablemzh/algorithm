#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 10, M = N * 2, mod = 998244353;
int h[N], e[M], ne[M], idx;
int d[N];
ll num[N][4]; // 0,2:肩膀+手， 1,3:肚子+腿
ll inv2;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

ll qmi(int a, int b, int p)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (ll)res * a % p;
        a = a * (ll)a % p;
        b >>= 1;
    }
    return res;
}

void solve()
{
    idx = 0;
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        d[i] = 0;
        h[i] = -1;
        for (int j = 0; j < 4; j++)
        {
            num[i][j] = 0;
        }
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
        d[a]++, d[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (d[i] >= 3)
        {
            num[i][1] = (ll)(d[i] - 1) * (d[i] - 2) % mod * inv2 % mod;
            num[i][0] = d[i] - 1;
        }
        else if (d[i] == 2)
        {
            num[i][0] = d[i] - 1;
        }
        // cout<<num[i][0]<<' '<<num[i][1]<<endl;
    }
    for (int t = 1; t <= n; t++)
    {
        if (d[t] >= 4)
        {
            for (int i = h[t]; ~i; i = ne[i])
            {
                int j = e[i];
                num[t][2] = (num[t][2] + num[j][0]) % mod;
                num[t][3] = (num[t][3] + num[j][1]) % mod;
                // cout<<j<<' '<<num[t][5]<<endl;
            }
            // cout<<t<<' '<<num[t][2]<<' '<<num[t][3]<<endl;
        }
    }
    ll ans = 0;
    for (int t = 1; t <= n; t++)
    {
        if (d[t] >= 4)
        {
            int nn = 0;
            for (int i = h[t]; ~i; i = ne[i])
            {
                int j = e[i];
                if (d[j] >= 3)
                {
                    ll a = num[t][2] - num[j][0];
                    if(a>=2) {
                        nn++;
                        ll tmp = (num[j][1] * ((a * (a - 1) % mod * inv2) % mod)) % mod;
                        ans = (ans + tmp) % mod;
                        // ans += num[j][1];
                        ans = (ans + num[j][1]) % mod;
                    }
                }
                // cout<<j<<' '<<ans<<endl;
            }
            ans = (ans - (nn * num[t][3] % mod) + mod) % mod;
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    inv2 = qmi(2, mod - 2, mod);
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
}