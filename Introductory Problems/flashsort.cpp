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

void insertionsort(int* begin, int* end) {
	for(int* i = begin + 1; i < end; ++i) {
		int* j = i, val = *i;
		while(j > begin && *(j - 1) > *j) swap(*j, *(j - 1)), --j;
		*j = val;
	}
}

void flashsort(int* a, int n)
{
	int minVal = a[0], max = 0, m = int(0.45 * n);
	int* l = new int[m];

	for (int i = 0; i < m; i++)
		l[i] = 0;

	for (int i = 1; i < n; i++) {
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}

	if (a[max] == minVal)
		return;

	for (int i = 0; i < n; i++) {
		int k = int((m - 1) * (a[j] - minVal) / (a[max] - minVal));
		++l[k];
	}

	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];

	swap(a[max], a[0]);
	int count = 0, j = 0, k = m - 1, hold;
	while (count < n - 1){
		while (j > l[k] - 1) {
			j++;
			k = int((m - 1) * (a[j] - minVal) / (a[max] - minVal));
		}

		hold = a[j];
		if (k < 0) break;
		while (j != l[k]) {
			k = int((m - 1) * (a[j] - minVal) / (a[max] - minVal));
			swap(a[--l[k]], hold);
			++count;
		}
	}
	delete[] l;

	//insertionsort(a, a + n);
}

void solve(){
	int n = 20;
	int* a = new int[n + 1];
	srand(time(0));
	for(int i = 0; i < n; a[i++] = rand() % 100);
	for(int i = 0; i < n; cout << a[i++] << ' '); cout << '\n';
	flashsort(a, n);
	for(int i = 0; i < n; cout << a[i++] << ' '); cout << '\n';
	delete[] a;
}

int main(){
	fastio();
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}