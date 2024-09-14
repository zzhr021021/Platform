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
 
#define alice cout<<"Alice\n"
#define bob cout<<"Bob\n"
#define draw cout<<"Draw\n"
 
typedef long long int ll;
const ll MOD = 1e9+1e6;
ll p = MOD;
const ll inf = 1e18;
const int N = 3e5+5;
using namespace std;
 
ll tt;
ll ttt;
ll n,k,m,d,q,f,h,w,c,t;
 
string s;

void printvec(vector<int> & v){
	for(auto &x : v){
		cout << x << " ";
	}
	cendl;
}

// return a vec, z[i] indicate for substring s[i]-s[n-1] and the original string, the longest common prefix length
// z[0] not usable
vector<int> z_func(string & s){
	int n = (int)s.length();
	vector<int> z(n);
	for(int i = 1, l = 0, r = 0; i < n; ++i){
		if(i <= r && z[i - l] < r - i + 1){
			z[i] = z[i - l];
		}
		else{
			z[i] = max(0, r - i + 1);
			while(i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
		}
		if(i + z[i] - 1 > r)l = i, r = i + z[i] - 1;
	}
	return z;
}



void sol(){
	string s = "abcdabd";
	vector<int> zz = z_func(s);
	printvec(zz);
	
}
 
int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);

    cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	return 0;
}
