/*
Problem Link: https://lightoj.com/problem/guilty-prince
Problem Type: Graph Traversal, Breadth First Search
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


vector<vector<int>> bfs(vector<vector<char>> grid, vector<vector<int>> visited, pair<int, int> start) {
	queue<pair<int, int>> q;
	q.push({start.first, start.second});
	while (!q.empty()) {
		pair<int, int> cell = q.front();
		q.pop();
		visited[cell.first][cell.second] = 1;
		if (cell.second > 0 && !visited[cell.first][cell.second - 1] && grid[cell.first][cell.second - 1] == '.') {
			q.push({cell.first, cell.second - 1});
		}
		if (cell.second < grid[0].size() - 1 && !visited[cell.first][cell.second + 1] && grid[cell.first][cell.second + 1] == '.') {
			q.push({cell.first, cell.second + 1});
		}
		if (cell.first > 0 && !visited[cell.first - 1][cell.second] && grid[cell.first - 1][cell.second] == '.') {
			q.push({cell.first - 1, cell.second});
		}
		if (cell.first < grid.size() - 1 && !visited[cell.first + 1][cell.second] && grid[cell.first + 1][cell.second] == '.') {
			q.push({cell.first + 1, cell.second});
		}
	}
	return visited;
}

void solve() {	
	int c, r; cin >> c >> r;
	vector<vector<char>> grid(r, vector<char> (c));
	vector<vector<int>> visited(r, vector<int> (c));
	pair<int, int> start;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> grid[i][j];
			if (grid[i][j] == '@') {
				start = {i, j};
				grid[i][j] = '.';
			}
		}
	}
	visited = bfs(grid, visited, start);
	int ans = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (visited[i][j]) ++ans;
		}
	}
	cout << ans << endl;
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

/*

4
6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..

*/ 
