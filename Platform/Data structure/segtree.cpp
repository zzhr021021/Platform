#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)

#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#define ll long long

using namespace std;

const ll inf = 1e18;

ll n,q,x,y;
ll a[50050];

struct quadple{
    ll sm, m, l, r;
}segs[200050];

quadple get(quadple l, quadple r){
    quadple ret;
    ret.sm = l.sm + r.sm;
    ret.m = max(l.m, r.m);
    ret.m = max(ret.m, l.r + r.l);
    ret.l = max(l.l, l.sm + r.l);
    ret.r = max(r.r, r.sm + l.r);
    return ret;
}

void maintain(ll o){
    segs[o] = get(segs[o << 1], segs[o << 1 | 1]);
}
void add(ll o, ll l, ll r, ll pos, ll val){
    if(pos < l || pos > r)return;
    if(l == r){
        segs[o].sm += val;
        segs[o].l = segs[o].r = segs[o].m = segs[o].sm;
    }
    else{
        ll mid = (l + r) / 2;
        add(o << 1, l, mid, pos, val);
        add(o << 1 | 1, mid + 1, r, pos, val);
        maintain(o);
    }
}
quadple query(ll o, ll l, ll r, ll L, ll R){
    if(R < l || L > r)return {0, -inf, -inf, -inf};
    if(l >= L && r <= R){
        return segs[o];
    }
    ll mid = (l + r) / 2;
    quadple lseg = query(o << 1, l, mid, L, R);
    quadple rseg = query(o << 1 | 1, mid + 1, r, L, R);
    quadple ret = get(lseg, rseg);
    return ret;
}


int main(int argc, char const *argv[])
{
    cin>>n;
    rep(i,n){
        cin>>a[i];
        add(1, 0, n - 1, i, a[i]);
    }
    cin>>q;
    rep(iq, q){
        ll op;cin>>op;
        cin>>x>>y;
        if(op == 0){
            x--;
            quadple tp = query(1, 0, n - 1, x, x);
            add(1, 0, n - 1, x, y - tp.sm);
        }
        else{
            x--;y--;
            quadple ans = query(1, 0, n - 1, x, y);
            cend(ans.m);
        }
    }
    system("pause");
    return 0;
}
