#include<bits/stdc++.h>
using namespace std;

int n,m,K,sx,sy,tx,ty;
struct edge{
	int x[2],y[2]; 
}e[20];

int mp[20][20];

int Lw[20][20],Dw[20][20];

bool dfs(int x,int y){	//是否能到终点
	mp[x][y]=1;
	if(x==tx && y==ty){
		return 1;
	}
	bool re=0;
	//x-1 y	上
	if(x>=1 && Lw[x][y]==0 && mp[x-1][y]==0){
		re|=dfs(x-1,y);
	}
	//x+1 y	下
	if(x+1<n && Lw[x+1][y]==0 && mp[x+1][y]==0){
		re|=dfs(x+1,y);
	}
	//x y-1	左
	if(y>=1 && Dw[x][y]==0 && mp[x][y-1]==0){
		re|=dfs(x,y-1);
	}
	//x y+1	右
	if(y+1<m && Dw[x][y+1]==0 && mp[x][y+1]==0){
		re|=dfs(x,y+1);
	}
	return re;
}

bool check(int s){	
	memset(mp,0,sizeof(mp));
	memset(Lw,0,sizeof(Lw));
	memset(Dw,0,sizeof(Dw));
	for(int i=0;i<K;++i){	//标记用的墙的位置
		if((s&(1<<i))==0){
			if(e[i].x[0]==e[i].x[1]){
				for(int j=e[i].y[0];j<e[i].y[1];++j){
					Lw[e[i].x[0]][j]=1;
				}
			}
			else{
				for(int j=e[i].x[0];j<e[i].x[1];++j){
					Dw[j][e[i].y[0]]=1;
				}
			}
		}
	}
	return dfs(sx,sy);
}

int popcount(int x){
	int re=0;
	while(x){
		if(x&1) ++re;
		x>>=1;
	}
	return re;
}

int f[(1<<15)+5];

void solve(){
	cin>>n>>m>>K>>sx>>sy>>tx>>ty;
	for(int i=0;i<K;++i){	//输入K堵墙的坐标
		cin>>e[i].x[0]>>e[i].y[0]>>e[i].x[1]>>e[i].y[1];
		if(e[i].x[0]==e[i].x[1]&&e[i].y[0]>e[i].y[1]){
			swap(e[i].y[0],e[i].y[1]);
		}
		if(e[i].y[0]==e[i].y[1]&&e[i].x[0]>e[i].x[1]){
			swap(e[i].x[0],e[i].x[1]);
		}
	}
	int ans=K;	//最多走过K堵墙
	for(int s=0;s<(1<<K);++s){	//清空
		f[s]=0;
	}
	for(int s=0;s<(1<<K);++s){	//枚举所有墙的状态
		if(f[s]){	//剪枝
			continue;
		}
		f[s]=check(s);	//该墙的状态，判断是否能到终点
		if(f[s]){
			ans=min(ans,popcount(s));
			for(int j=0;j<K;++j){	//剪枝，如果s状态的墙满足了，再多一个状态也能满足
				f[s|(1<<j)]|=f[s];
			}
		}
	}
	cout<<ans<<endl;
	return;
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	for(int i=1;i<=t;++i){
		solve();
	}
	return 0;
} 
