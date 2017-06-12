#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define pp4 pair<pp, pp>
#define fi first
#define se second
#define N 100010
#define mod 1000000007
#define inf 1000000001
#define esp 1e-9
#define BLOCK 777
#define BITNUM 1563
typedef long long ll;
using namespace std;
const T oo = (T) 1e18;
struct LineHull {
    struct Line {
        T a, b;
        Line(T a, T b) : a(a), b(b) {}
    };
    long double intersect(Line ln1, Line ln2) {
        return (long double) (ln2.b - ln1.b) / (ln1.a - ln2.a);
    }
    int bad(Line ln1, Line ln2, Line ln3) {
        return (long double) (ln1.a - ln2.a) * (ln2.b - ln3.b) >= (long double) (ln2.a - ln3.a) * (ln1.b - ln2.b);
        //return intersect(ln1, ln2) >= intersect(ln2, ln3);
        //return (long double) (ln1.a - ln2.a) * (ln2.b - ln3.b) <= (long double) (ln2.a - ln3.a) * (ln1.b - ln2.b); //for adding in ascending order
        //return intersect(ln1, ln2) <= intersect(ln2, ln3); //for adding in ascending order
    }
    vector<Line> hull;
    vector<long double> pos;
    LineHull() {
        pos.push_back(-oo);
        pos.push_back(+oo);
    }
    void add(T a, T b) {
        Line ln(a, b);
        pos.pop_back();
        while (hull.size() >= 2 && bad(hull[hull.size() - 2], hull[hull.size() - 1], ln)) {
            hull.pop_back();
            pos.pop_back();
        }
        hull.push_back(ln);
        if (hull.size() >= 2) pos.push_back(intersect(hull[hull.size() - 2], hull[hull.size() - 1]));
        //if (hull.size() >= 2) pos.push_back(-intersect(hull[hull.size() - 2], hull[hull.size() - 1])); //for adding in ascending order
        pos.push_back(+oo);
    }
    T query(T x) {
        if (!hull.size()) return +oo;
        int k = lower_bound(pos.begin(), pos.end(), x) - pos.begin() - 1;
        //int k = lower_bound(pos.begin(), pos.end(), -x) - pos.begin() - 1; //for adding in ascending order
        return hull[k].a * x + hull[k].b;
    }
} lh;

int nt, n;
int a[N + 1];
ll dp[N + 1];

int main() {
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
    	cin >> n;
    	for (int i = 1; i <= n; i++) cin >> a[i];

    }
	return 0;
}
