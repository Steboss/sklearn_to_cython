#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#include <time.h>


//the first hurdle is ot implmenet the identiy
//what can we do about identity/ what is X?
//we could start implmeneting a function, which required theX_rows and X_cols
//
//let's start implmeneting identity as a function
double** identity(double** X, int n_samples, int n_features){
  //This function implements the identity, namely it returns the tensor X
  // n_samples coincides with the number of rows while n_features with the number of
  //columns of X
  return X;
}


double ** logistic_sigmoid(double **X, int n_samples, int n_features){
  //THe logistic sigmoid aka expit is defined as:
  // expit(x) = 1/(1+ exp(-x) )
  //for each element of X return the expit(x_i)

  /*double** logistic_X ;
  logistic_X = (double**)malloc(n_samples*sizeof(double*));
  for (int i=0; i<n_samples;i++){
    logistic_X[i] = (double*)malloc(n_features*sizeof(double));
  }*/


  for(int i=0; i<n_samples;i++){
    for(int j=0;j<n_features;j++){
      //logistic_X[i][j] = 1.0/(1 + exp(-X[i][j]));
      X[i][j] = 1.0/(1+exp(-X[i][j]));
    }
  }
  return X;//logistic_X;
}


double ** tanh(double** X, int n_samples, int n_features){
  //return the tanh of X
  for(int i=0; i<n_samples;i++){
    for(int j=0;j<n_features;j++){
      X[i][j] = tanh(X[i][j]);
    }
  }
  return X;
}

double **relu(double**X, int n_samples, int n_features){
  //rectified linear unit
  //if < 0 == 0 else value
  for (int i =0; i<n_samples; i++){
    for (int j=0;j<n_features; j++){
      if(X[i[j]<0.0){
        X[i][j]=0;
      }
    }
  }
  return X;
}

double** softmax(double** X, int n_samples, int n_features){
  //softmax
  //find the max for each row
  double m=-999999999
  //make a matrix with the max
  double **maxmat;
  maxmat =(double**) malloc(n_samples*sizeof(double));
  for (int i=0; i<n_samples;i++){
    maxmat[i] = (double*)malloc(1*sizeof(double));
  }
  //n_samples * 1 column
  for (int i=0;i<n_samples;i++){
    for (int j=0;j<n_features;j++){
      if (X[i][j]>m){
        m=X[i][j];
      }
    //store the element ?
    //maxmat[i][0]=m ;
    //m=-999999999;
    }
    
  }


float sum = 0.0;
for (size_t i = 0; i < input_len; i++) {
  sum += expf(input[i] - m);
}

float offset = m + logf(sum);
for (size_t i = 0; i < input_len; i++) {
  input[i] = expf(input[i] - offset);
}
}
}
