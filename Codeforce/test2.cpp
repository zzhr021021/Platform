#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

#define ll long long
#define rep(i,n) for(int i = 0;i < n;i++)
#define rep1n(i,n) for(int i = 1;i <= n;i++)
#define cend(n) cout << n << endl

const ll N = 100000;
const ll NP = 100005;
const ll inf = 1e18;

bool isprime[NP];
ll minprime[NP];
ll primes[NP];
ll pp = 0;
void preprocess_prime(){
	for(int i = 2;i <= N;i++){
		isprime[i] = true;
		minprime[i] = inf;
	}
	for(int i = 2;i <= N;i++){
		if(isprime[i]){
			minprime[i] = i;
			for(int j = 2 * i;j <= N;j += i){
				minprime[j] = min(minprime[j], (ll)i);
				isprime[j] = false;
			}
			primes[pp] = i;
			pp++;
		}
	}
}

ll eulerArr[NP];
void preprocess_euler(){
	eulerArr[1] = 1;
	for(int i = 2;i <= N;i++){
		ll tp = minprime[i];
		if(i % (tp * tp) == 0)eulerArr[i] = eulerArr[i / tp] * tp;
		else eulerArr[i] = eulerArr[i / tp] * (tp - 1);
	}
}

ll quick_power_mod(ll x, ll y, ll m){
	ll ret = 1;
	if(y == 0)return 1;
	if(y & 1)ret = x;
	ll tp = quick_power_mod(x, y / 2, m);
	ret = (ret * tp) % m;
	ret = (ret * tp) % m;
	return ret;
}

ll getEuler(ll x){
	if(x <= N)return eulerArr[x];
	for(int j = 0;j < pp;j++){
		int i = primes[j];
		if(x % i == 0){
			if(x % (i * i) == 0)return getEuler(x / i) * i;
			else return getEuler(x / i) * (i - 1);
		}
	}
	return x - 1;
}

int main(){
	preprocess_prime();
	preprocess_euler();
	ll icase = 0;
	while(true){
		icase++;
		
		ll n;cin>>n;


		if(n == 0)return 0;
		cout << "Case " << icase << ": ";
		ll d = __gcd(n, (ll)8);

		if(__gcd((ll)10, 9 * n / d) != 1){
			cout << 0 << endl;
			continue;
		}

		ll theEuler = getEuler(9 * n / d);
		
		ll ans = inf;
		for(int i = 1;i * i <= theEuler;i++){
			if(theEuler % i == 0){
				ll x;
				x = i;
				if(quick_power_mod(10, x, 9 * n / d) == 1){
					ans = min(ans, (ll)x);
					break;
				}
				x = theEuler / i;
				if(quick_power_mod(10, x, 9 * n / d) == 1){
					ans = min(ans, (ll)x);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}