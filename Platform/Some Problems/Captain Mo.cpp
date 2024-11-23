#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

#define ll long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;
ll tt, ttt;
int n,k,m,t,x,y;

inline ll sq(ll x){return x * x;}
ll a[50050];
ll bl = 0;
inline ll ind(ll x){
	return x / bl;
}
inline ll ghs(ll l, ll r){
	return l * 1e9 + r;
}
struct que{
	ll l, r, id;
}ques[50050];
inline bool cmp(const que & u, const que & v){
	return u.r < v.r;
}
vector<que> llist[250];
ll ans[50050];
ll rec[50050];

// Luogu P1494
// blocking the queries
void sol(){
	scanf("%d%d", &n, &m);
	bl = n / sqrt(m * 2 / 3);
	// bl = sqrt(n);
	rep(i,n){
		scanf("%d", &a[i]);
	}
	rep(i,m){
		scanf("%d%d", &x, &y);
		x--;y--;
		ques[i].l = x;
		ques[i].r = y;
		ques[i].id = i;
		llist[ind(x)].push_back({x, y, i});
	}
	rep(i,250){
		if(llist[i].size() <= 1)continue;
		sort(all(llist[i]), cmp);
	}
	rep(i,250){
		if(llist[i].size() == 0)continue;
		ll l = 0, r = 0, sm = 1;
		memset(rec, 0, sizeof(rec));
		rec[a[0]] = 1;
		for(que o : llist[i]){
			while(r != o.r){
				r++;
				rec[a[r]]++;
				ll tp = rec[a[r]];
				sm -= sq(tp - 1);
				sm += sq(tp);
			}
			while(l < o.l){
				rec[a[l]]--;
				ll tp = rec[a[l]];
				sm -= sq(tp + 1);
				sm += sq(tp);
				l++;
			}
			while(l != o.l){
				l--;
				rec[a[l]]++;
				ll tp = rec[a[l]];
				sm -= sq(tp - 1);
				sm += sq(tp);
			}
			ans[o.id] = sm;
		}
	}
	rep(i,m){
		ll tp = ans[i];
		ll gap = ques[i].r - ques[i].l + 1;
		if(gap == 1){
			printf("0/1\n");
		}
		else{
			ll u = tp - gap;
			ll d = gap * (gap - 1);
			ll g = __gcd(u, d);
			u /= g;
			d /= g;
			printf("%lld/%lld\n", u, d);
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