// validator_tolerant.cpp
#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

void consume_till_eoln_or_fail() {
    // Baca char sampai newline; izinkan spaces, tabs, '\r' sebelum '\n'
    while (true) {
        int c = inf.readChar(); // baca next char
        if (c == '\n') return;
        if (c == '\r' || c == ' ' || c == '\t') continue;
        // Jika bukan whitespace sebelum newline -> gagal
        ensuref(false, "Expected EOLN (stdin, line %d)", inf.getLine());
    }
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(1, 200000, "N");
    inf.readSpace();
    int Q = inf.readInt(1, 200000, "Q");
    consume_till_eoln();

    vector<long long> P(N);
    for (int i = 0; i < N; ++i) {
        P[i] = inf.readLong(1, 1000000000LL, "P[i]");
        if (i + 1 < N) inf.readSpace();
    }
    consume_till_eoln();

    set<pair<int,int>> activeTemp;
    for (int t = 1; t <= Q; ++t) {
        int type = inf.readInt(1, 4, "type");
        if (type == 1) {
            inf.readSpace();
            int u = inf.readInt(1, N, "u");
            inf.readSpace();
            int v = inf.readInt(1, N, "v");
            ensuref(u != v, "query 1: u == v");
            consume_till_eoln();
        } else if (type == 2) {
            inf.readSpace();
            int u = inf.readInt(1, N, "u");
            inf.readSpace();
            int v = inf.readInt(1, N, "v");
            ensuref(u != v, "query 2: u == v");
            if (u > v) swap(u, v);
            ensuref(!activeTemp.count({u, v}), "query 2: edge already active");
            activeTemp.insert({u, v});
            consume_till_eoln();
        } else if (type == 3) {
            inf.readSpace();
            int u = inf.readInt(1, N, "u");
            inf.readSpace();
            int v = inf.readInt(1, N, "v");
            ensuref(u != v, "query 3: u == v");
            if (u > v) swap(u, v);
            ensuref(activeTemp.count({u, v}), "query 3: edge not active");
            activeTemp.erase({u, v});
            consume_till_eoln();
        } else { // type == 4
            inf.readSpace();
            int u = inf.readInt(1, N, "u");
            ensuref(1 <= u && u <= N, "query 4: u out of range");
            consume_till_eoln();
        }
    }

    ensuref(activeTemp.empty(), "not all temporer edges are closed at the end");

    inf.readEof();
    return 0;
}
