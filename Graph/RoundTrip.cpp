#include <bits/stdc++.h>

using namespace std;

#define init(file_name) freopen(filename.in, "r", stdin); freopen(filename.out, "w", stdout)
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(a) a.begin(), a.end()

#define ll long long
#define vt vector
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define db double

const ll MaxN = 1e5 + 5;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const db eps = 1e-5;
const db pi = acos(-1);

#ifndef _DSU_
#define _DSU_
 
class DSU{
	vt<int> par;
public:
	DSU(int n){
		par.resize(n + 1, -1);
	}

	int find(int node){
		if(par[node] < 0) return node;
		return par[node] = find(par[node]);
	}

	bool merge(int u, int v){
		/*merge by size*/
		u = find(u), v = find(v);
		if(u == v) return false;
		if(par[u] > par[v]) swap(u, v);
		par[u] += par[v];
		par[v] = u;
		return true;
	}
};
 
#endif

template <class T> std::istream &operator >> (std::istream &s, std::vector<T> &a){
	for(T &x: a) s >> x;
	return s;
}

template <class T> std::ostream &operator << (std::ostream &s, std::vector<T> &a){
	for(T &x: a) s << x << ' ';
	return s;
}

void solve() {
	int n, m; cin >> n >> m;
	DSU dsu(n);
	vt<vt<int>> g(n + 1, vt<int>());
	int start, end;
	start = end = -1;
	for(int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		
		if(dsu.find(u) == dsu.find(v)) 
			start = u, end = v;

		dsu.merge(u, v);
		g[u].pb(v), g[v].pb(u);
	}

	if(start == -1) {
		cout << "IMPOSSIBLE" << '\n';
	} else {
		vt<int> par(n + 1, 0);
		
		function<void(int)> dfs = [&](int x) {
			for(int u: g[x]) {
				if(par[u] == 0) 
					par[u] = x,
					dfs(u); 
			}
		};

		par[start] = start;
		dfs(start);
		start = end;
		vt<int> res;
		while(end != par[end]) res.push_back(end), end = par[end];
		res.push_back(end), res.push_back(start);
		cout << res.size() << '\n';
		cout << res << '\n';
	}

}

int main(){
	fastio();
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}