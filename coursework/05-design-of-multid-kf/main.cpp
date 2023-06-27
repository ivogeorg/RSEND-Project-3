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
        
        // I. *************** Measurement Update ***************
        
        // NOTE: 
        // 1. Primes are updaated state x and covariance P (aka uncertainty). 
        // 2. No explicit primes are used in the equations.
        // 3. Each loop is an update of both x and P.
        // 4. A (1, 2) and a (2, 1) matrix are initialized the same way in code.
        // 5. z = H * X, where H = [1 0], a (1, 2), and X = [x x_dot].transpose().
        // 6. z is then (1, 1). See below.
        
        // TODO:
        // 1. Examine the input matrices' dimensions for a clue for the dimensions of the local matrices.
        // 2. Consider (1, 1) matrices, especially for z, which is a degenerate (1, 1) matrix.
        // 3. Then, z << measurements[n] makes sense.
        
        // Measurement Update
        // Initialize and Compute Z, y, S, K, x, and P

        // Z - observation (comes from measurements)
        // H = [1 0] - measurement function
        // [x x_dot].transpose() - state (here position and velocity)
        // z = [1 0][x x_dot].transpose()
        MatrixXf Z(1, 1);
        Z << measurements[n];  // Degenerate matrix is initialized with a single number

        // y - measurement residual
        // y = z - H x_prime
        MatrixXf y(1, 1);  // Necessarily (1, 1) by the formula
        y << Z - (H * x);  // TODO: Are the parentheses needed?
        
        // S - result of mapping the state prediction covariance (P_prime) 
        // into the measurement space (H) and adds the measurement noise (R)
        // S = H P_prime H.transpose() + R
        MatrixXf S(1, 1);  // Necessarily (1, 1) by the formula
        S << H * P * H.transpose() + R;
        
        // K - Kalman gain coefficient (measurement or state predition)
        // The Kalman Gain determines how much weight should be placed on the 
        // state prediction, and how much on the measurement update. It is an 
        // averaging factor that changes depending on the uncertainty of the 
        // state prediction and measurement update.
        // K = P_prime H.transpose() S.inverse()
        MatrixXf K(2, 1);  // Necessarily (2, 1) by formula
        // TODO: Justify by K's role
        K << P * H.transpose() * S.inverse();
        

        // Compute posterior x and P (updated every iteration)

        // x - posterior state
        // x = x_prime + K y
        x << x + (K * y); 
        
        // P - posterior covariance
        // P = (I - K H) P_prime
        P << (I - (K * H)) * P;

        // II. *************** State Prediction ***************
        // x_prime = F * x
        x << F * x;
        
        // P_prime = F * P * F.transpose()
        P << F * P * F.transpose();
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
