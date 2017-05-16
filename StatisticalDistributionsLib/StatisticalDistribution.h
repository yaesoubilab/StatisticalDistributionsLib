#pragma once
#include "RNG.h"
#include <cmath>
#include <random>

namespace StatisticalDistributions {

  template<typename distype> class StatisticalDistribution {
  public:
    StatisticalDistribution() {};
    virtual long double pdf(distype value) = 0;
    virtual long double cdf(distype value) = 0;
    virtual long double Inverse(distype value) = 0;
    long double Sample(RNG &rng) {
      return(this->operator()(rng.mt_));
    }
    virtual distype operator()(std::mt19937_64 &g) = 0;
  };
}
