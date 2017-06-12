#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, ll>
#define ppp pair<pp, pp>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 30
#define base 311097
#define maxN 100011
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
string s;
int m;

int main() {
    //freopen("in.in", "r", stdin); // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> m;
    cin >> s;

    vector <char> st;
    for (int i = 0; i < s.size(); i++)
        st.pb(s[i]);

    while (true) {
        vector <char> tmp;
        vector <char> newSt;

        for (int i = 0; i < st.size(); i++) {
            tmp.pb(st[i]);
            if (tmp.size() >= 2) {
                int n = tmp.size() - 1;
                if (tmp[n - 1] != tmp[n]) {
                    newSt.pb(tmp[n - 1]);
                    tmp.pop_back();
                    tmp.pop_back();
                }
            }
        }

        st.clear();
        for (int i = 0; i < tmp.size(); i++)
            st.pb(tmp[i]);

        for (int i = 0; i < newSt.size(); i++)
            st.pb(newSt[i]);

        int cnt = 0;
        for (int i = 0; i < st.size(); i++)
            if (st[i] == 'D') cnt++;
        if (cnt == 0) break;
        if (cnt == st.size()) break;
        if (st.size() == 1) break;
    }

    cout << st[0];
    /**/ return 0;
}
