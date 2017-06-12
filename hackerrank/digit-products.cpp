#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, ll>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 101
typedef long long ll;
typedef long double ld;
using namespace std;
int nt;
string a, b;
map <pp, int> M;
ll K;

bool check(int n, ll k) {
    if (n > 18) return false;
    ll tmp = 1;
    for (int i = 1; i <= n; i++)
        tmp *= 9;
    if (tmp < k) return true;
    return false;
}

int fun(int n, ll k) {
    if (n == 0) {
        if (k > 1) return 0;
        else
            return 1;
    }
    if (M.count(mp(n, k))) return M[mp(n, k)];
    if (n == 1) {
        if (k > 9) return 0;
        else
            return 1;
    }

    if (check(n, k)) return 0;

    ll ret = 0;
    for (int i = 1; i < 10; i++)
        if (k % i == 0)
            ret = (ret + fun(n - 1, k / i)) % mod;

    M[mp(n, k)] = ret;
    return ret;
}

int get(int n, ll k) {
    ll ret = 0;
    for (int i = 1; i <= n; i++)
        ret = (ret + fun(i, k)) % mod;
    return ret;
}

ll com(string c, int sg) {
    ll RR = K;
    int n = c.size();
    ll ret = 0;
    if (n > 1) ret = get(n - 1, RR);

    for (int i = 0; i < n; i++) {
        if (c[i] == '0') return ret;

        int digit = c[i] - '0';
        for (int j = 1; j < digit; j++)
            if (RR % j == 0)
                ret = (ret + fun(n - 1 - i, RR / j)) % mod;

        if (RR % digit != 0) return ret;
        RR /= digit;
    }

    if (sg)
        ret = (ret + (RR == 1)) % mod;
    return ret;
}


int main() {
    //freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);


    cin >> nt;
    for (int kk = 1; kk <= nt; kk++) {
        cin >> a >> b >> K;
        cout << "Case " << kk << ": " << com(b, 1) - com(a, 0) << endl;
    }
   /**/ return 0;
}
