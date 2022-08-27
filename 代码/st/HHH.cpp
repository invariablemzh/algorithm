#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f3f3f3f3f
#define mod 1000000007 
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

typedef pair<ll,int> pir;
string sstr[]={"No\n","Yes\n"};
const int N=200010;
int n,m,s,t,cnt=1;//从2开始，保证相反边只有低位不同 
int to[N],nxt[N],head[N],pre[N],prep[N],gnum;//pre:维护路径前置节点,prep:维护链接的边的编号 
ll wei[N],dis[N],cost[N],h[N],totf,totc;//h维护势
void add(int u,int v,ll w,ll c)
{
	to[++cnt]=v;
	wei[cnt]=w;
	nxt[cnt]=head[u];
	head[u]=cnt;
	cost[cnt]=c;
	//反向边 
	to[++cnt]=u;
	wei[cnt]=0;
	nxt[cnt]=head[v];
	head[v]=cnt;
	cost[cnt]=-c;
}
void Dijkstra()
{
	for(int i=0;i<=gnum;i++) dis[i]=inf;
	static priority_queue<pir, vector<pir>, greater<pir> > q;
	while(!q.empty()) q.pop();
	dis[s]=0;
	q.push(pir(dis[s],s));
	while(!q.empty()){
		pir tmp=q.top();
		q.pop();
		int u=tmp.second;
		if(dis[u]<tmp.first) continue;//最大费用的话改变符号 
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(wei[i]<=0) continue;//流量用完
			if(dis[v]==inf||dis[v]>dis[u]+cost[i]+h[u]-h[v]){ //最大费用的话改变符号
				dis[v]=dis[u]+cost[i]+h[u]-h[v];
				pre[v]=u;prep[v]=i;
				q.push(pir(dis[v],v));
			} 
		}
	}
	
}
pair<ll,ll> solve()
{
	while(1){
		Dijkstra();
		if(dis[t]==inf) break;
		for(int i=1;i<=gnum;i++) h[i]+=(dis[i]!=inf)? dis[i]:0;
		ll cf=inf;//当前增广路的花费和流量
		for(int i=t;i!=s;i=pre[i]) cf=min(cf,wei[prep[i]]);
		totf+=cf;
		totc+=h[t]*cf;
		assert(totc>=0);
		for(int i=t;i!=s;i=pre[i]){
			wei[prep[i]]-=cf;//正向边 
			wei[prep[i]^1]+=cf;//反向边 
		}
	}
	return pair<ll,ll>(totf,totc);
}
void init()
{
	cnt=1;
	totc=totf=0;
	for(int i=0;i<=gnum;i++) head[i]=h[i]=0;
}
int g[510][510];
signed main()
{
    FAST
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
		}
	}
	s=n+3,t=n+4;
	gnum=n+5;
	init();
	for(int i=1;i<=n;i+=2) add(s,i,1,0);
	//2
	add(2,t,1,0);
	for(int i=1;i<=n;i+=2){
		if(g[i][2]!=0) add(i,2,1,g[i][2]);
	}
	for(int i=4;i<=n;i+=2){//枚举连接i,i-2的点
		add(i,t,1,0);
		for(int j=1;j<=n;j+=2){
			if(g[j][i]!=0&&g[j][i-2]!=0){
				add(j,i,1,g[j][i]+g[j][i-2]);
			}
		}
	}
	if(n%2){//奇数，最后还需要一个单独的n-1
		add(n+1,t,1,0);
		for(int j=1;j<=n;j+=2){
			if(g[j][n-1]!=0) add(j,n+1,1,g[j][n-1]);
		}
	}
	auto tmp=solve();
	cout<<tmp.second<<'\n';
}

