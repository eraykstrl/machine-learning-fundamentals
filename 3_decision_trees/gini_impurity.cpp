#include<vector>
#include<cmath>

using namespace std;

class GiniImpurity {

  public:

    double compute_gini(const vector<double> probs) {
      
      int len = probs.size();

      if(len == 0) {
        return 0.0;
      }
      double sum = 0;

      for(int i =0;i<len;i++) {
        double square = pow(probs[i],2);
        sum+= square;
      }

      return 1-sum;

    }

};