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

void solve(){
	int n, m; cin >> n >> m;
	vt<int> a(n), b(n); cin >> a >> b;
	vt<vt<int>> dp(n + 1, vt<int>(m + 1));
	int ans = 0;
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= m; ++j) {
			if(i * j == 0) dp[i][j] = 0;
			else if(a[i - 1] <= j) 
				dp[i][j] = max(dp[i][j], max(b[i - 1] + dp[i - 1][j - a[i - 1]], dp[i - 1][j]));
			else dp[i][j] = dp[i - 1][j];
			ans = max(dp[i][j], ans);
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