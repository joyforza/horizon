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
#define N 400010
#define base 311097
#define N3 9
#define N4 11
typedef long long ll;
typedef long double ld;
using namespace std;
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int n;
bool s[55];
int x[55];
int m = 9;
int ret = 0;

bool check() {
    for (int i = 1; i <= m - 2; i++) {
        if (s[x[i] + x[i + 1] + x[i + 2]]) return false;
    }
    for (int i = 1; i <= m - 3; i++) {
        if (s[x[i] + x[i + 1] + x[i + 2] + x[i + 3]]) return false;
    }

    for (int i = 1; i <= m - 4; i++) {
        if (s[x[i] + x[i + 1] + x[i + 2] + x[i + 3] + x[i + 4]]) return false;
    }

    for (int i = 1; i <= m - 2; i++) {
        cout <<  (x[i] + x[i + 1] + x[i + 2]) << " ";
    }

    cout << "\n";

     for (int i = 1; i <= m - 3; i++) {
        cout << (x[i] + x[i + 1] + x[i + 2] + x[i + 3]) << " ";
    }

    cout << "\n";

    for (int i = 1; i <= m - 4; i++) {
        cout << (x[i] + x[i + 1] + x[i + 2] + x[i + 3] + x[i + 4]) <<" ";
    }

    cout << "\n";

    return true;
}

void out() {
    ret++;
    for (int i = 1; i <= m; i++)
        cout << x[i];
    cout << "\n";
}

void go(int n) {
    if (n == m + 1) {
        if (check()) out();
        return;
    }

    for (int i = 0; i <= 9; i++) {
        x[n] = i;
        go(n + 1);
    }
}

int main() {
    //freopen("in.in", "r", stdin); // freopen("ou.ou", "w", stdout);
    s[0] = true;
    s[1] = true;
    for (int i = 2; i <= 50; i++)
    if (s[i] == false) {
        for (int j = i + i; j <= 50; j += i)
            s[j] = true;
    }

    for (int i = 1; i <= 9; i++) {
        x[1] = i;
        go(2);
    }

    cout << "total = " << ret;
    /**/ return 0;
}
