#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
int mapp[1001][1001];
int dis[1001];
int vis[1001];
void dijkstra()
{
    for(int k=1;k<=n;k++)
    {
        int minn=0x7f7f7f,pos;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&dis[i]<minn)
            {
                minn=dis[i],pos=i;
            }
        }
        vis[pos]=true; 
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&dis[i]>dis[pos]+mapp[pos][i])
            {
				dis[i]=dis[pos]+mapp[pos][i];
            }
        }
    }
    return;
}
int main()
{
	scanf("%d%d",&n,&m);//?? 
	for(int i=1;i<=m;i++)
	{
		int u,v,w; 
		scanf("%d%d%d",&u,&v,&w);
		mapp[u][v]=w;
	}
	dijkstra();
	printf("%d",dis[n]);
	return 0;
}
