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
	vt<int> a(n); cin >> a;
	sort(all(a));
	vt<vt<int>> dp(n, vt<int>(m + 1, 0));
	for(int iter = 0; iter <= m; dp[0][iter] = 1, iter += a[0]);
	for(int i = 1; i < n; ++i) {
		for(int j = 0; j <= m; ++j) {
			(dp[i][j] += dp[i - 1][j]) %= MOD;
			if(j - a[i] >= 0) (dp[i][j] += dp[i][j - a[i]]) %= MOD;
		}
	}
	cout << dp[n - 1][m] << '\n';
}

int main(){
	fastio();
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}