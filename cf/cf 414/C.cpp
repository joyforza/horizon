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
string s;
vector<char> a;
vector<char> b;
int n;

void getMax() {

}

void getMin() {

}

int l, r;
char res[N];

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    cin >> s;
    n = s.size();
    for (int i = 0; i < s.size(); i++) a.pb(s[i]);
    cin >> s;
    for (int i = 0; i < s.size(); i++) b.pb(s[i]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    l = 1;
    r = n;

    int la = 0;
    int lb = 0;

    for (int i = 0; i < n; i++) {
        if (i & 1) getMax();
        else
            getMin();
    }

    for (int i = 1; i <= n; i++) cout << res[i];

    /**/return 0;
}
