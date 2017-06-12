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
int dp[N][20][9][11];
bool s[55];
int pos[55];

void go(int n, int s4, int s3, int s2, int last) {
    for (int i = 0; i <= 9; i++) {
        go(n + 1, s3 + i, s2 + i, last + i);
    }
}

int main() {
    //freopen("in.in", "r", stdin); // freopen("ou.ou", "w", stdout);

    s[1] = true;
    int dem = 0;
    for (int i = 2; i <= 50; i++)
    if (s[i] == false) {
        for (int j = i + i; j <= 50; j += i)
            s[j] = true;
        pos[i] = dem++;
    }

    /**/ return 0;
}
