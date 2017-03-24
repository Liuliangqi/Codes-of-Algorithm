//created by Liangqi
#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void shellSort(T arr[], int n){
    for(int gap = n / 2; gap > 0; gap /= 2){
        for(int i = gap; i < n; i++){
            for(int j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j--){
                swap(arr[j], arr[j+gap]);
            }
        }
    }
}


int main(){
    int n = 10000;
    int* a = SortTest::generateRandomArray(n, 0, 100);
    SortTest::testSort("Shell Sort", shellSort, a, n);
  
    delete[] a;
    return 0;
}
