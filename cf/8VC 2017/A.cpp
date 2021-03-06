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
#define N 123
#define base 311097
#define MAXN 505
#define MAXE 1000001
#define sqr(x) (x)*(x)
#define RL double
#define EPS 1e-9
#define ll long long
using namespace std;

bool s[MAXE];
int n;

int main() {
   // freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);

    for (int i = 2; i < MAXE; i++)
    if (s[i] == false) {
        for (int j = i + i; j < MAXE; j += i)
            s[j] = true;
    }
    s[1] = true;
    cin >> n;
    for (int i = 1; i <= 1000; i++)
    if (s[i * n + 1]) {
        cout << i;
        break;
    }

    return 0;
}
