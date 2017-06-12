#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#define pp pair
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define N 300010
using namespace std;

int mask[N];
int sz[N]; // kt
int n;
map<int, int> M;
priority_queue <int> qu[N];
bool del[N];
int ret[N];

void split(int root) {
    del[root] = true;

    int p1 = root * 2;
    int p2 = root * 2 + 1;

    if (p1 < 2 * n) {
        qu[sz[p1]].push(-p1);
    }

    if (p2 < 2 * n) {
        qu[sz[p2]].push(-p2);
    }
}

void sign(int root, int val) {
    do {
        ret[root] = val;
        split(root);
        root = root * 2;
    }
    while (root < 2 * n);
}

void init(int node) {
    if (node * 2 >= 2 * n) {
        sz[node] = 1;
        return;
    }
    init(node * 2);
    init(node * 2 + 1);
    sz[node] = sz[node * 2] + 1;
}

bool place(int kt, int val) {
    while (!qu[kt].empty() && del[-qu[kt].top()]) qu[kt].pop();
    if (qu[kt].empty()) return false;
    int root = -qu[kt].top();
    qu[kt].pop();
    sign(root, val);
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i < 2 * n; i++) {
        int x;
        cin >> x;
        M[x]++;
    }
    init(1);

    qu[sz[1]].push(-1);
    bool ok = true;
    for (map<int, int> :: iterator it = M.begin(); it != M.end(); it++) {
        int val = (*it).fi;
        int kt = (*it).se;

       // cout << "try: " << val << " " << kt << "\n";

        ok = ok & place(kt, val);
        if (!ok) break;
    }
    if (!ok) cout << "NO";
    else {
        cout << "YES\n";
        for (int i = 1; i < 2 * n; i++) cout << ret[i] << " ";
    }
    return 0;
}
