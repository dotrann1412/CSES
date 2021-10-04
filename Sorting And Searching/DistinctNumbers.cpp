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

/*int result = 0;

struct node
{
	int data;
	node *left, *right;
	node(){
		
	}
	node(int data){
		this->data = data;
		left = right = nullptr;
	}
};

void insert(node* &head, int value) {
	if(head == nullptr) {
		head = new node(value);
		result++;
		return;
	}
	if(head->data == value) return;
	if(head->data > value) insert(head->left, value);
	else insert(head->right, value);
}

void solve(){
	node* bst = nullptr;
	int n; cin >> n;
	while(n--){
		int x; cin >> x;
		insert(bst, x);
	}
	cout << result << '\n';
} 
*///BST -> TLE ?

void solve() {
	int n; cin >> n;
	set<int> a;
	for(int i; n--;) cin >> i, a.insert(i);
	cout << a.size() << '\n';
}

int main(){
	//init();
	fastio();
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}