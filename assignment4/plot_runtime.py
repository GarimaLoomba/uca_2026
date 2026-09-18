
import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("runtime.csv")

plt.plot(
    data["n"],
    data["time_microseconds"],
    marker="o"
)

plt.xlabel("Dataset Size (n)")
plt.ylabel("Runtime (microseconds)")
plt.title("Quickselect Average Runtime")

plt.grid(True)

plt.savefig("quickselect_runtime.png", dpi=300)

plt.show()

