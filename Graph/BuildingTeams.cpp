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
	for(int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		g[v].pb(u), g[u].pb(v);
	}
	vt<int> teams(n + 1, 0);

	auto bfs = [&](int x) -> bool {
		teams[x] = 1;
		queue<int> que;
		que.push(x);
		while(!que.empty()) {
			int cur = que.front();
			que.pop();
			for(auto x: g[cur]) {
				if(teams[x] != 0) {
					if(teams[x] == teams[cur]) 
						return false;
				} else 
					teams[x] = 3 - teams[cur], 
					que.push(x);
			}
		}
		return true;
	};

	for(int i = 1; i <= n; ++i) 
		if(!teams[i] && !bfs(i)) {
			cout << "IMPOSSIBLE" << '\n';
			return;
		}

	for(int i = 1; i <= n; ++i)
		cout << teams[i] << ' ';
	cout << '\n';
}

int main(){
	fastio();
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}