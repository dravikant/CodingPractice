/*

heap structure properties 

1. element at parent node always greater/smaller than child nodes
    + there is no ordering among the child nodes

2. heap is always complete left filled 


kth largest/smallest element


brute force solution : sorting nlogn .. with k reduce it to nlogk


smallest -> max heap
largest -> min heap

https://www.youtube.com/watch?v=t0Cq6tVNRBA

 0  1  2  3  4  5  6
[7, 5, 3, 1, 2, 4, 6]
 
          7
       /     \
      5       3
    /   \   /   \
   1     2 4     6


node at index i
left child : 2i + 1
right child : 2i + 2

parent at : (i-1)/2




*/



#include<bits/stdc++.h>
using namespace std;

class Heap {

    private:
        vector<int> heap;

        // Helper function to maintain the heap property by swapping nodes
        //this is heapifydown i.e. we make sure everything from bottom till this index everything is in order
        void heapify(int idx) {

            // cout<<"heapify called for "<<heap[idx]<<endl;
            int left = 2 * idx + 1;

            int right = 2 * idx + 2;

            int largest = idx;

             if (left < heap.size() && heap[left] > heap[largest])
                largest = left;

            if (right < heap.size() && heap[right] > heap[largest])
                largest = right;

            if (largest != idx) {
                swap(heap[idx], heap[largest]);
                // called only when there is a swap and called with index of largest element which has parent element now after swap 
                heapify(largest);
            }
        }


    public:
        // constructor to create heap from a vector
        Heap(vector<int> vec){
            heap = vec;
            //last level is always a heap so start from first non leaf node
            for(int i= (heap.size())/2 -1; i>=0;i--){
                heapify(i);
            }

        }

        // Function to insert an element into the heap .. insert at end
        //this is heapifyup as we insert at bottom and move it up all the way to its correct position
        void insert(int x){
            heap.push_back(x);
            int idx = heap.size() -1;
            int parent = (idx -1)/2;

            while(idx > 0 && heap[parent] < heap[idx]){
                swap(heap[idx],heap[parent]);
                idx = parent;
                parent = (idx -1)/2;
            }
        }

        // Function to remove the root element from the heap
        void remove() {

            // cout <<"==============="<<endl;
            if (heap.empty()) {
                cout << "Heap is empty!" << endl;
                return;
            }

            swap(heap[0],heap[heap.size()-1]);
            heap.pop_back();
            heapify(0);
        }

        // Function to print the heap
        void print() {
            for (int i = 0; i < heap.size(); i++) {
                cout << heap[i] << " ";
            }
            cout << endl;
        }

};

// Test the Heap class
int main() {
    // vector<int> vec = {3, 2, 1, 5, 6, 4};
    vector<int> vec = {50,30,20,15,25,10,12};
    Heap h(vec);
    h.print(); // Output: 6 5 4 3 2 1
    // h.insert(10);
    // h.print(); // Output: 10 6 4 3 2 1 5
    // h.remove();
    // h.print(); // Output: 6 5 4 3 2 1
    h.remove();
    h.print(); // Output: 5 3 4 1 2
    return 0;
}


/*

Step 1: Add 3
   3

Step 2: Add 2
   3
  /
 2

Step 3: Add 1
   3
  / \
 2   1

Step 4: Add 5
   3
  / \
 2   1
/
5

Step 5: Add 6
   3
  / \
 2   1
/ \
5   6

Step 6: Add 4
   3
  / \
 2   1
/ \ /
5  6 4


heapify at 1 (index=  6/2 -1 = 2)

   4
  / \
 2   3
/ \ /
5  6 1

heapify at 2 (index =1)

   6
  /  \
 4    3
/ \  /
5  2|1


*/