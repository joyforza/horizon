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
#define SEG 555
typedef long long ll;
typedef long double ld;
using namespace std;
int nxt[N];
vector <int> ds[N];
int Back[1000100];
int a[N];
int n, m;

void cat(int pos, int x) {
   ds[pos].clear();
   while (x > 1) {
        int d = Back[x];
        while (x % d == 0) {
            ds[pos].pb(d);
            x /= d;
        }
    }
}

void update(int l, int r) {
    int tmp = l;
    while (true) {
        /// that's special
        if (ds[nxt[tmp]].size() == 0)
            nxt[tmp] = nxt[nxt[tmp]];

        tmp = nxt[tmp];

        if (tmp > r) break;

        if (ds[tmp].size() > 0) {
            ds[tmp].pop_back();
        }

        if (ds[tmp].size() == 0) {
            nxt[tmp] = nxt[tmp + 1];
        }

        tmp++;
    }
}

int query(int l, int r) {
    int ret = 1;
    int tmp = l;
    while (true) {
        tmp = nxt[tmp];
        /// that's special
        if (ds[nxt[tmp]].size() == 0)
            nxt[tmp] = nxt[nxt[tmp]];

        if (tmp > r) break;
        int val = (ds[tmp].size() == 0 ? 1 : ds[tmp][ds[tmp].size() - 1]);
        ret = max(ret, val);

        if (ds[tmp].size() == 0)
            nxt[tmp] = nxt[tmp + 1];

        tmp++;
    }
    return ret;
}

int main() {
   // freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);

    for (int i = 2; i <= 1000000; i++)
    if (Back[i] == 0) {
        for (int j = i + i; j <= 1000000; j += i) {
            Back[j] = i;
        }
        Back[i] = i;
    }
    int nt;
    scanf("%d", &nt);
    while (nt--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            cat(i, a[i]);
            nxt[i] = i;
        }
        nxt[n + 1] = n + 1;

        for (int i = 1; i <= m; i++) {
            int tp, l, r;
            scanf("%d%d%d", &tp, &l, &r);
            if (tp == 0)
                update(l, r);
            else
                printf("%d ", query(l, r));
        }
        printf("\n");
    }
    /**/ return 0;
}
