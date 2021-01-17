/*
  Problem Link: https://lightoj.com/problem/ip-checking
  Problem Type: Implementation, Brute Force, Decimal to Binary Conversion
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

string decimalToBinary(string n) {
	string result = "", ans = "";
	int temp = stoi(n);
	while (temp > 0) {
		ans += to_string(temp % 2);
		temp /= 2;
	}
	reverse(ans.begin(), ans.end());
	int lacking = 8 - ans.length();
	for (int i = 0; i < lacking; ++i) result += '0';
	result += ans;
	return result;
}	

void solve() {	
	string a, b;
	cin >> a >> b;
	vector<int> f, s;
	for (int i = 0; i < a.length(); ++i) {
		if (a[i] == '.') {
			f.push_back(i);
		}
	}
	for (int i = 0; i < b.length(); ++i) {
		if (b[i] == '.') {
			s.push_back(i);
		}
	}
	vector<string> ans1, ans2;
	ans1.push_back(a.substr(0, f[0]));
	ans1.push_back(a.substr(f[0] + 1, f[1] - f[0] - 1));
	ans1.push_back(a.substr(f[1] + 1, f[2] - f[1] - 1));
	ans1.push_back(a.substr(f[2] + 1, a.length() - f[2]));
	ans2.push_back(b.substr(0, s[0]));
	ans2.push_back(b.substr(s[0] + 1, s[1] - s[0] - 1));
	ans2.push_back(b.substr(s[1] + 1, s[2] - s[1] - 1));
	ans2.push_back(b.substr(s[2] + 1, b.length() - s[2]));
	for (int i = 0; i < 4; ++i) {
		if (decimalToBinary(ans1[i]) != ans2[i]) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
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
