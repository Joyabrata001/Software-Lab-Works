import pandas as pd
import matplotlib.pyplot as plt


def plot_graph(x, y, title, xlabel, ylabel):
    plt.figure(figsize=(8, 6))
    plt.plot(x, y)
    plt.title(title)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.grid(True)
    plt.tight_layout()
    plt.show()


iterations_data = pd.read_csv(
    "C:\\Users\\joyab\\Documents\\MyRepo\\College\\6th Sem\\Software Lab\\Assignment 1\\2_Kruskal_Algorithm_Iterations.csv"
)

V = iterations_data["V"]
ElogE = iterations_data["ElogE"]
VlogV = iterations_data["VlogV"]
ElogV = iterations_data["ElogV"]
VlogE = iterations_data["VlogE"]
Steps = iterations_data["Iterations"]

plot_graph(V, Steps / ElogE, "Steps / ElogE", "V", "Steps / ElogE")
plot_graph(V, Steps / VlogV, "Steps / VlogV", "V", "Steps / VlogV")
plot_graph(V, Steps / ElogV, "Steps / ElogV", "V", "Steps / ElogV")
plot_graph(V, Steps / VlogE, "Steps / VlogE", "V", "Steps / VlogE")
