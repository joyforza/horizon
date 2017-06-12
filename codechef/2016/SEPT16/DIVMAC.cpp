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
int nt;
int n, m;
vector <int> ds[N];
int a[N];
int Back[1000100];

struct seg {
    int pos;
    int rmax[22];
    int l, r;
    bool done; /// all element to be 1
};

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

seg T[333];

void initSeg(int id) {

    if (T[id].done) return;

    T[id].pos = 0;
    for (int i = 0; i <= 20; i++) {
        T[id].rmax[i] = -inf;
        for (int j = T[id].l; j <= T[id].r; j++)
            if (ds[j].size() <= i)
                T[id].rmax[i] = max(T[id].rmax[i], 1);
            else
                T[id].rmax[i] = max(T[id].rmax[i], ds[j][i]);
    }

    if (T[id].rmax[0] == 1) T[id].done = true;
}

void normSeg(int id) {
    if (T[id].pos >= 20) {
        T[id].done = true;
    }
    if (T[id].done) return;

    for (int j = T[id].l; j <= T[id].r; j++) {
        for (int i = 1; i <= T[id].pos; i++)
            if (ds[j].size() == 0) break;
            else
                ds[j].pop_back();
    }
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    for (int i = 2; i <= 1000000; i++)
    if (Back[i] == 0) {
        for (int j = i + i; j <= 1000000; j += i) {
            Back[j] = i;
        }
        Back[i] = i;
    }

    scanf("%d", &nt);
    while (nt--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            cat(i, a[i]);
        }
        for (int i = 1; i <= n; i++) {
            T[i / SEG].l = min(T[i / SEG].l, i);
            T[i / SEG].r = max(T[i / SEG].r, i);
        }

        for (int i = 0; i <= n / SEG; i++) {
            initSeg(i);
            T[i].done = false;
        }

        for (int i = 1; i <= m; i++) {
            int tp, l, r;
            cin >> tp >> l >> r;
            if (tp == 0) {

                if (l / SEG == r / SEG) {
                    if (T[l / SEG].done == false) {
                        normSeg(l / SEG);

                        for (int j = l; j <= r; j++) {
                            if (ds[j].size() > 0) ds[j].pop_back();
                        }

                        initSeg(l / SEG);
                    }
                }
                else {
                    int st = l / SEG;
                    int fn = r / SEG;

                    for (int j = st + 1; j < fn; j++)
                    if (T[j].done == false) {
                            T[j].pos++;
                            if (T[j].pos >= 20)
                                T[j].done = true;
                    }

                    if (T[st].done == false) {
                        normSeg(st);
                        for (int j = l; j <= T[st].r; j++)
                            if (ds[j].size() > 0) ds[j].pop_back();
                        initSeg(st);
                    }

                    if (T[fn].done == false) {
                        normSeg(fn);
                        for (int j = T[fn].l; j <= r; j++)
                            if (ds[j].size() > 0) ds[j].pop_back();
                        initSeg(fn);
                    }
                }
            }
            else {
                int ans = -inf;
                if (l / SEG == r / SEG) {
                    if (T[l / SEG].done) ans = 1;
                    else {
                        for (int j = l; j <= r; j++) {
                            if (ds[j].size() == 0) ans = max(ans, 1);
                            else
                                ans = max(ans, ds[j][ds[j].size() - 1]);
                        }
                    }
                }
                else {
                    int st = l / SEG;
                    int fn = r / SEG;


                        for (int j = st + 1; j < fn; j++) {
                            if (T[j].done) ans = max(ans, 1);
                            else
                                ans = max(ans, T[j].rmax[min(T[j].pos, 20)]);
                        }


                    if (T[st].done) ans = max(ans, 1);
                    else {
                        for (int j = l; j <= T[st].r; j++)
                            if (ds[j].size() == 0) ans = max(ans, 1);
                            else
                                ans = max(ans, ds[j][ds[j].size() - 1]);
                    }

                    if (T[fn].done) ans = max(ans, 1);
                    else {
                        for (int j = T[fn].l; j <= r; j++)
                            if (ds[j].size() == 0) ans = max(ans, 1);
                            else
                                ans = max(ans, ds[j][ds[j].size() - 1]);
                    }
                }
                printf("%d ", ans);
            }
        }
        printf("\n");
    }
    /**/ return 0;
}
