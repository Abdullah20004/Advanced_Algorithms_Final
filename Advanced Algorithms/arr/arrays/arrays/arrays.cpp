#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <string>
#include <iomanip>
#include <numeric>

using namespace std;
using namespace chrono;

typedef pair<double, int> SortResult;

void heapify(vector<int>& arr, int n, int i, int& comparisons)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n)
    {
        comparisons++;
        if (arr[left] < arr[smallest])
            smallest = left;
    }

    if (right < n)
    {
        comparisons++;
        if (arr[right] < arr[smallest])
            smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest, comparisons);
    }
}

SortResult heap_sort_count(vector<int> arr)
{
    int n = arr.size();
    int comparisons = 0;
    auto start = high_resolution_clock::now();

    for (int i = n / 2 - 1; i >= 0; --i)
    {
        heapify(arr, n, i, comparisons);
    }

    for (int i = n - 1; i > 0; --i)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, comparisons);
    }

    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;
    return { elapsed.count(), comparisons };
}

SortResult bubble_sort_count(vector<int> arr)
{
    int n = arr.size();
    int comparisons = 0;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < n - 1; ++i)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j)
        {
            comparisons++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }

    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;
    return { elapsed.count(), comparisons };
}

SortResult selection_sort_count(vector<int> arr)
{
    int n = arr.size();
    int comparisons = 0;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < n - 1; ++i)
    {
        int min_index = i;
        for (int j = i + 1; j < n; ++j)
        {
            comparisons++;
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
            swap(arr[i], arr[min_index]);
    }

    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;
    return { elapsed.count(), comparisons };
}

SortResult insertion_sort_count(vector<int> arr)
{
    int n = arr.size();
    int comparisons = 0;
    auto start = high_resolution_clock::now();

    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
        }

        if (j >= 0)
            comparisons++;
        arr[j + 1] = key;
    }

    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;
    return { elapsed.count(), comparisons };
}

void test_comparisons()
{
    vector<string> algorithms = { "heap_sort", "bubble_sort", "selection_sort", "insertion_sort" };
    vector<string> array_types = { "random", "sorted", "inverted" };

    ofstream time_file("execution_time.csv");
    ofstream comparison_file("comparisons.csv");

    time_file << "Algorithm,Array Type";
    comparison_file << "Algorithm,Array Type";
    for (int size = 1; size <= 30; ++size)
    {
        time_file << ",Size " << size;
        comparison_file << ",Size " << size;
    }
    time_file << "\n";
    comparison_file << "\n";

    for (const auto& algo : algorithms)
    {
        for (const auto& arr_type : array_types)
        {
            vector<double> times;
            vector<int> comparisons;

            for (int size = 1; size <= 30; ++size)
            {
                vector<int> arr(size);

                if (arr_type == "random")
                {
                    generate(arr.begin(), arr.end(), []()
                        { return rand() % 100 + 1; });
                }
                else if (arr_type == "sorted")
                {
                    iota(arr.begin(), arr.end(), 1);
                }
                else if (arr_type == "inverted")
                {
                    iota(arr.begin(), arr.end(), 1);
                    reverse(arr.begin(), arr.end());
                }

                SortResult result;
                if (algo == "heap_sort")
                    result = heap_sort_count(arr);
                else if (algo == "bubble_sort")
                    result = bubble_sort_count(arr);
                else if (algo == "selection_sort")
                    result = selection_sort_count(arr);
                else if (algo == "insertion_sort")
                    result = insertion_sort_count(arr);

                times.push_back(result.first);
                comparisons.push_back(result.second);
            }

            time_file << algo << "," << arr_type;
            comparison_file << algo << "," << arr_type;

            for (double time : times)
                time_file << "," << time;
            for (int comp : comparisons)
                comparison_file << "," << comp;

            time_file << "\n";
            comparison_file << "\n";
        }
    }

    time_file.close();
    comparison_file.close();
}

int main()
{
    test_comparisons();
    cout << "Sorting analysis completed. Results saved to CSV files." << endl;
    return 0;
}