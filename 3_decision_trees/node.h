#include<memory>

using namespace std;

class Node {

  public:

    bool is_leaf;
    double value;
    int feature;
    double threshold;

    unique_ptr<Node> left;
    unique_ptr<Node> right;

    Node()
      : is_leaf(true),
        value(0.0),
        feature(-1),
        threshold(0.0),
        left(nullptr),
        right(nullptr) {
          
        }
};