/*
法一：用最小生成树做
*/

#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 110, M = 410, INF = 0x3f3f3f3f;

int n, m;
int p[N];
bool st[N];

struct Edge{
    int a, b, w;
    bool operator< (const Edge &W)const{
        return w < W.w;
    }
}edges[M];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal(){
    sort(edges, edges + m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;    // 初始化并查集
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i ++ ){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        st[a] = true, st[b] = true;
        if (a != b){
            p[a] = b;
            res += w;
            cnt ++ ;
        }
    }
    return res;
}

int main(){
    FAST
    cin >> n >> m;
    int tmp = 0;
    for (int i = 0; i < m; i ++ ){
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
        tmp += w;
    }
    int tmp2 = 0;
    for(int i = 1;i<=n;i++){
        if(!st[i]){
            tmp2 += kruskal();
        }
    }
    cout << tmp - tmp2 << '\n';
    return 0;
}


/*
法二：用kruskal算法的原理做 + 并查集
*/

#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 110, M = 410, INF = 0x3f3f3f3f;

int n, m;
int p[N];

struct Edge{
    int a, b, w;
    bool operator< (const Edge &W)const{
        return w < W.w;
    }
}edges[M];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    FAST
    cin >> n >> m;
    for(int i = 1;i<=n;i++) p[i] = i;
    for (int i = 0; i < m; i ++ ){
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    sort(edges, edges + m);
    int tmp = 0;
    for(int i = 0;i<m;i++){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if(a!=b) p[a] = b;
        else tmp += w;
    }
    cout << tmp << '\n';
    return 0;
}


