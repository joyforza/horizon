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
#define N 300010
#define maxN 1000001
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n, k;
ppp s[N];
vector <ll> c;
map<ll, int> M;
int T[maxN];
int Len[N];
int Fn[N];
int ListVal[N + N];
int nn;

void up(int x) {
    while (x > 0) {
        T[x]++;
        x = x - (x & (x ^ (x - 1)));
    }
}

int get(int x) {
    int ret = 0;
    while (x < maxN) {
        ret += T[x];
        x = x + (x & (x ^ (x - 1)));
    }
    return ret;
}

bool cmp(ppp x, ppp y) {
    if (x.fi.fi != y.fi.fi) return x.fi.fi < y.fi.fi;
    if (x.fi.se != y.fi.se) return x.fi.se > y.fi.se;
    return true;
}


int check(int x) {
  // cout << "chek = " << x << "\n";

    memset(T, 0, sizeof(T));

    for (int i = 1; i <= n; i++) {
        int ls = s[i].fi.se;
        up(ls);

        ll maxSeg = (ll)Len[i] + x;
        //cout << "add segment: [ " << s[i].fi.fi << " , " << s[i].fi.se << " ]\n";



        int pos = -1;
        int l = 1;
        int r = nn;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ListVal[mid] >= maxSeg) {
                pos = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        if (pos == -1) continue;

        int dem = get(pos);

       // cout << s[i].fi.fi << " ==> " << pos << "\n";
       // cout << "start at: " << Len[i] << "\n";
       // cout << "end at: " << Len[i] + x << "\n";

        if (dem >= k) return i;
    }

    return -1;
}

int main() {
   //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);

    int l = 0;
    int r = 2000000000;


    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &s[i].fi.fi, &s[i].fi.se);
        s[i].se = i;
    }

    sort(s + 1, s + n + 1);

    /// zip
    c.clear();
    M.clear();

    for (int i = 1; i <= n; i++) {
        c.pb(s[i].fi.fi);
        c.pb(s[i].fi.se);
    }

    sort(c.begin(), c.end());
    int cnt = 0;
    for (int i = 0; i < c.size(); i++)
    if (!M.count(c[i])) {
        M[c[i]] = ++cnt;
        nn++;
        ListVal[nn] = c[i];
    }



    for (int i = 1; i <= n; i++) {
        Len[i] = s[i].fi.fi;
        Fn[i] = s[i].fi.se;
       // cout << "FROM: " << s[i].fi.fi << " " << s[i].fi.se << "\n";
        s[i].fi.fi = M[s[i].fi.fi];
        s[i].fi.se = M[s[i].fi.se];
       // cout << "TO: " << s[i].fi.fi << " " << s[i].fi.se << "\n";
    }

    int len = -1;
    int pos = -1;



    while (l <= r) {
        int mid = ((ll)l + r) / 2;


        int rr = check(mid);
        if (rr == -1) {
            r = mid - 1;
        }
        else {
            len = mid;
            pos = rr;
            l = mid + 1;
        }
    }

    if (len == -1) {
        printf("0\n");
        for (int i = 1; i <= k; i++)
            printf("%d ", i);
    }
    else {
        printf("%d\n", len + 1);
        ll st = Len[pos];
        ll fn = Len[pos] + len;

        int dem = 0;
        for (int i = 1; i <= n; i++)
            if (Len[i] <= st && fn <= Fn[i]) {
                printf("%d ", s[i].se);
                dem++;
                if (dem == k) break;
            }
    }

    /**/ return 0;
}
