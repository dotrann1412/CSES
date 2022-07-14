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
const ll INF = 3e15;
const ll MOD = 1e9 + 7;
const db eps = 1e-5;
const db pi = acos(-1);

template <class T> 
std::istream &operator >> (std::istream &s, std::vector<T> &a) {
	for(T &x: a) s >> x;
	return s;
}

template <class T> 
std::ostream &operator << (std::ostream &s, const std::vector<T> &a) {
	for(const T &x: a) s << x << ' ';
	return s;
}

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<pii>> g(n, vector<pii>());
	for (int i = 0, x, y, c; i < m; ++i) {
		cin >> x >> y >> c, --x, --y;
		g[x].pb({y, c});
	}

	vector<ll> path(n, INF);
	queue<int> que;
	que.push(0), path[0] = 0;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		for (auto x: g[cur]) {
			if (path[x.fi] > path[cur] + x.se) {
				que.push(x.fi), path[x.fi] = path[cur] + x.se;
			}
		}
	}

	cout << path << '\n';
}

int main() {
	fastio();
	int t = 1; // cin >> t;
	double start = clock();
	while(t--) solve();
	cerr << "Time execution: " << fixed << setprecision(6) << 1.0 * (clock() - start) / 1000 << " (s)\n";	
	return 0;
}