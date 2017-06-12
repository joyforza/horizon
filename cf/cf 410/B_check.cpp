#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 1000010
#define mod 1000000007
typedef long long ll;
using namespace std;
string s;

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdout);
    cin >> s;
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - i - 1]) cnt++;
	if (cnt == 1) cout << "YES";
	else
        cout << "NO";
	return 0;
}
