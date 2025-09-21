import sys

def read_graph(filename):
    with open(filename, "r") as f:
        n, m = map(int, f.readline().split())
        types = list(map(int, f.readline().split()))
        edges = set()
        for _ in range(m):
            u, v = map(int, f.readline().split())
            if u > v:
                u, v = v, u
            edges.add((u, v))
        return n, m, types, edges

def check_output(input_file, output_file):
    # Baca input
    n, m, types, existing_edges = read_graph(input_file)

    with open(output_file, "r") as f:
        lines = [line.strip() for line in f if line.strip()]
    
    # Cek baris pertama: jumlah koneksi baru
    try:
        k = int(lines[0])
    except:
        return False, "Baris pertama output tidak valid (bukan integer)."
    
    if k != len(lines) - 1:
        return False, f"Jumlah koneksi baru ({k}) tidak sesuai dengan baris yang diberikan ({len(lines)-1})."
    
    new_edges = set()
    for i in range(1, len(lines)):
        try:
            u, v = map(int, lines[i].split())
        except:
            return False, f"Baris {i+1} tidak valid (bukan dua angka)."
        
        # Cek batas
        if not (1 <= u <= n and 1 <= v <= n):
            return False, f"Koneksi ({u}, {v}) di luar batas."
        if u == v:
            return False, f"Self-loop ditemukan: ({u}, {v})."
        
        # Cek koneksi harus stasiun inti
        if types[u-1] == 0 and types[v-1] == 0:
            return False, f"Koneksi tidak mengandung stasiun inti: ({u}, {v})."
        
        a, b = min(u, v), max(u, v)
        if (a, b) in existing_edges:
            return False, f"Koneksi ({a}, {b}) sudah ada sebelumnya."
        if (a, b) in new_edges:
            return False, f"Koneksi ({a}, {b}) duplikat di output."
        
        new_edges.add((a, b))

    # Cek konektivitas akhir
    from collections import deque

    # Gabungkan semua edge
    graph = [[] for _ in range(n+1)]
    for u, v in existing_edges:
        graph[u].append(v)
        graph[v].append(u)
    for u, v in new_edges:
        graph[u].append(v)
        graph[v].append(u)

    visited = [False] * (n+1)
    q = deque()
    # Mulai dari semua stasiun inti
    for i, t in enumerate(types, 1):
        if t == 1:
            visited[i] = True
            q.append(i)

    while q:
        node = q.popleft()
        for nei in graph[node]:
            if not visited[nei]:
                visited[nei] = True
                q.append(nei)

    # Jika ada stasiun yang belum terhubung
    unconnected = [i for i in range(1, n+1) if not visited[i]]
    if unconnected:
        return False, f"Ada stasiun yang belum terhubung: {unconnected[:5]}{'...' if len(unconnected) > 5 else ''}"

    return True, "Output valid."

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python3 checker.py <input_file> <output_file>")
        sys.exit(1)

    ok, msg = check_output(sys.argv[1], sys.argv[2])
    if ok:
        print("[OK]", msg)
        sys.exit(0)
    else:
        print("[WRONG]", msg)
        sys.exit(1)
