#include <iostream>
#include <math.h>
#include <tuple>

using namespace std;

double new_mean, new_var;

tuple<double, double> measurement_update(double mean1, double var1, double mean2, double var2)
{
    new_mean = (mean1 * var2 + mean2 * var1) / (var1 + var2);
    new_var =  var1 * var2 / (var1 + var2);
    return make_tuple(new_mean, new_var);
}

int main()
{

    tie(new_mean, new_var) = measurement_update(10, 8, 13, 2);  // [12.400000, 1.600000]
    printf("[%f, %f]", new_mean, new_var);
    return 0;
}
