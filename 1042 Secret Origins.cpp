/*
Problem Link: https://lightoj.com/problem/secret-origins
Problmet Type: next_permutation, binary to decimal, decimal to binary conversion
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

string to_binary(int n) {
	string ans = "";
	while (n) {
		ans += to_string(n % 2);
		n /= 2;
	}
	int t_length = 32 - ans.length();
	while(t_length--) ans += '0';
	_reverse(ans);
	return ans;
}

int to_decimal(string bin) {
	int ans = 0;
	for (int i = 0; i < 32; i++) {
		ans += (bin[i] - '0') * pow(2, 32 - i - 1);
	}
	return ans;

}

void solve() {  
	int n; cin >> n;
	string bin = to_binary(n);
	next_permutation(bin.begin(), bin.end());
	cout << to_decimal(bin) << endl;
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
