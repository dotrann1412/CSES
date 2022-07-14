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

struct Node
{
	int data;
	Node *next, *prev;
	
	Node() {
		data = 0;
		next = prev = nullptr;
	}

	Node(int value) {
		data = value;
		next = prev = nullptr;
	}
};

class Stack
{
private:
	Node* head;
	int len;

public:
	Stack() {
		this->len = 0;
		this->head = nullptr;
	}

	Stack(const Stack& another) {
		Node* cur = another.head;
		this->head = nullptr;
		this->len = another.len;
		
		if(cur) 
			this->head = new Node(cur->data), 
			cur = cur->next;
		
		Node* iter = this->head;

		while(cur) {
			iter->next = new Node(cur->data);
			iter = iter->next;
			cur = cur->next;
		}
	}

	~Stack() {
		Node* cur = head;
		while(head) {
			cur = head;
			head = head->next;
			delete cur;
		}
	}

	bool empty() {
		return this->head == nullptr;
	}

	int size() {
		return this->len;
	}

	int top() {
		return this->head->data;
	}

	void push(int value) {
		Node* cur = new Node(value);
		cur->next = head;
		head = cur;
		++len;
	}

	void pop() {
		if(head) {
			Node* cur = head;
			head = head->next;
			delete cur;
			--len;
		}
	}
};

void solve(){
	Stack a;
	for(int i = 0; i < 10; ++i)
		a.push(i);

	Stack b(a);
	while(!b.empty())
		cout << b.top() << ' ', b.pop();
	cout << '\n';

}

int main(){
	fastio();
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}