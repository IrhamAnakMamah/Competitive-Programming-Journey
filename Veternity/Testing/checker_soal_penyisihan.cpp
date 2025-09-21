#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

using Edge = pair<int,int>;

// Normalisasi edge agar (u < v)
Edge normEdge(int u, int v) {
    if (u > v) swap(u, v);
    return {u, v};
}

// Fungsi menghitung koneksi yang benar sesuai aturan soal
vector<Edge> hitungKoneksiBenar(int N, int M, const vector<int> &tipe, const vector<Edge> &edges) {
    vector<vector<int>> adj(N+1);
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> inti;
    for (int i = 1; i <= N; i++) if (tipe[i-1] == 1) inti.push_back(i);
    sort(inti.begin(), inti.end());

    vector<bool> vis(N+1, false);
    vector<Edge> hasil;

    auto bfs = [&](int start) {
        queue<int> q;
        q.push(start);
        vis[start] = true;
        int minNode = start;
        bool adaInti = (tipe[start-1] == 1);

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            minNode = min(minNode, cur);
            if (tipe[cur-1] == 1) adaInti = true;

            for (int nxt : adj[cur]) {
                if (!vis[nxt]) {
                    vis[nxt] = true;
                    q.push(nxt);
                }
            }
        }

        // Hanya tambahkan koneksi jika komponen ini TIDAK memiliki stasiun inti
        if (!adaInti) {
            int best = inti[0];
            for (int x : inti) {
                if (abs(minNode - x) < abs(minNode - best)) best = x;
                else if (abs(minNode - x) == abs(minNode - best)) best = min(best, x);
            }
            hasil.push_back(normEdge(minNode, best));
        }
    };

    for (int i = 1; i <= N; i++) {
        if (!vis[i]) bfs(i);
    }

    sort(hasil.begin(), hasil.end());
    return hasil;
}

int main(int argc, char* argv[]) {
    setName("Custom checker for Teknisi Jaringan");
    registerTestlibCmd(argc, argv);

    // Baca input
    int N = inf.readInt();
    int M = inf.readInt();
    inf.readEoln();

    vector<int> tipe(N);
    for (int i = 0; i < N; i++) {
        tipe[i] = inf.readInt();
        if (i + 1 < N) inf.readSpace();
    }
    inf.readEoln();

    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        int u = inf.readInt();
        int v = inf.readInt();
        if (i + 1 < M) inf.readEoln();
        edges[i] = normEdge(u, v);
    }

    // Hitung koneksi yang seharusnya benar
    vector<Edge> benar = hitungKoneksiBenar(N, M, tipe, edges);
    set<Edge> setBenar(benar.begin(), benar.end());

    // Baca jawaban juri (official)
    int kJuri = ans.readInt();
    ans.readEoln();
    for (int i = 0; i < kJuri; i++) {
        ans.readInt(); ans.readSpace(); ans.readInt();
        if (i + 1 < kJuri) ans.readEoln();
    }

    // Baca jawaban peserta
    int kPeserta = ouf.readInt();
    ouf.readEoln();
    vector<Edge> peserta(kPeserta);
    for (int i = 0; i < kPeserta; i++) {
        int u = ouf.readInt();
        int v = ouf.readInt();
        if (i + 1 < kPeserta) ouf.readEoln();
        peserta[i] = normEdge(u, v);
    }

    // Periksa jumlah koneksi
    if (kPeserta != (int)benar.size())
        quitf(_wa, "Jumlah koneksi salah: seharusnya %d, peserta memberikan %d", (int)benar.size(), kPeserta);

    // Periksa kesesuaian set koneksi
    set<Edge> setPeserta(peserta.begin(), peserta.end());
    if (setPeserta != setBenar) {
        quitf(_wa, "Koneksi peserta tidak sesuai dengan koneksi minimal yang benar");
    }

    quitf(_ok, "Jawaban benar: semua koneksi sesuai");
}
