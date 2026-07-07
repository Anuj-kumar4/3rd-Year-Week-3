#include <iostream>
#include <vector>
using namespace std;

// Partition for Descending Order
int partition(vector<long long> &arr, int low, int high) {

    long long pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j] > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<long long> &arr, int low, int high) {

    if (low < high) {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {

    int n;
    cin >> n;

    vector<long long> arr(n);

    long long total = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    quickSort(arr, 0, n - 1);

    // Sorted Array
    for (long long x : arr)
        cout << x << " ";
    cout << endl;

    // Top 5 Values
    cout << "Top 5: ";

    long long sumTop = 0;

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
        sumTop += arr[i];
    }

    cout << endl;

    cout << "Average of Top 5: " << (double)sumTop / 5 << endl;

    double overallAvg = (double)total / n;

    int count = 0;

    for (long long x : arr) {
        if (x > overallAvg)
            count++;
    }

    cout << "Values Above Overall Average: " << count;

    return 0;
}
