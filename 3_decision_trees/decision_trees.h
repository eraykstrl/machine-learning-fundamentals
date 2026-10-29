#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class DecisionTrees {

  public:

    DecisionTrees(
      int max_depth = -1,
      int min_samples_split = 2,
      int min_samples_leaf = 1,
      string criterion = "gini",
      int max_features = 1
    );

    void fit(const vector<double>X,const vector<double> y) {
      int feature_number = X.size();

    }

    
  
  private:
    int max_depth;
    int min_samples_split;
    int min_samples_leaf;
    string criterion;
    int max_features;
    double feature_importances = 0.0;

  

};