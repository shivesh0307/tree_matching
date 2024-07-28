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
vil s(MAX, 0);

void dfs(ll node,ll par)
{
    s[node]=1;
    for(ll v: adj[node])
    {
        if(v==par) continue;
        dfs(v,node);
        s[node]+=s[v];
    }
}
ll get_centroid(ll node,ll par)
{
   for(ll v: adj[node])
    {
        if(v==par) continue;
        if(s[v]*2>n)
        {
            return get_centroid(v,node);
        }
        
    }  
    return node;
}

ll solve() {
    ll i, j, x;
    cin >> n;
    ll a, b;
    for (i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 0);

    cout<<get_centroid(1,0);
   
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
