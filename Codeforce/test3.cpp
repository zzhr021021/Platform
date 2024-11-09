#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<map>

#define ll long long
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;

ll qpow(ll x, ll y){
	if(y == 0)return 1;
	ll ret = 1;
	if(y & 1)ret = x;
	ll tp = qpow(x, y / 2);
	ret *= tp * tp;
	return ret;
}

bool is_prime(ll x){
	for(int i = 2;i * i <= x;i++){
		if(x % i == 0)return false;
	}
	return true;
}

map<ll, ll> prime_representation;
ll eulerval = 1;
void decomposition(ll x){
	for(int i = 2;i < (1 << 16);i++){
		ll cnt = 0;
		while(x % i == 0){
			prime_representation[i]++;
			x /= i;
			cnt++;
		}
		if(cnt == 1)eulerval *= i - 1;
		else if(cnt > 1)eulerval *= i;
	}
	if(x != 1){
		prime_representation[x]++;
		eulerval *= x - 1;
	}
}


int main(){
	ll n;
	cin>>n;
	if(is_prime(n)){
		cout << 2 * n - 1 << endl;
	}
	else{
		decomposition(n);
		ll ans = 1;
		for(auto o : prime_representation){
			ans *= (qpow(o.first, o.second + 1) - 1) / (o.first - 1);
		}
		ans -= 1;
		ans += eulerval;
		cout << ans << endl;
	}
	system("pause");
	return 0;
}