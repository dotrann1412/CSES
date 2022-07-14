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

template <class T> std::istream &operator >> (std::istream &s, std::vector<T> &a){
	for(T &x: a) s >> x;
	return s;
}

template <class T> std::ostream &operator << (std::ostream &s, std::vector<T> &a){
	for(T &x: a) s << x << ' ';
	return s;
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void solve(){
	int n, m; cin >> n >> m;
	vector<string> g(n); cin.ignore() >> g;
	int ans = 0;

	auto isvalid_idx = [&](int x, int y) -> bool {
		return x < n && x >= 0 && y < m && y >= 0;
	};

	auto bfs = [&](int x, int y) {
		queue<pii> que;
		que.push({x, y});
		while(!que.empty()) {
			pii cur = que.front();
			que.pop();
			for(int i = 0; i < 4; ++i) {
				if(isvalid_idx(cur.fi + dx[i], cur.se + dy[i]) 
					&& g[cur.fi + dx[i]][cur.se + dy[i]] == '.') {
					g[cur.fi + dx[i]][cur.se + dy[i]] = '#';
					que.push({cur.fi + dx[i], cur.se + dy[i]});
				}
			}
		}
	};

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(g[i][j] == '.') 
				g[i][j] = '#', bfs(i, j), ++ans;
		}
	}
	cout << ans << '\n';
}

int main(){
	fastio();
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}