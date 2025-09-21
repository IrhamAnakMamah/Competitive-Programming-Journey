#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Aho {
    struct Node {
        int next[26];
        int link;       
        int out_link;   
        vector<int> out; 
        Node() {
            fill(begin(next), end(next), -1);
            link = 0;
            out_link = -1;
        }
    };
    vector<Node> t;
    vector<int> pat_len;

    Aho() { t.emplace_back(); } 

    int add_pattern(const string &s) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1) {
                t[v].next[c] = (int)t.size();
                t.emplace_back();
            }
            v = t[v].next[c];
        }
        int id = (int)pat_len.size();
        pat_len.push_back((int)s.size());
        t[v].out.push_back(id);
        return id;
    }

    void build() {
        queue<int> q;
        t[0].link = 0;
        for (int c = 0; c < 26; ++c) {
            if (t[0].next[c] != -1) {
                t[t[0].next[c]].link = 0;
                q.push(t[0].next[c]);
            } else {
                t[0].next[c] = 0;
            }
        }
        t[0].out_link = -1;

        while (!q.empty()) {
            int v = q.front(); q.pop();
            int f = t[v].link;
            if (!t[f].out.empty()) t[v].out_link = f;
            else t[v].out_link = t[f].out_link;

            for (int c = 0; c < 26; ++c) {
                int u = t[v].next[c];
                if (u != -1) {
                    t[u].link = t[t[v].link].next[c];
                    q.push(u);
                } else {
                    t[v].next[c] = t[t[v].link].next[c];
                }
            }
        }
    }

    vector<pair<int,int>> search_all(const string &text) {
        vector<pair<int,int>> matches;
        int v = 0;
        for (int i = 0; i < (int)text.size(); ++i) {
            int c = text[i] - 'a';
            v = t[v].next[c];
            if (!t[v].out.empty()) {
                for (int id : t[v].out) matches.emplace_back(i, id);
            }
            int ol = t[v].out_link;
            while (ol != -1) {
                for (int id : t[ol].out) matches.emplace_back(i, id);
                ol = t[ol].out_link;
            }
        }
        return matches;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string S;
    cin >> S;
    int m;
    cin >> m;
    vector<string> patterns(m);
    for (int i = 0; i < m; ++i) cin >> patterns[i];

    Aho aho;
    for (int i = 0; i < m; ++i) {
        aho.add_pattern(patterns[i]);
    }
    aho.build();

    auto matches = aho.search_all(S);

    struct Interval { int l, r; ll w; };
    vector<Interval> intervals;
    intervals.reserve(matches.size());
    for (auto &pr : matches) {
        int end_pos = pr.first;
        int pid = pr.second;
        int len = aho.pat_len[pid];
        int l = end_pos - len + 1; 
        if (l < 0) continue;
        intervals.push_back({l+1, end_pos+1, 1LL * len * len}); 
    }

    if (intervals.empty()) {
        cout << 0 << "\n";
        return 0;
    }

    // for(auto x : intervals){
    //     cout << x.l << " " << x.r << " " << x.w << endl;
    // }

    sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
        if (a.r != b.r) return a.r < b.r;
        return a.l < b.l;
    });

    int K = (int)intervals.size();
    vector<int> R(K);
    for (int i = 0; i < K; ++i) R[i] = intervals[i].r;

    vector<ll> dp(K, 0);
    auto find_prev = [&](int idx)->int{
        int need = intervals[idx].l;
        int pos = int(upper_bound(R.begin(), R.end(), need - 1) - R.begin());
        return pos - 1;
    };

    for (int i = 0; i < K; ++i) {
        ll take = intervals[i].w;
        int p = find_prev(i);
        if (p >= 0) take += dp[p];
        ll notake = (i == 0 ? 0 : dp[i-1]);
        dp[i] = max(notake, take);
    }

    // for(auto x : dp){
    //     cout << x << " ";
    // }
    // cout << endl;
    cout << dp[K-1] << "\n";
    return 0;
}
