//created by Liangqi 
using namespace std;

template<typename Item>
class IndexHeap{
private:
    Item* data;
    int* indexes;
    
    int count;
    int capacity;
    
    void shiftUp(int n){
        while(n > 1 && data[indexes[n]] > data[indexes[n / 2]]){
            swap(indexes[n], indexes[n/2]);
            n /= 2;
        }
    }
    
    void shiftDown(int n){
        while(2 * n <= count){
            int j = 2 * n;
            if(j + 1 <= count && data[indexes[j+1]] > data[indexes[j]]){
                j++;
            }
            
            if(data[indexes[n]] >= data[indexes[j]])
                break;
            swap(indexes[n], indexes[j]);
            n = j;
        }
    }
    
public:
    IndexHeap(int capacity){
        data = new Item[capacity + 1];
        indexes = new int[capacity + 1];
        
        count = 0;
        this->capacity = capacity;
    }
    
    
    ~IndexHeap(){
        delete [] data;
        delete [] indexes;
    }
    
    
    int size(){
        return count;
    }
    
    
    bool isEmpty(){
        return count == 0;
    }
    
    //for user, i start from 0
    void insert(int i, Item item){
        assert(count + 1 <= capacity);
        //for us, index start from 1
        assert(i + 1 >= 1 && i + 1 <= capacity);
        
        i += 1;
        //change item in position i
        data[i] = item;
        //but save this index into last position of indexHeap
        indexes[count + 1] = i; 
        count++;
        
        shiftUp(count);
    }
    
    Item extractMax(){
        assert(count > 0);
        Item item = data[indexes[1]];
        swap(indexes[1], indexes[count]);
        count--;
        shiftDown(1);
        return item;
    }
    
    int extractMaxIndex(){
        assert(count > 0);
        //for user, index start from 0
        int ret = indexes[1] - 1;
        swap(indexes[1], indexes[count]);
        count--;
        shiftDown(1);
        return ret;
    }
    
    Item getMax(){
        assert(count > 0);
        return data[indexes[1]];
    }
    
    int getMaxIndex(){
        assert(count > 0);
        return indeses[1] - 1;
    }
    
    Item getItem(int i){
        return data[indexes[i + 1]];
    }
    
    void change(int i, Item newItem){
        i += 1;
        data[i] = newItem;
        
        for(int j = 1; j < count; j++){
            if(indexes[j] == i){
                shiftUp(j);
                shiftDown(j);
                return;
            }
        }
    } 
};
