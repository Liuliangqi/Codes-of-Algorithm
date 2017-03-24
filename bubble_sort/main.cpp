//created by Liangqi
#include <iostream>
#include "SortTestHelper.h"

using namespace std;


//normal way to solve this, start from 0 each round, and everytime find a smaller one, swap them
//inside loop, must smaller than n - i - 1, after n - i - 1,all in right place
template<typename T>
void bubbleSort(T arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

//use a flag to verify sorted or not
template<typename T>
void bubbleSortII(T arr[], int n){
    bool swapped;
    do{
        swapped = false;
        for(int i = 1; i < n; i++){
            if(arr[i - 1] > arr[i]){
                swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        n--;
    }while(swapped);
}


int main(){
    int n = 10000;
    //generate an array composed by nums lt 100 
    int* a = SortTest::generateRandomArray(n, 0, 100);
    int* b = SortTest::copyIntArray(a, n);
    SortTest::testSort("Bubble Sort", bubbleSort, a, n);
    SortTest::testSort("Bubble SortII", bubbleSortII, b, n);
    delete[] a;
    delete[] b;
    return 0;
}
