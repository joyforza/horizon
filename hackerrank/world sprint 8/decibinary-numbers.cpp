#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, ll>
#define ppp pair<pp, pp>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 20
#define base 311097
#define maxN 300011
typedef long long ll;
typedef long double ld;
using namespace std;

ll dp[maxN + 1][N + 1][10];
ll tot[maxN + 1];
ll sum[maxN + 1];
int q;

pp get(ll x) {
    int l = 0;
    int r = maxN - 1;
    int pos = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (x > sum[mid]) {
            pos = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    ll kth = x - sum[pos];
    return mp(pos + 1, kth);
}

void getResult(int val, ll kth) {
  //  cout << "this val = " << val << "\n";
  //  cout << "get-th = " << kth << "\n";

    ll tmp = kth;
    int mylen = -1;
    for (int len = 1; len <= N; len++)
        for (int d = 1; d <= 9; d++)
            if (tmp > dp[val][len][d]) {
                tmp -= dp[val][len][d];

            //    cout << dp[val][len][d] << "\n";
            }
            else {
                if (mylen == -1) mylen = len;
            }

   // cout << mylen << "\n";
    tmp = kth;
    do {
        for (int d = 0; d <= 9; d++)
            if (tmp > dp[val][mylen][d]) {
                tmp -= dp[val][mylen][d];
            }
            else {
                //cout << d;
                printf("%d", d);
                val -= d * (1 << (mylen - 1));
                break;
            }
        mylen--;
    }
    while (mylen > 0);
   // cout << "\n";
    printf("\n");
}

int main() {
    //freopen("in.in", "r", stdin); // freopen("ou.ou", "w", stdout);
   // ios::sync_with_stdio(false);

    dp[0][0][0] = 1;
    for (int i = 0; i < maxN; i++)
    for (int j = 0; j < N; j++)
    for (int k = 0; k <= 9; k++)
    for (int digit = 0; digit <= 9; digit++) {
        if (i + digit * (1 << j) <= maxN)
            dp[i + digit * (1 << j)][j + 1][digit] += dp[i][j][k];
    }

    for (int i = 1; i <= maxN; i++)
        for (int j = 0; j < N; j++)
            for (int digit = 1; digit <= 9; digit++)
                tot[i] += dp[i][j][digit];

    for (int i = 1; i <= maxN; i++) {
        sum[i] = sum[i - 1] + tot[i];
    }

    //cin >> q;
    scanf("%d", &q);
    while (q--) {
        ll x;
        //cin >> x;
        scanf("%lld", &x);
        x--;
        if (x == 0) {
            //cout << 0 << "\n";
            printf("0\n");
            continue;
        }

        pp pos = get(x);
        getResult(pos.fi, pos.se);
    }
    /**/ return 0;
}
