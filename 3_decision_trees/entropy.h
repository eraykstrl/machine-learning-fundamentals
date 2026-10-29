#ifndef ENTROPY_H
#define ENTROPY_H

#include<vector>

class Entropy {
  
  public:
    double compute_entropy(const std::vector<double> probs);
};

#endif