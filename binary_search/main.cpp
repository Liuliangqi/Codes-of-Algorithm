//created by Liangqi 

Using namespace std;

/*
    search in a sorted array
    return the index of target
    return -1, if no result
*/
template<typename T>
int binarySearch(T arr[], int n, T target){
    int left, right;
    // find target in [left, right]
    left = 0;
    right = n - 1;
    while(left <= right){
        //but here may occur some errors
//         int mid = (left + right) / 2;
        int mid = left + (right - left) / 2;
        if(arr[mid] == target){
            return mid;
        }else if(target < arr[mid]){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    // if cannot find
    return -1;
}

//recursion version
template<typename T>
int binarySearchRec(T arr[], int n, T target){
    return getResult(arr, 0, n - 1, target);
}

template<typename T>
int getResult(T arr[], int start, int end, T target){
    if(start > end)
        return -1;
    int mid = start + (end - start) / 2;
    if(arr[mid] == target){
        return mid;
    }else if(target < arr[mid]){
        return getResult(arr, 0, mid - 1, target);
    }else{
        return getResult(arr, mid + 1, end, target);
    }
}
