#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 100010
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
int a[N], b[N];
bool f[N];

bool test(int amout) {
   // cout << "check: " << amout << endl;
    for (int i = 2; i <= n; i++) {
        int tmp = 0;
        if (f[i - 1] == false)
            tmp += b[i - 1];
        //cout << i << ": " << tmp << endl;

        if (a[i] + tmp > amout) return false;
        if (a[i] + tmp == amout) continue;
        if (a[i] + tmp < amout) {
            if (f[i] == false && a[i] + tmp + b[i] == amout) {
                f[i] = true;
                continue;
            }
            if (i < n && a[i] + tmp + b[i + 1] == amout) {
                f[i + 1] = true;
                continue;
            }
            if (i < n && f[i] == false && a[i] + tmp + b[i] + b[i + 1] == amout) {
                f[i] = true;
                f[i + 1] = true;
                continue;
            }

       //     cout << "out of " << i << endl;
       //     cout << a[i] << " " << tmp << endl;
            return false;
        }

    }
    return f[n];
}

int main() {
    //freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int nt;
    cin >> nt;
    while (nt--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        /// case 1 :
        int ret = -1;
        memset(f, false, sizeof(f));
        if (test(a[1]))
            ret = max(ret, a[1]);
        /// case 2 :
        memset(f, false, sizeof(f));
        f[1] = true;
        if (test(a[1] + b[1]))
            ret = max(ret, a[1] + b[1]);

        if (n > 1) {
        /// case 3 :
        memset(f, false, sizeof(f));
        f[2] = true;
        if (test(a[1] + b[2]))
            ret = max(ret, a[1] + b[2]);
        /// case 4 :
        memset(f, false, sizeof(f));
            f[1] = true;
            f[2] = true;
            if (test(a[1] + b[1] + b[2]))
                ret = max(ret, a[1] + b[1] + b[2]);
        }
        cout << ret << endl;
    }
   /**/ return 0;
}
