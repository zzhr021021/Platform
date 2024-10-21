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
// ll dix[4] = {0, -1, 0, 1};
// ll diy[4] = {1, 0, -1, 0};
using namespace std;
// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll tt, ttt;
ll n,k,m,d,q,t,x,y,z,h;

void printvec(vll & v){
	for(ll &x : v){
		cout << x << " ";
	}
	cendl;
}

vector<string> indi(7);
ll estimate(vector<vll> & vv, ll tar){
	ll err = 0;
	for(int i = 2;i <= 4;i++){
		for(int j = 2;j <= 4;j++){
			if(i != 3 && j != 3){
				if(vv[i][j] != tar){
					err++;
				}
			}
		}
	}
	return err;
}

void sol(){
	vector<vll> a(7, vll(7, 0));
	vll araw(24);
	rep(i,24)cin>>araw[i];
	ll pos = 0;
	rep(i,7){
		rep(j,7){
			if(indi[i][j] == '1'){
				a[i][j] = araw[pos];
				pos++;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	indi[0] = "0010100";
	indi[1] = "0010100";
	indi[2] = "1111111";
	indi[3] = "0010100";
	indi[4] = "1111111";
	indi[5] = "0010100";
	indi[6] = "0010100";

	tt = 1;
	cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}