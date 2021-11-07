#include "function.h"
// random number 
int random(int min, int max) {
    return rand() % (max - min + 1) + min;
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
// create array random number
void create_Array(vector<int> arr, int size) {
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            arr.push_back(random(0, 50000));
        }
    }
    else {
        for (int i = 0; i < 50000; i++) {
            arr.push_back(random(0, 50000));
        }
    }
}

// create array 0  to 50000
void create_Array_0_to_50000(vector<int> arr, int size) {
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            arr.push_back(i);
        }
    }
    else {
        for (int i = 0; i < 50000; i++) {
            arr.push_back(i);
        }
    }
}

// create array 50000 to 0
void create_Array_50000_to_0(vector<int> arr, int size) {
    if (size > 0) {
        for (int i = size; i > 0; i--) {
            arr.push_back(i);
        }
    }
    else {
        for (int i = 50000; i > 0; i--) {
            arr.push_back(i);
        }
    }
}
// create array some number random
void create_Array_some_number_random(vector<int> arr, int size) {
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            arr.push_back(i);
        }
    }
    else {
        for (int i = 0; i < 50000; i++) {
            arr.push_back(i);
        }
    }
    for (int i = 0; i < 100; i++) {
        int j = random(0, 50000);
        swap(arr[i], arr[j]);
    }
}

// read array from file
vector<int> input_Array(int data_type, int size) {
    vector<int> arr;
    switch (data_type)
    {
    case 0:	// ngẫu nhiên
        create_Array(arr, size);
        break;
    case 1:	// có thứ tự
        create_Array_0_to_50000(arr, size);
        break;
    case 2:	// có thứ tự ngược
        create_Array_50000_to_0(arr, size);
        break;
    case 3:	// gần như có thứ tự
        create_Array_some_number_random(arr, size);
        break;
    }
    return arr;
}

// quick sort for array
void quick_Sort(vector<int>& arr, int left, int right) {
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
        quick_Sort(arr, left, j);
    if (i < right)
        quick_Sort(arr, i, right);
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
void heap_Sort(vector<int>& arr) {
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
void selection_Sort(vector<int>& arr) {
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
void merge_Sort(vector<int>& arr, int l, int n) {
    if (l < n) {
        int m = (l + n) / 2;
        merge_Sort(arr, l, m);
        merge_Sort(arr, m + 1, n);
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
void radix_Sort(vector<int>& arr)
{
    int n = arr.size();
    int mx = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > mx)
            mx = arr[i];
    }
    for (int exp = 1; mx / exp > 0; exp *= 10)
    {
        //
        int output[500005]; // output array
        int i, count[10] = { 0 };

        // Store count of occurrences in count[]
        for (i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        // Change count[i] so that count[i] now contains actual
        //  position of this digit in output[]
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Build the output array
        for (i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        // Copy the output array to arr[], so that arr[] now
        // contains sorted numbers according to current digit
        for (i = 0; i < n; i++)
            arr[i] = output[i];
    }
}


// shaker sort for array
void shaker_Sort(vector<int>& arr) {
    int n = arr.size();
    int Left = 0;
    int Right = n - 1;
    int k = 0;
    while (Left < Right)
    {
        for (int i = Left; i < Right; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                k = i;
            }
        }
        Right = k;
        for (int i = Right; i > Left; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
                k = i;
            }
        }
        Left = k;
    }
}
// Shell Sort for array 
void shell_Sort(vector<int>& arr) {
    int n = arr.size();
    int gap = n / 2;
    while (gap > 0) {
        for (int i = 0; i < n - gap; i++) {
            int j = i + gap;
            int temp = arr[j];
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j = j - gap;
            }
            arr[j] = temp;
        }
        gap = gap / 2;
    }
}
// counting Sort for array
void counting_Sort(vector<int>& arr) {
    int n = arr.size();
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    vector<int> count(max + 1);
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    for (int i = 1; i < max + 1; i++)
        count[i] += count[i - 1];
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    arr = output;
}

// flash sort for array
void flash_Sort(vector<int>& arr)
{
    int n = arr.size();
    int min = arr[0];
    int max = 0;
    int m = int(0.45 * n);
    int l[500006];
    for (int i = 0; i < m; i++) l[i] = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > arr[max])
            max = i;
    }
    if (arr[max] == min)
    {
        return;
    }
    double c1 = (double)(m - 1) / (arr[max] - min);
    for (int i = 0; i < n; i++)
    {
        int k = int(c1 * (arr[i] - min));
        ++l[k];
    }
    for (int i = 1; i < m; i++)
        l[i] += l[i - 1];
    //swap
    int temp = arr[max];
    arr[max] = arr[0];
    arr[0] = temp;

    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;
    while (nmove < n - 1)
    {
        while (j > l[k] - 1)
        {
            j++;
            k = int(c1 * (arr[j] - min));
        }
        flash = arr[j];
        if (k < 0)
        {
            break;
        }
        while (j != l[k])
        {
            k = int(c1 * (flash - min));
            int hold = arr[t = --l[k]];
            arr[t] = flash;
            flash = hold;
            ++nmove;
        }
    }
    for (int i = 1; i < n; i++)
    {
        int k = i - 1;
        int key = arr[i];
        while (arr[k] > key && k >= 0)
        {
            arr[k + 1] = arr[k];
            k--;
        }
        arr[k + 1] = key;
    }
}

