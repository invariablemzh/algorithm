// Problem: M. My University Is Better Than Yours
// Contest: Codeforces - 2022 Shanghai Collegiate Programming Contest
// URL: https://codeforces.com/gym/103931/problem/M
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ls first
#define rs second
#define Endl '\n'
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define eb emplace_back
// #define ll int

const int N = 5e5 + 3;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double inf = 1e20;
const ll INF = 1e18;

using namespace std;

int n, m;
int a[N], dp[N];
int vis[N];
vector<int> e[N], E[N];
int dfn[N], low[N], ins[N], bel[N], sz[N];
bool cmp(int x, int y)
{
    return bel[x] > bel[y];
}
struct Tarjan {
    int idx = 0, cnt = 0;
    stack<int> stk;
    vector<vector<int>> scc;
    void dfs(int u)
    {
        dfn[u] = low[u] = ++idx;
        ins[u] = 1;
        stk.push(u);
        for (auto v : e[u]) {
            if (!dfn[v]) {
                dfs(v);
            }
            if (ins[v]) {
                low[u] = min(low[u], low[v]);
            }
        }
        if (dfn[u] == low[u]) {
            vector<int> c;
            cnt++;
            while (1) {
                int v = stk.top();
                c.push_back(v);
                bel[v] = cnt;
                ins[v] = 0;
                sz[cnt]++;
                stk.pop();
                if (v == u) {
                    break;
                }
            }
            dp[cnt] = sz[cnt];
            scc.push_back(c);
        }
    }
    void work()
    {
        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) {
                dfs(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            sort(e[i].begin(), e[i].end(), cmp);
        }
        // for (int i = 1; i <= n; i++) {
        // cout << "#" << i << " ";
        // for (auto j : e[i]) {
        // cout << j << " ";
        // }
        // cout << Endl;
        // }
        // for (auto u : scc) {
        // for (auto v : u) {
        // cout << v << " ";
        // }
        // cout << Endl;
        // }
        for (int i = 1; i <= cnt; i++) {
            for (auto u : scc[i - 1]) {
                for (auto v : e[u]) {
                    if (vis[bel[v]] != bel[u] && bel[v] != bel[u]) {
                        E[i].pb(bel[v]);
                        for (auto j : E[bel[v]]) {
                            vis[j] = i;
                            E[i].pb(j);
                        }
                        // cout << u << " " << v << " " << bel[u] << " " << bel[v] << Endl;
                        vis[bel[v]] = bel[u];
                        dp[bel[u]] += dp[bel[v]];
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            assert(dp[bel[i]] - 1 < n);
            cout << dp[bel[i]] - 1 << " ";
        }
        cout << Endl;
    }
} tarjan;
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            a[x] = j;
        }
        for (int j = 1; j < n; j++) {
            e[a[j]].pb(a[j + 1]);
        }
    }
    // for (int i = 1; i <= n; i++) {
    // sort(e[i].begin(), e[i].end());
    // e[i].erase(unique(e[i].begin(), e[i].end()), e[i].end());
    // }

    tarjan.work();
}
int main()
{
    FAST;
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
