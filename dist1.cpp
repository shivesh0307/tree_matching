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
vil mx1(200000+1,0);
vil mx2(200000+1,0);
vil disttc(200000+1,0);
vil disttp(200000+1,0);
ll dfs(ll node,ll par)
{
     mx1[node]=0; 
     mx2[node]=0;
    multiset<ll> st;
    for(ll v:adj[node])
    {
        if(v==par) continue;
        st.insert(dfs(v,node));
        if(st.size()>2)
        st.erase(st.begin());
    }
    auto it=st.begin();
    if(st.size()==2)
    {
        mx2[node]=1+*it; 
    mx1[node]=1+*(++it);
    }
    else if(st.size()==1)
    {
        mx1[node]=1+*(it);
    }
    return mx1[node];
}
ll finddist(ll node,ll par)
{
    disttc[node]=mx1[node];
     if (par > 0) {
        disttp[node] = 1 + disttp[par];
 
        if (1 + mx1[node] != mx1[par])
            disttp[node] = max(disttp[node], 1 + mx1[par]);
        else
            disttp[node] = max(disttp[node], 1 + mx2[par]);
    }
    for(ll v: adj[node])
    {
        if(v==par) continue;
        finddist(v,node);
    
    }
    return -1;
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
     dfs(1,-1);
     finddist(1,-1);
     for(i=1;i<n+1;i++) cout<<max(disttc[i],disttp[i])<<" ";
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