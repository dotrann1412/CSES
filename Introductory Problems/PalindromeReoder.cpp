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
	string s; cin >> s;
	vt<int> a(26, 0);
	for(auto x: s) a[x - 'A']++;
	int cnt = 0;
	for(auto x: a) cnt += x & 1;
	if(cnt >= 2) cout << "NO SOLUTION" << '\n';
	else {
		string ans = "";
		for(int i = 0; i < 26; ++i) {
			if(a[i] % 2 == 0) ans += string(a[i] / 2, char(i + 'A'));
		}
		for(int i = 0; i < 26; ++i) {
			if(a[i] % 2) ans += string(a[i], char(i + 'A'));
		}
		for(int i = 25; i >= 0; --i) {
			if(a[i] % 2 == 0) ans += string(a[i] / 2, char(i + 'A'));
		}
		cout << ans << '\n';
	}
}

int main(){
	//init();
	fastio();
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}