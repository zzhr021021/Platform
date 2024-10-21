#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)

#define ll long long
#define ull unsigned long long
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>

#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

const ll MOD = 1e9;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
const int N = 200005;
using namespace std;
ll tt, ttt;
ll n,k,m,d,q,x,y,z,h;

void printvec(vll & v){
	for(ll &x : v){
		cout << x << " ";
	}
	cendl;
}

struct Node{
    ll val, dist, id;
    ll ls, rs;
    ll rt;
    bool operator<(Node x)const{
        if(val == x.val)return id < x.id;
        return val < x.val;
    }
} t[100005];
bool valid[100005];

ll getrt(ll x){
    if(t[x].rt != x){
        return t[x].rt = getrt(t[x].rt);
    }
    else return x;
}
ll merge(ll x, ll y){
    if(x == 0)return y;
    if(y == 0)return x;
    if(t[y] < t[x])swap(x, y);
    t[x].rs = merge(t[x].rs, y);
    if(t[t[x].ls].dist < t[t[x].rs].dist){
        swap(t[x].ls, t[x].rs);
    }
    t[x].dist = t[t[x].rs].dist + 1;
    return x;
}

void sol(){
    cin>>n>>m;
    vll a(n + 5);
    rep1n(i,n){
        cin>>a[i];
        valid[i] = true;
    }
    rep1n(i,n){
        t[i].val = a[i];
        t[i].dist = 0;
        t[i].id = i;
        t[i].rt = i;
        t[i].ls = t[i].rs = 0;
    }
    t[0].dist = -1;
    rep(iop, m){
        ll op;cin>>op;
        if(op == 1){
            cin>>x>>y;
            if(!valid[x])continue;
            if(!valid[y])continue;
            x = getrt(x);
            y = getrt(y);
            if(x == y)continue;
            t[x].rt = t[y].rt = merge(x, y);
        }
        else{
            cin>>x;
            if(!valid[x]){
                cend(-1);
                continue;
            }
            ll rt = getrt(x);
            valid[t[rt].id] = false;
            cend(t[rt].val);
            // important
            t[t[rt].ls].rt = t[t[rt].rs].rt = t[rt].rt = merge(t[rt].ls, t[rt].rs);
            t[rt].ls = t[rt].rs = t[rt].dist = 0;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	tt = 1;
	// cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}