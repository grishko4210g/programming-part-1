#ifndef LIB_H_
#define LIB_H_

double f11(double x, double y, double z, double w); // x + log(y+1) - √z * cos(w)
double f15(double x, double y, double z, double w); // x - √y * (exp(z) + sin(w))
double f20(double x, double y, double z, double w); // x + exp(y) * √z - sin(w)
double f5(double x, double y, double z, double w, double v); // x * sin(y) / cos(z) + w -√v

#endif // LIB_H_