/* 
  Problem Link: https://lightoj.com/problem/monkey-banana-problem
  Problem Type: Basic Dynamic Programming
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
	int n, k; cin >> n; 
	k = 2 * n - 1; 
	int dp[k][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			int x; cin >> x;
			dp[i][j] = x;
		}
		for (int j = i + 1; j < n; ++j) dp[i][j] = 0;
	}
	for (int i = n; i < k; ++i) {
		for (int j = 0; j < i - n + 1; ++j) {
			dp[i][j] = 0;
		}
		for (int j = i - n + 1; j < n; ++j) {
			int x; cin >> x; 
			dp[i][j] = x;
		}
	}
	for (int i = 1; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + dp[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j -1]) + dp[i][j];
			}
		}
	}
	cout << dp[k - 1][n - 1] << endl;
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
