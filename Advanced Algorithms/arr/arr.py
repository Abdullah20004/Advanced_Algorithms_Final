import pandas as pd
import matplotlib.pyplot as plt

# Load the CSV files
time_df = pd.read_csv(r'arrays\arrays\execution_time.csv')
comparison_df = pd.read_csv(r'arrays\arrays\comparisons.csv')

# Plotting execution time
plt.figure(figsize=(10, 6))
for algo in time_df['Algorithm'].unique():
    for arr_type in time_df['Array Type'].unique():
        subset = time_df[(time_df['Algorithm'] == algo) & (time_df['Array Type'] == arr_type)]
        plt.plot(subset.columns[2:], subset.iloc[0, 2:], label=f'{algo} ({arr_type})')

plt.title('Execution Time vs Array Size')
plt.xlabel('Array Size')
plt.ylabel('Execution Time (seconds)')
plt.legend()
plt.grid(True)
plt.xticks(rotation=45)
plt.tight_layout()
plt.savefig('execution_time_plot.png')
plt.show()

# Plotting number of comparisons
plt.figure(figsize=(10, 6))
for algo in comparison_df['Algorithm'].unique():
    for arr_type in comparison_df['Array Type'].unique():
        subset = comparison_df[(comparison_df['Algorithm'] == algo) & (comparison_df['Array Type'] == arr_type)]
        plt.plot(subset.columns[2:], subset.iloc[0, 2:], label=f'{algo} ({arr_type})')

plt.title('Number of Comparisons vs Array Size')
plt.xlabel('Array Size')
plt.ylabel('Number of Comparisons')
plt.legend()
plt.grid(True)
plt.xticks(rotation=45)
plt.tight_layout()
plt.savefig('comparisons_plot.png')
plt.show()
