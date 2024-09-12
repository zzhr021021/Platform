#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
#define alice cout<<"Alice\n"
#define bob cout<<"Bob\n"
#define draw cout<<"Draw\n"

// tree hashing, also identify the symmetrical tree

typedef long long int ll;
const ll MOD = 1e9+7;
const ll MODD = 1e9+9;
ll p = MOD;
const ll inf = 1e18;
const int N = 3e5+5;
using namespace std;
 
ll tt;
ll ttt;
ll n,k,m,d,q,f,h,w,t,x,y;

void printvec(vector<int> & v){
	for(auto &x : v){
		cout << x << " ";
	}
	cendl;
}

ll a[N];
ll b = 37363533;
ll bp[2*N];
ll bpp[2*N];

vector<ll> g[200005];
pair<ll, ll> hashes[200005];
bool issym[200005];
ll sz[200005];

pair<ll, ll> dfs(ll o, ll fa){
	pair<ll, ll> ret;
	ll soncount = g[o].size();
	if(o != 1)soncount--;
	if(soncount == 0){
		issym[o] = true;
		hashes[o] = {0,0};
		sz[o] = 1;
		return {0,0};
	}
	sz[o] = 1;
	vector<pair<pair<ll, ll>, ll>> sonhash;
	for(ll ad : g[o]){
		if(ad != fa){
			sonhash.pb({dfs(ad, o), sz[ad]});
			sz[o] += sz[ad];
		}
	}
	sort(sonhash.begin(), sonhash.end());
	
	ll fr = 0;
	ll se = 0;
	for(auto oo : sonhash){
		fr = (fr * bp[1] % MOD + 1) % MOD;
		fr = (fr * bp[oo.second*2] % MOD + oo.first.first) % MOD;
		fr = (fr * bp[1] % MOD + 2) % MOD;
		
		se = (se * bp[1] % MODD + 1) % MODD;
		se = (se * bp[oo.second*2] % MODD + oo.first.second) % MODD;
		se = (se * bp[1] % MODD + 2) % MODD;
	}	
	hashes[o] = {fr, se};
	
	ll l = 0;
	ll r = sonhash.size() - 1;
	while(r - l >= 1 && sonhash[l].first == sonhash[l + 1].first){
		l += 2;
	}
	if(l >= sonhash.size()){
		issym[o] = true;
	}
	else{
		while(r - l >= 1 && sonhash[r - 1].first == sonhash[r].first){
			r -= 2;
		}
		if(l == r){
			ll to;
			for(ll ad : g[o]){
				if(ad != fa){
					if(hashes[ad] == sonhash[l].first){
						to = ad;
					}
				}
			}
			issym[o] = issym[to];
		}
		else{
			issym[o] = false;;
		}
	}
	return {fr, se};
}

void sol(){
	cin>>n;
	rep(i,n+5)g[i].clear();
	rep(i,n+5)issym[i] = false;
	rep(i,n-1){
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1, -1);

	if(issym[1])yes;
	else no;
}

 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	bp[0] = bpp[0] = 1;
	rep1n(i,4e5){
		bp[i] = (bp[i - 1] * b) % MOD;
		bpp[i] = (bpp[i - 1] * b) % MODD;
	}
	
    cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	return 0;
}
