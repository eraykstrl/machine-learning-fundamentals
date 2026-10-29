#include "gini.h"
#include "entropy.h"
#include<vector>
#include<string>


using namespace std;

class InfomationGain {

  private:


  public:

    double information_gain(
      const vector<double> left_labels,
      const vector <double> parent_labels,
      const vector <double>right_labels,
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

      double child_imp = 0.0;
      
      switch (method)
      {
      case 0:
        Gini gini;
        parent_imp = gini.compute_gini(parent_labels);
        left_imp = gini.compute_gini(left_labels);
        right_imp = gini.compute_gini(right_labels);
        child_imp = (left_n / n) * left_imp;
        child_imp += (right_n / n) * right_imp;
        break;

      case 1:
        Entropy entropy;
        parent_imp = entropy.compute_entropy(parent_labels);
        left_imp = entropy.compute_entropy(left_labels);
        right_imp = entropy.compute_entropy(right_labels);
        child_imp = (left_n / n) * left_imp;
        child_imp += (right_n / n) * right_imp;
        break;
      
      default:
        parent_imp = gini.compute_gini(parent_labels);
        left_imp = gini.compute_gini(left_labels);
        right_imp = gini.compute_gini(right_labels);
        child_imp = (left_n / n) * left_imp;
        child_imp += (right_n / n) * right_imp;
        break;
      }
    }
};