#include <iostream> // For input and output
using namespace std;

// Function to perform Selection Sort using Greedy approach
void selectionSort(int arr[], int n) {
    // Traverse the entire array except the last element
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the current index has the smallest element

        // Traverse the unsorted part of the array to find the minimum
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update minIndex if smaller element is found
            }
        }

        // Swap the found minimum element with the element at current index
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function to print the elements of the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print each element followed by a space
    }
    cout << endl; // Print newline after printing the array
}

// Main function
int main() {
    int n; // Variable to store the size of the array

    // Ask user to enter number of elements
    cout << "Enter number of elements: ";
    cin >> n; // Take input for size

    int arr[n]; // Declare array of size n

    // Ask user to input array elements
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Read each element into the array
    }

    cout << "Original array: ";
    printArray(arr, n); // Print array before sorting

    selectionSort(arr, n); // Sort array using Greedy Selection Sort

    cout << "Sorted array: ";
    printArray(arr, n); // Print array after sorting

    return 0; // Indicate successful program execution
}
