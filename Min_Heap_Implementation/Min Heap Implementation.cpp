class minHeap{
public:
    // Constructor for the class.
    vector<int> minHeapVector;
    minHeap(int capacity) {
    }

    void heapify(int index) {
        int smallest = index;
        int left = 2 * smallest + 1;
        int right = 2* smallest + 2;

        if(left<minHeapVector.size() && minHeapVector[left]<minHeapVector[smallest]) {
            smallest = left;
        }
        if(right<minHeapVector.size() && minHeapVector[right]<minHeapVector[smallest]) {
            smallest = right;
        }
        if(smallest != index) {
            swap(minHeapVector[smallest], minHeapVector[index]);
            heapify(smallest);
        }
    }
    // Implement the function to remove minimum element.
    int extractMinElement() {
        // Write you code here.
        if(minHeapVector.size() == 0) return -1;
        int n = minHeapVector[0];
        swap(minHeapVector[0], minHeapVector[minHeapVector.size()-1]);
        minHeapVector.pop_back();
        heapify(0);
        return n;
    } 

    // Implement the function to delete an element.
    void deleteElement(int ind) {
        // Write you code here.
        if(ind >= minHeapVector.size()) return;
        swap(minHeapVector[ind], minHeapVector[minHeapVector.size()-1]);
        minHeapVector.pop_back();
        heapify(ind);
    }

    // Implement the function to insert 'val' in the heap.
    void insert(int val) {
        // Write you code here.
        minHeapVector.push_back(val);
        int index = minHeapVector.size()-1;
        while(index >= 0) {
            int parent = (index-1)/2;
            if(minHeapVector[parent]>minHeapVector[index]) {
                swap(minHeapVector[parent], minHeapVector[index]);
                index = parent;
            } else break;
        }
    }
};
