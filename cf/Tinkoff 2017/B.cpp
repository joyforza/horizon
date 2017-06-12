#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 1000010
#define inf 1000000001
#define mod 1000000007
typedef long long ll;
using namespace std;
int n, m;
int bx, by;
int ex, ey;
string s[1010];
bool canA[1010];
bool canB[1010];
bool rowA[1010];
bool rowB[1010];

int main() {
	freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++)
        if (s[i][j] == 'S') {
            bx = i;
            by = j;
        }
        else
        if (s[i][j] == 'T') {
            ex = i;
            ey = j;
        }
    }

    canA[by] = true;
    for (int i = by - 1; i >= 0; i--)
        if (s[bx][i] == '.') canA[i] = true;
        else
            if (s[bx][i] == '*') break;

    for (int i = by + 1; i < m; i++)
        if (s[bx][i] == '.') canA[i] = true;
        else
            if (s[bx][i] == '*') break;

    canB[ey] = true;
    for (int i = ey - 1; i >= 0; i--)
        if (s[ex][i] == '.') canB[i] = true;
        else
            if (s[ex][i] == '*') break;

    for (int i = ey + 1; i < m; i++)
        if (s[ex][i] == '.') canB[i] = true;
        else
            if (s[ex][i] == '*') break;

    rowA[bx] = true;
    for (int i = bx - 1; i >= 0; i--)
        if (s[i][by] == '.') rowA[i] = true;
        else
           if (s[i][by] == '*') break;

    for (int i = bx + 1; i < n; i++)
        if (s[i][by] == '.') rowA[i] = true;
        else
            if (s[i][by] == '*') break;

    rowB[ex] = true;
    for (int i = ex - 1; i >= 0; i--)
        if (s[i][ey] == '.') rowB[i] = true;
        else
            if (s[i][ey] == '*') break;

    for (int i = ex + 1; i < n; i++)
        if (s[i][ey] == '.') rowB[i] = true;
        else
            if (s[i][ey] == '*') break;

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (canA[i] && canB[i]) {
            bool ok = true;
            for (int j = min(bx, ex); j <= max(bx, ex); j++) {
                if (s[j][i] == '*') { ok = false; break; }
            }
            cnt += ok;
        }
    }

    for (int i = 0; i < n; i++) {
        if (rowA[i] && rowB[i]) {
            bool ok = true;
            for (int j = min(by, ey); j <= max(by, ey); j++) {
                if (s[i][j] == '*') {ok = false; break;}
            }
            cnt += ok;
        }
    }

    if (cnt) cout << "YES";
    else
        cout << "NO";
	/**/return 0;
}
