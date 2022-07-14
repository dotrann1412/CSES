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

int Cau2(int* a, int l, int r) {
	if(a[l] == a[r]) return 1;
	int mid = (l + r) / 2;
	return Cau2(a, l, mid) + Cau2(a, mid + 1, r);
}

void Cau3(int* a, int n) {
	int j = 1;
	for(int i = 0; i < n; i += 2) {
		if(a[i] < 0) {
			while(j < n && a[j] < 0) j += 2;
			if(j >= n) break;
			swap(a[j], a[i]);
		}
	}

	j = n - 1;
	for(int i = 0; i < n - 1; i++) {
		if(i % 2 && a[i] > 0 || i % 2 == 0 && a[i] < 0) {
			while(a[i] * a[j] > 0 && j >= i) --j;
			if(j <= i) break;
			swap(a[i], a[j]);
		}
	}
}

void Cau3_v(int* a, int n) {
	int idx = 0;
	for(int i = 0; i < n; ++i) {
		if(a[i] >= 0) {
			swap(a[i], a[idx]);
			idx += 2;
			if(idx >= n) break;
		}
	}
	idx = 1;
	for(int i = 0; i < n; ++i) {
		if(a[i] < 0) {
			swap(a[i], a[idx]);
			idx += 2;
			if(idx >= n) break;
		}
	}
}

void solve(){
	int a[] = { -1, -2, -3, -1, -2, -3, 1, 2 , 3, -2, -3, 1};
	int n = sizeof(a) / sizeof(int);
	//sort(a, a + n);
	Cau3(a, n);
	for(int i = 0; i < n; cout << a[i++] << ' ');
}

int main(){
	fastio();
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}