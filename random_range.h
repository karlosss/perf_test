#pragma once

#pragma once
#include <random>
#include <cmath>
#include <cfenv>
#include <cfloat>

#include "common.h"

static unsigned int seed;
static std::default_random_engine gen;

static double getRandNumUniform(int magnitude) {
    static std::uniform_int_distribution<int> distribution(0.0);

    int rnum = distribution(gen);

    double min = pow(2, magnitude);
    double max = pow(2, magnitude+1);

    return (max - min) * ( (double)(rnum + 1) / (double)INT32_MAX ) + min;
}

static double getRandomPositiveDouble(int min_exp, int dyn_range) {
    std::uniform_int_distribution<int> distribution(min_exp,min_exp + dyn_range);
    int rand_magintud = distribution(gen);

    return getRandNumUniform(rand_magintud);
}

///
/// \param neg : Percentage of negative numbers (0-100)
/// \param min_exp : Minimum exponent to generate random number
/// \param dyn_range : Dynamic range in bits
/// \return random number r = [2^(min_exp), 2^(min_exp + dyn_range)]
///
static double getRandomDouble(int min_exp, int dyn_range, size_t neg = 0) {
    static std::uniform_int_distribution<int> distribution(0,99);
    int coin = distribution(gen);
    double r_num = getRandomPositiveDouble(min_exp, dyn_range);
    if (coin < neg) {
        r_num = -r_num;
    }

    return r_num;
}

static void initRandomSeed() {
    static std::random_device r;
    seed = r();
    gen.seed(seed);
}

static void restartRandomGenSeed() {
    gen.seed(seed);
}

static int getRandomInt(int from, int to) {
    std::uniform_int_distribution<int> distribution(from, to);
    return distribution(gen);
}

static dd_I _ia_set_dd(double loh, double lol, double uph, double upl) {
    return _mm256_set_pd(upl, uph, lol, loh);
}

static dd_I getRandomDDI() {
    int rm = fegetround();

    double a = getRandomDouble(-3, 8, 50);
    double b = getRandomDouble(0, 0, 0);

    fesetround(FE_DOWNWARD);
    double s_lo  = a * b;
    double t_lo  = a * b - s_lo;

    fesetround(FE_UPWARD);
    double s_up  = a * b;
    double t_up  = (a * b - s_up) + DBL_MIN;

    dd_I c = _ia_set_dd(-s_lo, -t_lo, s_up, t_up);

    fesetround(rm);
    return c;
}