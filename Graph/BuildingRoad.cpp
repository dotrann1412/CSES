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

	int count() {
		int cnt = 0;
		for(int i = 1; i < par.size(); ++i)
			cnt += par[i] < 0;
		return cnt;
	}

	vector<int> get() {
		vector<int> ans;
		for(int i = 1; i < par.size(); ++i)
			if(par[i] < 0) ans.pb(i);
		return ans;
	}
};
 
#endif

void solve(){
	int n, m; cin >> n >> m;
	DSU dsu(n);
	while(m--) {
		int u, v; cin >> u >> v;
		dsu.merge(u, v);
	}
	auto res = dsu.get();
	cout << res.size() - 1 << '\n';
	for(int i = 1; i < res.size(); ++i)
		cout << res[i] << ' ' << res[0] << '\n';
}

int main(){
	fastio();
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}