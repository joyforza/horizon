#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 500010
#define mod 1000000007
#define inf 1000000001
#define esp 1e-9
typedef long long ll;
using namespace std;
int n, k;
int a[N];
map<int, int> M;
int s[N];
int dp[N];
int cnt;
int f[N];

void del(int x) {
    if (x > k) return;
    M[x]--;
    if (M[x] == 0) cnt--;
}

void add(int x) {
    if (x > k) return;
    M[x]++;
    if (M[x] == 1) cnt++;
}

bool check() {
    return (cnt == k + 1);
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int rr = 0;
    for (int i = 1; i <= n; i++) {
        if (rr < i) {
            rr = i;
            add(a[i]);
        }

        //cout << check() << "\n";

        if (i > 1) del(a[i - 1]);
        while (!check() && rr < n) {
            rr++;
            add(a[rr]);
        }
        if (check()) f[i] = rr - 1;
        else
            f[i] = rr;
    }


    dp[n + 1] = 1;
    s[n + 1] = 1;
    for (int i = n; i >= 1; i--) {
        int l = i + 1;
        int r = f[i] + 1;
       // cout << l << " " << r << "\n";
        int add = (s[l] - s[r + 1]) % mod;
        if (add < 0) add += mod;
       // cout << "add = " << add << "\n";
        dp[i] = add;
        s[i] = (s[i + 1] + dp[i]) % mod;
    }

    cout << dp[1];
    /**/return 0;
}
