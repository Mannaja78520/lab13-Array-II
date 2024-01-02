#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat (const double A[] ,int N, double B[]){
    double sum = 0, sumsqure = 0, multiGeometric = 1, sumHarmonic = 0, min = A[0], max = A[0];

    for (int i = 0; i < N; i++){
        sum += A[i];
        sumsqure += pow(A[i], 2);
        multiGeometric *= A[i];
        sumHarmonic += 1.0/A[i];
        max = max <= A[i] ? A[i] : max;
        min = min >= A[i] ? A[i] : min;
    }

    double mean = sum / N;
    double standardDeviation = sqrt((sumsqure / N) - pow(mean, 2));
    double geometricMean = pow(multiGeometric, 1.0 / N); 
    double HarmonicMean = N / sumHarmonic;

    B[0] = mean;
    B[1] = standardDeviation;
    B[2] = geometricMean;
    B[3] = HarmonicMean;
    B[4] = max;
    B[5] = min;
}