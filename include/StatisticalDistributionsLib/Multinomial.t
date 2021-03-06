namespace StatisticalDistributions {

  template<size_t N>
  void Multinomial<N>::init(const std::array<long double, N> &weights,
			    long ts) {
    trials = ts;
    long double twt = 0;
    for(int i = 0; i < N; i++)
      twt += weights[i];
    for(int i = 0; i < N; i++)
      ps[i] = weights[i] / twt;
    dist = std::discrete_distribution<long>(weights.begin(),
						   weights.end());
  }
  template<size_t N>
  long double Multinomial<N>::pdf(std::array<long, N> x) const {
    long double prob = 1, tot = 0;
    for(int i = 0; i < N; i++) {
      prob *= std::pow(ps[i], x[i]) / std::tgamma((long double)(x[i] + 1));
      tot += x[i];
    }
    return(prob / std::tgamma(tot + 1));
  }
  template<size_t N>
  std::array<long, N> Multinomial<N>::operator()(std::mt19937_64 &g) const {
    std::array<long, N> rval;
    rval.fill(0);
    for(int i = 0; i < trials; i++)
      rval[dist(g)]++;
    return(rval);
  }
}

