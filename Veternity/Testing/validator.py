import sys

MAX_N = 10**5
MAX_M = 2 * 10**5

def validate_input(file_path):
    try:
        with open(file_path, "r") as f:
            lines = [line.strip() for line in f if line.strip()]
    except FileNotFoundError:
        return False, f"File {file_path} tidak ditemukan."

    # --- Baris pertama: N dan M ---
    try:
        n, m = map(int, lines[0].split())
    except:
        return False, "Baris pertama harus berisi dua integer (N dan M)."

    if not (1 <= n <= MAX_N):
        return False, f"Nilai N ({n}) di luar batas (1 ≤ N ≤ {MAX_N})."
    if not (0 <= m <= MAX_M):
        return False, f"Nilai M ({m}) di luar batas (0 ≤ M ≤ {MAX_M})."

    # --- Baris kedua: tipe stasiun ---
    if len(lines) < 2:
        return False, "Baris kedua (tipe stasiun) hilang."
    try:
        types = list(map(int, lines[1].split()))
    except:
        return False, "Baris kedua harus berupa deretan integer (0 atau 1)."

    if len(types) != n:
        return False, f"Jumlah tipe stasiun ({len(types)}) tidak sama dengan N ({n})."

    if all(t == 0 for t in types):
        return False, "Tidak ada stasiun inti (semua 0). Harus ada minimal satu 1."

    for t in types:
        if t not in (0, 1):
            return False, f"Tipe stasiun tidak valid: {t} (hanya boleh 0 atau 1)."

    # --- Sisa baris: edges ---
    if len(lines) != 2 + m:
        return False, f"Jumlah baris koneksi ({len(lines)-2}) tidak sesuai dengan M ({m})."

    edges_seen = set()
    for i in range(2, 2 + m):
        try:
            u, v = map(int, lines[i].split())
        except:
            return False, f"Baris {i+1} tidak valid (harus dua integer)."
        if not (1 <= u <= n and 1 <= v <= n):
            return False, f"Koneksi ({u}, {v}) di luar batas 1..N."
        if u == v:
            return False, f"Self-loop ditemukan pada baris {i+1}."
        e = (min(u, v), max(u, v))
        if e in edges_seen:
            return False, f"Duplikat koneksi ditemukan: {e}."
        edges_seen.add(e)

    return True, "Input valid."

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 validator.py <input_file>")
        sys.exit(1)

    ok, msg = validate_input(sys.argv[1])
    if ok:
        print("[OK]", msg)
        sys.exit(0)
    else:
        print("[INVALID]", msg)
        sys.exit(1)
