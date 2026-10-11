#include<bits/stdc++.h>
#define rep(i,x) for(int i=0;i<(x);i++)
#define rep1n(i,x) for(int i=1;i<=(x);i++)
#define ll long long
#define csp(x) cout<<x<<" "
#define cendl cout<<endl
#define cend(x) cout<<x<<endl
using namespace std;

ll n,q;
ll a[200500];
ll tree[800500];

void build(ll o, ll l, ll r){
    if(l == r){
        tree[o] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1 | 1, mid + 1, r);
    tree[o] = tree[o << 1] + tree[o << 1 | 1];
}
void maintain(ll o){
    tree[o] = tree[o << 1] + tree[o << 1 | 1];
}
void update(ll o, ll l, ll r, ll pos, ll val){
    if(l == r){
        tree[o] = val;
        return;
    }
    ll mid = (l + r) >> 1;
    if(pos <= mid) update(o << 1, l, mid, pos, val);
    else update(o << 1 | 1, mid + 1, r, pos, val);
    maintain(o);
}
ll query(ll o, ll l, ll r, ll L, ll R){
    if(l >= L && r <= R){
        return tree[o];
    }
    if(r < L || l > R) {
        return 0;
    }
    ll mid = (l + r) >> 1;
    ll ans = 0;
    ans += query(o << 1, l, mid, L, R);
    ans += query(o << 1 | 1, mid + 1, r, L, R);
    return ans;
}

ll x, y;
void sol(){
    cin>>n>>q;
    rep1n(i,n){
        cin>>a[i];
    }
    build(1,1,n);
    rep1n(i,q){
        ll op;cin>>op;
        if(op == 1){
            cin>>x>>y;
            update(1,1,n,x,y);
        }
        else{
            cin>>x>>y;
            ll ans = query(1,1,n,x,y);
            cend(ans);
        }
    }
}
int main(){
    sol();
}