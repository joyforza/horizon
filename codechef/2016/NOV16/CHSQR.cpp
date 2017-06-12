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
#define N 50100
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
int nt;
int a[555][555];
bool row[555][555];
bool col[555][555];

int main() {
  //  freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        int m = n / 2 + 1;
        int u = 1, v = m;
        while (true) {
            a[u][v] = 1;
            u++;
            v--;
            if (v == 0) break;
        }
        u = m + 1;
        v = n;
        while (true) {
            a[u][v] = 1;
            u++;
            v--;
            if (u > n) break;
        }

        int k = 2;
        for (int i = 1; i <= n; i++)
        if (a[1][i] == 0) {
            u = 1;
            v = i;
            while (true) {
                a[u][v] = k;
                u++;
                v--;
                if (v == 0) break;
            }
            u = i + 1;
            v = n;
            while (true) {
                a[u][v] = k;
                u++;
                v--;
                if (u > n) break;
            }
            k++;
        }

       // cout << n / 2 << "\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                cout << a[i][j] << " ";
            cout << "\n";
        }
    }

    /**/ return 0;
}
