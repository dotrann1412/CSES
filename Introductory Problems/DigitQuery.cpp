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

vector<ll> f;

void build() {
	f.pb(0);
	f.pb(9);
	for(int i = 2; i <= 15; ++i) {
		f.pb(10 * f[i - 1] * i);
	}

	for(int i = 1; i < f.size(); ++i) 
		f[i] += f[i - 1];


}

int digit(ll a, int n) {
	while(a && n--) a /= 10;
	return a % 10;
}

void solve(){
	int q; cin >> q;
	build();
	while(q--) {
		ll x; cin >> x;
		int layer = lower_bound(all(f), x) - f.begin();
		x -= f[layer - 1];

		int a = f[layer - 1] + (x + layer - 1) / layer;
		int b = layer - a % layer;

		cout << x << ' ' << a << ' ' << b << '\n';
		cout << digit(a, b - 1) << '\n';
	}
}

int main(){
	fastio();
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
} 