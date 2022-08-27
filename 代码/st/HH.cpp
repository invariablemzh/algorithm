#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 610, M = 200010;

int n,m,S,T;//从2开始，保证相反边只有低位不同 
int h[N], e[M], ne[M], idx;
ll f[M], w[M], incf[N],d[N];
int q[N], pre[N];
int g[510][510];
bool st[N];

void add(int a,int b,ll c,ll d){
	e[idx] = b, f[idx] = c, w[idx] = d, ne[idx] = h[a], h[a] = idx ++ ;
    e[idx] = a, f[idx] = 0, w[idx] = -d, ne[idx] = h[b], h[b] = idx ++ ;
}

bool spfa(){
    queue<int> q;
    for(int i = 0;i<=n+5;i++) d[i] = INF;
    memset(incf, 0, sizeof incf);
    memset(st,false,sizeof(st));
    while(q.size()) q.pop();
    q.push(S);
    d[S] = 0, incf[S] = INF;
    while (q.size()){
        int t = q.front(); q.pop();
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i]){
            int ver = e[i];
            if (f[i] && d[ver] > d[t] + w[i]){
                d[ver] = d[t] + w[i];
                pre[ver] = i;
                incf[ver] = min(f[i], incf[t]);
                if (!st[ver]){
                    q.push(ver);
                    st[ver] = true;
                }
            }
        }
    }
    return incf[T] > 0;
}
	

ll EK(){
    ll cost = 0;
    while (spfa()){
        ll t = incf[T];
        cost += t * d[T];
        for (int i = T; i != S; i = e[pre[i] ^ 1]){
            f[pre[i]] -= t;
            f[pre[i] ^ 1] += t;
        }
    }
    return cost;
}

// void init()
// {
// 	cnt=1;
// 	// totc=totf=0;
// 	for(int i=0;i<=gnum;i++) head[i]=h[i]=0;
// }

int main()
{
    FAST
    memset(h,-1,sizeof(h));
    idx = 0;
	
    cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
            cin>>g[i][j];
		}
	}
	S=n+3,T=n+4;
	for(int i=1;i<=n;i+=2) add(S,i,1,0);
	//2
	add(2,T,1,0);
	for(int i=1;i<=n;i+=2){
		if(g[i][2]) add(i,2,1,g[i][2]);
	}
	for(int i=4;i<=n;i+=2){//枚举连接i,i-2的点
		add(i,T,1,0);
		for(int j=1;j<=n;j+=2){
			if(g[j][i]&&g[j][i-2]){
				add(j,i,1,g[j][i]+g[j][i-2]);
			}
		}
	}
	if(n&1){//奇数，最后还需要一个单独的n-1
		add(n+1,T,1,0);
		for(int j=1;j<=n;j+=2){
			if(g[j][n-1]) add(j,n+1,1,g[j][n-1]);
		}
	}
    cout<<EK()<<'\n';
    return 0;
}

