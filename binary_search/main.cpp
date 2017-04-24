//created by Liangqi 

Using namespace std;

template<typename T>
/*
    search in a sorted array
    return the index of target
    return -1, if no result
*/
int binarySearch(T arr[], int n; T target){
    int left, right;
    // find target in [left, right]
    left = 0;
    right = n - 1;
    while(left <= right){
        //but here may occur some errors, I will provide another solution in the following codes
        int mid = (left + right) / 2;
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
