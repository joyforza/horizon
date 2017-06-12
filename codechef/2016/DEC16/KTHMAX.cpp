#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<int, pp>
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

struct SuffixArray {
	static const int MAXN = 100000 + 10;
	int T[MAXN];
	int nsz;
	int RA[MAXN], tmpRA[MAXN];
	int SA[MAXN], tmpSA[MAXN];
	int c[MAXN];
	int Phi[MAXN], PLCP[MAXN];
	int LCP[MAXN];

	void init(int str[], int n) {

		for (int i = 0; i < n; i++) T[i] = str[i];
		nsz = n;

		for (int i = 0; i < nsz; i++) {
			RA[i] = tmpRA[i] = 0;
			SA[i] = tmpSA[i] = 0;
			Phi[i] = PLCP[i] = LCP[i] = 0;
		}

		constructSA();
		computeLCP();
	}

	void countingsort(int k) {
		int sum = 0, maxi = max(300, nsz);
		memset(c, 0, sizeof(c));
		for (int i = 0; i < nsz; i++) c[i + k < nsz ? RA[i + k] : 0]++;
		for (int i = 0; i < maxi; i++) {
			int t = c[i]; c[i] = sum; sum += t;
		}
		for (int i = 0; i < nsz; i++) tmpSA[c[SA[i] + k < nsz ? RA[SA[i] + k] : 0]++] = SA[i];
		for (int i = 0; i < nsz; i++) SA[i] = tmpSA[i];
	}

	void constructSA() {
		int r;
		for (int i = 0; i < nsz; i++) RA[i] = T[i];
		for (int i = 0; i < nsz; i++) SA[i] = i;
		for (int k = 1; k < nsz; k <<= 1) {
			countingsort(k);
			countingsort(0);
			tmpSA[SA[0]] = r = 0;
			for (int i = 1; i < nsz; i++) tmpRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
			for (int i = 0; i < nsz; i++) RA[i] = tmpRA[i];
			if (RA[SA[nsz - 1]] == nsz - 1) break;
		}
	}

	void computeLCP() {
		int L = 0;
		Phi[SA[0]] = -1;
		for (int i = 1; i < nsz; i++) Phi[SA[i]] = SA[i - 1];
		for (int i = 0; i < nsz; i++) {
			if (!~Phi[i]) {PLCP[i] = 0; continue;}
			while (T[i + L] == T[Phi[i] + L]) L++;
			PLCP[i] = L;
			L = max(L - 1, 0);
		}
		for (int i = 0; i < nsz; i++) LCP[i] = PLCP[SA[i]];
	}
} sa;

int nt, n, m;
int a[N];
int ret[N];
int Tmax[N][18];
vector <ppp> qu;
int tmp[N];
int ans[N];
int T[N];

void up(int x, int val) {
    while (x < N) {
        T[x] += val;
        x = x + (x & (x ^ (x - 1)));
    }
}

int get(int x) {
    int cnt = 0;
    while (x > 0) {
        cnt += T[x];
        x = x - (x & (x ^ (x - 1)));
    }
    return cnt;
}

/// (log^2)
int findK(int x) {
    int l = 1;
    int r = n;
    int ret;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (get(mid) <= x) {
            ret = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ret;
}

int getMax(int l, int r) {
    int k = log2(r - l + 1);
    return max(Tmax[l][k], Tmax[r - (1 << k) + 1][k]);
}

ppp add(int p, int pos) {
   // cout << "query = " << p << "\n";

    p = tmp[n] - p + 1;


    cout << p << "\n";

    int l = 0;
    int r = n;
    int ret;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (p <= tmp[mid]) {
            ret = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }


    int kth = p - tmp[ret - 1];
    cout << p << " " << ret << "\n";
    cout << "at = " << kth << "\n";

    return mp(ret, mp(kth, pos));
}

int main() {
    freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    cin >> nt;
    while (nt--) {
        memset(T, 0, sizeof(T));

        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            tmp[i] = tmp[i - 1] + (n - i + 1);
        }

        for (int i = 0; i < n; i++) cin >> a[i];

        sa.init(a, n);

        for (int i = 0; i < n; i++) ret[n - sa.SA[i]] = i;

        /// RMQ
        for (int i = 0; i < n; i++)
            Tmax[i][0] = a[i];
        for (int j = 1; j < 18; j++)
            for (int i = 0; i < n; i++)
                Tmax[i][j] = max(Tmax[i][j - 1], Tmax[i + (1 << (j - 1))][j - 1]);

        qu.clear();
        for (int i = 1; i <= m; i++) {
            int p;
            cin >> p;
            qu.pb(add(p, i));
        }

        sort(qu.begin(), qu.end());

        /// init BIT
        for (int i = 1; i <= n; i++) up(i, 1);

        int cur = 1;
        for (int i = 0; i < qu.size(); i++) {
            int kth = qu[i].se.fi;
            int len = qu[i].fi;

            /// delete
            while (cur < len) {
                up(ret[cur] + 1, -1);
                cur++;
            }
            /// find kth
            int pos = findK(kth);

            cout << pos << "\n";

            int x = qu[i].se.se;
            ans[x] = getMax(sa.SA[pos - 1], sa.SA[pos - 1] + len - 1);


        }
        /**/
        for (int i = 1; i <= m; i++)
            cout << ans[i] << "\n";
    }
    /**/ return 0;
}
