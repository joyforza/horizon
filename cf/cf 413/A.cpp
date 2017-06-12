#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 200010
#define mod 1000000007
typedef long long ll;
using namespace std;
int n, t, d, k;

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    cin >> n >> t >> k >> d;
    /// 1
    int t1 = (n / k + (n % k != 0)) * t;
    int t2;

    int add = d / t;

    int m2 = d;
    int m1 = add * t;

    n -= add * k;

    if (n <= 0) {
        cout << "NO";
        return 0;
    }
    else {
        //cout << m1 << "\n";
        //cout << m2 << "\n";

        while (n > 0) {
            m1 += t;
            n -= min(n, k);
            if (n == 0) break;
            m2 += t;
            n -= min(n, k);
            if (n == 0) break;
        }

        t2 = max(m1, m2);
    }

    if (t1 <= t2) cout << "NO";
    else
        cout << "YES";

    /**/return 0;
}
