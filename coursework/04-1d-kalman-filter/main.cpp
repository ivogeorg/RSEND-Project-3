#include <iostream>
#include <math.h>
#include <tuple>

using namespace std;

double new_mean, new_var;

tuple<double, double> measurement_update(double mean1, double var1, double mean2, double var2)
{
    new_mean = (var2 * mean1 + var1 * mean2) / (var1 + var2);
    new_var = 1 / (1 / var1 + 1 / var2);
    return make_tuple(new_mean, new_var);
}

tuple<double, double> state_prediction(double mean1, double var1, double mean2, double var2)
{
    new_mean = mean1 + mean2;
    new_var = var1 + var2;
    return make_tuple(new_mean, new_var);
}

int main()
{
    //Measurements and measurement variance
    double measurements[5] = { 5, 6, 7, 9, 10 };
    double measurement_sig = 4;
    
    //Motions and motion variance
    double motion[5] = { 1, 1, 2, 1, 1 };
    double motion_sig = 2;
    
    //Initial state
    double mu = 5;
    double sig = 500;
    
    //######TODO: Put your code here below this line######//
    
    // Loop through all the measurments
    int iteration_count = sizeof(measurements) / sizeof(double);
    for (int i = 0; i < iteration_count; i ++) {
        // Apply a measurment update
        tie(mu, sig) = measurement_update(mu, sig, measurements[i], measurement_sig);        
        printf("update:  [%f, %f]\n", mu, sig);
        // Apply a state prediction
        tie(mu, sig) = state_prediction(mu, sig, motion[i], motion_sig);
        printf("predict: [%f, %f]\n", mu, sig);
    }
    
    
    return 0;
}

/*
update: [5.000000, 3.968254] predict: [6.000000, 5.968254] 
update: [6.000000, 2.394904] predict: [7.000000, 4.394904] 
update: [7.000000, 2.094082] predict: [9.000000, 4.094082] 
update: [9.000000, 2.023247] predict: [10.000000, 4.023247] 
update: [10.000000, 2.005795] predict: [11.000000, 4.005795]
*/
