#ifndef _GLIBCXX_PARALLEL_RANDOM_NUMBER_H
#define _GLIBCXX_PARALLEL_RANDOM_NUMBER_H 1

#include <parallel/types.h>
#include <tr1/random>
#include <limits>
using namespace std;
int M;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>M
RandomNumber(uint32_t __seed, uint64_t _M_supremum = 0x100000000ULL)
    : _M_mt(__seed), _M_supremum(_M_supremum),
      _M_rand_sup(1ULL << std::numeric_limits<uint32_t>::digits),
      _M_supremum_reciprocal(double(_M_supremum) / double(_M_rand_sup)),
      _M_rand_sup_reciprocal(1.0 / double(_M_rand_sup)),
      __cache(0), __bits_left(0) { }
}
