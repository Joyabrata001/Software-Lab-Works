import pandas as pd
import matplotlib.pyplot as plt


def plot_scatter(x, y, title, xlabel, ylabel):
    plt.scatter(x, y)
    plt.title(title)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.grid(True)
    plt.tight_layout()


iterations_data = pd.read_csv(
    "C:\\Users\\joyab\\Documents\\MyRepo\\College\\6th Sem\\Software Lab\\Assignment 1\\3_Dijkstra_Algorithm_Iterations.csv"
)

V = iterations_data["V"]
ElogE = iterations_data["ElogE"]
VlogV = iterations_data["VlogV"]
ElogV = iterations_data["ElogV"]
VlogE = iterations_data["VlogE"]
StepsPQ = iterations_data["StepsPQ"]
StepsSet = iterations_data["StepsSet"]

fig, axs = plt.subplots(2, 2, figsize=(12, 8))

# Plot Steps / ElogE for PQ and Set as scatter plots
axs[0, 0].scatter(V, StepsPQ / ElogE, label="PQ")
axs[0, 0].scatter(V, StepsSet / ElogE, label="Set")
axs[0, 0].set_title("Steps / ElogE")
axs[0, 0].set_xlabel("V")
axs[0, 0].set_ylabel("Steps / ElogE")
axs[0, 0].legend()
axs[0, 0].grid(True)

# Plot Steps / VlogV for PQ and Set as scatter plots
axs[0, 1].scatter(V, StepsPQ / VlogV, label="PQ")
axs[0, 1].scatter(V, StepsSet / VlogV, label="Set")
axs[0, 1].set_title("Steps / VlogV")
axs[0, 1].set_xlabel("V")
axs[0, 1].set_ylabel("Steps / VlogV")
axs[0, 1].legend()
axs[0, 1].grid(True)

# Plot Steps / ElogV for PQ and Set as scatter plots
axs[1, 0].scatter(V, StepsPQ / ElogV, label="PQ")
axs[1, 0].scatter(V, StepsSet / ElogV, label="Set")
axs[1, 0].set_title("Steps / ElogV")
axs[1, 0].set_xlabel("V")
axs[1, 0].set_ylabel("Steps / ElogV")
axs[1, 0].legend()
axs[1, 0].grid(True)

# Plot Steps / VlogE for PQ and Set as scatter plots
axs[1, 1].scatter(V, StepsPQ / VlogE, label="PQ")
axs[1, 1].scatter(V, StepsSet / VlogE, label="Set")
axs[1, 1].set_title("Steps / VlogE")
axs[1, 1].set_xlabel("V")
axs[1, 1].set_ylabel("Steps / VlogE")
axs[1, 1].legend()
axs[1, 1].grid(True)

plt.tight_layout()
plt.show()
