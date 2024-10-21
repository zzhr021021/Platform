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

#define NODE array<array<ll, 7>, 7> 

const ll MOD = 1e9;
const ll MODD = 1e9+9;
const ll MOOD = 998244353;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
const int N = 200005;
using namespace std;

ll tt, ttt;
ll n,k,m,d,q,t,x,y,z,h;

void printvec(vll & v){
	for(ll &x : v){
		cout << x << " ";
	}
	cendl;
}
void printvec(vector<char> & v){
	for(char &x : v){
		cout << x;
	}
	cendl;
}
vector<string> indi(7);
string ops = "ABCDEFGH";
vector<char> seq;
ll estimate(NODE & vv){
	vll cnt(4);
	for(int i = 2;i <= 4;i++){
		for(int j = 2;j <= 4;j++){
			cnt[vv[i][j]]++;
		}
	}
    ll ret = 8;
    rep1n(i, 3){
        ret = min(ret, 8 - cnt[i]);
    }
	return ret;
}
ll isend(NODE & vv){
	vll cnt(4);
	for(int i = 2;i <= 4;i++){
		for(int j = 2;j <= 4;j++){
			cnt[vv[i][j]]++;
		}
	}
	if(cnt[1] == 8)return 1;
	if(cnt[2] == 8)return 2;
	if(cnt[3] == 8)return 3;
	return 0;
}
bool isendtar(NODE & vv, ll tar){
	vll cnt(4);
	for(int i = 2;i <= 4;i++){
		for(int j = 2;j <= 4;j++){
			cnt[vv[i][j]]++;
		}
	}
	return cnt[tar] == 8;
}
ll storex[8] = {0, 0, 2, 4, 6, 6, 4, 2};
ll storey[8] = {2, 4, 6, 6, 4, 2, 0, 0};
ll dix[8] = {1, 1, 0, 0, -1, -1, 0, 0};
ll diy[8] = {0, 0, -1, -1, 0, 0, 1, 1};
NODE move(NODE & vv, ll op){
	NODE ret = vv;
	ll tx = storex[op];
	ll ty = storey[op];
	ll tp = ret[tx][ty];
	rep(iop, 6){
		ll nx = (tx + dix[op]) % 7;
		ll ny = (ty + diy[op]) % 7;
		ret[tx][ty] = ret[nx][ny];
		tx = nx;
		ty = ny;
	}
	ret[tx][ty] = tp;
	return ret;
}

bool dfs(NODE & vv, ll dep, ll maxdep){
	if(isend(vv)){
		printvec(seq);
		cend(vv[2][2]);
		return true;
	}
	if(estimate(vv) + dep > maxdep){
		return false;
	}
	rep(iop, 8){
		NODE next = move(vv, iop);
		seq.push_back(ops[iop]);
		bool ret = dfs(next, dep + 1, maxdep);
		if(ret)return true;
		seq.pop_back();
	}
    return false;
}


void sol(){
	vll araw(24);
	rep(i,24)cin>>araw[i];
	while(araw[0]){
        seq.clear();
		NODE a;
        rep(i,7)rep(j,7)a[i][j] = 0;
		ll pos = 0;
		rep(i,7){
			rep(j,7){
				if(indi[i][j] == '1'){
					a[i][j] = araw[pos];
					pos++;
				}
			}
		}
        bool flag = false;
		if(isend(a)){
			cend("No moves needed");
			cend(isend(a));
		}
		else{
			rep1n(idep, 20){
                bool ret = dfs(a, 0, idep);
                if(ret){
                    flag = true;
                    break;
                }
			}
		}
		rep(i,24){
            cin>>araw[i];
            if(araw[i] == 0)return;
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
	// cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}