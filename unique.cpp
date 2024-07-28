#include <bits/stdc++.h>
using namespace std;

#define PRIME 1000000007
#define MOD 1000000009
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ll long long int
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define sz(c) c.size()
#define r(i, a, b) for(i = a; i < b; i++)
#define ra(i, a, b) for(i = a; i <= b; i++)
#define vi vector<int>
#define vil vector<ll>
#define MAX 200001 // Corrected the MAX value

ll n, m, k, q;
vil adj[MAX];
vil val(MAX, 0);
vil unq(MAX, 0);
map<ll, ll> cnt;

set<ll> dfs(ll node, ll par) {
    set<ll> curr;
    curr.insert(val[node]);
    for (ll v : adj[node]) {
        if (v == par) continue;
        set<ll> child = dfs(v, node);
        if (child.size() > curr.size()) {
            swap(child, curr);
        }
        for (ll x : child) {
            curr.insert(x);
        }
    }
    unq[node] = curr.size();
    return curr;
}

ll solve() {
    ll i, j, x;
    cin >> n;
    ll a, b;
    for (i = 1; i <= n; i++) cin >> val[i];
    for (i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 0);

    for(i=1;i<=n;i++) cout<<unq[i]<<" ";
   
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
