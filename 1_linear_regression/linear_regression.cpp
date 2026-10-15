#include<iostream>

#define MAX_EPOCHS 1000
using namespace std;



class LinearRegression {

  // a linear function is like y = w * x + b

  private:
    double weight = 0; // w
    double bias = 0; // b
    double learning_rate = 0.01; // learning rate 
    double cost_history[MAX_EPOCHS] = {}; 
    int cost_count = 0;

  public:
    // cost function computes mse 
    double calculate_cost(
      int n,
      double X[],
      double y[]
    ) {

      double cost=0.0;
      
      for(int i=0;i<n;i++) {
        double pred = predict(X[i]);
        double error = pred - y[i];
        
        cost += error * error;
      }
      return cost / n;
    }

    double predict(double X) {

      return weight * X + bias;
    }

    void fit(
        double X[],
        double y[],
        int n,
        int epoch_number

    ) {

      for(int i=0;i<epoch_number;i++) {
        double dw = 0.0;
        double db = 0.0;

        calculate_gradients(X, y, n, &dw, &db);

        weight = weight - learning_rate * dw;
        bias = bias - learning_rate * db;

        double cost = calculate_cost(n,X,y);

        if(cost_count<1000) {
          cost_history[cost_count] = cost;
          cost_count++;
        }

        if(i == 999) {
          cout << "Epoch " << i + 1
         << " | Cost " << cost
         << " | w " << weight
         << " | b " << bias
         << endl;
        }
      }

    }

    void calculate_gradients(
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

      *dw = (2.0 / n) * *dw;
      *db = (2.0/n) * *db;
    }

};

int main(void) {

  LinearRegression model = LinearRegression();

  double X_array[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  double y_array[] = {3.0, 5.0, 7.0, 9.0, 11.0}; 
  int n = 5; 
  int epoch_number = 1000; 
  model.fit(X_array, y_array, n, epoch_number);

}