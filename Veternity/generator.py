import random
import sys

def generate_test_case(n, q):
    """
    Menghasilkan test case besar untuk soal Restrukturisasi Kerajaan Naga.
    """
    # Mencetak N dan Q
    print(n, q)

    # Menghasilkan kekuatan naga secara acak
    powers = [random.randint(1, 1_000_000_000) for _ in range(n)]
    print(*powers)

    active_temp_edges = []
    
    # Memastikan semua node terhubung dalam beberapa komponen besar
    # untuk membuat struktur awal yang menarik
    parent = list(range(n + 1))
    def find(i):
        if parent[i] == i:
            return i
        parent[i] = find(parent[i])
        return parent[i]
    def unite(i, j):
        root_i = find(i)
        root_j = find(j)
        if root_i != root_j:
            parent[root_i] = root_j
            return True
        return False

    num_initial_edges = min(n - 1, q // 4)
    edges_made = 0
    
    # Membuat beberapa koneksi permanen di awal
    for _ in range(num_initial_edges):
        u, v = random.randint(1, n), random.randint(1, n)
        if u != v and unite(u, v):
            print(f"1 {u} {v}")
            edges_made += 1

    remaining_q = q - edges_made

    for _ in range(remaining_q):
        # Memilih tipe query secara acak dengan bobot tertentu
        # Bobot: 45% tipe 2, 25% tipe 3, 30% tipe 4
        query_type_rand = random.random()

        if query_type_rand < 0.45:
            # Tipe 2: Tambah jalan temporer
            u, v = random.randint(1, n), random.randint(1, n)
            while u == v:
                v = random.randint(1, n)
            
            if u > v: u, v = v, u
            
            # Hindari duplikat edge temporer yang aktif
            if (u, v) not in active_temp_edges:
                print(f"2 {u} {v}")
                active_temp_edges.append((u, v))
            else:
                # Jika edge sudah ada, lakukan query tipe 4 saja
                query_node = random.randint(1, n)
                print(f"4 {query_node}")

        elif query_type_rand < 0.70 and active_temp_edges:
            # Tipe 3: Hapus jalan temporer (jika ada)
            edge_to_remove = random.choice(active_temp_edges)
            u, v = edge_to_remove
            print(f"3 {u} {v}")
            active_temp_edges.remove(edge_to_remove)
        
        else:
            # Tipe 4: Tanya stabilitas
            query_node = random.randint(1, n)
            print(f"4 {query_node}")


if __name__ == "__main__":
    # Non-aktifkan buffer untuk output yang lebih cepat saat redirect
    sys.stdout.reconfigure(write_through=True) 
    
    N = 200000
    Q = 200000
    generate_test_case(N, Q)