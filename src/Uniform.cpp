#include "../include/StatisticalDistributionsLib/Uniform.h"

namespace StatisticalDistributions {


  Uniform::Uniform(long double min, long double max)
    : dist(min, max), cdist(min, max) {}
  long double Uniform::pdf(long double value) const {
    return(boost::math::pdf(cdist, value));
  }
  long double Uniform::cdf(long double value) const {
    return(boost::math::cdf(cdist, value));
  }
  long double Uniform::Inverse(long double value) const {
    return(boost::math::quantile(cdist, value));
  }
  long double Uniform::operator()(std::mt19937_64 &g) const {
    return(this->dist(g));
  }
}
