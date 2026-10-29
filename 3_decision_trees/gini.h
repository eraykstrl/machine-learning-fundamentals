#ifndef GINI_H
#define GINI_H

#include<vector>

class Gini{
  public:
    double compute_gini(const std::vector<double> probs);
};

#endif