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
#define MAX 200000+1 

ll n, m, k, q;
vil adj[MAX];
vil subs(MAX, 0);
vil val(MAX, 0);
vil ind(MAX, 0);
vil tree(4*MAX, 0);
vil lazy(4*MAX, 0);
ll timer = 0;
vil arr(MAX, 0);

void build_segment_tree(vector<ll> &arr, int ss, int se, int si) {
    if (ss > se) return;

    if (ss == se) {
        tree[si] = arr[ss];
        return;
    }

    int mid = (ss + se) / 2;
    build_segment_tree(arr, ss, mid, si * 2 + 1);
    build_segment_tree(arr, mid + 1, se, si * 2 + 2);

    tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}

void update(int si, int ss, int se, int us, int ue, int diff) {
    if (lazy[si] != 0) {
        tree[si] += (se - ss + 1) * lazy[si];

        if (ss != se) {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }

        lazy[si] = 0;
    }

    if (ss > se || ss > ue || se < us)
        return;

    if (ss >= us && se <= ue) {
        tree[si] += (se - ss + 1) * diff;

        if (ss != se) {
            lazy[si * 2 + 1] += diff;
            lazy[si * 2 + 2] += diff;
        }

        return;
    }

    int mid = (ss + se) / 2;
    update(si * 2 + 1, ss, mid, us, ue, diff);
    update(si * 2 + 2, mid + 1, se, us, ue, diff);

    tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}

ll get(int ss, int se, int qs, int qe, int si) {
    if (lazy[si] != 0) {
        tree[si] += (se - ss + 1) * lazy[si];

        if (ss != se) {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }

        lazy[si] = 0;
    }

    if (ss > se || ss > qe || se < qs)
        return 0;

    if (ss >= qs && se <= qe)
        return tree[si];

    int mid = (ss + se) / 2;
    return get(ss, mid, qs, qe, 2 * si + 1) + get(mid + 1, se, qs, qe, 2 * si + 2);
}

void dfs(ll node, ll par) {
    subs[node] = 1;
    arr[timer] = val[node];
    ind[node] = timer;
    if(par>0)
    arr[ind[node]]+=arr[ind[par]];
    timer++;
    for (ll v : adj[node]) {
        if (v == par) continue;
        dfs(v, node);
        subs[node] += subs[v];
    }
}

ll solve() {
    ll i, j, x;
    cin >> n >> q;
    ll a, b;
    for (i = 1; i <= n; i++) cin >> val[i];
    for (i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 0);
    //for(i=0;i<timer;i++) cout<<arr[i]<<" ";
    //cout<<endl;
    build_segment_tree(arr, 0, n - 1, 0);
    while (q--) {
        ll t; cin >> t;
        if (t == 1) {
            ll s, x;
            cin >> s >> x;
            update(0, 0, n - 1, ind[s], ind[s]+subs[s]-1, x - val[s]);
            val[s] = x; // update the value to the new one
        } else {
            ll s; cin >> s;
            cout << get(0, n - 1, ind[s], ind[s], 0) << endl;
        }
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
