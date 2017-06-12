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
#define N 1000100
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int nt;
int const MAXN = 300000 + 10;
bool f[MAXN];
int dp[MAXN];

struct KMP {
	char s[MAXN];
	int nsz, link[MAXN];
	void init(char* str) {
		strcpy(s, str); nsz = strlen(s);
		int cur = link[0] = -1;
		for (int i = 1; i < nsz; i++) {
			while (cur >= 0 && s[i] != s[cur + 1]) cur = link[cur];
			if (s[i] == s[cur + 1]) cur++;
			link[i] = cur;
		}
	}
	void search(char* t) {
		int k = strlen(t);
		int cur = -1;
		for (int i = 0; i < k; i++) {
			while (cur >= 0 && t[i] != s[cur + 1]) cur = link[cur];
			if (t[i] == s[cur + 1]) cur++;
			if (cur == nsz - 1) {
				f[i] = true;
				cur = link[cur];
			}
		}
	}
};
KMP kmp;
char s[MAXN];
char t[MAXN];

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while(nt--) {
        memset(f, false, sizeof(f));
        memset(dp, 0, sizeof(dp));
        cin >> s;

        cin >> t;

        kmp.init(t);
        kmp.search(s);
        int n = strlen(s);
        int m = strlen(t);


        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        if (f[i - 1]) {
            dp[i] = (dp[i - 1] + dp[i - m]) % mod;
        }
        else
            dp[i] = dp[i - 1];

        cout << (dp[n] - 1 + mod) % mod << "\n";
    }
    /**/ return 0;
}
