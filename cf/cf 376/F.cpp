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
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
int a[N];
int d[N];
int ret[N];

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    int bs = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        bs = max(bs, x);
        d[x]++;
    }

    int cnt = 0;
    for (int i = bs; i >= 1; i--) {
        cnt += d[i];


    }

    /**/ return 0;
}
