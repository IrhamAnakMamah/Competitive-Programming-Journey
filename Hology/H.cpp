#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n=0): n(n), bit(n+1, 0) {}
    void init(int _n){ n=_n; bit.assign(n+1,0); }
    void add(int idx, int val){
        for(; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    int sum(int idx){
        int r = 0;
        for(; idx > 0; idx -= idx & -idx) r += bit[idx];
        return r;
    }
    // return smallest index idx (1-based) s.t. prefix sum >= k
    int find_kth(int k){
        int idx = 0;
        int bitMask = 1;
        while((bitMask << 1) <= n) bitMask <<= 1;
        for(int step = bitMask; step > 0; step >>= 1){
            int nxt = idx + step;
            if(nxt <= n && bit[nxt] < k){
                idx = nxt;
                k -= bit[nxt];
            }
        }
        return idx + 1;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int MAXA = 200000; // batas problem
    // precompute semua divisor untuk 1..MAXA
    vector<vector<int>> divisors(MAXA+1);
    for(int d=1; d<=MAXA; ++d){
        for(int m=d; m<=MAXA; m+=d) divisors[m].push_back(d);
    }

    int t; 
    if(!(cin >> t)) return 0;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];

        // Fenwick pada indeks counts: kita menyimpan frekuensi berapa banyak d memiliki count = c
        // counts c berada di [0..n], kita peta ke indeks BIT sebagai c+1 di [1..n+1]
        Fenwick bit(n+1);
        bit.init(n+1);

        // awalnya semua d in [1..n] punya count 0
        // jadi freq_of_counts[0] = n  --> bit.add(1, n)
        bit.add(1, n);

        vector<int> cnt(n+1, 0); // cnt[d] untuk d = 1..n
        vector<int> ans(n, 0);

        for(int i = 0; i < n; ++i){
            int x = a[i];
            // update semua divisor d dari x, tetapi hanya d <= n (karena kita hanya track d dalam 1..n)
            for(int d : divisors[x]){
                if(d > n) continue;
                int oldc = cnt[d];
                // pindahkan 1 dari oldc -> oldc+1
                bit.add(oldc + 1, -1);       // index = oldc+1
                cnt[d] = oldc + 1;
                bit.add(cnt[d] + 1, +1);     // index = newc+1
            }

            int prefix_len = i + 1;
            // kita mau maksimum c dengan c <= prefix_len-1  <=> index <= (prefix_len-1)+1 = prefix_len
            int total_in_range = bit.sum(prefix_len); // jumlah d dengan count <= prefix_len-1
            if(total_in_range == 0){
                ans[i] = 0;
            } else {
                int pos = bit.find_kth(total_in_range); // pos adalah indeks BIT (1-based) dari entri terakhir di range
                int c = pos - 1; // kembalikan ke nilai count (karena indeks = c+1)
                ans[i] = c;
            }
        }

        for(int i=0;i<n;i++){
            if(i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}
