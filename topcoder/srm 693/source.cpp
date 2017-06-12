#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 100100
typedef long long ll;
typedef long double ld;
using namespace std;
int dp[123][123][2];
int d[123][2];
int n;

class BiconnectedDiv1 {
public:
    BiconnectedDiv1(){}
    int minimize(vector <int> w1, vector <int> w2) {
    n = w1.size() + 1;
    for (int i = 0; i < w1.size(); i++)
        d[i][0] = w1[i];
    for (int i = 0; i < w2.size(); i++)
        d[i][1] = w2[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = inf;

    dp[0][0][0] = 0;

        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                for (int k = 0; k < 2; k++) {
                    if (k == 1) {
                        if (i + 1 < n) {
                            if (i + 1 != j)
                                dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + d[i][0]);
                        }
                        if (i + 2 < n) {
                            if (i + 2 != j)
                                dp[i + 2][j][0] = min(dp[i + 2][j][0], dp[i][j][k] + d[i][1]);
                        }

                        if (j + 1 < n) {
                            if (j + 1 != i)
                                dp[i][j + 1][0] = min(dp[i][j + 1][0], dp[i][j][k] + d[j][0]);
                        }
                        if (j + 2 < n) {
                            if (j + 2 != i)
                                dp[i][j + 2][0] = min(dp[i][j + 2][0], dp[i][j][k] + d[j][1]);
                        }
                    }
                    else {
                        if (i + 1 < n) {
                            if (i + 1 == j)
                                dp[i + 1][j][1] = min(dp[i + 1][j][1], dp[i][j][k] + d[i][0]);
                            else
                                dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + d[i][0]);
                        }

                        if (i + 2 < n) {
                            if (i + 2 == j)
                                dp[i + 2][j][1] = min(dp[i + 2][j][1], dp[i][j][k] + d[i][1]);
                            else
                                dp[i + 2][j][0] = min(dp[i + 2][j][0], dp[i][j][k] + d[i][1]);
                        }

                        if (j + 1 < n) {
                            if (j + 1 == i)
                                dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][k] + d[j][0]);
                            else
                                dp[i][j + 1][0] = min(dp[i][j + 1][0], dp[i][j][k] + d[j][0]);
                        }

                        if (j + 2 < n) {
                            if (j + 2 == i)
                                dp[i][j + 2][1] = min(dp[i][j + 2][1], dp[i][j][k] + d[j][1]);
                            else
                                dp[i][j + 2][0] = min(dp[i][j + 2][0], dp[i][j][k] + d[j][1]);
                        }
                    }
            }
    return dp[n - 1][n - 1][0];
}

};

int main() {
    //freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    vector <int> w1;
    vector <int> w2;
    w1.pb(3);
    w1.pb(3);
    w1.pb(3);
    w1.pb(3);
    w2.pb(3);
    w2.pb(6);
    w2.pb(3);

    BiconnectedDiv1 a;
    cout << a.minimize(w1, w2);
    return 0;
}
