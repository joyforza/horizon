#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 100010
#define mod 1000000007
#define inf 1000000001
#define esp 1e-9
typedef long long ll;
using namespace std;
int n, m;
string s[55];

int get(string s) {
    if (s == "NORTH") return 0;
    if (s == "EAST") return 1;
    if (s == "SOUTH") return 2;
    return 3;
}

int up[55][55];
int dn[55][55];
int L[55][55];
int R[55][55];
int tmp[55][55];
bool f[55][55];

bool check(int x, int y) {
    if (x < 0 || x >= n) return false;
    if (y < 0 || y >= m) return false;
    return (s[x][y] != 'X');
}

void incRow(int id, int l, int r) {
    tmp[id][l]++;
    tmp[id][r + 1]--;
}

void incCol(int id, int l, int r) {
    tmp[l][id]++;
    tmp[r + 1][id]--;
}

void normRow() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            tmp[i][j] += tmp[i][j - 1];
    }
}

void normCol() {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            tmp[j][i] += tmp[j - 1][i];
    }
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        if (s[i][j] != 'X') {

            if (check(i - 1, j)) up[i][j] = up[i - 1][j];
            else
                up[i][j] = i;

            if (check(i, j - 1)) L[i][j] = L[i][j - 1];
            else
                L[i][j] = j;
        }

    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
            if (s[i][j] != 'X') {
                if (check(i + 1, j)) dn[i][j] = dn[i + 1][j];
                else
                    dn[i][j] = i;
                if (check(i, j + 1)) R[i][j] = R[i][j + 1];
                else
                    R[i][j] = j;
            }
    int q;
    cin >> q;
    while(q--) {
        memset(f, false, sizeof(f));
        string t;
        cin >> t;
        int dir = get(t);
        memset(tmp, 0, sizeof(tmp));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (s[i][j] == '*') {
                    f[i][j] = true;
                    //tmp[i][j]--;
                    if (dir == 0) {
                        int l = up[i][j];;
                        int r = i;
                        incCol(j + 1, l + 1, r + 1);
                    }
                    else
                    if (dir == 1) {
                        int r = R[i][j];
                        int l = j;
                        incRow(i + 1, l + 1, r + 1);
                    }
                    else
                    if (dir == 2) {
                        int l = i;
                        int r = dn[i][j];
                        incCol(j + 1, l + 1, r + 1);
                    }
                    else {
                        int l = L[i][j];
                        int r = j;
                        incRow(i + 1, l + 1, r + 1);
                    }
                }
            if (dir == 1 || dir == 3) normRow();
            else
                normCol();
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
            if (s[i][j] != 'X') {
                if (tmp[i + 1][j + 1] - f[i][j] > 0) s[i][j] = '*';
                else
                    s[i][j] = '.';
            }

           /* cout << "TABLE: \n";
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++)
                    cout << tmp[i][j] << " ";
                cout << "\n";
            } */

    }
    for (int i = 0; i < n; i++) cout << s[i] << "\n";




    /**/return 0;
}
