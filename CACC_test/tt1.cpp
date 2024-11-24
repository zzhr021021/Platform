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
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

const ll MOD = 1e9 + 7;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
using namespace std;
ll ask(vll & v){
    ll ret = -1;
    rep(i,v.size()){
        rep(j,i){
            if((v[i] & v[j]) > ret){
                ret = v[i] & v[j];
            }
        }
    }
    return ret;
}
void printvec(vll & v){
	for(auto o : v){
		csp(o);
	}
	cendl;
}

ll tt, ttt;
ll n,k,m,t,x,y,z,h,q;

ll a[100005];
ll lazy[400050];
vll frontline[400050];
ll MX = 35;

vll mymerge(vll & v, vll & u){
    vll ret;
    ll pv = 0, pu = 0;
    while(pv < v.size() || pu < u.size()){
        if(ret.size() == MX)break;
        if(pv < v.size() && pu < u.size()){
            if(v[pv] > u[pu]){
                ret.push_back(v[pv]);
                pv++;
            }
            else{
                ret.push_back(u[pu]);
                pu++;
            }
        }
        else if(pv < v.size()){
            ret.push_back(v[pv]);
            pv++;
        }
        else{
            ret.push_back(u[pu]);
            pu++;
        }
    }
    return ret;
}

void build(ll o, ll l, ll r){
    if(l == r){
        frontline[o].push_back(0);
    }
    else{
        ll mid = (l + r) / 2;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        frontline[o] = mymerge(frontline[o << 1], frontline[o << 1 | 1]);
        while(frontline[o].size() > MX){
            frontline[o].pop_back();
        }
    }
}
void maintain(ll o){
    frontline[o].clear();
    frontline[o] = mymerge(frontline[o << 1], frontline[o << 1 | 1]);
    while(frontline[o].size() > MX){
        frontline[o].pop_back();
    }
    rep(i,frontline[o].size()){
        frontline[o][i] += lazy[o];
    }
}
void propagate(ll o){
    lazy[o << 1] += lazy[o];
    lazy[o << 1 | 1] += lazy[o];
    rep(i,frontline[o << 1].size()){
        frontline[o << 1][i] += lazy[o];
    }
    rep(i,frontline[o << 1 | 1].size()){
        frontline[o << 1 | 1][i] += lazy[o];
    }
    lazy[o] = 0;
}
void add(ll o, ll l, ll r, ll L, ll R, ll val){
    if(R < l || L > r)return;
	if(l >= L && r <= R){
        rep(i,frontline[o].size()){
            frontline[o][i] += val;
        }
		lazy[o] += val;
		return;
	}
	ll mid = (l + r) / 2;
	add(o << 1, l, mid, L, R, val);
	add(o << 1 | 1, mid + 1, r, L, R, val);
	maintain(o);
}
vll query(ll o, ll l, ll r, ll L, ll R){
    vll ret;
    if(r < L || l > R)return ret;
	if(l >= L && r <= R)return frontline[o];
	propagate(o);
	ll mid = (l + r) / 2;
    vll rl = query(o << 1, l, mid, L, R);
	vll rr = query(o << 1 | 1, mid + 1, r, L, R);
	ret = mymerge(rl, rr);
    while(ret.size() > MX){
        ret.pop_back();
    }
	return ret;
}

void sol(){
	// input 
	cin>>n>>m;
    build(1, 0, n - 1);
	rep(i,n){
		cin>>a[i];
		add(1, 0, n - 1, i, i, a[i]);
	}
    // ctest;
    // rep(i,40){
    //     ctest;cend(i);
    //     cout << "vec is  ";printvec(frontline[i]);
    // }
	rep(iop,m){
        ll op;cin>>op;
        ll l, r, x;
        if(op == 1){
            cin>>l>>r>>x;
            l--;r--;
            add(1, 0, n - 1, l, r, x);
        }
        else{
            cin>>l>>r;
            l--;r--;
            vll thevec = query(1, 0, n - 1, l, r);
            
            cend(ask(thevec));
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