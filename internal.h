#pragma once

#include "common.h"

typedef struct {
    dd_v h;
    dd_v l;
} dd2_v;

static dd2_v twoSum(dd_v a, dd_v b) {
#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s  = a + b;
    dd_v a_ = s - b;
    dd_v b_ = s - a_;
    dd_v da = a - a_;
    dd_v db = b - b_;
    dd_v t  = da + db;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd2_v r;
    r.h = s;
    r.l = t;
    return r;
}

static dd2_v fastTwoSum(dd_v a, dd_v b) {
#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s = a + b;
    dd_v z = s - a;
    dd_v t = b - z;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd2_v r;
    r.h = s;
    r.l = t;
    return r;
}

static dd_v _vec_add_dd(dd_v a, dd_v b) {
    dd2_v s_t  = twoSum(a, b);
    dd_v  th   = _mm256_permute_pd(s_t.h, 0b0101);
    dd_v  tl   = _mm256_permute_pd(s_t.l, 0b0101);
    dd_v  c    = s_t.l + th;
    dd2_v v    = fastTwoSum(s_t.h, c);
    dd_v  w    = tl + v.l;
    dd2_v z    = fastTwoSum(v.h, w);
    dd_v  z_hl = _mm256_unpacklo_pd(z.h, z.l);
    return z_hl;
}

static dd_I _ia_add_dd(dd_I a, dd_I b) {
    return _vec_add_dd(a, b);
}