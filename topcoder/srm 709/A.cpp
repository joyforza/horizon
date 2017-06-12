#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-15
#define inf 1000000001
#define mod 1000000007
#define N 50005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;

int dp[16][33000];
int n;


class Xscoregame{
public:
    Xscoregame(){}
    int getscore(vector <int> A) {
        n = A.size();
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < (1 << n); j++)
                if (__builtin_popcount(j) == i) {
                    for (int k = 0; k < n; k++)
                    if (((j >> k) & 1) == 0) {
                        dp[i + 1][j | (1 << k)] = max(dp[i + 1][j | (1 << k)], dp[i][j] + (dp[i][j] ^ A[k]));
                    }
                }
        return dp[n][(1 << n) - 1];
    }
};

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);

    /**/ return 0;
}

