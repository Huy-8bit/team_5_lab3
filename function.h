#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;
int random(int min, int max);
void quick_Sort(vector<int>& arr, int left, int right);
void write_Array(vector<int>& arr, string fileName);
void print_Array(vector<int>& arr);
void heap_Sort(vector<int>& arr);
void heapify(vector<int>& arr, int n, int i);
void selection_Sort(vector<int>& arr);
void input_Array(vector<int>& arr, int data_type, int size);
void merge(vector<int>& arr, int l, int m, int r);
void merge_Sort(vector<int>& arr, int l, int n);
void control_functions(vector<int>& arr);
void insertion_Sort(vector<int>& arr);
void bubble_Sort(vector<int>& arr);
void radix_Sort(vector<int>& arr);
void shaker_Sort(vector<int>& arr);
void shell_Sort(vector<int>& arr);
void time_sort(vector<int>& arr);
void counting_Sort(vector<int>& arr);
void flash_Sort(vector<int>& arr);
double sort_with_name(vector<int>& arr, string name);
void out_sort_times(double& duration, string name, int size, int data_type);
void print_data_file();
void create_Array(vector<int>& arr, int size);
void create_Array_0_to_50000(vector<int>& arr, int size);
void create_Array_some_number_random(vector<int>& arr, int size);