// sort witch sort name 
double sort_with_name(vector<int>& arr, string name)
{
    clock_t start, end;
    if (name == "bubble") {
        start = clock();
        bubble_Sort(arr);
        end = clock();
    }
    else if (name == "insertion") {
        start = clock();
        insertion_Sort(arr);
        end = clock();
    }
    else if (name == "selection") {
        start = clock();
        selection_Sort(arr);
        end = clock();
    }
    else if (name == "merge") {
        start = clock();
        merge_Sort(arr, 0, arr.size() - 1);
        end = clock();
    }
    else if (name == "quick") {
        start = clock();
        quick_Sort(arr, 0, arr.size() - 1);
        end = clock();
    }
    else if (name == "heap") {
        start = clock();
        heap_Sort(arr);
        end = clock();
    }
    else if (name == "radix") {
        start = clock();
        radix_Sort(arr);
        end = clock();
    }
    else if (name == "shaker") {
        start = clock();
        shaker_Sort(arr);
        end = clock();
    }
    else if (name == "shell") {
        start = clock();
        shell_Sort(arr);
        end = clock();
    }
    else if (name == "counting") {
        start = clock();
        counting_Sort(arr);
        end = clock();
    }
    else if (name == "flash") {
        start = clock();
        flash_Sort(arr);
        end = clock();
    }

    double duration = (double)(end - start);
    return duration;

}
void out_sort_times(double& duration, string name) {
    fstream fsTime("time_sort.txt", ios::out | ios::app);
    fsTime << name << " sort have times: " << duration << " seconds" << endl;
}
void time_sort(vector<int>& arr) {


    // enter sort name 
    cout << "Sort name " << endl;
    cout << "1. quick " << endl;
    cout << "2. merge " << endl;
    cout << "3. heap " << endl;
    cout << "4. counting " << endl;
    cout << "5. flash " << endl;
    cout << "6. shaker " << endl;
    cout << "7. shell " << endl;
    cout << "8. radix " << endl;
    cout << "9. bubble " << endl;
    cout << "10. insertion " << endl;
    cout << "11. selection " << endl;
    cout << "12. exit " << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    string name;
    switch (choice)
    {
    case 1:
        name = "quick";
        break;
    case 2:
        name = "merge";
        break;
    case 3:
        name = "heap";
        break;
    case 4:
        name = "counting";
        break;
    case 5:
        name = "flash";
        break;
    case 6:
        name = "shaker";
        break;
    case 7:
        name = "shell";
        break;
    case 8:
        name = "radix";
        break;
    case 9:
        name = "bubble";
        break;
    case 10:
        name = "insertion";
        break;
    case 11:
        name = "selection";
        break;
    case 12:
        return;
    default:
        cout << "Invalid choice" << endl;
        return;
    }
    double duration = sort_with_name(arr, name);
    cout << "Times: " << duration << " seconds " << "by " << name << " sort " << endl;
    out_sort_times(duration, name);
}

// print data file time_sort.txt
void print_data_file() {
    fstream fsTime("time_sort.txt", ios::in);
    string line;
    while (getline(fsTime, line))
    {
        cout << line << endl;
    }
}


// control_functions for array
void control_functions(vector<int>& arr) {
    int choice;
    cout << "Enter type data of array" << endl;
    cout << "0. random " << endl;
    cout << "1. sorted " << endl;
    cout << "2. reverse " << endl;
    cout << "3. some number random " << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    int size = 0;
    cout << "Enter size of array" << endl;
    cout << "If you enter 0 the array have size 50000" << endl;
    cout << "Enter your choice: ";
    cin >> size;
    
    arr = input_Array(choice, size);
    cout << endl << endl;
    write_Array(arr, "array.txt");
    time_sort(arr);
    write_Array(arr, "array_sort.txt");

    cout << endl << "print sort time history: " << endl;
    print_data_file();
}
