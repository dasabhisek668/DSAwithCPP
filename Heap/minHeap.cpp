#include <iostream>
#include <limits>
using namespace std;

class BinaryHeap {

    public:
    //to store the capacity of the heap
    int capacity;

    // Current no of elements in heap
    int size;

    //Array for storing elements
    int *arr;

    BinaryHeap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    ~BinaryHeap() {
        delete []arr;
    }

    //return the parent of the ith node 
    int parent(int i) {
        return (i-1)/2;
    }

    //return the left child of the ith node
    int left(int i) {
        return (2*i)+1;
    }

    //return the right child of the ith node
    int right(int i ) {
        return (2*i)+2;
    }


    void insert(int x) {
        if(size == capacity) {
            cout << "Binary heap overflow!" << endl;
            return;
        }

        // insert new element at the end 
        arr[size] = x;

        int k = size;

        size++; //increase the size

        //fix the heap property
        while(k != 0 && arr[parent(k)] > arr[k]) {
            swap(&arr[parent(k)] , &arr[k]);
            k = parent(k);
        }
    }

    void heapify(int idx) {

        //right child
        int ri = right(idx);

        //left child
        int li = left(idx);

        int smallest = idx; //assume the small index as parent

        if(li < size && arr[smallest] > arr[li] ) smallest = li; //if left child is smallest
        if(ri < size && arr[smallest] > arr[ri]) smallest = ri; //if right child is smallest
        
        //if smallest index found
        if(smallest != idx) { 
            swap(&arr[smallest] , &arr[idx]);
            heapify(smallest);
        }


        

    }

    int getMin() {
        return size > 0 ?  arr[0] : numeric_limits<int>::max();
    }

    int extractMin() {

        if(size <= 0) {
            return numeric_limits<int>::max();
        }

        if(size == 1) {
            size--;
            return arr[0];
        }

        //copy the last node value to the root node 
        int mini = arr[0];
        arr[0] = arr[size-1];

        //decrease size 
        size--;

        heapify(0);

        return mini;

    }

    void decreaseKey(int i , int val) {
        arr[i] = val;

        while(i != 0 && arr[parent(i)] > arr[i]) {
            swap(&arr[parent(i)] , &arr[i]);
            i = parent(i);
        }
    }

    void Delete(int i) {
        decreaseKey(i , INT_MIN);
        extractMin();
    }

    void swap(int* x, int* y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main(){
    
    BinaryHeap h(20);
    h.insert(4);
    h.insert(1);
    h.insert(2);
    h.insert(6);
    h.insert(7);
    h.insert(3);
    h.insert(8);
    h.insert(5);

    cout << "Min value is " << h.getMin() << endl;

    h.insert(-1);
    cout << "Min value is " << h.getMin() << endl;

    h.decreaseKey(3, -2);
    cout << "Min value is " << h.getMin() << endl;

    h.extractMin();
    cout << "Min value is " << h.getMin() << endl;

    h.Delete(0);
    cout << "Min value is " << h.getMin() << endl;

    
    return 0;
}