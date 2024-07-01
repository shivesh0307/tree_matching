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
 
ll n, m,k,q;
vil adj[200000+1];
ll dp[200000+1][32];
vil depth(200000+1,0);
ll lift(ll x, ll k)
{
    ll i=0; 
    while(i<32)
    {
        if(k&(1<<i))
        {
            x=dp[x][i];
        }
        i++;
    }
    return x;
}
void dfs(ll node, ll par)
{
    if(par>0)
    depth[node]=1+depth[par];
    dp[node][0]=par;
    for(ll v: adj[node])
    {
        if(v==par) continue;
        dfs(v,node);
    }
}
ll lca(ll n1,ll n2)
{
    if(depth[n1]<depth[n2]) return lca(n2,n1);
    
    n1 = lift(n1,depth[n1]-depth[n2]);
    if(n1==n2)
    {
       return n2;
    }
    
    for(ll i=31;i>=0;i--)
    {
        if(dp[n1][i]!=dp[n2][i])
        {
            n1=dp[n1][i];
            n2=dp[n2][i];
        }
    }
    return dp[n1][0];
    
}
ll solve() {
    ll i, j,x; 
    cin>>n>>q; 
     ll a, b;
     memset(dp,0,sizeof(dp));
    for(i=1;i<=n-1;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    for(j=1;j<32;j++)
    {
    for(i=1;i<n+1;i++)
    {
        dp[i][j]=dp[dp[i][j-1]][j-1];
    }
    }
    while(q--)
    {
        cin>>a>>b;
        ll ans=lca(a,b);
       cout<<depth[a]+depth[b]-2*depth[ans]<<endl;
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