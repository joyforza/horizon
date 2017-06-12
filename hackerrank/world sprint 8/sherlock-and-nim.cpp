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
int nt;

int L[33];
int R[33];

bool canWin(vector<int> a) {
    if (a.size() == 1) return true;
    int minVal = a[0];

    L[0] = a[0];
    for (int i = 1; i < a.size(); i++)
        L[i] = L[i - 1] ^ a[i];
    R[a.size() - 1] = a[a.size() - 1];
    for (int i = a.size() - 2; i >= 0; i--)
        R[i] = R[i + 1] ^ a[i];

    bool ok = true;

    if (R[1] == 0) return true;
    if (L[a.size() - 2] == 0) return true;

    for (int i = 1; i < a.size() - 1; i++) {
        int val = L[i - 1] ^ R[i + 1];
        if (val == 0) return true;
    }

    for (int i = 1; i <= minVal; i++) {
        for (int j = 0; j < a.size(); j++)
            a[j] -= i;
        ok &= canWin(a);
        if (!ok) return true;
        for (int j = 0; j < a.size(); j++)
            a[j] += i;
    }


    return false;
}

int n;
vector <int> tmp;


int main() {
    //freopen("in.in", "r", stdin); // freopen("ou.ou", "w", stdout);
    cin >> nt;
    while (nt--) {
        tmp.clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            tmp.pb(x);
        }
        if (canWin(tmp)) {
            cout << "Sherlock\n";
        }
        else
            cout << "Watson\n";
    }

    /**/ return 0;
}
