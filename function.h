#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;
int random(int min, int max);
void quickSort(vector<int>& arr, int left, int right);
void write_Array(vector<int>& arr, string fileName);
void print_Array(vector<int>& arr);
void heapSort(vector<int>& arr);
void heapify(vector<int>& arr, int n, int i);
void selections_Sort(vector<int>& arr);
vector<int> input_Array(string fileName);
void merge(vector<int>& arr, int l, int m, int r);
void merge_sort(vector<int>& arr, int l, int n);
void control_functions(vector<int>& arr);
void insertion_Sort(vector<int>& arr);
void bubble_Sort(vector<int>& arr);
void radix_Sort(vector<int>& arr);
void shaker_Sort(vector<int>& arr);
void shell_Sort(vector<int>& arr);
void time_sort(vector<int>& arr);
void counting_Sort(vector<int>& arr);
void flash_Sort(vector<int>& arr);

