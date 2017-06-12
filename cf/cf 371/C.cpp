#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, ll>
#define fi first
#define se second
#define esp 1e-9
#define inf 10000000000000001ll
#define mod 1000000007
#define N 100010
#define lg 18
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;

ll hs(string s) {
    ll val = 0;
    for (int i = 0; i < s.size(); i++)
        val = val * base + s[i];
    return val;
}

int t;
map <ll, int> M;
map <int, int> ret;
pp qu[N];
string s;
int cnt = 0;

int main() {
  //  freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        char c;
        cin >> c;
        if (c == '?') {

            cin >> s;

            int len = s.size();
            for (int j = 1; j <= 18 - len; j++)
                s = '0' + s;

            ll val = hs(s);
            if (M[val] == 0) {
                cnt++;
                M[val] = cnt;
            }

            qu[i] = mp(3, val);


        }
        else {

            int sg = (c == '+' ? 1 : 2);
            cin >> s;
            for (int i = 0; i < s.size(); i++) {
                int digit = s[i] - '0';
                if (digit % 2 == 0)
                    s[i] = '0';
                else
                    s[i] = '1';
            }

            int len = s.size();
            for (int j = 1; j <= 18 - len; j++)
                s = '0' + s;

            ll val = hs(s);
            qu[i] = mp(sg, val);
        }
    }


   for (int i = 1; i <= t; i++) {
   //    cout << qu[i].fi << " " << qu[i].se << "\n";
        if (qu[i].fi == 1) {
            if (M.count(qu[i].se))
                ret[M[qu[i].se]]++;
        }
        else
        if (qu[i].fi == 2) {
            if (M.count(qu[i].se))
                ret[M[qu[i].se]]--;
        }
        else {

            cout << ret[M[qu[i].se]] << endl;

        }

    }
    /**/ return 0;
}
