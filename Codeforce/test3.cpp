#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)

#define ll long long
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back
#define all(a) a.begin(), a.end()

const ll inf = 1e18;
const ll INF = 1e18;
const ll N = 200005;
using namespace std;

ll tt, ttt;
ll n,k,m,t,x,y,z,h,r;
ll a[N];
struct qu{
	ll op, x, y, z;
}qus[N << 1], qul[N << 1], qur[N << 1];
ll cntop = 0;
stack<pll> seq;
ll fenw[N << 1];
ll ans[N << 1];
ll cntq;

void recover(){
	while(seq.size()){
		auto o = seq.top();
		seq.pop();
		fenw[o.first] = o.second;
	}
}
ll pa(ll x){
	ll tp = x & (-x);
	return x - tp;
}
void add(ll pos, ll val){
    while (pos < (N << 1)){
		seq.push({pos, fenw[pos]});
        fenw[pos] += val;
        pos |= (pos + 1);
    }
}
ll get(ll pos){
    ll res = 0;
    while (pos >= 0){
        res += fenw[pos];
        pos &= (pos + 1);
        pos--;
    }
    return res;
}
ll get(ll l, ll r){
    ll vr = get(r);
    ll vl = get(l - 1);
    return vr - vl;
}

void solve(ll l, ll r, ll whl, ll whr){
	if(whl > whr)return;
	if(l == r){
		for(int i = whl;i <= whr;i++){
			auto o = qus[i];
			ans[o.op] = l;
		}
		return;
	}
	ll cntl = 0, cntr = 0;
	ll mid = (l + r) >> 1;
	for(int i = whl;i <= whr;i++){
		if(qus[i].op == 0){
			if(qus[i].y <= mid){
				ll tp = get(qus[i].x, qus[i].x);
				add(tp, -1);
				add(qus[i].x, 1);
				qul[cntl] = qus[i];
				cntl++;
			}
			else{
				qur[cntr] = qus[i];
				cntr++;
			}
		}
		else{
			ll cnt = get(qus[i].x, qus[i].y);
			if(cnt >= qus[i].z){
				qul[cntl] = qus[i];
				cntl++;
			}
			else{
				qus[i].z -= cnt;
				qur[cntr] = qus[i];
				cntr++;
			}
		}
	}
	recover();
	for(int i = 0;i < cntl;i++){
		qus[whl + i] = qul[i];
	}
	for(int i = 0;i < cntr;i++){
		qus[whl + i + cntl] = qur[i];
	}
	solve(l, mid, whl, whl + cntl - 1);
	solve(mid + 1, r, whl + cntl, whr);
}

void sol(){
	cin>>n>>m;

	rep(i,n){
		cin>>a[i];
		qus[cntop].op = 0;
		qus[cntop].x = i;
		qus[cntop].y = a[i];
		cntop++;		
	}
	rep(j,m){
		ll i = cntop;
		char op;cin>>op;
		if(op == 'Q'){
			cntq++;
			cin>>qus[i].x>>qus[i].y>>qus[i].z;
		    qus[i].op = cntq;qus[i].x--;qus[i].y--;
		    cntop++;
		}
		else{
			cin>>qus[i].x>>qus[i].y;
		    qus[i].op = 0;qus[i].x--;qus[i].y--;
		    cntop++;
		}
	}
	ll u = 1e10;
	ll d = -1;

	solve(d, u, 0, cntop - 1);

	rep1n(i,cntq)cend(ans[i]);
}

int main(){
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	sol();
	system("pause");
	return 0;
}