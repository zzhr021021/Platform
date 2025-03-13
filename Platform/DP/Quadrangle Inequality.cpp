#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define replr(i, l, r) for (int i = l;i <= r;i++)

#define ll long long
#define ld long double
#define ull unsigned long long
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define vpl vector<pair<long long, long long>>

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define cgap cout << "--------------------" << endl

const ll N = 100500;
using namespace std;

ll tt, ttt;
ll n,k,m,t,x,y,z,h,s;
ll L,P;
string poem[100500];
ll a[100500];
ld sum[100500];
ld dp[100500];
ll dpwh[100500];
ld qpow(ld x, ll y){
    if(y == 0)return 1;
    ld ret = 1;
    if(y & 1)ret = x;
    ld hlf = qpow(x, y / 2);
    return ret * hlf * hlf;
}
ld getv(ll i, ll j){
    return qpow(fabs(sum[i] - sum[j] + (i - j - 1) - L), P);
}
struct node{
    ll wh, l, r;
};
// quadrangle inequality
// Luogu P1912
void sol(){
    cin>>n>>L>>P;
    rep1n(i,n){
        cin>>poem[i];
        a[i] = poem[i].length();
        sum[i] = sum[i - 1] + a[i];
        dp[i] = 0;
    }
    vpl ans;
    deque<node> dq;
    dq.push_back({0, 1, n});
    rep1n(i,n){
		// get rid of front item
        while(dq.size() >= 2 && dq.front().r < i){
            dq.pop_front();
        }
        // set dp
        ll wh = dq.front().wh;
        dpwh[i] = wh;
        dp[i] = dp[wh] + getv(i, wh);
        // renew back item
        ll tpos = n + 1;
        while(dq.size() && dp[i] + getv(dq.back().l, i) <= dp[dq.back().wh] + getv(dq.back().l, dq.back().wh)){
            tpos = dq.back().l;
            dq.pop_back();
        }
        if(dq.size() == 0){
			dq.push_back({i, i + 1, n});
        }
        else{
            ll l = dq.back().l;
            ll r = dq.back().r;
			ll res = r + 1;
            while(l <= r){
                ll mid = (l + r) / 2;
                if(dp[i] + getv(mid, i) > dp[dq.back().wh] + getv(mid, dq.back().wh)){
                    l = mid + 1;
                }
                else{
					res = mid;
                    r = mid - 1;
                }
            }
			dq.back().r = res - 1;
			if(res <= n){
				dq.push_back({i, res, n});
			}
        }
    }

    if(dp[n] > 1e18){
        cend("Too hard to arrange");;
    }
    else{
        cend((ll)dp[n]);
        deque<ll> tp;
        ll cur = n;
        while(cur != 0){
            tp.push_front(cur);
            cur = dpwh[cur];
        }
        ll la = 1;
        while(tp.size()){
            for(int i = la;i <= tp.front();i++){
                if(i != tp.front())csp(poem[i]);
                else cend(poem[i]);
            }
            la = tp.front() + 1;
            tp.pop_front();
        }
    }
    cgap;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	tt = 1;
	cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	system("pause");
	return 0;
}