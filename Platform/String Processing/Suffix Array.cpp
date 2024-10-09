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

const ll MOD = 1e9;
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

vll radix_sort(vll & v, ll range){
	return v;
}

// calculate suffix array
vector<ll> get_rank(string & s){
	n = s.size();
	ll x = 1, ti = 1;
	while(x < n){
		x *= 2;
		ti++;
	}
	
	vll rank(n);
	vll newstring(n);
	rep(i,n){
		newstring[i] = s[i];
	}
	
	ll gap = 1;
	rep(iti, ti){
		if(iti != 0){
			rep(i,n){
				newstring[i] = rank[i] * MOD;
				if(i + gap < n){
					newstring[i] += rank[i + gap];
				}
			}
			gap *= 2;
//			ctest;ctest;printvec(newstring);
		}
		
		if(iti == 0){
			set<ll> st;
			rep(i,n){
				st.insert(newstring[i]);
			}
			map<ll, ll> nmp;
			ll ii = 1;
			for(auto o : st){
				nmp[o] = ii;
				ii++;
			}
			rep(i,n){
				rank[i] = nmp[newstring[i]];
			}
		}
		else{
			vector<vll> radix_sort_arr_2(n + 5);
			rep(i,n){
				x = newstring[i] % (ll)MOD;
				radix_sort_arr_2[x].pb(newstring[i]);
			}
			
			vector<vll> radix_sort_arr_1(n + 5);
			rep(i,n + 5){
				for(auto o : radix_sort_arr_2[i]){
					radix_sort_arr_1[o / (ll)MOD].pb(o);
				}
			}
			
			vll tp;
			rep(i,n + 5){
				for(auto o : radix_sort_arr_1[i]){
					if(tp.size()== 0 || tp.back() != o){
						tp.pb(o);
					}
				}
			}
			
			ll ii = 1;
			unordered_map<ll, ll> ump;
			for(auto o : tp){
				ump[o] = ii;
				ii++;
			}
			rep(i,n){
				rank[i] = ump[newstring[i]];
			}
			
		}
		
//		ctest;printvec(rank);
		
	}
	
	return rank;
}

vll get_sa(string & s){
	ll n = s.size();
	vll rank = get_rank(s);
	vll ret(n);
	rep(i,n){
		ret[rank[i] - 1] = i + 1;
	}
	return ret;
}

void sol(){
	string s;cin>>s;
	vll thesa = get_sa(s);
	printvec(thesa);
	
	

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
//    system("pause");
	return 0;
}
