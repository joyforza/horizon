#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, int>
#define ppp pair<int, pp>
#define fi first
#define se second
#define esp 1e-15
#define inf 1000000001
#define mod 1000000007
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
bool f[N];
int n, k, nt;
priority_queue<int> qu;

int main() {
    freopen("C_2.in", "r", stdin);
    freopen("C_2.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    for (int kk = 1; kk <= nt; kk++) {
        cin >> n >> k;
        if (k > n * 2 / 3)
            cout << "Case #" << kk << ": 0 0\n";
        else {
        while (!qu.empty()) qu.pop();
        qu.push(n);
        for (int i = 1; i < k; i++) {
            int len = qu.top();
            qu.pop();
            if (len % 2 != 0) {
                if (len / 2 > 0) qu.push(len / 2);
                if (len / 2 > 0) qu.push(len / 2);
            }
            else {
                qu.push(len / 2);
                if (len / 2 - 1 > 0) qu.push(len / 2 - 1);
            }
        }
        int val = qu.top();
        cout << "Case #" << kk << ": ";
        if (val % 2 != 0)
            cout << val / 2 << " " << val / 2 << "\n";
        else
            cout << val / 2  << " " << val / 2 - 1<< "\n";
        }
    }
    /**/ return 0;
}
