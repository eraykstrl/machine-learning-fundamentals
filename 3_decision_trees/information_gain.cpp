#include "gini.h"
#include "entropy.h"
#include<vector>
#include<string>


using namespace std;

class InfomationGain {

  private:


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

      int method = 0;

      if(criterion == "gini") {
        method = 0;
      }
      else {
        method = 1;
      }

      int n = parent_labels.size();
      int left_n = left_labels.size();
      int right_n = right_labels.size();

      double parent_imp = 0.0;
      double left_imp = 0.0;
      double right_imp =0.0;

      if (left_n == 0 || right_n ==0) {
        return 0.0;
      }
      
      switch (method)
      {
      case 0:
        Gini gini;
        break;

      case 1:
        break;
      
      default:
        break;
      }
    }
};