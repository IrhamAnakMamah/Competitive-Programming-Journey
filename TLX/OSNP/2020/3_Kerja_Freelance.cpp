#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e4+5, MAXE = 2e4+5;

int M, S[MAXN], E[MAXN], P[MAXN];
ll dp[MAXE];

ll solve(int day) {
    if (day == 0) return 0;
    if (dp[day] != -1) return dp[day];

    ll hasil = solve(day - 1);
    for (int j : V[day]) {
        hasil = max(hasil, solve(S[j] - 1) + P[j]);
    }
    return dp[day] = hasil;
}

int main() {
    cin >> M;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= M; i++) {
        cin >> S[i] >> E[i] >> P[i];
        V[E[i]].push_back(i);
    }
    cout << solve(15000) << endl;
}
