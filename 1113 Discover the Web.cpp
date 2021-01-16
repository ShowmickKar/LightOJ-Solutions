/*
  Problem Link: https://lightoj.com/problem/discover-the-web
  Problem Type: Data Structures, Stacks
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
	string s, current = "http://www.lightoj.com/";
	stack<string> back, forward;
	while (1) {
		cin >> s; 
		if (s == "QUIT") break;
		else if (s == "VISIT") {
			back.push(current);
			cin >> current;
			while(!forward.empty()) forward.pop();
			cout << current << endl;
		}
		else if (s == "BACK") {
			if (back.empty()) {
				cout << "Ignored\n";
			}
			else {
				forward.push(current);
				current = back.top();
				back.pop();
				cout << current << endl;
			}
		} 
		else if (s == "FORWARD") {
			if (forward.empty()) cout << "Ignored\n";
			else {
				back.push(current);
				current = forward.top();
				forward.pop();
				cout << current << endl;
			} 
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
