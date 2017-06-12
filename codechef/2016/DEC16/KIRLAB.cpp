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
#define M 10000001
typedef long long ll;
typedef long double ld;
using namespace std;
int nt;
int n;
int dp[N];
int tr[10000010];
int D[10000010];

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);

    for (int i = 2; i < M; i++)
    if (tr[i] == 0) {
        tr[i] = i;
        for (int j = i + i; j < M; j += i)
            tr[j] = i;
    }

    scanf("%d", &nt);
    while (nt--) {
        memset(D, 0, sizeof(D));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {

            dp[i] = 0;

            int x;
            scanf("%d", &x);

            int tmp = x;
            while (tmp > 1) {
                int rr = tr[tmp];
                dp[i] = max(dp[i], D[rr] + 1);
                while (tmp % rr == 0) tmp /= rr;
            }

            tmp = x;
            while (tmp > 1) {
                int rr = tr[tmp];
                D[rr] = max(D[rr], dp[i]);
                while (tmp % rr == 0) tmp /= rr;
            }
        }

        int ret = 1;
        for (int i = 1; i <= n; i++) ret = max(ret, dp[i]);

        printf("%d\n", ret);
    }

    /**/ return 0;
}
