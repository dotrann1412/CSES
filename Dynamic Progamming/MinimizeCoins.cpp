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
	vt<int> dp(m + 1, 2 * INF);
	dp[0] = 0;
	sort(all(a));
	for(int i = 1; i <= m; ++i) {
		for(auto x: a) {
			if(i - x >= 0) dp[i] = min(dp[i], dp[i - x] + 1);
			else break;
		}
	}
	if(dp[m] == 2 * INF) cout << -1 << '\n';
	else cout << dp[m] << '\n';
}

int main(){
	fastio();
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}