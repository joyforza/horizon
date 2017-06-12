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
int Tup[N];
int Tdown[N];
int dpUp[N];
int dpDown[N];
int a[N];
int n;

void updateUp(int x, int val) {
    while (x > 0) {
        Tup[x] = max(Tup[x], val);
        x = x - (x & (x ^ (x - 1)));
    }
}

int queryUp(int x) {
    int ret = 0;
    while (x < N) {
        ret = max(ret, Tup[x]);
        x = x + (x & (x ^ (x - 1)));
    }
    return ret;
}

void updateDown(int x, int val) {
    while (x < N) {
        Tdown[x] = max(Tdown[x], val);
        x = x + (x & (x ^ (x - 1)));
    }
}

int queryDown(int x) {
    int ret = 0;
    while (x > 0) {
        ret = max(ret, Tdown[x]);
        x = x - (x & (x ^ (x - 1)));
    }
    return ret;
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // init
    dpUp[1] = 1;
    dpDown[1] = 1;
    updateUp(a[1], dpUp[1]);
    updateDown(a[1], dpDown[1]);
    // query
    for (int i = 2; i <= n; i++) {
        dpDown[i] = queryUp(a[i] + 1) + 1;
        dpUp[i] = queryDown(a[i] - 1) + 1;
        updateDown(a[i], dpDown[i]);
        updateUp(a[i], dpUp[i]);
    }
    // get ret
    int ret = 0;
    for (int i = 1; i <= n; i++)
        ret = max(ret, max(dpUp[i], dpDown[i]));
    cout << ret;
    /**/ return 0;
}
