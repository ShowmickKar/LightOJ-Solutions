/*
Problem Link: https://lightoj.com/problem/neighbor-house
Problem Type: Basic 2D Dynamic Programming
*/

#include <bits/stdc++.h>
#define INF 1e18
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
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

vector<int> read_array(int n) {vector<int>a(n); for(int i=0; i<n;i++) cin>>a[i]; return a;}
vector<ll> read_array(ll n) {vector<ll>a(n); for(int i=0; i<n;i++) cin>>a[i]; return a;}
vector<pair<int,int>> read_pair(int n) {vector<pair<int, int>>a(n); for(int i=0; i<n; i++) {cin>>a[i].first>>a[i].second;} return a;}
void write_array(vector<int>a) {for(auto &u:a) cout<<u<< " "; cout<<endl;}

void solve() {  
	int n, ans = 1000000007; cin >> n; 
	int arr[n][3], dp[n][3];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
			if (i == 0) {
				dp[i][j] = arr[i][j];
				continue;
			}
			if (j == 0) {
				dp[i][j] = arr[i][j] + min(dp[i - 1][1], dp[i - 1][2]);
			}
			else if (j == 1) {
				dp[i][j] = arr[i][j] + min(dp[i - 1][0], dp[i - 1][2]);
			}
			else {
				dp[i][j] = arr[i][j] + min(dp[i - 1][0], dp[i - 1][1]);
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		ans = min(ans, dp[n - 1][i]);
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


2
4
13 23 12
77 36 64
44 89 76
31 78 45
3
26 40 83
49 60 57
13 89 99

*/
