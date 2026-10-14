#include<stdio.h>
#include<stdlib.h>

#define MAX_EPOCHS 1000

struct linear_regression
{
  double w;
  double b;
  double learning_rate;
  double cost_history[MAX_EPOCHS];
  int cost_count;
};

double predict(struct linear_regression *model,double x) {
  return model->w * x + model -> b;
}

double calculate_cost(struct linear_regression *model, double X[],double y[],double n) {
  
  double cost = 0.0;

  for(int i=0;i<n;i++) {

    double pred = predict(model,X[i]);
    double error = pred-y[i];

    cost += error * error;

  }

  return cost / n;

}

void calculate_gradients(
  struct linear_regression * model,
  double X[],
  double y[],
  double n,
  double *dw,
  double *db 
) {


  for(int i =0;i<n;i++) {
    double pred = predict(model,X[i]);
    double error = pred - y[i];

    *dw += error * X[i];
    *db += error;
  }

  *dw = (2.0 / n) * *dw;
  *db = (2.0/n) * *db;
}

void fit_model(
  struct linear_regression *model,
  double X[],
  double y[],
  int n,
  int epochs
) {

  model->cost_count=0.0;


  for(int i=0;i<epochs;i++) {

    double dw, db;
    calculate_gradients(model,X,y,n,&dw,&db);
    
    model->w -= model->learning_rate * dw;
    model->b -= model->learning_rate * db;

    double cost = calculate_cost(
      model,
      X,
      y,
      n
    );

    if(model->cost_count < 1000) {
      model->cost_history[model->cost_count] = cost;
      model->cost_count++;
    }

    if(i % 5 == 0) {
      printf(
    "Epoch %4d | Cost %.4f | w %.4f | b %.4f\n",
    i,
    cost,
    model->w,
    model->b);
    }
  }
}



int main(void) {

  int n_samples = 100;
  double true_weight_value = 9.0;
  double true_bias_value = 8.0;

  srand(42);

  double X[n_samples];
  double y[n_samples];


  for(int i=0;i<n_samples;i++) {
    X[i] = ((double)rand() / RAND_MAX) * 10.0;
  }

  for(int i=0;i<n_samples;i++) {
    y[i] = true_weight_value  * X[i] + true_bias_value;
  }

  struct linear_regression model = {
    .w = 0.0,
    .b = 0.0,
    .learning_rate = 0.001,
    .cost_count = 0
  };

  fit_model(
    &model,
    X,
    y,
    n_samples,
    10000
  );

  return 0;
}