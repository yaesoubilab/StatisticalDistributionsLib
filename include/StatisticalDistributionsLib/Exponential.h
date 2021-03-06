#pragma once
#include "StatisticalDistribution.h"
#include <boost/math/distributions/exponential.hpp>

namespace StatisticalDistributions {
  class Exponential : public StatisticalDistribution<long double> {
  public:
    // Proportional to e^-(rate * x), but 0 if x < shift.
    Exponential(long double rate, long double shift = 0) {
      init(rate, shift);
    }
    void init(long double, long double = 0);
    virtual long double pdf(long double value) const;
    virtual long double cdf(long double value) const;
    virtual long double Inverse(long double value) const;
    virtual long double operator()(std::mt19937_64 &g) const;
    ACCESSOR(cdist, pcdist);
    ACCESSORC(shift, pshift);
  private:
    boost::math::exponential_distribution<long double> pcdist;
    long double pshift;
    mutable std::exponential_distribution<long double> dist;
  };
}
