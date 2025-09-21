#!/usr/bin/env python3
import random
import os

def generate_case(N, Q, filename, seed=None):
    """
    Men-generate satu test case yang valid:
    - tepat Q query (baris)
    - setiap temporer (2 u v) pasti ditutup oleh 3 u v
    - 3 hanya menghapus temporer yang aktif
    - ketika N == 1, hanya boleh query 4 1
    """
    if seed is not None:
        random.seed(seed)
    else:
        random.seed()

    with open(filename, "w") as f:
        f.write(f"{N} {Q}\n")
        # Energi tiap dimensi (1..1e9)
        powers = [str(random.randint(1, 10**9)) for _ in range(N)]
        f.write(" ".join(powers) + "\n")

        # Jika N == 1, satu-satunya query valid adalah "4 1"
        if N == 1:
            for _ in range(Q):
                f.write("4 1\n")
            return

        active_stack = []  # stack of temporer edges (min(u,v), max(u,v))
        active_set = set()

        for i in range(Q):
            remaining_slots = Q - i              # termasuk slot sekarang
            required_closures = len(active_stack)

            # Jika sisa slot == sisa temporer, kita wajib menutup satu sekarang
            if remaining_slots == required_closures:
                u, v = active_stack.pop()
                active_set.remove((u, v))
                f.write(f"3 {u} {v}\n")
                continue

            # Kita bisa memilih berbagai tipe; pastikan logika tidak menyebabkan
            # jumlah temporer yang harus ditutup melebihi slot yang tersisa.
            # Probabilitas: permanen ~35%, temporer ~25%, query ~40%
            r = random.random()
            can_add_temp = (remaining_slots >= required_closures + 2)  # setelah menambah temporer, masih perlu 1 slot untuk menutupnya plus menutup required_closures

            # Beri peluang menutup salah satu temporer bila ada
            if required_closures > 0 and r < 0.18:
                u, v = active_stack.pop()
                active_set.remove((u, v))
                f.write(f"3 {u} {v}\n")
                continue

            # Pilih tipe
            # ulangi sampling agar kita tidak memilih temporer bila tidak memungkinkan
            choice = random.random()
            if choice < 0.35:
                # permanen
                u, v = random.sample(range(1, N+1), 2)
                f.write(f"1 {u} {v}\n")
            elif choice < 0.60:
                # temporer (hanya jika memungkinkan)
                if not can_add_temp:
                    # fallback ke permanen atau query
                    if random.random() < 0.5:
                        u, v = random.sample(range(1, N+1), 2)
                        f.write(f"1 {u} {v}\n")
                    else:
                        u = random.randint(1, N)
                        f.write(f"4 {u}\n")
                else:
                    # pilih edge yang belum aktif sebagai temporer (hindari duplikat)
                    attempts = 0
                    while True:
                        u, v = random.sample(range(1, N+1), 2)
                        e = (min(u, v), max(u, v))
                        if e not in active_set:
                            break
                        attempts += 1
                        if attempts > 50:
                            # jika sulit menemukan, izinkan duplikat (sangat jarang)
                            break
                    e = (min(u, v), max(u, v))
                    active_stack.append(e)
                    active_set.add(e)
                    f.write(f"2 {e[0]} {e[1]}\n")
            else:
                # query 4
                u = random.randint(1, N)
                f.write(f"4 {u}\n")

        # Dalam desain ini, active_stack seharusnya kosong (karena logic memastikan)
        if active_stack:
            # seharusnya tidak terjadi — tapi jika terjadi, kita laporkan (tidak menambah baris)
            raise RuntimeError(f"Generation failed: temporer masih aktif in {filename}")

def generate_all_tests():
    os.makedirs("tests", exist_ok=True)

    # 20 test cases: variasi dari minimum sampai maksimum
    specs = [
        (1, 1),       # 1: minimum
        (3, 3),
        (5, 10),
        (10, 20),
        (50, 100),
        (100, 200),
        (500, 1000),
        (1000, 2000),
        (2000, 5000),
        (5000, 10000),
        (10000, 20000),
        (20000, 20000),
        (30000, 40000),
        (50000, 60000),
        (70000, 70000),
        (100000, 100000),
        (150000, 150000),
        (180000, 180000),
        (200000, 100000),
        (200000, 200000)  # 20: max stress test
    ]

    for idx, (N, Q) in enumerate(specs, start=1):
        filename = f"tests/input{idx}.txt"
        print(f"Generating {filename} (N={N}, Q={Q}) ...")
        generate_case(N, Q, filename, seed=idx)

    print("Generation complete.")

# --- checker ---
def check_testcase(filename):
    with open(filename, "r") as f:
        header = f.readline().strip()
        if not header:
            raise AssertionError(f"{filename}: empty file or missing header")
        n, q = map(int, header.split())
        powers_line = f.readline().strip()
        if not powers_line:
            raise AssertionError(f"{filename}: missing powers line")
        powers = list(map(int, powers_line.split()))
        if len(powers) != n:
            raise AssertionError(f"{filename}: number of powers != N")

        active_temp = set()
        for line_no in range(1, q+1):
            line = f.readline()
            if not line:
                raise AssertionError(f"{filename}: expected {q} queries but file ended early at line {line_no+2}")
            parts = line.strip().split()
            if not parts:
                raise AssertionError(f"{filename}: empty query at line {line_no+2}")
            t = int(parts[0])
            if t == 1:
                if len(parts) != 3:
                    raise AssertionError(f"{filename}: invalid format for query 1 at line {line_no+2}")
                u, v = map(int, parts[1:])
                assert 1 <= u <= n and 1 <= v <= n and u != v
            elif t == 2:
                if len(parts) != 3:
                    raise AssertionError(f"{filename}: invalid format for query 2 at line {line_no+2}")
                u, v = map(int, parts[1:])
                assert 1 <= u <= n and 1 <= v <= n and u != v
                e = (min(u, v), max(u, v))
                assert e not in active_temp, f"{filename}: temporer duplicated at line {line_no+2}"
                active_temp.add(e)
            elif t == 3:
                if len(parts) != 3:
                    raise AssertionError(f"{filename}: invalid format for query 3 at line {line_no+2}")
                u, v = map(int, parts[1:])
                assert 1 <= u <= n and 1 <= v <= n and u != v
                e = (min(u, v), max(u, v))
                assert e in active_temp, f"{filename}: closing non-existent temporer at line {line_no+2}"
                active_temp.remove(e)
            elif t == 4:
                if len(parts) != 2:
                    raise AssertionError(f"{filename}: invalid format for query 4 at line {line_no+2}")
                u = int(parts[1])
                assert 1 <= u <= n
            else:
                raise AssertionError(f"{filename}: invalid query type {t} at line {line_no+2}")

        if active_temp:
            raise AssertionError(f"{filename}: temporer edges remain open after Q queries")

def check_all_tests():
    folder = "tests"
    files = sorted([f for f in os.listdir(folder) if f.startswith("input") and f.endswith(".txt")])
    all_ok = True
    for fname in files:
        path = os.path.join(folder, fname)
        try:
            check_testcase(path)
            print(f"OK: {fname}")
        except AssertionError as e:
            print(f"INVALID: {fname} -> {e}")
            all_ok = False
    if all_ok:
        print("All test files are valid ✅")
    else:
        print("Some test files are invalid ❌")

if __name__ == "__main__":
    generate_all = True
    if generate_all:
        generate_all_tests()
        print("\nNow running checker on generated files...")
        check_all_tests()
