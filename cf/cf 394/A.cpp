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
#define MAXN 505
#define MaxE 1000011
#define sqr(x) (x)*(x)
#define RL double
#define EPS 1e-9
#define ll long long
using namespace std;
int a, b;

int main() {
   // freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> a >> b;
    if (a == 0 && b == 0) cout << "NO";
    else
    if (abs(a - b) > 1) cout << "NO";
    else {
        cout << "YES";
    }
    /**/ return 0;
}
