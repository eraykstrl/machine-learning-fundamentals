#include<vector>
#include<string>

using namespace std;

class InfomationGain {

  public:

    double information_gain(
      const vector<int> left_labels,
      const vector <int> parent_labels,
      const vector <int>right_labels,
      string criterion
    ) {
      if(criterion.empty()) {
        criterion = "gini";
      }
    }

};