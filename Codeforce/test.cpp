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
// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll tt, ttt;
ll n,k,m,t,x,y,z,h,q,r;

ll sq(ll x){return x * x;}
ll a[50050];
ll bl = 0;
ll ind(ll x){
	return x / bl;
}
ll ghs(ll l, ll r){
	return l * 1e9 + r;
}
struct que{
	ll l, r;
}ques[50050];
bool cmp(const que & u, const que & v){
	return u.r < v.r;
}
vector<que> llist[250];
unordered_map<ll, ll> inj;

void sol(){
	cin>>n>>m;
	bl = sqrt(n);
	rep(i,n)cin>>a[i];
	rep(i,m){
		cin>>x>>y;
		x--;y--;
		ques[i].l = x;
		ques[i].r = y;
		llist[ind(x)].push_back({x, y});
	}
	rep(i,250){
		sort(all(llist[i]), cmp);
	}
	rep(i,250){
		if(llist[i].size() == 0)continue;
		ll l = 0, r = 0, sm = 1;
		unordered_map<ll, ll> rec;
		rec[a[0]] = 1;
		for(auto o : llist[i]){
			while(r != o.r){
				r++;
				rec[a[r]]++;
				ll tp = rec[a[r]];
				sm -= sq(tp - 1);
				sm += sq(tp);
			}
			while(l < o.l){
				rec[a[l]]--;
				ll tp = rec[a[l]];
				sm -= sq(tp + 1);
				sm += sq(tp);
				l++;
			}
			while(l != o.l){
				l--;
				rec[a[l]]++;
				ll tp = rec[a[l]];
				sm -= sq(tp - 1);
				sm += sq(tp);
			}
			inj[ghs(o.l, o.r)] = sm;
		}
	}
	rep(i,m){
		ll tp = inj[ghs(ques[i].l, ques[i].r)];
		ll gap = ques[i].r - ques[i].l + 1;
		if(tp == gap){
			cend("0/1");
		}
		else{
			ll u = tp - gap;
			ll d = gap * (gap - 1);
			ll g = __gcd(u, d);
			u /= g;
			d /= g;
			cout << u << "/" << d << endl;
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