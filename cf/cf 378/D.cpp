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
#define N 100100
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
map<pp, pp> M;
ppp best = mp(mp(0, 0), 0);
int id = 1;
ppp best2 = mp(mp(0, 0), 0);
int id1 = -1;
int id2 = -1;

/// return x > y
bool cmp(ppp x, ppp y) {
    if (x == mp(mp(0, 0), 0)) return false;
    if (y == mp(mp(0, 0), 0)) return true;

    int L1 = x.fi.fi;
    int R1 = x.fi.se;
    int H1 = x.se;

    int L2 = y.fi.fi;
    int R2 = y.fi.se;
    int H2 = y.se;


    return min(L1, min(R1, H1)) > min(L2, min(R2, H2));
}

void com(int L, int R, int H, int id) {
    pp stt = mp(L, R);
    if (!M.count(stt)) return;

    int lastId = M[stt].se;
    int lastH = M[stt].fi;

    ppp newRec = mp(mp(L, R), H + lastH);

    if (cmp(newRec, best2)) {
            best2 = newRec;
            id1 = lastId;
            id2 = id;
    }
}

void add(int L, int R, int H, int id) {

    pp stt = mp(L, R);
    if (!M.count(stt)) {
        M[stt] = mp(H, id);
    }
    else {
        int lastH = M[stt].fi;
        if (lastH < H) {
            M[stt] = mp(H, id);
        }
    }
}

int main() {

    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        ppp newBest = mp(mp(x, y), z);

        if (cmp(newBest, best)) {
            best = newBest;
            id = i;
        }

        com(x, y, z, i);
        com(y, x, z, i);
        com(x, z, y, i);
        com(z, x, y, i);
        com(y, z, x, i);
        com(z, y, x, i);
        add(x, y, z, i);
        add(y, x, z, i);
        add(x, z, y, i);
        add(z, x, y, i);
        add(y, z, x, i);
        add(z, y, x, i);
    }

    if (cmp(best, best2)) {
        cout << 1 << "\n";
        cout << id << "\n";
    }
    else {
        cout << 2 << "\n";
        cout << id1 << " " << id2 << "\n";
    }
    /**/ return 0;
}
