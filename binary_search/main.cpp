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

// return first index of target
// if no target, return the first index lt target
template<typename T>
int floor(T arr[], int n, T target){
    assert(n >= 0);
    // start should from -1, because index of target could be 0
    int left = -1;
    int right = n - 1;
    while(left < right){
        mid = left + (right - left + 1) / 2;
        if(target <= arr[mid]){
            right = mid - 1;
        }else
            left = mid;
    }    
    assert(left == right);    
    if(left + 1 < n && arr[left + 1] == target){
        return left + 1;
    }
    // if no target
    return left;
}

template<typename T>
int ceil(T arr[], int n, T target){
    assert( n >= 0 );
    // end should be n, because index of target could be n - 1
    int left = 0, right = n;    
    while( left < right ){
        int mid = left + (right - left)/2;
        if( arr[mid] <= target )
            left = mid + 1;
        else // arr[mid] > target
            right = mid;
    }
    assert( left == right );
    if( right - 1 >= 0 && arr[right - 1] == target )
        return right -1;

    // if no result
    return right;
}
