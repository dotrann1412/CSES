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

void solve() {
	int n, m; cin >> n >> m;
	vector<pii> a(n);
	for(int i = 0; i < n; a[i].se = i++) cin >> a[i].fi;
	int ans = 1;
	
	sort(all(a));
	for(int i = 1; i < n; ++i)
		ans += a[i].se < a[i - 1].se;
	
	while(m--) {
		int xx, yy; cin >> xx >> yy, --xx, --yy;
		
		if(a[xx].se < a[yy].se) ++ans;
		else --ans;

		swap(a[xx], a[yy]);
		cout << ans << '\n';
	}
}

int main() {
	fastio();
	int t = 1; // cin >> t;
	while(t--) solve();
	return 0;
}