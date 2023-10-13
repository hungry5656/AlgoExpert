#include <vector>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
    public:
        vector<int> heap;

        MinHeap(vector<int> vector) { heap = buildHeap(vector); }

        vector<int> buildHeap(vector<int>& vector) {
            // Write your code here.
            return {};
        }

        void siftDown(int currentIdx, int endIdx, vector<int>& heap) {
            // Write your code here.
        }

        void siftUp(int currentIdx, vector<int>& heap) {
            // Write your code here.
        }

        int peek() {
            // Write your code here.
            return -1;
        }

        int remove() {
            // Write your code here.
            return -1;
        }

        void insert(int value) {
            // Write your code here.
        }
};
