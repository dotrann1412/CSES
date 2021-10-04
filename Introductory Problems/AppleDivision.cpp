/**
 *	Author		: DoTran
 *	Last edit	: 13 08 2021 
**/

#include <bits/stdc++.h>

using namespace std;


/**
 * #ifndef _CP_TEMPLATE_
 * #define _CP_TEMPLATE_
**/

#define init() freopen("inp.txt", "r", stdin); freopen("out.txt", "w", stdout)
#define db_problem() cout.precision(10)
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(a) a.begin(), a.end()

#define ll long long
#define vt vector
#define us unsigned
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


/**
 * #endif
**/

void solve(){
	/*your code goes here!*/
	int n; cin >> n;
	vt<int> a(n); cin >> a;
	ll ans = 2 * INF;
	ll S = 0;
	for(auto x: a) S += x;
	for(int i = 0; i < (1 << n); ++i) {
		ll sum = 0;
		for(int j = 0; j < n; ++j)
			if(i >> j & 1) sum += a[j];
		ans = min(ans, abs(S - 2 * sum));
	}
	cout << ans << '\n';
}

int main(){
	//init();
	fastio();
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}