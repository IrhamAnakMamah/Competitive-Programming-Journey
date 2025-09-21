#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(2, 100000, "N");
    inf.readSpace();
    int M = inf.readInt(1, 200000, "M");
    inf.readEoln();

    vector<int> tipe(N);
    bool adaStasiunInti = false;
    for (int i = 0; i < N; i++) {
        tipe[i] = inf.readInt(0, 1, "tipe");
        if (i + 1 < N) inf.readSpace();
        if (tipe[i] == 1) adaStasiunInti = true;
    }
    inf.readEoln();
    ensuref(adaStasiunInti, "Harus ada minimal satu stasiun inti");

    set<pair<int,int>> edges;
    for (int i = 0; i < M; i++) {
        int U = inf.readInt(1, N, "U");
        inf.readSpace();
        int V = inf.readInt(1, N, "V");
        inf.readEoln();
        ensuref(U != V, "Tidak boleh ada self-loop");
        if (U > V) swap(U, V);
        ensuref(edges.insert({U, V}).second, "Edge duplikat ditemukan");
    }

    inf.readEof();
}
