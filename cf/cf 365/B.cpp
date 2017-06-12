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
#define N 100010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n, k;
int a[N];
ll ret = 0;
int c[N];
bool dd[N];

int getNext(int x) {
    x++;
    if (x > n) x = 1;
    return x;
}

int getPre(int x) {
    x--;
    if (x == 0) x = n;
    return x;
}

int main() {
   // freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    ll sumAll = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sumAll += a[i];
    }

    ll cnt = 0;


    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        dd[c[i]] = true;
        cnt += a[c[i]];
    }


    for (int i = 1; i <= n; i++)
    if (dd[i] == false) {
        ll mul = cnt;

        if (dd[i]) mul -= a[i];

        int nxt = getNext(i);
        int pre = getPre(i);

        if (dd[nxt] == false)
            mul += a[nxt];

        if (dd[pre] == false)
            mul += a[pre];
        ret += mul * a[i];
    }
    else {
        ret += (sumAll - a[i]) * a[i];
    }
    cout << ret / 2;
   /**/ return 0;
}
