//created by Liangqi
#inlcude <iostream>
#include "SortTestHelper.h"

using namespace std;

//start from index 1, back-forward and find a num smaller than current num, then swap
//but this spend lots of space and time, we can improve it
template<typename T>
void insertionSort(T arr[], int n){
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            if(arr[j] < arr[j - 1]){
                swap(arr[j], arr[j-1]);
            }
        }
        
        //or using another way
        /*
          for(int j = i; j > 0 && arr[j] < arr[j - 1]; j--){
              swap(arr[j], arr[j - 1]);
          }
        */
    }
}

//record curr num, every time arr[j - 1] > curr, let arr[j] = arr[j - 1], that means, j is not the right position
template<typename T>
void insertionSortII(T arr[], int n){
    for(int i = 1; i < n; i++){
        int temp = arr[i];
        int j;
        for(j = i; j > 0 && arr[j - 1] > temp; j--){
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}

int main() {
    int n = 10000;

    int* a = SortTest::generateRandomArray(n, 0, 100);
    int* b = SortTest::copyIntArray(a, n);

    SortTest::testSort("Insertion Sort", insertionSort, a, n);
    SortTest::testSort("Insertion SortII", insertionSortII, b, n);

    delete[](a);
    delete[](b);
    return 0;
}
