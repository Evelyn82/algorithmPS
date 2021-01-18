#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double x, y, c;
double solve(double n){
	double h1=sqrt(x*x-n*n);
	double h2=sqrt(y*y-n*n);
	
	return (h1*h2)/(h1+h2);
}
int main(){
	scanf("%lf %lf %lf", &x, &y, &c);
	
	double low=0, high=min(x,y);
	double ret=0;
	
	while(high-low>0.000001){
		double mid=(low+high)/2.0;
		if(solve(mid)>=c){
			ret=mid;
		    low=mid;
		}
		else high=mid;
	}	
	printf("%.3f\n", ret);
}
