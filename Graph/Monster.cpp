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
 
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char dir[] = {'D', 'U', 'R', 'L'};
 
void solve() {
	int n, m; cin >> n >> m;
	vector<string> g(n); cin >> g;
 
	vector<vector<bool>> visited(n, vector<bool>(m, false));
 	vector<vector<int>> trace(n, vector<int>(m, 1)); 
 
	function<bool(int, int)> completed = [&] (int x, int y) {
		return x == 0 || y == 0 || x == n - 1 || y == m - 1;
 	};

 	function<bool(int, int)> valid = [&] (int x, int y) {
 		return x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '.';
 	};

 	function<void(int, int)> bfs = [&] (int x, int y) {
 		queue<pii> que;
 		que.push({x, y});
 		while(!que.empty()) {
 			int u = que.front().fi;
 			int v = que.front().se;
 			que.pop();
 			for(int i = 0; i < 4; ++i) {
 				int xx = u + dx[i];
 				int yy = v + dy[i];
 				if(valid(xx, yy) && !visited[xx][yy] && !completed(xx, yy)) {
 					trace[xx][yy] = i;
 					visited[xx][yy] = true;
 					que.push({xx, yy});
 					g[xx][yy] = g[x][y];
 				}
 			} 
 		}
 	};

 	for(int i = 0; i < n; ++i) {
 		for(int j = 0; j < m; ++j) {
 			if(g[i][j] != '.') visited[i][j] = 1;
 		}
 	}

 	for(int i = 0; i < n; ++i) {
 		for(int j = 0; j < m; ++j) {
 			if(g[i][j] == 'M') bfs(i, j);
 		}
 	}
 
 	for(int i = 0; i < n; ++i) {
 		for(int j = 0; j < m; ++j) {
 			if(g[i][j] == 'A') bfs(i, j);
 		}
 	}

 	// for(auto x: g) cerr << x << '\n';
 
 	function<string(int, int)> path = [&] (int x, int y) {
 		string s = "";
 		while(g[x][y] == 'A') {
 			s += dir[trace[x][y]];
 			int i = trace[x][y];
 			x -= dx[i], y -= dy[i];
 		}
 		s.pop_back();
 		reverse(all(s));
 		return s;
 	};
 
 	for(int i = 0; i < n; ++i) {
 		if(visited[i][0] && g[i][0] == 'A') {
 			string sol = path(i, 0);
 			cout << "YES\n" << sol.size() << '\n' << sol << '\n';
 			return;
 		}
 		if(visited[i][m - 1] && g[i][m - 1] == 'A') {
 			string sol = path(i, m - 1);
 			cout << "YES\n" << sol.size() << '\n' << sol << '\n';
 			return;
 		}
 	}
 
 	for(int i = 0; i < m; ++i) {
 		if(visited[0][i] && g[0][i] == 'A') {
 			string sol = path(0, i);
 			cout << "YES\n" << sol.size() << '\n' << sol << '\n';
 			return;
 		}
 		if(visited[n - 1][i] && g[n - 1][i] == 'A') {
 			string sol = path(n - 1, i);
 			cout << "YES\n" << sol.size() << '\n' << sol << '\n';
 			return;
 		}
 	}
 
 	cout << "NO" << '\n';
 
}
 
int main() {
	fastio();
	int t = 1; // cin >> t;
	while(t--) solve();
	return 0;
}