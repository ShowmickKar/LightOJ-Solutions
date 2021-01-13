/* Problem Link: https://lightoj.com/problem/drunk
   Problem Type: Graph Travarsal, Topological Sorting, Detecting Cycle in a Directed Graph
*/

#include <bits/stdc++.h>
#define INF 1e18
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

vector<vector<int>> graph(10000);
vector<int> flag(100000), visited(10000);

bool isCycle(int x) {
	visited[x] = 1; 
	flag[x] = 1;
	for (auto &u : graph[x]) {
		if (!visited[u] && isCycle(u)) return true;
		else if (flag[u]) return true;
	}
	flag[x] = 0;
	return false;
}


void solve() {	
	int m, c = 0; cin >> m;
	unordered_map<string, int> hash;
	while(m--) {
		string a, b; 
		int p, q;
		cin >> a >> b;
		if (hash.find(a) == hash.end()) {
			++c;
			hash[a] = c;
		}
		if (hash.find(b) == hash.end()) {
			++c;
			hash[b] = c;
		}
		p = hash[a];
		q = hash[b];
		graph[p].push_back(q);
	}
	bool check = true;
	for (int i = 1; i < hash.size() + 1; ++i) {
		if (visited[i]) continue;
		if (isCycle(i)) {
			cout << "No\n";
			check = false; 
			break;
		}
	}
	if (check) cout << "Yes\n";
	for (int i = 1; i < hash.size() + 1; ++i) {
		graph[i].clear();
		visited[i] = 0;
		flag[i] = 0;
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
