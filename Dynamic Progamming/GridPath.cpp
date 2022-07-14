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
	int n; cin >> n;
	vt<string> s(n);
	cin.ignore() >> s;
	vt<vt<int>> dp(n, vt<int>(n, 0));
	if(n == 1) {
		cout << (s[0][0] == '*' ? 0 : 1) << '\n';
		return;
	}
	dp[0][0] = 1;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(s[i][j] == '*') continue;
			if(i > 0 && s[i - 1][j] != '*') (dp[i][j] += dp[i - 1][j]) %= MOD;
			if(j > 0 && s[i][j - 1] != '*') (dp[i][j] += dp[i][j - 1]) %= MOD;
		}
	}
	cout << dp[n - 1][n - 1] << '\n';
}

int main(){
	fastio();
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}