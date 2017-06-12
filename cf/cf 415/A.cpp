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
int n, k;

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int need = (2 * k - 1);
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        tot += x;
    }

    int ret = 0;
    do {
        n++;
        tot += k;
        ret++;
        if (2 * tot >= need * n) break;
    }
    while (true);

    cout << ret;
    /**/return 0;
}
