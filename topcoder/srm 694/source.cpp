#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 256
typedef long long ll;
typedef long double ld;
using namespace std;
bool dp[N][N][N];
bool tmp[N][N][N];

class TrySail {
public:
    TrySail() {}
    int get(vector <int> strength) {
        int n = strength.size();

        dp[0][0][0] = true;
        for (int p = 0; p < strength.size(); p++) {
            int val = strength[p];
            memset(tmp, false, sizeof(tmp));
            for (int i = 0; i < 256; i++)
                for (int j = 0; j < 256; j++)
                    for (int k = 0; k < 256; k++)
                    if (dp[i][j][k]) {
                        tmp[i ^ val][i][j] = true;
                        tmp[i][j ^ val][k] = true;
                        tmp[i][j][k ^ val] = true;
                    }
            for (int i = 0; i < 256; i++)
                for (int j = 0; j < 256; j++)
                    for (int k = 0; k < 256; k++)
                        dp[i][j][k] = tmp[i][j][k];
        }
        int ret = 0;
        for (int i = 0; i < 256; i++)
            for (int j = 0; j < 256; j++)
                for (int k = 0; k < 256; k++)
                    if (dp[i][j][k]) ret = max(ret, i + j + k);
        return ret;
    }
};
int main() {
//    freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);


   /**/ return 0;
}
