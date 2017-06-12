#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 100010
#define base 311097
#define SEG 555
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
int a[100100];
int b[100100];

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    b[n] = a[n];
    for (int i = n - 1; i >= 1; i--) {
        b[i] = a[i] + a[i + 1];
    }

    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";
    /**/ return 0;
}
