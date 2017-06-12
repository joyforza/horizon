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

template<class T> T mulmod(T a, T b, T p) {
	a %= p; b %= p;
	T q = (T) ((long double) a * b / p);
    T r = a * b - q * p;
    while (r < 0) r += p;
    while (r >= p) r -= p;
    return r;
}

template<class T> T powmod(T n, T k, T p) {
	if (!n) return 0;
	T r = 1;
	for (; k; k >>= 1) {
		if (k & 1) r = mulmod(r, n, p);
		n = mulmod(n, n, p);
	}
	return r;
}
template<class T> int rabin(T n) {
	if (n == 2) return 1;
	if (n < 2 || !(n & 1)) return 0;
	const T p[3] = {3, 5, 7};
	T a, d = n - 1, mx = 3;
	int i, r, s = 0;
	while (!(d & 1)) {++s; d >>= 1;}
	for (i = 0; i < mx; i++) {
		if (n == p[i]) return 1;
		if (!(n % p[i])) return 0;
		a = powmod(p[i], d, n);
		if (a != 1) {
			for (r = 0; r < s && a != n - 1; r++) a = mulmod(a, a, n);
			if (r == s) return 0;
		}
	}
	return 1;
}

template<class T> T pollardrho(T n) {
	int it = 0, k = 2;
	T x = 3, y = 3;
	while (1) {
		it++;
		x = (mulmod(x, x, n) + n - 1) % n;
		T d = __gcd(abs(y - x), n);
		if (d != 1 && d != n) return d;
		if (it == k) y = x, k <<= 1;
	}
}

int back[N];
vector<int> tmp;
vector<int> uc;
ll A, B;

void split(int x) {
	while(x > 1) {
		int lastPrime = back[x];
		while (x % lastPrime == 0) {
			tmp.pb(lastPrime);
			x /= lastPrime;
		}
	}
}

bool isPrime(ll x) {
	if (x > 1000000) return rabin(x);
	return (back[x] == x);
}

void goPollard(ll x) {
	if (isPrime(x)) {
		tmp.pb(x);
		return;
	}
	if (x <= 1000000) {
		split(x);
		return;
	}
	ll s1 = pollardrho(x);
	ll s2 = x / s1;
	goPollard(s1);
	goPollard(s2);
}

int com_dp(int x) {
	int cnt = 0;
	int val = 0;
	for (int i = 1; i < x; i++)
		if (x % i == 0) {
			cnt++;
			val = max(val, com_dp(i));
		}
	return cnt + 1 + val;
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdout);
	for (int i = 2; i < N; i++)
		if (back[i] == 0) {
			back[i] = i;
			for (int j = i + i; j < N; j += i)
				back[j] = i;
		}
	cin >> A >> B;

	ll ret = 0;

	for (ll i = A; i <= B; i++) {
		tmp.clear();
		goPollard(i);
		sort(tmp.begin(), tmp.end());
		tmp.pb(-1);
		int dem = 0;
		for (int j = 0; j < tmp.size() - 1; j++) {
			dem++;
			if (tmp[j] != tmp[j + 1]) {
				uc.pb(dem + 1);
				dem = 0;
			}
		}
		ll mul = 1;
		for (int j = 0; j < uc.size(); j++)
			mul *= uc[j];

		ll cnt = mul - 1;
		while(true) {
			int posMax = 0;
			for (int j = 1; j < uc.size(); j++)
				if (uc[j] > uc[posMax]) posMax = j;
			if (uc[posMax] == 1) break;
			mul /= uc[posMax];
			mul *= (uc[posMax] - 1);
			cnt += mul;
            uc[posMax]--;
		}

		cout << cnt << " " << com_dp(i) - 1 << "\n";
		ret += cnt;
	}
	cout << ret;
	return 0;
}
