// Created at 2026/02/07 13:09

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void solution()
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (auto &a : A)
        cin >> a;

    vector<pair<double, double>> P(N);
    for (auto &[x, y] : P)
        cin >> x >> y;

    auto getValue = [&](double R)
    {
        int64_t res = 0;
        for (int i = 0; i < N; i++)
        {
            vector<pair<double, int64_t>> events;

            for (int j = 0; j < N; j++)
            {
                if (i == j)
                    continue;

                double dx = P[i].first - P[j].first;
                double dy = P[i].second - P[j].second;
                double d = hypot(dx, dy);

                if (d > 2.0 * R)
                    continue;

                double angle = atan2(dy, dx);
                double cosv = d / (2.0 * R);

                double delta = acos(cosv);
                double L = angle - delta;
                double Rr = angle + delta;

                if (L < -M_PI)
                {
                    events.emplace_back(L + 2 * M_PI, A[j]);
                    events.emplace_back(M_PI, -A[j]);
                    events.emplace_back(-M_PI, A[j]);
                    events.emplace_back(Rr, -A[j]);
                }
                else if (Rr > M_PI)
                {
                    events.emplace_back(L, A[j]);
                    events.emplace_back(M_PI, -A[j]);
                    events.emplace_back(-M_PI, A[j]);
                    events.emplace_back(Rr - 2 * M_PI, -A[j]);
                }
                else
                {
                    events.emplace_back(L, A[j]);
                    events.emplace_back(Rr, -A[j]);
                }
            }

            sort(events.begin(), events.end());

            int64_t c = 0;
            int64_t mx = 0;

            for (auto &e : events) {
                c += e.second;
                mx = max(mx, c);
            }

            res = max(res, mx + A[i]);
        }
    };

    double Rl = 0, Rr = 1e7;

    while (Rr - Rl >= 1e4)
    {
        double R = (Rr - Rl) / 2;

        double xl = -1e6, xr = 1e6;

        while (xr - xl >= 1e4)
        {
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 1;
    cin >> n;
    while (n--)
        solution();
    return 0;
}