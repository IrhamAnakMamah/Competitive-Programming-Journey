#include <bits/stdc++.h>
using namespace std;

// random generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
char rnd_char() { return 'a' + (rng() % 26); }

string random_string(int len) {
    string s(len, 'a');
    for (int i = 0; i < len; i++) s[i] = rnd_char();
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int tc = 1; tc <= 30; tc++) {
        string filename = to_string(tc) + ".in";
        ofstream out(filename);

        int n, m;
        if (tc == 1) {
            // minimal input
            n = 1; m = 1;
            out << n << "\n";
            out << "a\n";
            out << m << "\n";
            out << "aa\n"; // pola panjang=2
        } else if (tc == 2) {
            n = 5; m = 2;
            out << n << "\n";
            out << "abcde\n";
            out << m << "\n";
            out << "ab\n";
            out << "de\n";
        } else if (tc <= 5) {
            n = 20 + rng() % 30;
            out << n << "\n";
            out << random_string(n) << "\n";
            m = 5 + rng() % 10;
            out << m << "\n";
            set<string> used;
            while ((int)used.size() < m) {
                int len = 2 + rng() % 5;
                used.insert(random_string(len));
            }
            for (auto &p : used) out << p << "\n";
        } else if (tc <= 10) {
            n = 100 + rng() % 200;
            out << n << "\n";
            out << random_string(n) << "\n";
            m = 50 + rng() % 50;
            out << m << "\n";
            set<string> used;
            while ((int)used.size() < m) {
                int len = 2 + rng() % 20;
                used.insert(random_string(len));
            }
            for (auto &p : used) out << p << "\n";
        } else if (tc <= 20) {
            n = 5000 + rng() % 5000;
            out << n << "\n";
            out << random_string(n) << "\n";
            m = 1000 + rng() % 2000;
            out << m << "\n";
            set<string> used;
            while ((int)used.size() < m) {
                int len = 2 + rng() % 50;
                used.insert(random_string(len));
            }
            for (auto &p : used) out << p << "\n";
        } else {
            // maximal tests
            n = 100000;
            out << n << "\n";
            out << random_string(n) << "\n";
            m = 30000; // batas maksimal
            out << m << "\n";

            set<string> used;
            int total = 0;
            int avg_len = max(2, 200000 / m); // sekitar 6-7
            while ((int)used.size() < m) {
                int remain = m - (int)used.size();
                int maxlen = max(2, (200000 - total) / remain); 
                int len = 2 + rng() % maxlen; 
                string p = random_string(len);
                if (used.insert(p).second) {
                    out << p << "\n";
                    total += len;
                }
            }
        }

        out.close();
    }
    return 0;
}
