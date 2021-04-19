#include <string>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;
using vpii = vector<pair<int, int>>;
using pii = pair<int, int>;

const int MAXN = 250001;
struct Node {
    int n;
    vector<Node*> child;

    void setChild(Node* other) {
        child.push_back(other);
    }
};
bool visited[MAXN];
vpii search(int n, Node* v) {
    memset(visited, false, sizeof(visited));

    queue<pii> q;
    vpii ret;
    q.push({ n,0 });
    visited[n] = true;
    while (!q.empty()) {
        pii now = q.front();
        q.pop();

        for (Node* node : v[now.first].child) {
            int next = node->n;
            int nextCost = now.second + 1;
            if (visited[next]) continue;
            while (!ret.empty() && ret.back().second < nextCost) ret.pop_back();

            visited[next] = true;
            ret.push_back({ next, nextCost });
            q.push({ next, nextCost });
        }
    }return ret;
}
int solution(int n, vector<vector<int>> edges) {

    sort(edges.begin(), edges.end());
    Node* v = new Node[n + 1];
    for (int i = 1; i <= n; ++i) v[i].n = i;
    for (vector<int> n : edges) {
        int n1 = n[0], n2 = n[1];
        v[n1].setChild(&v[n2]);
        v[n2].setChild(&v[n1]);
    }

    // 임의의 노드에서 가장 먼 A노를 찾는다.
    vpii Anode = search(1, v);

    // A노드를 기준으로 B후보를 찾는다
    vpii Bnode = search(Anode[0].first, v);
    if (Bnode.size() > 1) return Bnode[0].second;

    // B기준으로 C를 찾는다
    vpii Cnode = search(Bnode[0].first, v);
    
    // c가 여러개이면 return 지름
    if (Cnode.size() > 1) return Cnode[0].second;
    
    // 1개이면 일직선이므로 지름 -1
    else return Cnode[0].second - 1;
}
