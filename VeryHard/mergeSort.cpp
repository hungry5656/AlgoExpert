#include <vector>
using namespace std;

vector<int> Merge(vector<int> A, vector<int> B){
    /*
    ** This function Merge the vector and count the number of inversion
    */

    vector<int> array;
    int iMax = A.size(), jMax = B.size();
    int i = 0, j = 0;
    while(!(i == iMax && j == jMax)){
        if (i == iMax){
            array.push_back(B[j]);
            ++j;
        } else if (j == jMax){
            array.push_back(A[i]);
            ++i;
        } else {
            if (A[i] < B[j]){
                array.push_back(A[i]);
                ++i;
            } else {
                array.push_back(B[j]);
                ++j;
            }
        }
    }
    return array;
}

vector<int> mergeSort(vector<int> array){
    if (array.size() == 1){
        return array;
    }
    int currSize = array.size();
    int HalfIndex = currSize / 2;

    vector<int> A(array.begin(), array.begin() + HalfIndex);
    vector<int> B(array.begin() + HalfIndex, array.end());
    A = mergeSort(A);
    B = mergeSort(B);
    array = Merge(A, B);
    return array;
}
