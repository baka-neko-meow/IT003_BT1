import numpy as np

num_sequences = 10
num_elements = 1_000_000


descending = np.random.uniform(-1000000, 1000000, num_elements)
descending.sort()
descending = descending[::-1] 
np.savetxt("sequence_1.txt", descending, fmt="%.6f")


ascending = np.random.uniform(-1000000, 1000000, num_elements)
ascending.sort()  
np.savetxt("sequence_2.txt", ascending, fmt="%.6f")


for i in range(3, num_sequences + 1):
    random_array = np.random.uniform(-1000000, 1000000, num_elements)
    np.savetxt(f"sequence_{i}.txt", random_array, fmt="%.6f")

