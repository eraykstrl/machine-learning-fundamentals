#include "decision_trees.h"
#include<vector>
#include "node.h"

using namespace std;

unique_ptr<Node> DecisionTrees::build_tree(const vector<vector<double>>& X,const vector<double> &y,int depth) {


}

SplitData DecisionTrees::split_data(const vector<vector<double>> &X,const vector<double> &y,int feature,double threshold) {

  SplitData result;

  int len_x = X.size();

  for(int i=0;i<len_x;i++) {
    if(X[i][feature]<=threshold) {
      result.left_X.push_back(X[i]);
      result.left_y.push_back(y[i]);
    }
    else {
      result.right_X.push_back(X[i]);
      result.right_y.push_back(y[i]);
    }
  }

  return result;
}

double DecisionTrees::predict_one(
    const vector<double>& X,
    const Node& node
) {

  if(node.is_leaf) {
    return node.value;
  }

  if(X[node.feature] <= node.threshold) {
    return predict_one(X,*node.left);
  }

  return predict_one(X,*node.right);

}