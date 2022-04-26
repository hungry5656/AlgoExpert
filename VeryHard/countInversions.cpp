#include <vector>
using namespace std;

vector<int> MergeAndCount(vector<int> A, vector<int> B, int* NumInv){
    /*
    ** This function Merge the vector and count the number of inversion
    */

    vector<int> List;
    int iMax = A.size(), jMax = B.size();
    int i = 0, j = 0;
    while(!(i == iMax && j == jMax)){
        if (i == iMax){
            List.push_back(B[j]);
            ++j;
        } else if (j == jMax){
            List.push_back(A[i]);
            ++i;
        } else {
            if (A[i] <= B[j]){
                List.push_back(A[i]);
                ++i;
            } else {
                List.push_back(B[j]);
                ++j;
                *NumInv = *NumInv + iMax - i;
            }
        }
    }
    return List;
}

vector<int> SortAndCount(vector<int> List, int* NumInv){
    if (List.size() == 1){
        return List;
    }
    int currSize = List.size();
    int HalfIndex = currSize / 2;

    vector<int> A(List.begin(), List.begin() + HalfIndex);
    vector<int> B(List.begin() + HalfIndex, List.end());
    A = SortAndCount(A, NumInv);
    B = SortAndCount(B, NumInv);
    List = MergeAndCount(A, B, NumInv);
    return List;
}

int countInversions(vector<int> array) {
    if (array.size() == 0) return 0;
    int retVal = 0;
    array = SortAndCount(array, &retVal);
    return retVal;
}
