#include "lib.h"
#include <math.h>

double f11(double x, double y, double z, double w)
{
    if ( z < 0.0 || y <= -1.0 ) {
        return NAN;
    }
    return x + log(y+1.0) - sqrt(z) * cos(w);
}

// func.15 x - √y * (exp(z) + sin(w))

double f15(double x, double y, double z, double w)
{
    if ( y < 0.0 ) {
        return NAN;
    }
    return x - sqrt(y) * (exp(z) + sin(w));

}

// funct.20 x  +exp(y) * √z - sin(w)

double f20(double x, double y, double z, double w)
{
    if( z < 0.0 ) {
        return NAN;
    }
    return x + exp(y) * sqrt(z) - sin(w);
}

// func.5 x * sin(y) / cos(z) + w -√v
double f5(double x, double y, double z, double w, double v)
{
    if (v < 0.0 || cos(z) == 0.0) {
        return NAN;
    }
    return x * sin(y) / cos(z) + w - sqrt(v);
}
