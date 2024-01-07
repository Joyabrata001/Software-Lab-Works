import pandas as pd
import matplotlib.pyplot as plt
# import matplotlib.ticker as ticker

runtime_data = pd.read_csv(
    "C:\\Users\\joyab\\Documents\\MyRepo\\College\\6th Sem\\Software Lab\\Assignment 1\\5_Merge_Sort_Iterations.csv"
)
N = runtime_data["N"]
runtime = runtime_data["Iterations"]

plt.plot(N, runtime, linestyle="-")
plt.title("Merge_Sort Runtime")
plt.xlabel("N")
plt.ylabel("Iterations")
plt.tight_layout()
plt.grid(True)
plt.show()
