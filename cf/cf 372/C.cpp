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
#define N 100010
#define base 311097
#define SEG 555
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
vector<ll> nxt[N];
ll tmp;

ll gcd(ll a, ll b) {
    while (b > 0) {
       ll r = a % b;
       a = b;
       b = r;
    }
    return a;
}

bool isSquare(int x) {
    int k = sqrt(x);
    return (k * k == x);
}

ll get(int x, ll cur) {
    ll tu = (ll) x * x;
    int mau = (x - 1);


    ll rr = gcd(tu, mau);
    tu /= rr;
    mau /= rr;

    //cout << tu << " " << mau << "\n";

   // cout << nxt[mau].size() << "\n";

    for (int i = 0; i < nxt[mau].size(); i++) {
        ll nw = nxt[mau][i];

        ll demo = tu * (nw / mau);

        if (demo >= cur / (x - 1)) {

            tmp = x * sqrt(nw);

            return demo;
        }
    }

    return -1;
}

int main() {
    //freopen("in.in", "r", stdin);
    freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i)
            if (isSquare(j)) {
                    nxt[i].pb(j);
            }
        if (nxt[i].size() == 0)
            nxt[i].pb((ll) i * i);
    }

//    cout << get(632, 1) << "\n";

  //  cout << get(55229, 1);

    cin >> n;
    ll cur = 2;
    for (int i = 2; i <= n + 1; i++) {
        ll val = get(i, cur) ;
        //cout << i << "\n";
     //   if (val > 1000000000000000000) cout << "dkm\n";
       // cout << val << " " << cur << "\n";
        cout << val - (cur / (i - 1)) << "\n";
        cur = tmp;
       // cout << "cur: " << cur << " " << sqrt(val * (i - 1)) <<  "\n";
       // cout << val * (i - 1) << "\n";
    }

    /**/ return 0;
}
