#include<vector>
#include<cmath>

using namespace std;

class Entropy {

  public:

    double compute_entropy(const vector<double> probs) {

      int n = probs.size();

      double sum = 0;
      for(int i=0;i<n;i++) {
        
        double log_p = log(probs[i]);
        sum+=log_p * probs[i];
      }

      return -(sum/n);
    }
  
};