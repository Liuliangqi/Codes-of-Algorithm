    template<typename Item>
    void __shiftdown(Item arr[], int n; int i){
        while(2 * i + 1 < n){
            int j = 2 * i + 1;
            if(j + 1 < n && arr[j + 1] > arr[j]){
                j++;
            }
            if(arr[i] >= arr[j])
                break;
            swap(arr[i], arr[j]);
            i = j;
        }
    }
    //implace heap sort
    template<typename Item>
    void heapSort(Item arr[], int n){
        for(int i = (n - 1) / 2; i >= 0; i--){
            __shiftdown(arr, n, i);
        }
        //when there is only one node we do not need to compare, it is in the right place
        //so i > 0
        for(int i = n - 1; i > 0; i--){
            swap(arr[0], arr[i]);
            //everytime, there are only i nums need to sort
            __shiftdown(arr, i, 0);
        }
    }
