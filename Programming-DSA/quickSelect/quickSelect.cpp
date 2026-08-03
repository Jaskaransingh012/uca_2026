#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[high]);
    return i;
}

void quickSelect(vector<int>& arr, int low, int high, int k) {
    if (low >= high)
        return;

    int pivotIndex = partition(arr, low, high);

    if (pivotIndex == k)
        return;
    else if (pivotIndex > k)
        quickSelect(arr, low, pivotIndex - 1, k);
    else
        quickSelect(arr, pivotIndex + 1, high, k);
}

vector<int> firstKElements(vector<int>& arr, int k) {
    if (k <= 0) return {};
    if (k >= arr.size()) return arr;

    quickSelect(arr, 0, arr.size() - 1, k - 1);

    return vector<int>(arr.begin(), arr.begin() + k);
}

int main() {
    vector<int> arr = {8, 1, 6, 2, 5, 3, 7, 4};
    int k = 4;

    vector<int> result = firstKElements(arr, k);

    cout << "First " << k << " smallest elements: ";
    for (int x : result)
        cout << x << " ";

    return 0;
}
