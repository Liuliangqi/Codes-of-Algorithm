//created by Liangqi
#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void merge(T arr[], int start, int middle, int end){
    T* aux = new T[end - start + 1];
    //position in arr is start, in aux is i - start (from 0)
    for(int i = start; i <= end; i++){
        aux[i - start] = arr[i];
    }
    //actually adjust the position of nums in aux[0, mid] and aux[mid, last]
    int i = start, j = middle + 1;
    for(int k = start; k <= end; k++){
        if(i > middle){
            arr[k] = aux[j - start];
            j++;
        }else if(j > end){
            arr[k] = aux[i - start];
            i++;
        }else if(aux[i - start] < aux[j - start]){
            arr[k] = aux[i - start];
            i++;
        }else{
            arr[k] = aux[j - start];
            j++;
        }
    }
}

template<typename T>
void mergeSortII(T arr[], int start, int end){
    if(start >= end){
        return;
    }
    int middle = start + (end - start) / 2;
    
    mergeSortII(arr, start, middle);
    mergeSortII(arr, middle + 1, end);
    //save some time, if arr[middle] already lt arr[middle + 1] that means do not need to merge, already done
    if(arr[middle] > arr[middle + 1])
        merge(arr, start, middle, end);
}

template<typename T>
void mergeSort(T arr[], int n){
    mergeSortII(arr, 0, n - 1);
}


template<typename T>
void mergeSortv2(T arr[], int n){
    //size start from 1, means each round only compare 2 nums
    // everytime double size, and go through 4, 8 .... n
    for(int sz = 1; sz <= n; sz += sz){
        //everytime merge 2*sz nums, and move this window forward till end
        //but merge should check ends
        for(int i = 0; i + sz < n; i += sz + sz){
            merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
        }
    }
}

int main(){
    int n = 10000;
    int* a = SortTest::generateRandomArray(n, 0, 100);
    
    SortTest::testSort("Merge Sort", mergeSort, a, n);
    
    delete[] a;
    return 0;
}
