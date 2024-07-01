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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// Define ordered set with PBDS
template<class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
ll n, m,k,a,b;
vil adj[200000+1];
vil dist(200000+1,0);
ll sm=0;
vil ans(200000+1,0);
vil tot(200000+1,0);
void dfs(ll node,ll par, ll h)
{
    dist[node]=h;
    tot[node]++;
    sm+=h;
    for(ll v: adj[node])
    {
        if(v==par) continue;
        dfs(v,node,1+h);
        tot[node]+=tot[v];
    }
}
void dfs2(ll node, ll par, ll sm)
{
    ans[node]=sm-tot[node]+(n-tot[node]);
    for(ll v: adj[node])
    {
        if(v==par) continue;
        dfs2(v,node,ans[node]);
    }
}
ll solve() {
    ll i, j; 
    cin>>n; 
     ll a, b;
    for(i=0;i<n-1;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1,0);
    ans[1]=sm;
    for(ll v: adj[1])
    {
        dfs2(v,1,sm);
    }
    
    for(i=1;i<n+1;i++)
    {
        cout<<ans[i]<<" ";
    }
     
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