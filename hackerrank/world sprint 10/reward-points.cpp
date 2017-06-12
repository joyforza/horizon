#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 100010
#define inf 1000000001
#define mod 1000000007
typedef long long ll;
using namespace std;
int a, b, c;

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    cout << min(100, a * 10) + min(100, b * 10) + min(100, c * 10);
    /**/return 0;
}
