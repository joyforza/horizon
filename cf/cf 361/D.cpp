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
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
int a[N];
int b[N];
int Tmax[N][20];
int Tmin[N][20];

int getMax(int l, int r) {
    int k = (log(r - l + 1) / log(2));
    return max(Tmax[l][k], Tmax[r - (1 << k) + 1][k]);
}

int getMin(int l, int r) {
    int k = (log(r - l + 1) / log(2));
    return min(Tmin[l][k], Tmin[r - (1 << k) + 1][k]);
}

int com(int l, int r) {
    return getMax(l, r) - getMin(l, r);
}

int main() {
   // freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &Tmax[i][0]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &Tmin[i][0]);

    for (int L = 1; L < 18; L++)
    for (int i = 1; i <= n - (1 << L) + 1; i++) {
        int p = i + (1 << (L - 1));
        Tmax[i][L] = max(Tmax[i][L - 1], Tmax[p][L - 1]);
        Tmin[i][L] = min(Tmin[i][L - 1], Tmin[p][L - 1]);
    }

    ll ret = 0;
   for (int i = 1; i <= n; i++) {
        int Test = a[i] - b[i];
        if (Test > 0) continue;
        if (com(i, n) < 0) continue;
        int l = i, r = n;
        int head = -1, tail = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
           // cout << i << " " << com(i, mid) << endl;
            if (com(i, mid) >= 0) {
                head = mid;
                r = mid - 1;

            }
            else
                l = mid + 1;
        }

        if (head == -1) continue;
        if (com(i, head) != 0) continue;

        l = head, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (com(i, mid) == 0) {
                tail = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        ret += (tail - head + 1);
    }
    cout << ret;
/**/ return 0;
}
