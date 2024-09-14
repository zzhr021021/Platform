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

// process a string s, return a vector v of length size(s)
// v[i] indicate the palindrome number (also the radius of longest palindrom) centered s[i]
vector<int> manacher_odd(string s){
	int n = s.length();
	vector<int> ret(n, 0);
	int l = 0, r = -1;
	for(int i = 0;i < n;i++){
		int bias = 0;
		if(i > r){
			bias = 0;
		}
		else{
			ret[i] = ret[l + r - i];
			ret[i] = min(ret[i], r - i + 1);
			bias = ret[i];
		}
		while(i - bias >= 0 && i + bias < n){
			if(s[i - bias] == s[i + bias]){
				ret[i]++;
				l = i - bias;
				r = i + bias;
				bias++;
			}
			else break;
		}
	}
	return ret;

}

vector<int> palin;

// get the appended s (#a#b#a#z#) manacher vector
vector<int> manacher_append(string s){
	string s_append;
	for(auto c: s) {
        s_append += string("#") + c;
    }
    vector<int> res = manacher_odd(s_append + "#");
    return res;
}

// ask if substring s[i]-s[j] is a palindrome
// make sure v_ma is the manacher vector of appended string
bool ask_palin(vector<int> & v_ma, int l, int r){
	l = l*2+1;
	r = r*2+1;
	int mid = (l+r) / 2;
	return v_ma[mid] >= r - mid + 1; 
}

void sol(){
	// make s longer than 6
	string s;cin>>s;
	palin = manacher_append(s);
	cend(ask_palin(palin, 0, 3));
	cend(ask_palin(palin, 1, 3));
	cend(ask_palin(palin, 0, 5));
	cend(ask_palin(palin, 3, 5));
	cend(ask_palin(palin, 4, 4));
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
