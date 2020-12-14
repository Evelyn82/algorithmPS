#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

const int ALPHA = 26;
struct Trie {
	int cnt;
	bool terminal;
	Trie* child[ALPHA];

	Trie() : cnt(0), terminal(false) {
		for (int i = 0; i < ALPHA; ++i) child[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < ALPHA; ++i) if (child[i]) delete child[i];
	}
	void init(const char* key) {
		if (*key == 0) {
			terminal = true;
			return;
		}
		int next = (int)(*key - 'a');
		if (child[next] == NULL) {
			child[next] = new Trie();
			cnt++;
		}
		child[next]->init(key + 1);
	}
	int query(const char* key, int ret) {
		if (*key == 0) return ret;

		if (cnt > 1 || terminal) ret++;
		int next = (int)(*key - 'a');
		return child[next]->query(key + 1, ret);
	}
};
int main() {
	int N;
	while (scanf("%d", &N) != EOF) {
		vector<string> v(N);
		for (string& i : v) cin >> i;

		Trie* node = new Trie();

		for (string& i : v) node->init(i.c_str());

		double ans = 0.0;
		if (node->cnt == 1) ans += (double)N;
		for (string& i : v) ans += (double)node->query(i.c_str(), 0);

		ans /= (double)N;
		ans *= 100;
		ans = round(ans);
		ans /= 100;
		printf("%.2f\n", ans);
		delete(node);
	}
}
