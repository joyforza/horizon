#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 1000010
#define mod 1000000007
typedef long long ll;
using namespace std;
int nt;
ll n, k;
int m;

const ll BASE = 1000000000000;
const int NBLOCK = 9;
struct Bigint {
	vector<ll> data;
	Bigint() {data.push_back(0);}
	Bigint(long long x) {
		if (!x) data.push_back(0);
		while (x) data.push_back(x % BASE), x /= BASE;
	}
	void trim() {while (data.size() > 1 && !data.back()) data.pop_back();}
	ll& operator[] (int i) {return data[i];}
	int len() {return data.size();}
	int iszero() const {return data.empty() || (data.size() == 1 && !data[0]);}
};
Bigint operator + (Bigint a, Bigint b) {
	if (a.len() < b.len()) swap(a, b);
	Bigint c; c.data = a.data, c.data.push_back(0);
	int r = 0;
	for (int i = 0; i < c.len(); i++) {
		c[i] += ((i < b.len()) ? b[i] : 0) + r;
		if ((r = (c[i] >= BASE))) c[i] -= BASE;
	}
	c.trim();
	return c;
}
Bigint operator * (Bigint a, ll m) {
	long long r = 0;
	for (int i = 0; i < a.len(); i++) {
		r += (long long) a[i] * m;
		a[i] = r % BASE;
		r /= BASE;
	}
	while (r) a.data.push_back(r % BASE), r /= BASE;
	a.trim();
	return a;
}

pair<Bigint, int> divmod(Bigint a, int m) {
	long long r = 0;
	for (int i = a.len() - 1; i >= 0; i--) {
		r = r * BASE + a[i];
		a[i] = r / m;
		r %= m;
	}
	a.trim();
	return make_pair(a, (int) r);
}

Bigint operator / (Bigint a, int m) {
	return divmod(a, m).first;
}
int operator % (Bigint a, int m) {
	return divmod(a, m).second;
}
Bigint operator * (const Bigint& a, const Bigint& b) {
	Bigint res;
	res.data.assign(a.data.size() + b.data.size(), 0);
	for (int i = 0; i < a.data.size(); i++) {
		long long carry = 0;
		for (int j = 0; j < b.data.size() || carry > 0; j++) {
			long long s = res[i + j] + carry + (long long) a.data[i] * (j < b.data.size() ? (long long) b.data[j] : 0);
			res[i + j] = s % BASE;
			carry = s / BASE;
		}
	}
	res.trim();
	return res;
}


void compute(ll n, ll k) {
   Bigint r = 1;
   ll d;
   for (d = 1; d <= k; d++)
   {
      r = r * (n--);
      r = r / d;
   }

   Bigint gg = m;

   cout << r % m << "\n";
  // return (r % m);
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        cin >> n >> k >> m;
        ll p = n / k + (n % k != 0); /// divide to p part
        ll md = n % k;
        if (md > 0) md = k - md;
        p--;
        cout << p + 1 << " ";
        compute(p + md, min(md, p));
    }
    /**/ return 0;
}
