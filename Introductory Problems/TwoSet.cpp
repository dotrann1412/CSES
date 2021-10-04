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
	vt<int> a(n);
	for(int i = 0; i < n; ++ i) 
		a[i] = n - i;
	vt<int> f1, f2;
	ll s1 = 0, s2 = 0;
	for(auto x: a) 
		if(s1 < s2) f1.pb(x), s1 += x;
		else f2.pb(x), s2 += x;
	if(s1 == s2) 
		cout << "YES" << '\n' 
		<< f1.size() << '\n'
		<< f1 << '\n'
		<< f2.size() << '\n'
		<< f2 << '\n';
	else 
		cout << "NO" << '\n';
}

int main(){
	//init();
	fastio();
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}