#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define rep1nr(i, n) for (int i = (n); i >= 1; --i)
#define rep01n(i, n) for (int i = 0; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)

#define pll pair<ll, ll>

#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>

#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define csp(n) cout << n << " "
#define cend(n) cout << n << endl
#define cendl cout << endl
#define ctest cout << "test   "
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
#define alice cout<<"Alice\n"
#define bob cout<<"Bob\n"
#define draw cout<<"Draw\n"
 
typedef long long int ll;
const ll MOD = 1e9+7;
const ll MODD = 1e9+9;
const ll MOOD = 998244353;
ll p = MOD;
const ll inf = 1e18;
const ll INF = 1e18; 
const int N = 200005;
using namespace std;
 
ll tt;
ll ttt;
ll n,k,m,d,q,t,x,y,z,h;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

void printvec(vector<ll> & v){
	for(ll &x : v){
		cout << x << " ";
	}
	cendl;
}


ll a[500005];
ll b[200005];

ll qpow(ll x, ll y)
{
    ll ans = 1;
    while(y)
    {
        if(y&1) ans = ans * x % p;
        x = x * x % p,y >>= 1;
    }
    return ans;
}

// Given an array where each element is a vector containing integers in sorted order.
// Count the numbers smaller than or equal to k in range from array index 'start' to 'end'.
// Constructs a segment tree and stores sTree[]
void buildTree(int idx, int ss, int se, vector<int> a[], vector<int> sTree[]){
    /*leaf node*/
    if (ss == se) {
        sTree[idx] = a[ss];
        return;
    }
    int mid = (ss + se) / 2;

    buildTree(2 * idx + 1, ss, mid, a, sTree);
    buildTree(2 * idx + 2, mid + 1, se, a, sTree);
 
    /* merging left and right child in sorted order */
    merge(sTree[2 * idx + 1].begin(),
          sTree[2 * idx + 1].end(),
          sTree[2 * idx + 2].begin(),
          sTree[2 * idx + 2].end(),
          back_inserter(sTree[idx]));
}

// Recursive function to count smaller elements from row
// a[ss] to a[se] and value smaller than or equal to k.
int queryRec(int node, int start, int end, int ss, int se, int k, vector<int> a[], vector<int> sTree[]){
    /* If out of range return 0 */
    if (ss > end || start > se)
        return 0;
 
    /* if inside the range return count */
    if (ss <= start && se >= end) {
        /* binary search over the sorted vector
        to return count >= X */
        return upper_bound(sTree[node].begin(), sTree[node].end(), k) - sTree[node].begin();
    }
 
    int mid = (start + end) / 2;

    int p1 = queryRec(2 * node + 1, start, mid, ss, se, k, a, sTree);
    int p2 = queryRec(2 * node + 2, mid + 1, end, ss, se, k, a, sTree);
 
    /*adding both the result*/
    return p1 + p2;
}
 
// A wrapper over query().
int query(int start, int end, int k, vector<int> a[], int n, vector<int> sTree[]){
    return queryRec(0, 0, n - 1, start, end, k, a, sTree);
}

void sol(){
	n = 3;
    int arr[][3]
        = { { 2, 4, 5 }, { 3, 4, 9 }, { 6, 8, 10 } };
 
    // build an array of vectors from above input
    vector<int> a[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i].push_back(arr[i][j]);
 
    // Construct segment tree
    vector<int> sTree[1000];
    buildTree(0, 0, n - 1, a, sTree);
 
    /* un-comment to print merge sort tree*/
    for (int i = 0;i < 2 * n - 1;i++){
            cout << i << " ";
            for (int j=0;j<sTree[i].size();j++)
            cout << sTree[i][j]<<" ";
            cout << endl;
    }
 
    // Answer queries
    cout << query(0, 1, 5, a, n, sTree) << endl;
    cout << query(1, 2, 1, a, n, sTree) << endl;
    cout << query(0, 2, 6, a, n, sTree) << endl;	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
		
	tt = 1;
//	cin>>tt;
	for(ttt = 1;ttt <= tt;ttt++){
		sol();
	}
	return 0;
}
