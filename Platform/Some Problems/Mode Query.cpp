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
#define vpl vector<pair<long long, long long>>
#define vstr vector<string>
#define smpq priority_queue<long long, vector<long long>, greater<long long>>
#define bgpq priority_queue<long long> 

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


const ll MOD = 1e9 + 7;
const ll MODD = 1e9 + 9;
const ll MOOD = 666623333;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
// ll dix[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// ll diy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
using namespace std;
 mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll tt, ttt;
ll n,k,m,t,x,y,z,w,h,q;

ll a[50000];
ll md[1000][1000];
ll mdcnt[1000][1000];
ll ct[50000];
ll bl, bc;
ll cuni = 0;
set<ll> st;
map<ll, ll> inj;
map<ll, ll> ivj;
vll seq[50000];
ll ind(ll x){
	return x / bl;
}
ll rloc(ll x){
	return (x / bl + 1) * bl - 1;
}
ll lloc(ll x){
	return (x / bl) * bl;
}
// return : the time appeared between [l, r]
ll get(ll x, ll itvl, ll itvr){
	ll lloc, rloc;
	ll l,r;
	
	l = 0;r = seq[x].size() - 1;
	while(l != r){
		ll mid = (l + r) / 2;
		if(seq[x][mid] < itvl)l = mid + 1;
		else r = mid;
	}
	lloc = l - 1;

	l = 0;r = seq[x].size() - 1;
	while(l != r){
		ll mid = (l + r + 1) / 2;
		if(seq[x][mid] > itvr)r = mid - 1;
		else l = mid;
	}
	rloc = r + 1;

	return rloc - lloc - 1;
}

void sol(){
	// pre
	cin>>n>>m;
	bl = pow((double)n / log(n), 0.5);
	if(bl == 0)bl++;
	bc = (n / bl);
	if(bc * bl != n)bc++;

	rep(i,n){
		cin>>a[i];
		st.insert(a[i]);
	}
	for(auto o : st){
		cuni++;
		inj[o] = cuni;
		ivj[cuni] = o;
	}
	rep(i,n){
		a[i] = inj[a[i]];
	}

	// get cnt
	rep(i,bc){
		memset(ct, 0, sizeof(ct));
		ll mx = 0;
		ll mxis = 0;
		ll st = bl * i;
		for(int j = st;j < bl * bc;j++){
			if(a[j]){
				ct[a[j]]++;
				if(ct[a[j]] > mx || (ct[a[j]] == mx && a[j] < mxis)){
					mx = ct[a[j]];
					mxis = a[j];
				}
			}
			if((j + 1) % bl == 0){
				md[i][ind(j)] = mxis;
				mdcnt[i][ind(j)] = mx;
			}
		}
	}

	// get seq
	rep(i,45000)seq[i].push_back(-1e9);
	rep(i,n)seq[a[i]].push_back(i);
	rep(i,45000)seq[i].push_back(1e9);

	// query
	ll last = 0;
	rep(iop,m){
		cin>>x>>y;
		x = (x + last - 1) % n + 1;
		y = (y + last - 1) % n + 1;
		if(x > y)swap(x, y);
		x--;y--;
		ll ans = 0;
		ll acnt = 0;
		if(ind(y) - ind(x) <= 1){
			map<ll, ll> cn;
			for(int i = x;i <= y;i++){
				if(a[i] == 0)break;
				cn[a[i]]++;
			}
			for(auto o : cn){
				if(o.second > acnt){
					ans = o.first;
					acnt = o.second;
				}
			}
			ans = ivj[ans];
		}
		else{
			ll indl = ind(x) + 1;
			ll indr = ind(y) - 1;
			ans = md[indl][indr];
			acnt = mdcnt[indl][indr];
			for(int i = x;i <= rloc(x);i++){
				if(a[i] == 0)break;
				ll tp = get(a[i], x, y);
				if(tp > acnt || (tp == acnt && a[i] < ans)){
					acnt = tp;
					ans = a[i];
				}
			}
			for(int i = lloc(y);i <= y;i++){
				if(a[i] == 0)break;
				ll tp = get(a[i], x, y);
				if(tp > acnt || (tp == acnt && a[i] < ans)){
					acnt = tp;
					ans = a[i];
				}
			}
			ans = ivj[ans];
		}

		cend(ans);
		last = ans;
	}


}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	tt = 1;
//	cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}
