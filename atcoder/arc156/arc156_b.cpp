#include <bits/stdc++.h>
using namespace std;

#ifdef _RUTHEN
#include <debug.hpp>
#else
#define show(...) true
#endif

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
template <class T> using V = vector<T>;

#include <atcoder/modint>
using mint = atcoder::modint998244353;

#include "math/binomial.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    V<int> A(N);
    rep(i, N) cin >> A[i];
    int AM = 400105;
    V<int> cnt(AM);
    rep(i, N) cnt[A[i]]++;
    mint ans = 0;
    int zc = 0;
    Binomial<mint> B;
    for (int v = 0; v < AM; v++) {
        ans += B.C(K - zc - 1 + v, K - zc - 1);
        if (cnt[v] == 0) zc++;
        if (K == zc) break;
    }
    cout << ans.val() << '\n';
    return 0;
}
