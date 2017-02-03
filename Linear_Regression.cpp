#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
double cost0(double theta0,double theta1, vector<double> X, vector<double> Y)
{
   double Cost = 0;
   for(int i=0;i<X.size();i++)
   {
       Cost = Cost + ((theta0+theta1*X[i])-Y[i]);
   }
    int Size = X.size();
    Cost = Cost*(1.00/(Size));
    return Cost;
}
double cost1(double theta0,double theta1, vector<double> X, vector<double> Y)
{
   double Cost = 0;
   for(int i=0;i<X.size();i++)
   {
       Cost = Cost + ((theta0+theta1*X[i])-Y[i])*X[i];
   }
    int Size = X.size();
    Cost = Cost*(1.00/(Size));
    return Cost;
}


void grad_decent(double& theta0,double& theta1, vector<double> X, vector<double> Y)
{
    double Learning_Rate = 0.01;
    double Zero,Previous_Zero=1;
    double One,Previous_One=1;
    int Iteration = 0;
    while(abs(Previous_Zero-theta0)>0.0 || abs(Previous_One-theta1)>0.0)
    {
        Previous_Zero = theta0;
        Previous_One = theta1;
        Zero = theta0 - Learning_Rate*cost0(theta0,theta1,X,Y);
        One = theta1 - Learning_Rate*cost1(theta0,theta1,X,Y);
        theta0 = Zero;
        theta1 = One;
        Iteration += 1;
    }
    cout << "Iterations: " << Iteration << endl;
}

int main()
{
    vector<double> x;
    vector<double> y;
    x = {1.17,2.97,3.26,4.69,5.83,6.00,6.41};
    y = {78.93,58.2,67.47,37.47,45.65,32.92,29.97};
    double Constant = 0.0;
    double Variable = 0.0;
    grad_decent(Constant,Variable,x,y);
    cout << "y = " << Variable << "x+" << Constant << endl;
    return 0;
}
