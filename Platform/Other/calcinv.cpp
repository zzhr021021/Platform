#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)

#define pll pair<ll, ll>

#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define vpl vector<pair<ll, ll>>

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
 
typedef long long int ll;
const ll MOD = 1e9+7;
const ll MODD = 1e9+9;
const ll MOOD = 998244353;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
const int N = 200005;
using namespace std;
 
ll tt;
ll ttt;
ll n,k,m,d,q,t,x,y,z,h;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

void printvec(vll & v){
	for(ll &x : v){
		cout << x << " ";
	}
	cendl;
}

void printvec(vll & v, bool rev){
	for(ll &x : v){
		cout << x << " ";
	}
	cendl;
}

vll calc_presum(vll & v){
	vll ret(n + 2);
	rep(i,n){
		ret[i + 1] = ret[i] + v[i];
	}
	return ret;
}

vll calc_sufsum(vll & v){
	vll ret(n + 2);
	ll n = v.size();
	for(int i = n;i >= 1;i--){
		ret[i] = ret[i + 1] + v[i - 1];
	}
	return ret;
}

ll qpow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y & 1)ans = ans * x % p;
        x = x * x % p;
		y >>= 1;
    }
    return ans;
}

ll qpowll(ll x, ll y, ll p){
	ll ret = 0;
	while(y){
		if(y & 1)ret = (ret + x) % p;
		x = x * 2 % p;
	}
	return ret;
}

ll qpowmodp(ll x, ll y, ll p){
    ll ans = 1;
    while(y){
        if(y & 1)ans = ans * x % p;
        x = x * x % p;
		y >>= 1;
    }
    return ans;
}

ll ladder(ll u, ll d, ll gap){
	ll ret = (u + d) * ((d - u) / gap + 1) / 2;
	return ret;
}

ll vemax(vll & v){
	ll ret = -1e18;
	for(ll o : v){
		ret = max(ret, o);
	}
	return ret;
}

ll vemin(vll & v){
	ll ret = 1e18;
	for(ll o : v){
		ret = min(ret, o);
	}
	return ret;
}

ll vesum(vll & v){
	ll ret = 0;
	for(ll o : v){
		ret += o;
	}
	return ret;
}


// count the number of inverse pair of an array, via merge-sort, so it sort the array by the way
ll calcinv(vll & ve){
	if(ve.size() == 1){
		return 0;
	}
	else{
		ll vn = ve.size();
		ll mid = vn / 2;
		vll vel(mid);
		vll ver(vn - mid);
		ll ln = mid;
		ll rn = vn - mid;
		rep(i,ln)vel[i] = ve[i];
		rep(i,rn)ver[i] = ve[mid + i];
		
		ll ret = 0;
		ret += calcinv(vel) + calcinv(ver);
		ll pol = 0, por = 0;
		ve.clear();
		while(pol != ln || por != rn){
			if(pol != ln && por != rn){
				if(vel[pol] < ver[por]){
					ve.pb(vel[pol]);
					pol++;
				}
				else{
					ve.pb(ver[por]);
					por++;
					ret += ln - pol;
				}
			}
			else if(pol == ln && por != rn){
				ve.pb(ver[por]);
				por++;
			}
			else if(pol != ln && por == rn){
				ve.pb(vel[pol]);
				pol++;
			}
		}
		return ret;
	}
}

void sol(){
	cin>>n;
	
}

int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
	
//	initinv();
		
	tt = 1;
//	cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	return 0;
}
