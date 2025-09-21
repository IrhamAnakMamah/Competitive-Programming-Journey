import random
import os
import subprocess
import zipfile

MAX_N = 10**5
MAX_M = 2 * 10**5

def generate_graph(n, m, core_count, seed=None):
    if seed is not None:
        random.seed(seed)

    # Proteksi N dan core_count
    n = max(1, min(n, MAX_N))
    core_count = max(1, min(core_count, n))

    # Pilih stasiun inti
    core_stations = sorted(random.sample(range(1, n + 1), core_count))
    stations = [1 if i + 1 in core_stations else 0 for i in range(n)]

    # Hitung jumlah edge maksimum
    max_edges = min(MAX_M, n * (n - 1) // 2)
    m = max(0, min(m, max_edges))

    edges = set()
    while len(edges) < m:
        u, v = random.sample(range(1, n + 1), 2)
        if (u, v) not in edges and (v, u) not in edges:
            edges.add((u, v))

    return n, m, stations, list(edges)

def save_input(filename, n, m, stations, edges):
    with open(filename, "w") as f:
        f.write(f"{n} {m}\n")
        f.write(" ".join(map(str, stations)) + "\n")
        for u, v in edges:
            f.write(f"{u} {v}\n")

def generate_testcases(num_easy=3, num_medium=3, num_hard=4, output_dir="cases", solution_path="./solution"):
    os.makedirs(f"{output_dir}/in", exist_ok=True)
    os.makedirs(f"{output_dir}/out", exist_ok=True)

    case_id = 1
    # Easy cases
    for _ in range(num_easy):
        n = random.randint(5, 50)
        m = random.randint(0, min(n * 2, MAX_M))
        core = random.randint(1, n)
        n, m, stations, edges = generate_graph(n, m, core, seed=case_id * 111)
        save_input(f"{output_dir}/in/input{case_id}.txt", n, m, stations, edges)
        subprocess.run([solution_path], stdin=open(f"{output_dir}/in/input{case_id}.txt"),
                       stdout=open(f"{output_dir}/out/output{case_id}.txt", "w"))
        case_id += 1

    # Medium cases
    for _ in range(num_medium):
        n = random.randint(1000, 10000)
        m = random.randint(n, min(5 * n, MAX_M))
        core = random.randint(1, n // 5 + 1)
        n, m, stations, edges = generate_graph(n, m, core, seed=case_id * 222)
        save_input(f"{output_dir}/in/input{case_id}.txt", n, m, stations, edges)
        subprocess.run([solution_path], stdin=open(f"{output_dir}/in/input{case_id}.txt"),
                       stdout=open(f"{output_dir}/out/output{case_id}.txt", "w"))
        case_id += 1

    # Hard cases
    for _ in range(num_hard):
        n = random.randint(MAX_N // 2, MAX_N)
        m = random.randint(n, MAX_M)
        core = random.randint(1, n // 10 + 1)
        n, m, stations, edges = generate_graph(n, m, core, seed=case_id * 333)
        save_input(f"{output_dir}/in/input{case_id}.txt", n, m, stations, edges)
        subprocess.run([solution_path], stdin=open(f"{output_dir}/in/input{case_id}.txt"),
                       stdout=open(f"{output_dir}/out/output{case_id}.txt", "w"))
        case_id += 1

    # Bundling ke ZIP
    zip_filename = f"{output_dir}.zip"
    with zipfile.ZipFile(zip_filename, 'w', zipfile.ZIP_DEFLATED) as zipf:
        for folder in ["in", "out"]:
            folder_path = os.path.join(output_dir, folder)
            for file in os.listdir(folder_path):
                zipf.write(os.path.join(folder_path, file),
                           arcname=os.path.join(folder, file))

    print(f"[INFO] {case_id-1} test case berhasil dibuat dan dibundel ke {zip_filename}")

if __name__ == "__main__":
    generate_testcases()
