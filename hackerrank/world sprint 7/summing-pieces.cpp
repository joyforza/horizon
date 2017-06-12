#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define N 1000010
#define mod 1000000007
typedef long long ll;
using namespace std;
int n;
int a[N];
ll sum[N];
ll dp[N];
ll num[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    num[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i - 1; j >= 0; j--)
            num[i] = (num[i] + num[j]) % mod;

    for (int i = 1; i <= n; i++) {
        cout << "i = " << i << "\n";

        for (int j = i - 1; j >= 0; j--) {
            dp[i] = (dp[i] + (dp[j]  +  num[j] * (sum[i] - sum[j]) % mod * (i - j) % mod)) % mod;
            cout << num[j] << " " << (sum[i] - sum[j]) << "\n";
        }
        cout << "val = " << dp[i] << "\n";
    }
    //cout << dp[n];

    return 0;
}
