#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, pp>
#define pp3 pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 200010
#define base 311097
#define SEG 555
typedef long long ll;
typedef long double ld;
using namespace std;
map<string, int> M;
int d[10];
int n;
string s;

int p[] = {0, 1, 2, 3, 4, 5};

int main() {
   // freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    M["S"] = 0;
    M["M"] = 1;
    M["L"] = 2;
    M["XL"] = 3;
    M["XXL"] = 4;
    M["XXXL"] = 5;

    for (int i = 0; i < 6; i++)
        cin >> d[i];

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        int pos = -1;
        for (int j = 0; j < s.size(); j++)
            if (s[j] == '.') pos = j;
        if (pos != -1) {
            d[M[s]]--;
        }
        else {
            string r1 = "";
            string r2 = "";
            for (int j = 0; j < pos; i++)
                r1 = r1 + s[j];
            for (int j = pos + 1; j < s.size(); j++)
                r2 = r2 + s[j];

        }
    }

    for (int i = 0; i < 6; i++)
    if (d[i] < 0) {
        cout << "NO";
        return 0;
    }


    /**/return 0;
}
