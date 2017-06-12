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
#define N 100100
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
int a[100100];
int b[100100];
int L;
int R;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        L += a[i];
        R += b[i];
    }

    int best = abs(L - R);
    int k = 0;
    for (int i = 1; i <= n; i++) {
        int nL = L - a[i] + b[i];
        int nR = R - b[i] + a[i];
        if (abs(nL - nR) > best) {
            best = abs(nL - nR);
            k = i;
        }
        }

    cout << k;
    /**/ return 0;
}
