//created by Liangqi
#include <iostream>
#include "SortTestHelper.h"

using namespace std;

//regard current num as minIndex, compare it with all following nums
//let minIndex point to the smallest num in the remaining nums, and swap it with current num
template<typename T>
void selectionSort(T arr[], int n){
    for(int i = 0; i < n; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    
    int main(){
        int n = 10000;
        int* a = SortTest::generateRandomArray(n, 0, 100);
        SortTest::testSort("Selection Sort", selectionSort, a, n);
        
        delete[] a;
        return 0;
    }
    
}
