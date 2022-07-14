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

void solve(){
	int n, m; cin >> n >> m;
	vt<vt<int>> g(n + 1, vt<int>());
	for(int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	vt<int> par(n + 1, -1);

	auto bfs = [&](int x) {
		par[x] = x;
		queue<int> que;
		que.push(x);
		while(!que.empty()) {
			int cur = que.front();
			que.pop();
			for(auto u: g[cur]) if(par[u] < 0) {
				par[u] = cur;
				que.push(u);
			}
		}
	};
	bfs(1);
	if(par[n] < 0) cout << "IMPOSSIBLE" << '\n';
	else {
		stack<int> ans;
		int cur = n;
		int cnt = 0;
		while(cur != par[cur])
			ans.push(cur),
			cur = par[cur];
		ans.push(cur);
		cout << ans.size() << '\n';
		while(!ans.empty()) 
			cout << ans.top() << ' ', ans.pop();
	}
}

int main(){
	fastio();
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}