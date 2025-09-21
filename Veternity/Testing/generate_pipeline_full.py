import random
import os
import subprocess
import zipfile
from checker import check_output
from validator import validate_input

MAX_N = 10**5
MAX_M = 2 * 10**5
MAX_REGENERATE = 5  # regenerasi maksimum sebelum error

def generate_graph(n, m, core_count, seed=None):
    if seed is not None:
        random.seed(seed)

    n = max(1, min(n, MAX_N))
    core_count = max(1, min(core_count, n))

    core_stations = sorted(random.sample(range(1, n + 1), core_count))
    stations = [1 if i + 1 in core_stations else 0 for i in range(n)]

    max_edges = min(MAX_M, n * (n - 1) // 2)
    m = max(0, min(m, max_edges))

    edges = set()
    while len(edges) < m:
        u, v = random.sample(range(1, n + 1), 2)
        if u != v and (u, v) not in edges and (v, u) not in edges:
            edges.add((u, v))

    return n, m, stations, list(edges)

def save_input(filename, n, m, stations, edges):
    with open(filename, "w") as f:
        f.write(f"{n} {m}\n")
        f.write(" ".join(map(str, stations)) + "\n")
        for u, v in edges:
            f.write(f"{u} {v}\n")

def generate_pipeline(num_easy=3, num_medium=3, num_hard=4,
                      output_dir="cases", solution_path="./soal_penyisihan.exe"):
    os.makedirs(f"{output_dir}/in", exist_ok=True)
    os.makedirs(f"{output_dir}/out", exist_ok=True)

    case_id = 1
    categories = [
        ("easy", num_easy, 5, 50, lambda n: random.randint(0, min(n * 2, MAX_M))),
        ("medium", num_medium, 1000, 10000, lambda n: random.randint(n, min(5 * n, MAX_M))),
        ("hard", num_hard, MAX_N // 2, MAX_N, lambda n: random.randint(n, MAX_M))
    ]

    for category, num_cases, n_min, n_max, m_gen in categories:
        for _ in range(num_cases):
            regenerate_attempts = 0
            while True:
                n = random.randint(n_min, n_max)
                m = m_gen(n)
                core = random.randint(1, max(1, n // 5))
                n, m, stations, edges = generate_graph(n, m, core, seed=case_id * 111 + regenerate_attempts)
                
                input_path = f"{output_dir}/in/input{case_id}.txt"
                output_path = f"{output_dir}/out/output{case_id}.txt"
                save_input(input_path, n, m, stations, edges)

                # Validate input
                valid, v_msg = validate_input(input_path)
                if not valid:
                    regenerate_attempts += 1
                    if regenerate_attempts > MAX_REGENERATE:
                        raise RuntimeError(f"Gagal membuat input valid setelah {MAX_REGENERATE} percobaan: {v_msg}")
                    print(f"[REGENERATE] Input tidak valid: {v_msg} → regenerasi...")
                    continue

                # Generate output menggunakan solusi resmi
                subprocess.run([solution_path], stdin=open(input_path),
                               stdout=open(output_path, "w"))

                # Check output
                ok, c_msg = check_output(input_path, output_path)
                if not ok:
                    regenerate_attempts += 1
                    if regenerate_attempts > MAX_REGENERATE:
                        raise RuntimeError(f"Gagal membuat output valid setelah {MAX_REGENERATE} percobaan: {c_msg}")
                    print(f"[REGENERATE] Output tidak valid: {c_msg} → regenerasi...")
                    continue

                print(f"[OK] Case {case_id} ({category}) ✔")
                break

            case_id += 1

    # Buat ZIP
    zip_filename = f"{output_dir}.zip"
    with zipfile.ZipFile(zip_filename, 'w', zipfile.ZIP_DEFLATED) as zipf:
        for folder in ["in", "out"]:
            folder_path = os.path.join(output_dir, folder)
            for file in os.listdir(folder_path):
                zipf.write(os.path.join(folder_path, file),
                           arcname=os.path.join(folder, file))

    print(f"[INFO] {case_id-1} test case berhasil dibuat, divalidasi, diverifikasi, dan dibundel ke {zip_filename}")

if __name__ == "__main__":
    generate_pipeline()
