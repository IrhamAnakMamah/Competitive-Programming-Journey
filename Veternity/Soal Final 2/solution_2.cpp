#include <bits/stdc++.h>
using namespace std;

struct Node {
    int next[26];
    int suff = 0;
    vector<int> linkChild;
    int tin = 0, tout = 0;
    int active = 0;
    Node() {
        fill(begin(next), end(next), 0);
    }
};

const int MAXN = 1000005;
vector<Node> trie(1);
int timerDFS = 0;
vector<int> fenwick;
vector<int> endNode;


void fenwickAdd(int i, int v) {
    for (; i < (int)fenwick.size(); i += i & -i) fenwick[i] += v;
}
int fenwickSum(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) res += fenwick[i];
    return res;
}

int insertWord(const string &s) {
    int v = 0;
    for (char c : s) {
        int idx = c - 'a';
        if (!trie[v].next[idx]) {
            trie[v].next[idx] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[idx];
    }
    return v;
}

void buildAho() {
    queue<int> q;
    for (int c = 0; c < 26; c++) {
        if (trie[0].next[c]) {
            q.push(trie[0].next[c]);
        }
    }
    while (!q.empty()) {
        int v = q.front(); q.pop();
        int u = trie[v].suff;
        trie[u].linkChild.push_back(v);
        for (int c = 0; c < 26; c++) {
            if (trie[v].next[c]) {
                trie[trie[v].next[c]].suff = trie[u].next[c];
                q.push(trie[v].next[c]);
            } else {
                trie[v].next[c] = trie[u].next[c];
            }
        }
    }
}

void dfsEuler(int v) {
    trie[v].tin = ++timerDFS;
    for (int to : trie[v].linkChild) dfsEuler(to);
    trie[v].tout = ++timerDFS;
}

void toggle(int v, int delta) {
    if (delta == 1 && trie[v].active == 0) {
        fenwickAdd(trie[v].tin, +1);
        fenwickAdd(trie[v].tout, -1);
        trie[v].active = 1;
    } else if (delta == -1 && trie[v].active == 1) {
        fenwickAdd(trie[v].tin, -1);
        fenwickAdd(trie[v].tout, +1);
        trie[v].active = 0;
    }
}

long long queryText(const string &s) {
    long long res = 0;
    int v = 0;
    for (char c : s) {
        v = trie[v].next[c - 'a'];
        res += fenwickSum(trie[v].tin);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q, W;
    cin >> Q >> W;
    endNode.resize(W + 1);

    for (int i = 1; i <= W; i++) {
        string w;
        cin >> w;
        endNode[i] = insertWord(w);
    }

    buildAho();
    dfsEuler(0);

    fenwick.assign(timerDFS + 5, 0);

    for (int i = 1; i <= W; i++) {
        toggle(endNode[i], +1);
    }

    for (int i = 0; i < Q; i++) {
        char type;
        cin >> type;
        if (type == '+') {
            int x; cin >> x;
            toggle(endNode[x], +1);
        } else if (type == '-') {
            int x; cin >> x;
            toggle(endNode[x], -1);
        } else if (type == '?') {
            string t; cin >> t;
            cout << queryText(t) << "\n";
        }
    }

    return 0;
}
