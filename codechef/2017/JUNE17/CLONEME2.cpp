#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define pp4 pair<pp, pp>
#define fi first
#define se second
#define N 100010
#define mod 1000000007
#define inf 1000000001
#define esp 1e-9
#define BLOCK 555
#define BITNUM 1563
typedef long long ll;
using namespace std;
struct mb {
    ll x[BITNUM + 1];
};

int nt;
int n, q, m;
int a[N + 1];
ppp qr[N + N + 1];
int cnt[N + 1];
ll bitMap[BITNUM + 1];
vector<mb> dp;
int stt;
pp mask[N + 1];
vector<int> pos[N + 1];
int mapping[N + 1];
bool res[N + 1];
int last[N + 1];


void addBit(int val) {
	if (val == 0) return;
    int pos = (val - 1) % 64;
    int nbit = (val - 1) / 64;
    bitMap[nbit] |= (1ll << pos);
}

void delBit(int val) {
    if (val == 0) return;
    int pos = (val - 1) % 64;
    int nbit = (val - 1) / 64;
    bitMap[nbit] ^= (1ll << pos);
}

int getPos(int i, int j) {
	if (pos[i].size() < j) return 0;
	if (j - 1 < 0) return 0;
	return pos[i][j - 1];
}

void add(int x) {
    cnt[x]++;
    addBit(getPos(x, cnt[x]));
}

void rm(int x) {
    delBit(getPos(x, cnt[x]));
    cnt[x]--;
}

bool cmp(ppp a, ppp b) {
    pp x = a.fi;
    pp y = b.fi;
    if (x.fi / BLOCK != y.fi / BLOCK) return (x.fi < y.fi);
    return x.se < y.se;
}


bool compare(int u) {

    int cnt = 0;
    int p1 = 0;
    int p2 = 0;
    int l1 = -1;
    int r1 = -1;
    int l2 = -1;
    int r2 = -1;

    for (int i = 0; i < BITNUM; i++) {

    	ll x = (dp[u].x[i] ^ bitMap[i]);

    	int cur = __builtin_popcountll(x);
    	cnt += cur;


    	if (cnt > 2) return false;

    	if (cur > 0) {
            int zz = 0;

    		for (int j = 0; j < 64; j++)
    			if ((x >> j) & 1) { // O (2 x 64)

    				if ((dp[u].x[i] >> j) & 1) {
    					zz++;
    					r1 = p1;
    					for (int k = 0; k <= j; k++)
    						r1 += ((dp[u].x[i] >> k) & 1);
    					l1 = r1 - mask[j + i * 64 + 1].se + 1;
     				}

                    if (zz == 2) return false;

    				if ((bitMap[i] >> j) & 1) {
    					r2 = p2;
    					for (int k = 0; k <= j; k++)
    						r2 += ((bitMap[i] >> k) & 1);
    					l2 = r2 - mask[j + i * 64 + 1].se + 1;
    				}
    			}
    	}

    	p1 += __builtin_popcountll(dp[u].x[i]);
    	p2 += __builtin_popcountll(bitMap[i]);
    }

    if (l1 <= r2 && r2 <= r1) return true;
    if (l1 <= l2 && l2 <= r1) return true;
    return false;
}

int main() {
        //freopen("in.in", "r", stdin);
    	scanf("%d", &nt);
    	while(nt--) {

        memset(mapping, 0, sizeof(mapping));

        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            mapping[a[i]]++;
        }

        for (int i = 1; i < N; i++)
        	pos[i].clear();

        int ncnt = 0;
        for (int i = 1; i < N; i++)
        	if (mapping[i] > 0) {
        		for (int j = 1; j <= mapping[i]; j++) {
        			mask[++ncnt] = mp(i, j);
        			pos[i].pb(ncnt);
        		}
        	}



        for (int i = 1; i <= q; i++) {
            int u, v, x, y;
            scanf("%d%d%d%d", &u, &v, &x, &y);
            qr[i + i - 1] = mp(mp(u, v), i);
            qr[i + i] = mp(mp(x, y), i);
        }

        sort(qr + 1, qr + q + q + 1, cmp);

        memset(cnt, 0, sizeof(cnt));
        memset(bitMap, 0, sizeof(bitMap));
 		//memset(dp, 0, sizeof(dp));
        memset(last, -1, sizeof(last));
        memset(res, false, sizeof(res));

        m = 0;
        int l = 0;
        int r = 0;
        stt = 0;

        for (int i = 1; i <= q + q; i++) {

            int nl = qr[i].fi.fi;
            int nr = qr[i].fi.se;
            int callPos = qr[i].se;
            // MO's algorithm
            while (l < nl) {
                if (a[l] > 0) rm(a[l]);
                l++;
            }

            while (l > nl) {
                add(a[l - 1]);
                l--;
            }

            while (r < nr) {
                add(a[r + 1]);
                r++;
            }

            while (r > nr) {
                rm(a[r]);
                r--;
            }

            if (last[callPos] == -1) {
                mb tmp;
                for (int j = 0; j < BITNUM; j++) {
                    tmp.x[j] = bitMap[j];
                }
                dp.pb(tmp);
                last[callPos] = dp.size() - 1;
            }
            else {
                res[callPos] = compare(last[callPos]);
            }
        }

        for (int i = 1; i <= q; i++) {
            if (res[i]) puts("YES");
            else
                puts("NO");
        }
    }
	return 0;
}
