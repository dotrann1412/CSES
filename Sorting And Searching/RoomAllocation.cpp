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

template <class T> istream &operator >> (istream &s, vt<T> &a){
	for(T &x: a) s >> x;
	return s;
}

template <class T> ostream &operator << (ostream &s, vt<T> a){
	for(T &x: a) s << x << ' ';
	return s;
}

void solve(){
	/*your code goes here!*/
	int n; cin >> n;
	vt<pii> a(n);
	for(auto& x: a) cin >> x.fi >> x.se;
	sort(all(a), [&](pii a, pii b){
		return a.se == b.se ? a.fi < b.fi : a.se < b.se;
	});
	vt<int> ans(n);
	ans[0] = 1;
	int iter = 1;
	set<int> set;
	for(int i = 1; i < n; ++i) {
		int l = 0, r = i - 1;
		while(l < r) {
			int mid = (l + r) / 2;
			if(a[mid].se >= a[i].fi) r = mid;
			else l = mid + 1;
		}
		if(a[l].se >= a[i].fi) ans[i] = iter++;
		else ans[i] = ans[l];
	}
	cout << iter << '\n';
	cout << ans << '\n';
}

int main(){
	//init();
	fastio();
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}