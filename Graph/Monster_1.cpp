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

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const char back[] = {'L', 'R', 'U', 'D'};

template <class T, class U>
std::istream &operator >> (std::istream &s, std::pair<T, U> &a) {
	return s >> a.first >> a.second;
}

template <class T, class U>
std::ostream &operator << (std::ostream &s, const std::pair<T, U>& a) {
	return s << a.first << ' ' << a.second;
}

template <class T, class U> 
std::ostream &operator << (std::ostream &s, const std::vector<std::pair<T, U>> &a) {
	for(const std::pair<T, U> &x: a) s << "{" << x << "} ";
	return s;
}

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


void DBG() {
	cerr << "]" << endl;
}

template<class H, class... T> 
void DBG(H h, T... t) {
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}

#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

void solve() {
	int n, m; cin >> n >> m;
	vector<string> g(n); cin >> g;
	vector<vector<int>> trace(n, vector<int>(m, -1)), visited(n, vector<int>(m, 0));
	pii sur = {-1, -1};
	queue<pii> que;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (g[i][j] == 'M') {
				que.push({i, j});
				visited[i][j] = 2;
			}

			if (g[i][j] == 'A') {
				sur = {i, j};
				visited[i][j] = 1;
			}
		}
	}

	que.push(sur);

	while (!que.empty()) {
		pii cur = que.front();
		que.pop();
		int u = cur.fi, v = cur.se;
		for (int i = 0; i < 4; ++i) {
			int x = u + dx[i], y = v + dy[i];
			if (x < 0 || x >= n || y < 0 || y >= m) continue; 
			if(visited[x][y] || g[x][y] != '.') continue;
			trace[x][y] = i, visited[x][y] = visited[u][v];
			que.push({x, y});
		}
	}

	for (auto x: visited) cerr << x << '\n';

	pii start = {-1, -1};
	for (int i = 0; i < n && start == pii(-1, -1); ++i) {
		if (visited[i][0] == 1) start = {i, 0};
		else if(visited[i][m - 1] == 1) start = {i, m - 1};
	}

	for (int i = 0; i < m && start == pii(-1, -1); ++i) {
		if (visited[0][i] == 1) start = {0, i};
		else if(visited[n - 1][i] == 1) start = {n - 1, i};
	}

	if (start == pii(-1, -1)) cout << "NO" << '\n';
	else {
		int x = start.fi, y = start.se;
		string ans = "";
		while (g[x][y] != 'A') {
			ans += back[trace[x][y]];
			int dir = trace[x][y];
			x -= dx[dir];
			y -= dy[dir];
		}
		reverse(all(ans));
		cout << "YES" << '\n' << ans.size() << '\n' << ans << '\n';
	}
}

int main() {
	fastio();
	int t = 1; // cin >> t;
	while(t--) solve();
	return 0;
}