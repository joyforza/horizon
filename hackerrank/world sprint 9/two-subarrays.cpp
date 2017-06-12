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
#define MAXN 505
#define MaxE 1000011
#define sqr(x) (x)*(x)
#define RL double
#define EPS 1e-9
#define ll long long
using namespace std;
int bg[N][88];
int en[N][88];
int a[N];
int len[88];
int sum[88];
int T[N];

int get(int l, int r) {
    return T[r] - T[l - 1];
}

int ansSum = -inf;
int ansLen = inf;
int ansNum = 0;

void com(int l, int r) {
    if (l == r) {
        for (int i = -40; i <= 40; i++) {
            bg[l][i + 40] = inf;
            en[l][i + 40] = inf;
        }

        bg[l][a[l] + 40] = a[l];
        en[l][a[l] + 40] = a[l];
        return;
    }

    int mid = (l + r) >> 1;
    com(l, mid);
    com(mid + 1, r);

    /// tich luy
    for (int i = -40; i <= 40; i++) {
        len[i + 40] = inf;
        sum[i + 40] = -inf;
    }
    for (int i = mid + 1; i <= r; i++)
    for (int j = -40; j <= 40; j++) {
        int val = get(mid + 1, i) - en[i][j + 40];
        if (val > sum[j + 40]) {
            len[j + 40] = i - mid + 1;
            sum[j + 40] = val;
        }
        else
            if (val == sum[j + 40] && len[j + 40] > i - mid + 1)
                len[j + 40] = i - mid + 1;
    }
    /// tinh ket qua
    for (int i = l; i <= mid; i++)
    for (int j = -40; j <= 40; j++) {
        int val = get(l, i) - bg[i][j + 40] + sum[j + 40];
        int maxlen = (i - l + 1) + len[j + 40];
        if (val > ansSum) {
            ansSum = val;
            ansLen = maxlen;
            ansNum = 1;
        }
        else
        if (val == ansSum) {
            if (ansLen == maxlen) ansNum++;
            else
            if (ansLen > maxlen) {
                ansLen = maxlen;
                ansNum = 1;
            }
        }
    }
    /// ket hop 2 mang
    /// for ed[ ][ ]...
    for (int i = mid + 1; i <= r; i++)
        for (int j = -40; j <= 40; j++)
            tmp[i][j] = -inf;

    for (int i = mid + 1; i <= r; i++)
    for (int j = -40; j <= 40; j++)
        for (int k = j + 1; k <= 40; k++)
            tmp[i][j] = max(tmp[i][j], en[mid][j] + en[i][k]);


    for (int i = mid + 1; i <= r; i++)
        for (int j = -40; j <= 40; j++)
            en[i][j] = tmp[i][j];


    /// for bg[ ][ ]...
    for (int i = l; i <= mid; i++)
        for (int j = -40; j <= 40; j++)
            tmp[i][j] = inf;

    for (int i = l; i <= mid; i++)
        for (int j = -40; j <= 40; j++)
            for ()
}

int main() {
   // freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        T[i] = T[i - 1] + a[i];
    }

    /**/ return 0;
}
