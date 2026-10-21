#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

#define MAX_EPOCHS 100000

using namespace std;

class LogisticRegression {

  private:
    double weight = 0;
    double bias = 0;
    double learning_rate = 0.01;
    double cost_history[MAX_EPOCHS] = {};
    int cost_count = 0;
  
  public:

    double predict(double X) {
      double z = this->weight * X + this->bias;
      return compute_sigmoid(z);
    }

    // sigmoid 
    double compute_sigmoid(double X) {
      double sigmoid = (1) / (1+exp(-X));
      return sigmoid;
    }

    // binary cross entropy function
    double compute_binary_crossentropy(double y_true,double y_pred) {

      const double eps = 1e-15;
      y_pred= max(eps,min(1.0-eps,y_pred));
      
      return -(y_true * log(y_pred)
           + (1.0 - y_true) * log(1.0 - y_pred));
    }
    
    // binary cross entropy is cost function of logistic regression
    double calculate_cost(
      double X[],
      double y[],
      int n
    ) {

      double total_cost = 0.0;
      for(int i =0;i<n;i++) {
        double pred = predict(X[i]);
        total_cost += compute_binary_crossentropy(y[i],pred);
      }
      return total_cost / n;
    }

    void calculate_gradient(
      double X[],
      double y[],
      int n,
      double *dw,
      double *db
    ) {


      for(int i=0;i<n;i++) {
        double pred = predict(X[i]);
        double error = pred - y[i];
        
        *dw += error * X[i];
        *db += error;
      }

      *dw /= n;
      *db /=n;
    }

    vector<double> fit(
      int n,
      double X[],
      double y[],
      int epoch_number
    ) {

      for(int i = 0;i<epoch_number;i++) {
        double dw = 0.0;
        double db = 0.0;

        calculate_gradient(X,y,n,&dw,&db);

        this->weight = this->weight - this->learning_rate * dw;
        this->bias = this->bias - this->learning_rate * db;

        double cost = calculate_cost(X,y,n);
    
        if(cost_count < 100000) {
          cost_history[cost_count] = cost;
          cost_count++;
        }

        if (i == epoch_number - 1) {
          cout << "Epoch " << i + 1
          << " | Cost " << cost
          << " | w " << this->weight
          << " | b " << this->bias
          << endl;
        }
      }

      vector<double> preds;

      for(int i =0;i<n;i++) {
        preds.push_back(predict(X[i]));
      }

      return preds;
    }

};


int main(void) {

  LogisticRegression model = LogisticRegression();

  double X[] = {1, 2, 3, 4, 5, 6, 7, 8};
  double y[] = {0, 0, 0, 0, 1, 1, 1, 1};
  int n = sizeof(X) / sizeof(X[0]);
  int epoch_number = 10000;

  vector<double> preds = model.fit(n, X, y, epoch_number);

  for (double pred : preds) {
    cout << "pred rate is "<< pred << endl;
    int pred_class = pred >=0.5 ? 1:0;
    cout << "pred class is "<<pred_class<<endl;
  }

  return 0;
}