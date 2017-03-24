//created by Liangqi
#ifndef ALGORITHM_SORTTESTHELPER_H
#define ALGORITHM_SORTTESTHELPER_H
#include <cassert>
#include <ctime>
#include <iostream>
using namespace std;

//create a new namespace
namespace SortTest{
    int* generateRandomArray(int n, int rangeL, int rangeR){
        //if rangeL > rangeR, stop the code and print some error information
        assert(rangeL <= rangeR);
        int* arr = new int[n]l
        //initial seed
        srand(time(NULL));
        for(int i = 0; i < n; i++){
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }
    
    //print array
    template<typename T>
    void printArray(T* arr, int n){
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    //verify sort result
    template<typename T>
    bool isSorted(T arr[], int n){
        for(int i = 0; i < n-1; i++){
            if(arr[i] > arr[i + 1]){
                return false;
            }
        }
        return true;
    }
    //test sort time and result
    template<typename T>
    void testSort(string name, void(*sort)(T[], int), T arr[], int n){
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        
        assert(isSorted(arr, n));
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s;" << endl;
        return;
    }
    
    
    //copy int array
    int* copyIntArray(int* arr, int n){
        int* a = new int[n];
        copy(arr, arr+n, a);
        return a;
    }
    
    //generate an array that less random
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
}
