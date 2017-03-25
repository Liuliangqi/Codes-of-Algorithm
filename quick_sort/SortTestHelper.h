//
// Created by Liangqi on 2017/3/13.
//

#ifndef ALGORITHM_SORTTESTHELPER_H
#define ALGORITHM_SORTTESTHELPER_H

#include <cassert>
#include <ctime>
#include <iostream>
using namespace std;
namespace SortTest{
    int* generateRandomArray(int n, int rangeL, int rangeR){
        assert(rangeL <= rangeR);
        int* arr = new int[n];
        srand(time(NULL));
        for(int i = 0; i < n; i++){
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }

        return arr;
    }

    template <typename T>
    void printArray(T* arr, int n){
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    template <typename T>
    bool isSorted(T arr[], int n){
        for(int i = 0; i < n - 1; i++){
            if(arr[i] > arr[i+1]){
                return false;
            }
        }
        return true;
    }

    template <typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n){
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();

        assert(isSorted(arr, n));
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s;" << endl;
        return;
    }

    int* copyIntArray(int* arr, int n){
        int* a = new int[n];
        copy(arr, arr+n, a);
        return a;
    }

    int* generateLessRandomArray(int n, int randomTime){
        int* arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = i;
        }
        srand(time(NULL));
        for(int i = 0; i < randomTime; i++){
            int posX = rand() % n;
            int posY = rand() % n;
            swap(arr[posX], arr[posY]);
        }
        return arr;
    }
};


#endif //ALGORITHM_SORTTESTHELPER_H
