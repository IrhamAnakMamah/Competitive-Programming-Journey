#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<ll>> edges;
vector<ll> d;
vector<bool> vis;
vector<ll> p,sz;

class dsu{
public:
    dsu(ll n){
        p.resize(n+1, 0);
        sz.resize(n+1, 0);
        for(ll i = 1; i<=n; i++){
            p[i] = i;
            sz[i] = 1;
        }
    }

    ll find(ll u){
        if(p[u] == u){
            return u;
        }
        return p[u] = find(p[u]);
    }

    void unite(ll u, ll v){
        ll x = find(u);
        ll y = find(v);
        if(x == y) return;
        if(sz[x] < sz[y]){
            swap(x,y);
        }
        sz[x] += sz[y];
        p[y] = x;
    }
};

ll dfs(ll i){
    vis[i] = 1;
    ll ans = 1;
    for(auto x : edges[i]){
        if(!vis[x]){
            ans += dfs(x);
        }
    }
    d[i] = ans;
    return d[i];
}

void dfs2(ll i){
    vis[i] = 1;
    for(auto x : edges[i]){
        if(!vis[x]){
            dfs2(x);
        }else{
            d[i] = max(d[x], d[i]);
        }
    }
}

int main(){
    ll n,m,k;
    cin >> n >> m >> k;

    vector<ll> a(n+1, 0);
    vector<ll> b(k+1, 0);
    for(ll i = 1; i<=n ; i++){
        cin >> a[i];
    }
    for(ll i = 1; i<=k ; i++){
        cin >> b[i];
    }
    edges.resize(n+1);
    d.resize(n+1, 0);
    dsu dsu(n);
    for(ll i = 0; i<m; i++){
        ll x,y;
        cin >> x >> y;
        dsu.unite(x,y);
        edges[x].push_back(y);
    }
    vis.resize(n+1, 0);
    for(ll i = 1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    
    vis.clear();
    vis.resize(n+1, 0);
    for(ll i = 1; i<=n; i++){
        if(!vis[i]){
            dfs2(i);
        }
    }
    ll ans = 0;
    
    vis.clear();
    vis.resize(n+1, 0);
    vector<pair<ll,ll>> v(n+1, {0,0}); // parent, sz
    ll comp = 0;
    for(ll i = 1; i<=n ; i++){
        ll idx = dsu.find(i);
        if(!vis[idx]){
            vis[idx] = 1;
            v[idx] = {a[i], i};
            comp++;
        }else{
            auto [x,y] = v[idx];
            if(d[i] == d[y]){
                if(a[i] < x){
                    v[idx] = {a[i], i};
                }
            }else if(d[i] > d[y]){
                v[idx] = {a[i], i};
            }
        }
    }
    sort(v.begin(), v.end(), greater<>());
    for(auto [x,y] : v){
      cout << x << " " << y << endl;
    }
    sort(b.begin(), b.end());
    if(comp > k){
        cout << -1 << endl;
        return 0;
    }
    for(ll i = 0; i<comp; i++){
        ans += v[i].first * b[i+1];
    }
    cout << ans << endl;
}