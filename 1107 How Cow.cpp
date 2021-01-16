/*
  Problem Link: https://lightoj.com/problem/how-cow?fbclid=IwAR0zzjhpV9_bl5EwuxnCtjYzRoPgnM26RVHtBve7-dLdIv02-_Ng5EatmtQ
  Problem type: Coordinate Geometry

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

void solve() {	
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int m; cin >> m; 
	while(m--) {
		int x, y; cin >> x >> y; 
		if ((x < x2 && x > x1) && (y < y2 && y > y1)) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t, i = 1; cin >> t;
    while(t--) {
    	cout << "Case " << i << ":\n";
        solve();
        ++i;
    }
}  
