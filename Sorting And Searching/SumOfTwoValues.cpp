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
	int n, x; cin >> n >> x;
	vt<pii> a(n);
	for(int i = 0; i < n; cin >> a[i++].fi) 
		a[i].se = i;
	sort(all(a));
	for(int i = 0; i < n; ++i) {
		int idx = lower_bound(all(a), pii(x - a[i].fi, 0)) - a.begin();
		if(a[idx].fi + a[i].fi == x && idx != i) {
			cout << a[i].se + 1 << ' ' << a[idx].se + 1 << '\n';
			return;
		}
	}
	cout << "IMPOSSIBLE" << '\n';
}

int main(){
	fastio();
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}