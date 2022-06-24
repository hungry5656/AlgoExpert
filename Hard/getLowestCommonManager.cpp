#include <vector>
using namespace std;

class OrgChart {
public:
    char name;
    vector<OrgChart *> directReports;

    OrgChart(char name) {
        this->name = name;
        this->directReports = {};
    }

    void addDirectReports(vector<OrgChart *> directReports);
};

OrgChart *getLowestCommonManager(OrgChart *topManager, OrgChart *reportOne,
                                 OrgChart *reportTwo) {
    // recursive find through children, if One found, mark that
    // If both children returns non nullptr, it means that topManager right now is the lowest common ancestor
    if (topManager == reportOne || topManager == reportTwo){
        return topManager;
    }
    OrgChart *ptr1 = nullptr;
    for (int i = 0; i < topManager -> directReports.size(); ++i){
        OrgChart *currPtr = getLowestCommonManager(topManager->directReports[i], reportOne, reportTwo);
        if (currPtr != nullptr){
            if (ptr1 == nullptr){
                ptr1 = currPtr;
            } else {
                return topManager;
            }
        }
    }
    if (ptr1 != nullptr){
        return ptr1;
    }
    return nullptr;
}
