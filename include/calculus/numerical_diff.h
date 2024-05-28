#ifndef FIN_DIFF_H
#define FIN_DIFF_H

#include <functional>
#include "linalg/vector.h"

namespace calculus {


double central_diff(std::function<double(double)> f, double a, double h = 0.001);

double first_order_upwind(std::function<double(double)> f, double a,double h = 0.001);


}

#endif