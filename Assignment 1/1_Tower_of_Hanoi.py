import pandas as pd
import matplotlib.pyplot as plt

# Read runtime data
runtime_data = pd.read_csv(
    "C:\\Users\\joyab\\Documents\\MyRepo\\College\\6th Sem\\Software Lab\\Assignment 1\\1_Tower_of_Hanoi_Runtime.csv"
)
discs = runtime_data["Discs"]
runtime = runtime_data["Runtime(ms)"]

# Read moves data
moves_data = pd.read_csv(
    "C:\\Users\\joyab\\Documents\\MyRepo\\College\\6th Sem\\Software Lab\\Assignment 1\\1_Tower_of_Hanoi_Iterations.csv"
)
moves = moves_data["Moves"]

# Create subplots side by side
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 6))

# Plot 1: Runtime
ax1.plot(discs, runtime, marker="o", linestyle="-")
ax1.set_title("ToH Runtime")
ax1.set_xlabel("Discs")
ax1.set_ylabel("Runtime (ms)")
ax1.set_xticks(range(0, len(discs) + 4, 4))
ax1.grid(True)

# Plot 2: Number of Moves
ax2.plot(discs, moves, marker="o", linestyle="-")
ax2.set_title("ToH Iterations")
ax2.set_xlabel("Discs")
ax2.set_ylabel("Moves")
ax2.set_xticks(range(0, len(discs) + 4, 4))
ax2.grid(True)

# Adjust layout and display
plt.tight_layout()
plt.show()
