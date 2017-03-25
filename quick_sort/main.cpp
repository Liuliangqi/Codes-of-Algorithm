//created by Liangqi
#include <iostream>
#inlcude "SortTestHelper.h"

using namespace std;

//this is the common way to do partition
template<typename T>
int partition(T arr[], int start, int end){
    T v = arr[start];
    int j = start;
    for(int k = start + 1; k <= end; k++){
        if(arr[k] < v){
            j++;
            swap(arr[j], arr[k]);
        }
    }
    swap(arr[j], arr[start]);
    return j;
}


//two-way partition
//two pointers, one from start, another from end
template<typename T>
int partitionII(T arr[], int start, int end){
    T v = arr[start];
    int i = start + 1, j = end;
    while(true){
        while(i <= end && arr[i] < v) i++;
        while(j >= start + 1 && arr[j] > v) j--;
        if(i > j) break;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    swap(arr[start], arr[j]);
    return j;
}

//three-way partition
//devide array into three part, first smaller than v, second equal to v, third bigger than v
//the return value should be a pointer to indicate the split point
template<typename T>
int* partitionIII(T arr[], int start, int end){
    T v = arr[start];
    int i = start + 1;
    int lt = start, gt = end + 1;
    while(i < gt){
        if(arr[i] < v){
            swap(arr[lt+1], arr[i]);
            lt++;
            i++'
        }else if(arr[i] > v){
            swap(arr[i], arr[gt - 1]);
            gt--;
        }else{
            i++;
        }
    }
    swap(arr[start], arr[lt]);
    int* a = new int[2];
    a[0] = lt - 1;
    a[1] = gt;
    return a;
}


template<typenam T>
void __quickSort(T arr[], int start, int end){
    if(start >= end){
        return;
    }
    
    int q = partition(arr, start, end);
    __quickSort(arr, 0, q);
    __quickSort(arr, q + 1, end);
}

template<typename T>
void quickSort(T arr[], int n){
    __quickSort(arr, 0, n - 1);
}

int main(){
    int n = 10000;
    int* a = SortTest::generateRandomArray(n, 0, 100);
    SortTest::testSort("Quick Sort", quickSort, a, n);
    
    delete[] a;
    return 0;
}
