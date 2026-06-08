#include<bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define replr(i, l, r) for (int i = l;i <= r;i++)
#define repij(i, j, n, m) for (int i = 0; i < (n); ++i) for (int j = 0; j < (m); ++j)

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
#define bob cout<<"Bob\n"
#define alice cout<<"Alice\n"
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define cgap cout << "--------------------" << endl
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#define alice cout<<"Alice\n"
#define bob cout<<"Bob\n"
#define draw cout<<"Draw\n"

#define M_PI 3.14159265358979323846

const ll MOD = 1e9 + 7;
const ll MODD = 1e9 + 9;
const ll MOOD = 998244353;
ll p = 676767677;
const ll inf = 1e18;
const ll INF = 1e18;
const ll N = 200500;
// ll dix[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
// ll diy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
using namespace std;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
void ckmax(ll & x, ll y){
    if(y > x)x = y;
}
void ckmin(ll & x, ll y){
    if(y < x)x = y;
}
void printvec(vll & v){
    for(auto o : v){
        csp(o);
    }
    cendl;
}
ll tt, ttt;
ll n,k,m,t,x,y,z,h,q,d,s;

ll a[500500];
ll b[500500];
void md(ll & x){
    x = (x + p) % p;
}

ll ladder(ll x){
    return (1 + x) * x / 2;
}
ll ladder(ll x, ll y){
    return (x + y) * (y - x + 1) / 2;
}
ll sq(ll x){
    return x * x;
}
ll qpow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y&1) ans = ans * x % p;
        x = x * x % p,y>>=1;
    }
    return ans;
}


void sol(){
    cin>>n;
    multiset<ll> ost;
    multiset<ll> st;
    // omp[-inf] = mp[-inf] = 1;
    // omp[inf] = mp[inf] = 1;
    rep1n(i,n){
        cin>>a[i];
        ost.insert(a[i]);
    }

    ll l = 0, r = n - 1;
    while(l < r){
        ll mid = (l + r + 1) >> 1;
        ll fl = true;

        st.clear();
        for(auto o : ost){
            st.insert(o);
        }
        for(int i = mid;i > 0;i--){
            if(st.find(i) != st.end()){
                st.erase(st.find(i));
            }
            else{
                // get max key in st
                auto it = st.end();
                it--;
                if((*it) >= i * 2 + 1){
                    st.erase(it);
                }
                else{
                    fl = false;
                    break;
                }
            }
        }
        if(fl){
            l = mid;
        }
        else{
            r = mid - 1;
        }

    }
    cend(l + 1);

}

ll tnt(){
    while(1){
    }
    return 0;
}
int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);

    tt = 1;
    cin>>tt;
    for(ttt = 1;ttt <= tt;ttt++){
        sol();
    }
    system("pause");
    return 0;
}