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
}
