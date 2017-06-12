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
#define N 45000
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int cnt0;
int cnt1;
int down, up;
int n0, n1;
int cc[N];

int get(int x) {
    for (int i = 2; i < N; i++)
        if (i * (i - 1) == x) return i;
    return -1;
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n0 >> up >> down >> n1;

    if (n0 == 0 && n1 == 0 && up == 0 && down == 0) {
        cout << 0;
        return 0;
    }

    cnt0 = get(2 * n0);
    cnt1 = get(2 * n1);


    if (down > 0 && n1 > 0 && n0 == 0 && up == 0) cnt0 = 1;
    if (up > 0 && n0 > 0 && down == 0 && n1 == 0) cnt1 = 1;

    if (cnt0 > 0 && cnt1 == -1) {
        if (up == 0 && down == 0) {
            for (int i = 1; i <= cnt0; i++)
                cout << 0;
        }
        else {
            cout << "Impossible";
        }
        return 0;
    }

    if (cnt1 > 0 && cnt0 == -1) {
        if (up == 0 && down == 0) {
            for (int i = 1; i <= cnt1; i++)
                cout << 1;
        }
        else {
            cout << "Impossible";
        }
        return 0;
    }

    if (cnt0 == -1 || cnt1 == -1) {
        cout << "Impossible";
        return 0;
    }

    ll n = cnt0 + cnt1;
    ll sum = n0;
    sum += n1;
    sum += down;
    sum += up;

    if (n * (n - 1) / 2 != sum) {
        cout << "Impossible";
        return 0;
    }

    ll tot = (ll)cnt0 * cnt1;
    if (tot - down != up) {
        cout << "Impossible";
        return 0;
    }


    int rr_div = up / cnt0;
    int rr_mod = up % cnt0;

    if (rr_mod > 0) {
        cc[rr_mod]++;
        cnt1--;
    }

    cc[cnt0] = rr_div;
    cnt1 -= rr_div;

    for (int i = 1; i <= cnt1; i++)
        cout << 1;
    for (int i = 1; i <= cnt0; i++) {
        cout << 0;
        for (int j = 1; j <= cc[i]; j++) cout << 1;
    }
    /**/ return 0;
}
