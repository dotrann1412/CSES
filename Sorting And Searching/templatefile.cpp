/*
 * Author : DoTran
 * Created: Thu Dec  2 12:44:01 2021
**/

#include <bits/stdc++.h>

using namespace std;

/**
 * #ifndef _CP_TEMPLATE_
 * #define _CP_TEMPLATE_
**/

#define init() freopen("inp.txt", "r", stdin); freopen("out.txt", "w", stdout)
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

/**
 * #endif
**/

void solve(){
	/*your code goes here!*/
	
}

int main(){
	//init();
	fastio();
	int t = 1; cin >> t;
	while(t--) solve();
	return 0;
}