#include "function.h"
// random number 
int random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// quick sort for array
void quickSort(vector<int>& arr, int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
// write array to file
void write_Array(vector<int>& arr, string fileName) {
    // delete data of file
    ofstream fs_delete(fileName);
    fs_delete.close();
    // write data to file
    ofstream fs_out;
    fs_out.open(fileName);
    for (int i = 0; i < arr.size(); i++) {
        fs_out << arr[i] << endl;
    }
    fs_out.close();
}
// print array to console
void print_Array(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// read array from file
vector<int> input_Array(string fileName) {
    vector<int> arr;
    ifstream fs_in;
    fs_in.open(fileName);

    // check file have data
    if (fs_in.is_open()) {
        int tmp;
        while (fs_in >> tmp) {
            arr.push_back(tmp);
        }
    }
    if (arr.size() < 1) {
        for (int i = 0; i < 5000; i++) {
            arr.push_back(random(0, 10000));
        }
    }
    fs_in.close();
    return arr;
}


// heap sort for array
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}
void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
// selections sort
void selections_Sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[min], arr[i]);
    }
}

// merge sort for array 
void merge(vector<int>& arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1);
    vector<int> R(n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(vector<int>& arr, int l, int n) {
    if (l < n) {
        int m = (l + n) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, n);
        merge(arr, l, m, n);
    }
}

// insertion sort for array
void insertion_Sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// bubble sort for array
void bubble_Sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// radix sort for array

void radix_Sort(vector<int>& arr) {
    int n = arr.size();
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > m)
            m = arr[i];
    }
    for (int exp = 1; m / exp > 0; exp *= 10) {
        vector<int> output(n);
        vector<int> count(10);
        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--)
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        for (int i = 0; i < n; i++)
            arr[i] = output[i];
    }
}

void time_sort(vector<int>& arr) {
    clock_t start, end;
    start = clock();
    // quickSort(arr, 0, arr.size() - 1);
    // heapSort(arr);
    selections_Sort(arr);
    // merge_sort(arr, 0, arr.size() - 1);
    // insertion_Sort(arr);
    // bubble_Sort(arr);
    // radix_Sort(arr);  // dont run this function
    end = clock();
    double duration = (double)(end - start);
    cout << "duration: " << duration << " seconds" << endl;
}

// control_functions for array
void control_functions(vector<int>& arr) {
    arr = input_Array("array.txt");
    write_Array(arr, "array.txt");
    time_sort(arr);
    write_Array(arr, "array_sort.txt");
}
