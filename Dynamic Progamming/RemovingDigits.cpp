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

vector<int> digit(int a) {
	vt<int> res;
	while(a) res.pb(a % 10), a /= 10;
	return res;
}

void solve(){
	int n; cin >> n;
	vt<int> dp(n + 1, INF);
	for(int i = n; i >= 0; --i) {
		auto a = digit(i);
		for(auto x: a) 
	}
}

int main(){
	fastio();
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}