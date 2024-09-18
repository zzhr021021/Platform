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

// Longest Increasing Subsequence
// suppose elements in v are unique
int LIS(vll & v){
	if(v.size() == 0)return 0;
	if(v.size() == 1)return 1;
	vll st;
	for(auto o : v){
		if(st.size() == 0){
			st.pb(o);
		}
		else{
			if(o > st.back()){
				st.pb(o); 
			}
			else if(o < st[0]){
				st[0] = o;
			}
			else{
				ll l = 0, r = st.size() - 1;
				while(l != r){
					ll mid = (l + r) / 2;
					if(o > st[mid]){
						l = mid + 1;
					}
					else{
						r = mid;
					}
				}
				st[l] = o;
			}
		}
	}
	return st.size();
}

void sol(){
	int n;
	cin>>n;
	vector<int> v1, v2;
	vector<int> mp(n + 1); 
	for(int i = 0;i < n;i++){
		int tp;cin>>tp;
		v1.push_back(tp);
		mp[tp] = i + 1;
	}
	for(int i = 0;i < n;i++){
		int tp;cin>>tp;
		v2.push_back(tp);
	}
	
	vll test2(n);
	for(int i = 0;i < n;i++){
		test2[i] = mp[v2[i]];
	}
    cout << LIS(test2);   
	
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
