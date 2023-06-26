#include <iostream>
#include <math.h>
#include <tuple>
#include "Core" // Eigen Library
#include "LU"   // Eigen Library

using namespace std;
using namespace Eigen;

float measurements[3] = { 1, 2, 3 };

tuple<MatrixXf, MatrixXf> kalman_filter(MatrixXf x, MatrixXf P, MatrixXf u, MatrixXf F, MatrixXf H, MatrixXf R, MatrixXf I)
{
    for (int n = 0; n < sizeof(measurements) / sizeof(measurements[0]); n ++) {
        //****** TODO: Kalman-filter function********//
        
        // Measurement Update
        // Initialize and Compute Z, y, S, K, x, and P

        // Z - observation (comes from measurements)
        // z = [1 0][x x_dot].transpose()

        // y - measurement residual
        // y = z - H x_prime
        
        // S - result of mapping the state prediction covariance (P_prime) 
        // into the measurement space (H) and adds the measurement noise (R)
        // S = H P_prime H.transpose() + R
        
        // K - Kalman gain coefficient (measurement or state predition)
        // K = P_prime H.transpose() S.inverse()
        
        
        
        
        
        
        
        // State Prediction
        // Compute x and P (updated every iteration)

        // x - posterior state
        // x = x_prime + K y
        
        // P - (posterior) covariance
        // P = (I - K H) P_prime

        
        
    }

    return make_tuple(x, P);
}

int main()
{

    MatrixXf x(2, 1);// Initial state (location and velocity) 
    x << 0,
    	 0; 
    MatrixXf P(2, 2);//Initial Uncertainty
    P << 100, 0, 
    	 0, 100; 
    MatrixXf u(2, 1);// External Motion
    u << 0,
    	 0; 
    MatrixXf F(2, 2);//Next State Function
    F << 1, 1,
    	 0, 1; 
    MatrixXf H(1, 2);//Measurement Function
    H << 1,
    	 0; 
    MatrixXf R(1, 1); //Measurement Uncertainty
    R << 1;
    MatrixXf I(2, 2);// Identity Matrix
    I << 1, 0,
    	 0, 1; 

    tie(x, P) = kalman_filter(x, P, u, F, H, R, I);
    cout << "x = " << x << endl;
    cout << "P = " << P << endl;

    return 0;
}
