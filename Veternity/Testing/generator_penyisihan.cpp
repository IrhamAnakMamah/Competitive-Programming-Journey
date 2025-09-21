// generator_penyisihan.cpp
#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;

void printCase(int N, int M, const vector<int> &tipe, const vector<pii> &edges) {
    printf("%d %d\n", N, M);
    println(tipe);
    for (auto &e : edges) {
        printf("%d %d\n", e.first, e.second);
    }
}

vector<pii> generateRandomEdges(int N, int M) {
    ll maxEdges = (ll)N * (N - 1) / 2;
    if (M > maxEdges) M = (int)maxEdges;

    vector<pii> edges;
    edges.reserve(M);
    unordered_set<unsigned long long> used;
    used.reserve(M * 2);

    while ((int)edges.size() < M) {
        int u = rnd.next(1, N);
        int v = rnd.next(1, N);
        if (u == v) continue;
        if (u > v) swap(u, v);

        unsigned long long key = ((unsigned long long)u << 32) | (unsigned long long)v;
        if (used.insert(key).second) {
            edges.emplace_back(u, v);
        }
    }
    return edges;
}

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);

    if (argc < 3) {
        println("Usage: %s <mode> <seed>   (modes: small, random, large, custom)", argv[0]);
        return 0;
    }

    string mode = argv[1];
    int N = 0, M = 0;
    vector<int> tipe;
    vector<pii> edges;

    if (mode == "small") {
        N = 2;
        M = 1;
        tipe = {1, 0};
        edges = {{1, 2}};
    }
    else if (mode == "random") {
        N = rnd.next(2, 100000);
        int maxEdges = N * (N - 1) / 2;
        M = rnd.next(1, min(200000, maxEdges));

        tipe.assign(N, 0);
        int numCores = rnd.next(1, max(1, N / 10));
        unordered_set<int> coreIdx;
        while ((int)coreIdx.size() < numCores)
            coreIdx.insert(rnd.next(1, N));
        for (int idx : coreIdx) tipe[idx - 1] = 1;

        edges = generateRandomEdges(N, M);
    }
    else if (mode == "large") {
        N = 100000;
        M = 200000;
        tipe.assign(N, 0);
        tipe[0] = 1;
        tipe[N / 2] = 1;
        for (int i = 1; i <= 100; ++i) {
            int pos = 2 + (i * 9973) % (N - 2);
            tipe[pos] = 1;
        }
        edges = generateRandomEdges(N, M);
    }
    else if (mode == "custom") {
        if (argc < 5) {
            println("Usage: generator_penyisihan custom <N> <M> <seed>");
            return 0;
        }
        N = atoi(argv[2]);
        M = atoi(argv[3]);
        if (N < 2) N = 2;
        if (N > 100000) N = 100000;
        ll maxEdges = (ll)N * (N - 1) / 2;
        if (M < 1) M = 1;
        if ((ll)M > min(200000LL, maxEdges)) M = (int)min(200000LL, maxEdges);

        tipe.assign(N, 0);
        tipe[rnd.next(1, N) - 1] = 1;
        edges = generateRandomEdges(N, M);
    }
    else {
        println("Unknown mode: %s", mode.c_str());
        return 0;
    }

    // Verifikasi eksplisit sebelum print
    set<pair<int,int>> checkSet;
    for (auto &e : edges) {
        if (e.first < 1 || e.second < 1 || e.first > N || e.second > N)
            quitf(_fail, "Edge (%d,%d) out of bounds", e.first, e.second);
        if (e.first == e.second)
            quitf(_fail, "Self-loop detected at (%d,%d)", e.first, e.second);
        if (!checkSet.insert(e).second)
            quitf(_fail, "Duplicate edge (%d,%d)", e.first, e.second);
    }

    bool hasCore = false;
    for (int x : tipe) if (x == 1) { hasCore = true; break; }
    if (!hasCore) tipe[0] = 1; // jaga-jaga

    printCase(N, M, tipe, edges);
    return 0;
}
