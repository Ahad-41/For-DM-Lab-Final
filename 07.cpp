#include<bits/stdc++.h>
using namespace std;

int inBubbleSort, inInsertionSort;

void bubbleSort(int arr[], int n) {
    if (n == 1) return;
    int swapped = 0;

    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
            swapped = 1;
            inBubbleSort++;
        }
    }

    if (swapped == 0) return;
    bubbleSort(arr, n-1);
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int currentValue = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > currentValue) {
            arr[j + 1] = arr[j];
            inInsertionSort++;
            j--;
        }

        arr[j + 1] = currentValue;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }

    bubbleSort(arr1, n);
    insertionSort(arr2, n);

    cout << "The number of comparisons in bubble sort is " <<  inBubbleSort <<  endl;
    cout << "The number of comparisons in insertion sort is "  << inInsertionSort << endl;

    return 0;
}
