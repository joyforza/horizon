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
int n, q;
int s[N];
int cnt;

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt = 0;
        for (int j = 1; j <= sqrt(x); i++)
        if (x % j == 0) {
            int tmp = x;
            while (tmp % j == 0) {cnt++; tmp /= j;}
            if (x / j != j) {
                tmp = x;
                int val = x / j;
                while (tmp % val == 0) {cnt++; tmp /= val;}
            }
        }
        s[i] = s[i - 1] + x;
    }

    /**/return 0;
}
