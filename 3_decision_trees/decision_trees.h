#ifndef DECISION_TREE.H
#define DECISION_TREE.H

#include<string>
#include<vector>
#include<unordered_map>
#include "node.h"

using namespace std;

struct SplitData {
    vector<vector<double>> left_X;
    vector<double> left_y;

    vector<vector<double>> right_X;
    vector<double> right_y;
};


class DecisionTrees {

  public:

    DecisionTrees(
      int max_depth = -1,
      int min_samples_split = 2,
      int min_samples_leaf = 1,
      string criterion = "gini",
      int max_features = 1
    );

    void fit(const vector<vector<double>>&X,const vector<double>& y);

    unique_ptr<Node> build_tree(const vector<vector<double>>&X ,const vector<double> &y,int depth);
    
    double predict(const vector<vector<double>>& X);

    double predict_one(const vector<double> &X,const Node & node);

    Node make_leaf(const vector<double>&y);

    void best_split(const vector<double>& X,const vector<double> &y);

    SplitData split_data(
    const vector<vector<double>>& X,
    const vector<double>& y,
    int feature,
    double threshold
);
  
  private:
    int max_depth;
    int min_samples_split;
    int min_samples_leaf;
    string criterion;
    int max_features;

    int n_features = 0;
    int n_samples = 0;
    vector<double> feature_importances;
    unique_ptr<Node> root;

};

#endif