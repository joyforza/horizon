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
#define N 10010
#define base 311097
#define MAXN 505
#define MAXE 1000001
#define sqr(x) (x)*(x)
#define RL double
#define EPS 1e-9
#define ll long long
using namespace std;
int n;
int lab[N];

void uni(int r1, int r2) {
    int x = lab[r1] + lab[r2];
    if (lab[r1] < lab[r2]) {
        lab[r1] = x;
        lab[r2] = r1;
    }
    else {
        lab[r2] = x;
        lab[r1] = r2;
    }
}

int get(int x) {
    if (lab[x] < 0) return x;
    lab[x] = get(lab[x]);
    return lab[x];
}

int main() {
    //freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    memset(lab, -1, sizeof(lab));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int r1 = get(i);
        int r2 = get(x);
        if (r1 != r2) uni(r1, r2);
    }

    set<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(get(i));
    }

    cout << s.size();
    return 0;
}
