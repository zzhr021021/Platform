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

const ll MOD = 1e9 + 7;
const ll MODD = 1e9 + 9;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
using namespace std;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

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

void build(ll o, ll l, ll r){
    if(l == r){
        frontline[o].push_back(0);
    }
    else{
        ll mid = (l + r) / 2;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid + 1, r);
        merge(all(frontline[o << 1]), all(frontline[o << 1 | 1]), back_inserter(frontline[o]));
        while(frontline[o].size() > MX){
            frontline[o].pop_back();
        }
    }
}
void maintain(ll o){
    frontline[o].clear();
    merge(all(frontline[o << 1]), all(frontline[o << 1 | 1]), back_inserter(frontline[o]));
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
	merge(all(rl), all(rr), back_inserter(ret));
    while(ret.size() > MX){
        ret.pop_back();
    }
	return ret;
}

ll q2(ll l, ll r){
	ll ret = -1;
	for(int i = l;i <= r;i++){
		for(int j = l;j < i;j++){
			if((a[i] & a[j]) > ret){
				ret = a[i] & a[j];
			}
		}
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
        ll op;;
		op = rnd() % 2 + 1;
        ll l, r, x;
        if(op == 1){
            // cin>>l>>r>>x;
			l = rnd() % n;
			r = rnd() % n;
			x = rnd() % 10;
			csp(l);csp(r);cendl;
			if(l > r)swap(l, r);
            add(1, 0, n - 1, l, r, x);
			for(int i = l;i <= r;i++){
				a[i] += x;
			}
        }
        else{
            l = rnd() % n;
			r = rnd() % n;
			x = rnd() % 1000000;
			x = llabs(x);
			csp(l);csp(r);csp(x);cendl;
			if(l > r)swap(l, r);
            vll thevec = query(1, 0, n - 1, l, r);
            
            cend(ask(thevec));

			ll ans = q2(l, r);
			cend(ans);
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