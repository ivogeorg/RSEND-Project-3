#include <iostream>
#include <vector>

using namespace std;

vector<double> w = { 0.6, 1.2, 2.4, 0.6, 1.2 };//You can also change this to a vector

//TODO: Define a  ComputeProb function and compute the Probabilities
vector<double> ComputeProb(vector<double> weights) {
    double norm = 0.0;
    for (int i = 0; i < weights.size(); i ++) norm += weights[i];
    
    vector<double> prob(weights.size());
    for (int i = 0; i < weights.size(); i ++) prob[i] = weights[i] / norm;
    
    return prob;
}






int main()
{
    //TODO: Print Probabilites each on a single line:
    //P1=Value
    //:
    //P5=Value
    vector<double> prob = ComputeProb(w);
    for (int i = 0; i < prob.size(); i ++)
        cout << "P" << i + 1 << "=" << prob[i] << endl;
    
    
    
    
    
    
    return 0;
}

