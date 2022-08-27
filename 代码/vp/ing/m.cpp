#include<stdio.h>
#include<list>
#include <iostream>
#define MAXN 6010
using namespace std;

long long s;
int i,n,t[MAXN],d[MAXN],ans[MAXN];

int main(){
	list<int> l;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",t+i,d+i);
		l.push_back(i);
		s+=t[i];
	}
	for(i=0;i<n;i++){
		auto p = l.end();
		int tmp = 1;
		while(p!=l.begin()){
			p--;
			if(s<=d[*p]){
				ans[i] = *p;
				s -= t[*p];
				l.erase(p);
				tmp = 0;
				break;
			}
		}
		if(tmp){
			putchar('*');
            puts("");
			return 0;
		}
	}
	while(n--)
		printf("%d ",ans[n]+1);
    puts("");
	return 0;
}