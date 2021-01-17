/*
    Problem Link: https://lightoj.com/problem/back-to-underworld
    Problem Type: Graph Traversal, Graph Coloring
*/

#include <bits/stdc++.h>
#define INF 1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define arr array
#define endl "\n";
#define _min(a) *min_element(a.begin(), a.end());
#define _max(a) *max_element(a.begin(), a.end());
#define _sort(x) sort(x.begin(), x.end())
#define _rsort(x) sort(x.rbegin(), x.rend())
#define _reverse(x) reverse(x.begin(), x.end())
#define _debug(x) cout << #x << " = " << x << endl;
#define debug(x, y) cout << #x " = " << x << " " << #y << " = " << y << endl;
#define _lower_bound(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
#define _upper_bound(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()
typedef long long ll;
using namespace std;
vector<int> color(20005, 0), parent(20005, 0);
vector<vector<int>> graph(20005);
int red = 0, blue = 0;

void bfs(int x) {
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int s = q.front();
		q.pop();
		bool flag = true;
		if (color[s]) flag = false;
		if (!parent[s] || parent[s] == 2) {
			color[s] = 1;
		} else {
			color[s] = 2;
		}
		if (flag) {
			if (color[s] == 1) ++red; else ++blue;
		}
		for (auto &u : graph[s]) {
			parent[u] = color[s];
			if (color[u]) continue;			
			q.push(u);
		}
	}
}

void solve() {	
	int n, ans = 0; cin >> n;
	unordered_set<int> s;
	for (int i = 0; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		s.insert(u);
		s.insert(v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (auto &i : s) {
		// _debug(i);
		if (color[i]) continue;
		bfs(i);
		// debug(red, blue);
		ans += max(red, blue);
		red = 0, blue = 0;
	}
	cout << ans << endl;
	for (int i = 0; i < color.size(); ++i) {
		color[i] = 0;
		graph[i].clear();
	}
}   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t, i = 1; cin >> t;
    while(t--) {
    	cout << "Case " << i << ": ";
        solve();
        ++i;
    }
}
