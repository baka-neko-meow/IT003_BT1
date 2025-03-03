import numpy as np

def generate_sequences(num_sequences=10, sequence_length=1_000_000, output_prefix="output"):
    
    sequences = [np.linspace(0, 1, sequence_length), np.linspace(1, 0, sequence_length)]
    
    for _ in range(8):
        sequences.append(np.random.rand(sequence_length))
    
    for i, seq in enumerate(sequences):
        output_file = f"{output_prefix}_{i+1}.txt"
        with open(output_file, "w") as f:
            f.write(" ".join(map(str, seq)) + "\n")
generate_sequences()
