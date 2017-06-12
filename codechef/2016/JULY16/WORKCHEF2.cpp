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
#define N 20
typedef long long ll;
typedef long double ld;
using namespace std;
ll dp[N][555][2525];
int mask[555];
int way[5555];
ll G[20][555][2525];

int gcd(int x, int y) {
    if (x < y)
        swap(x, y);
    while (y > 0) {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int lcm(int x, int y) {
    int z = gcd(x, y);
    return x / z * y;
}

int bitOn(int x, int k) {
    return (x | (1 << k));
}

int digit[20];

int query(ll n) {
    int m = 0;
    while (n > 0) {
        digit[m++] = n % 10;
        n /= 10;
    }
    for (int i = m - 1; i >= 0; i--) {

    }
}
int main() {
   // freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);

    for (int i = 1; i < (1 << 9); i++) {
        int stt = 0;
        int rr = 1;
        for (int j = 1; j <= 9; j++)
            if ((i >> j) & 1) {
                stt = bitOn(stt, j - 1);
                rr = lcm(rr, j);
            }
        mask[stt] = rr;
    }
    dp[1][0][0] = 1;
    for (int i = 1; i <= 9; i++)
        dp[1][(1 << (i - 1))][i] = 1;

    for (int p = 0; p < 18; p++)
    for (int i = 1; i < (1 << 9); i++)
    for (int j = 0; j < 2520; j++) {
        dp[p + 1][i][(j * 10) % 2520] += dp[p][i][j];
        for (int k = 1; k <= 9; k++) {
            int nstt = i;
            if (!((nstt >> (k - 1)) & 1)) nstt = bitOn(nstt, k - 1);
            dp[p + 1][nstt][(j * 10 + k) % 2520] += dp[p][i][j];
        }
    }


    for (int p = 1; p <= 18; p++)
    for (int i = 1; i < (1 << 9); i++) {
        int tmp = 1;
        for (int j = 0; j < 9; j++)
            if ((i >> j) & 1)
                tmp = lcm(tmp, j + 1);
        for (int j = 0; j < 2520; j++)
            G[p][i][j % tmp] += dp[p][i][j];
    }



 /**/ return 0;
}
