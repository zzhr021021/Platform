#include<bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (ll i = 1; i <= (n); ++i)

#define ll int
#define vll vector<long long>
#define vb vector<bool>

#define ctest cout << "test  "
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
using namespace std;
ll tt, ttt;
ll n,k,m,t,x,y,z,h,q,d,s;

// value PST
// 权值可持久化线段树实现，离散化后可以静态查询区间第K小
struct PersistentSegTree{
    struct Node{
        ll l, r, sum, pl, pr;
    };
    ll n;
    ll tree_size = 0;
    ll version_count = 0;
    vector<Node> tree;
    vll verpos;
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
            tree[treepos].sum = 0;
        }
        return treepos;
    }
    void build_tree(){
        build_node(1, n);
        verpos[0] = 1;
    }
    PersistentSegTree(int n) : n(n){
        tree.resize(30 * n + 5);
        verpos.resize(n + 5);
        PersistentSegTree::build_tree();
    }
    void update_version(ll l, ll r, ll pos, ll val){
        version_count++;
        ll node = verpos[version_count - 1];
        ll tp = update_node(node, l, r, pos, val);
        verpos[version_count] = tp;
    }
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
    // choose the right version
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
    // kth
    ll get_segment_kth_node(ll posl, ll posr, ll k){
        if(tree[posl].l == tree[posl].r){
            return tree[posl].r;
        }
        ll tp = tree[tree[posr].pl].sum - tree[tree[posl].pl].sum;

        if(tp >= k){
            return get_segment_kth_node(tree[posl].pl, tree[posr].pl, k);
        }
        else{
            return get_segment_kth_node(tree[posl].pr, tree[posr].pr, k - tp);
        }
    }
    ll get_segment_kth(ll l, ll r, ll k){
        ll posl = verpos[l - 1];
        ll posr = verpos[r];
        return get_segment_kth_node(posl, posr, k);
    }
};

ll a[200500];
ll b[200500];

map<ll, ll> inj;
ll jni[200500];

void sol(){
    cin>>n>>m;
    set<ll> st;
    ll cnt = 0;
    rep1n(i,n){
        a[i] = 0;
        cin>>b[i];
        st.insert(b[i]);
    }
    for(auto o : st){
        cnt++;
        inj[o] = cnt;
        jni[cnt] = o;
    }

    PersistentSegTree pst(n);
    pst.build_tree();
    rep1n(i,n){
        ll pos = inj[b[i]];
        a[pos]++;
        pst.update_version(1, n, pos, a[pos]);
    }

    rep1n(ii,m){
        cin>>x>>y>>z;
        cend(jni[pst.get_segment_kth(x, y, z)]);
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