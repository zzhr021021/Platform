#include<bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)

#define ll int
#define vll vector<long long>
#define vb vector<bool>

#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
using namespace std;
ll tt, ttt;
ll n,k,m,t,x,y,z,h,q,d,s;

ll a[1000500];

struct node{
    ll l, r, sum, pl, pr;
};
node tree[23000005];
ll tree_size = 0;
ll verpos[1000005];
ll version_count = 0;

ll build_node(ll l, ll r){
    tree_size += 1;
    ll treepos = tree_size;
    tree[treepos] = {l, r, -1, -1, -1};
    if(l != r){
        ll mid = (l + r) >> 1;
        ll tl = tree[treepos].pl = build_node(l, mid);
        ll tr = tree[treepos].pr = build_node(mid + 1, r);
        tree[treepos].sum = tree[tl].sum + tree[tr].sum;
    }
    else{
        tree[treepos].pl = -1;
        tree[treepos].pr = -1;
        tree[treepos].sum = a[l];
    }
    return treepos;
}
ll build_tree(ll n){
    return build_node(1, n);
}
// node is the replaced node position
ll update_node(ll node, ll l, ll r, ll pos, ll val){
    tree_size += 1;
    ll treepos = tree_size;
    if(l == r){
        tree[treepos] = {l, r, val, -1, -1};
    }
    else{
        tree[treepos] = {l, r, -1, -1, -1};
        ll mid = (l + r) >> 1;
        if(pos <= mid){
            ll tr = tree[treepos].pr = tree[node].pr;
            ll tl = tree[treepos].pl = update_node(tree[node].pl, l, mid, pos, val);
            tree[treepos].sum = tree[tl].sum + tree[tr].sum;
        }
        else{
            ll tl = tree[treepos].pl = tree[node].pl;
            ll tr = tree[treepos].pr = update_node(tree[node].pr, mid + 1, r, pos, val);
            tree[treepos].sum = tree[tl].sum + tree[tr].sum;
        }
    }
    return treepos;
}
// choss the right version
ll single_get(ll node, ll l, ll r, ll pos){
    if(l == r){
        return tree[node].sum;
    }
    ll mid = (l + r) >> 1;
    if(pos <= mid){
        return single_get(tree[node].pl, l, mid, pos);
    }
    else{
        return single_get(tree[node].pr, mid + 1, r, pos);
    }
}


void sol(){
    scanf("%d%d", &n, &m);
    rep1n(i,n){
        scanf("%d", &a[i]);
    }
    verpos[0] = build_tree(n);

    rep(ii,m){
        ll ver, op;
        scanf("%d", &ver);
        scanf("%d", &op);
        if(op == 1){
            scanf("%d", &x);
            scanf("%d", &y);
            version_count += 1;
            verpos[version_count] = update_node(verpos[ver], 1, n, x, y);
        }
        else{
            scanf("%d", &x);
            ll tp = single_get(verpos[ver], 1, n, x);
            printf("%d\n", tp);
            version_count += 1;
            verpos[version_count] = verpos[ver];
        }
    }
}

int main(){
    tt = 1;
    // cin>>tt;
    for(ttt = 1;ttt <= tt;ttt++){
        sol();
    }
    system("pause");
    return 0;
}