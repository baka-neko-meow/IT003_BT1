import numpy as np
import time
import os

def process_file(filename):
    with open(filename, "r") as file:
        data = [float(line.strip()) for line in file]

    array = np.array(data)

    start_time = time.time()
    sorted_array = np.sort(array)
    elapsed_time = (time.time() - start_time) * 1000 

    print(f"{filename}: {elapsed_time:.3f} ms")

for i in range(1, 11):
    filename = f"sequence_{i}.txt"
    process_file(filename)
