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
double ret = 0;
string s;
vector <string> c;

int val(string s) {
    int last = s.size() - 1;

    if (s[s.size() - 2] == '.') {
        last = s.size() - 2;
    }
    if (s[s.size() - 3] == '.') {
        last = s.size() - 3;
    }

    int cnt = 0;
    for (int j = 0; j <= last; j++)
        if (s[j] != '.')
            cnt = cnt * 10 + (s[j] - '0');

    return cnt;
}



int val_neg(string s) {

    if (s[s.size() - 2] == '.') {
        return (s[s.size() - 1] - '0') * 10;
    }

    if (s[s.size() - 3] == '.') {
        return (s[s.size() - 1] - '0') + (s[s.size() - 2] - '0') * 10;
    }
    return 0;
}


int main() {
   // freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> s;
    s = s + 'a';


    bool notReady = true;
    string rr = "";

    for (int i = 0; i < s.size(); i++)
    if ((s[i] <= '9' && s[i] >= '0') || (s[i] == '.')){
        rr = rr + s[i];
        notReady = false;
    }
    else {
        if (!notReady) {
            c.pb(rr);
            rr = "";
        }
        notReady = true;
    }

    int tot = 0;
    int neg = 0;

    for (int i = 0; i < c.size(); i++) {
        if (c[i].size() < 3) {
            int cnt = 0;
            for (int j = 0; j < c[i].size(); j++)
                if (c[i][j] != '.')
                    cnt = cnt * 10 + (c[i][j] - '0');
            tot += cnt;
        }
        else {
            tot += val(c[i]);
            neg += val_neg(c[i]);
        }
    }


    //cout << "tot: " << tot << "\n";

    tot += (neg / 100);
    neg = neg % 100;

   // cout << neg << "\n";

    vector <int> ans;

    while (tot >= 1000) {
        ans.pb(tot % 10);
        tot /= 10;
        ans.pb(tot % 10);
        tot /= 10;
        ans.pb(tot % 10);
        tot /= 10;
        ans.pb(-1);
    }

    cout << tot;



    for (int i = ans.size() - 1; i >= 0; i--)
        if (ans[i] == -1) cout << ".";
    else
        cout << ans[i];

    if (neg > 0) {
        cout << ".";

        if (neg < 10) {
            cout << "0";
            cout << neg;
        }
        else {
            cout << neg;
        }
    }

    /**/return 0;
}
