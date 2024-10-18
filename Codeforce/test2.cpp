#include<bits/stdc++.h>
using namespace std;
int mp[810][810];
int n, m, bx, by, gx, gy;
int sx[3], sy[3], cnt;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
struct node{int x, y, dep;};
int get(node t){
	if(t.dep<=3) return 1;
    else return (t.dep-1)/3+1;
}
bool pd(int x, int y, int dep) {
	return dep*2>=min(abs(x-sx[1])+abs(y-sy[1]), abs(x-sx[2])+abs(y-sy[2]));
}
void bfs_boy() {
    queue<node> q; q.push({bx, by, 0});
    while(q.size()) {
        node t=q.front(); q.pop(); t.dep++;
        for(int i=0;i<4;i++) {
            int xx=t.x+dx[i];
            int yy=t.y+dy[i];
            if(xx<1||yy<1||xx>n||yy>m||mp[xx][yy]!=0)continue;
            if(pd(xx, yy, get(t))) continue;
            mp[xx][yy]=get(t);
            q.push({xx, yy, t.dep});
        }
    }
}
void bfs_girl() {
    queue<node> q;
    q.push({gx, gy, 0});
    while(q.size()) {
        node t=q.front(); q.pop(); t.dep++;
        for(int i=0;i<4;i++) {
            int xx=t.x+dx[i], yy=t.y+dy[i];
            if(!xx||!yy||xx>n||yy>m||mp[xx][yy]==-1) continue;
            if(pd(xx, yy, t.dep)) continue;
            if(mp[xx][yy]<=t.dep&&mp[xx][yy]>0) {
                printf("%d\n", t.dep);
                return;
            }
            mp[xx][yy]=-1;
            q.push({xx, yy, t.dep});
        }
    }
    puts("-1");
}
int main() {
    int t; scanf("%d", &t);
    while(t--) {
        cnt=0; scanf("%d%d", &n, &m);
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
            	char c; cin >> c;
                if(c=='X') mp[i][j]=-1;
                if(c=='.') mp[i][j]=0;
                if(c=='Z') mp[i][j]=-1, sx[++cnt]=i, sy[cnt]=j;
                if(c=='M') bx=i, by=j;
                if(c=='G') gx=i, gy=j;
            }
        }
        bfs_boy(); 
		bfs_girl();
    }
	system("pause");
    return 0;
}