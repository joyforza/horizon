#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 100010
#define mod 1000000007
#define inf 1000000001
#define esp 1e-9
typedef long long ll;
using namespace std;
int a, b, c;
int n;
int x[N];

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    int ret = 0;
    sort(x + 1, x + n + 1);
    for (int i = 1; i <= n; i++)
        if (b < x[i] && x[i] < c) ret++;
    cout << ret;

    /**/return 0;
}
