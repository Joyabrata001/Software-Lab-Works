import pandas as pd
import matplotlib.pyplot as plt

runtime_data = pd.read_csv(
    "C:\\Users\\joyab\\Documents\\MyRepo\\College\\6th Sem\\Software Lab\\Assignment 1\\4_N_Queen_Runtime.csv"
)
size = runtime_data["N"]
runtime = runtime_data["Runtime(ms)"]

plt.plot(size, runtime, marker="o", linestyle="-")
plt.title("N-Queen Runtime")
plt.xlabel("N")
plt.ylabel("Runtime(ms)")
plt.grid(True)
plt.tight_layout()
plt.show()
