#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 100010
#define base 311097
#define SEG 555
typedef long long ll;
typedef long double ld;
using namespace std;
int n, k;
int d[123];
string s;

int norm(int x) {
    int d = x / k - (x % k == 0);
    return x + d * 5;
}

int main() {
    //freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        d[s.size()]++;
    }
    cin >> s;
    int best = 0, worst = 0;

    for (int i = 1; i <= 100; i++)
    if (i == s.size()) {
        best++;
        worst += d[i];
        break;
    }
    else {
        best += d[i];
        worst += d[i];
    }


    cout << norm(best) << " " << norm(worst);
    /**/return 0;
}
