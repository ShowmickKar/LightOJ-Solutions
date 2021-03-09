/* Problem Link: https://lightoj.com/problem/false-ordering */
// Problem Type: Math, Number Theory, Number of Divisors, custom compare function in C++

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


const int m = 1000;
int arr[m];

int nod(int n) { 
	if (!n) return 1;
	n++;
	int ans = 0, s = sqrt(n);
	for (int i = 1; i <= s; i++) {
		if (n % i == 0) ans += 2;
	}
	return (s * s == n ? --ans : ans);
}

bool comp(int a, int b) {
	if (nod(a) < nod(b)) return true;
	if (nod(a) == nod(b) && a > b) return true; 
	return false;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < m; i++) arr[i] = i;
    sort(arr, arr + m, comp);

    int t, i = 1; cin >> t;
    while(t--) {
    	cout << "Case " << i << ": ";
        int n; cin >> n; 
        cout << arr[n - 1] + 1 << endl;
        ++i;
    }
}  
