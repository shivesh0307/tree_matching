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
ll dp[200000+1][2];
 
ll calc(ll node , ll used , ll par)
{
    if(dp[node][used]!=-1) return dp[node][used];
    if(adj[node].size()==0) return 0; 
    ll ans=0; 
    if(!used)
    {
        ll ans1=0;
        for(ll v:adj[node])
        {
            if(v==par) continue;
            ll temp=calc(v,0,node);
            ans1+=temp;
        }
        for(ll v:adj[node])
        {
            if(v==par) continue;
            //use 1 and unuse other
            ans=max(ans,1+calc(v,1,node)+ans1-calc(v,0,node));
        }
        dp[node][used]=max(ans,ans1); return dp[node][used];
    }
    for(ll v:adj[node])
    {
        if(v==par) continue;
            ans+=calc(v,0,node);
    }
    dp[node][used]=ans; return ans;
    
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
     memset(dp,-1,sizeof(dp));
    ll mx=0; 
    for(i=1;i<n+1;i++)
    {
        mx=max(mx,max(calc(i,0,-1),calc(i,1,-1)));
    }
    cout<<mx;
    
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