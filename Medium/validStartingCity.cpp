#include <vector>
using namespace std;

int validStartingCity(vector<int> distances, vector<int> fuel, int mpg) {
    int retVal = 0, fuelbfArrive = 0, minfuel = 0;
    for (int i = 0; i < distances.size(); ++i){
        fuelbfArrive += (fuel[i] * mpg);
        fuelbfArrive -= distances[i];
        if (fuelbfArrive < minfuel){
            retVal = i + 1;
            minfuel = fuelbfArrive;
        }
    }
    if (retVal == distances.size()){
        retVal = 0;
    }
    return retVal;
}
