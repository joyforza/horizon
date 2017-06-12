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
int n, m;
int a[N];

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        int d1 = 0;
        int d2 = 0;
        for (int i = l; i <= r; i++)
            if (a[i] < a[x]) d1++;
            else
                if (a[i] > a[x]) d2++;
        if (d1 == x - l && d2 == r - x) cout << "Yes\n";
        else
            cout << "No\n";
    }
    /**/return 0;
}
