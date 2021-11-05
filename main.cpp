#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

// random number 
int random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// quick sort for array
void quickSort(vector<int> &arr, int left, int right) {
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
void writeArray(vector<int> &arr, string fileName) {
    ofstream outFile;
    outFile.open(fileName);
    for (int i = 0; i < arr.size(); i++) {
        outFile << arr[i] << endl;
    }
    outFile.close();
}
int main(int argc, char** argv) {
    srand((int)time(NULL));
    // create array of numbers have size 1000;
    vector<int> array;
    for (int i = 0; i < 1000; i++) {
        array.push_back(random(0, 1000));
    }
    // sort array witch functions
    quickSort(array, 0, 999);
    // write array to file witch functions
    writeArray(array, "array.txt");

    return 0;
}