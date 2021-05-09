#include <immintrin.h>

#include "common.h"
#include "internal.h"

inline static ddi_4 f1(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dst.f[0] = _ia_add_dd(a.f[0], b.f[0]);
    dst.f[1] = _ia_add_dd(a.f[1], b.f[1]);
    dst.f[2] = _ia_add_dd(a.f[2], b.f[2]);
    dst.f[3] = _ia_add_dd(a.f[3], b.f[3]);

    return dst;
}

inline static ddi_4 f2(ddi_4 a, ddi_4 b) {
    ddi_4 dst;
    for(int i = 0; i < 4; ++i){
        dst.f[i] = _ia_add_dd(a.f[i], b.f[i]);
    }
    return dst;
}

inline static ddi_4 f3(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif
    dd_v af0 = a.f[0];
    dd_v bf0 = b.f[0];
    dd_v s0  = af0 + bf0;
    dd_v a_0 = s0 - bf0;
    dd_v b_0 = s0 - a_0;
    dd_v da0 = af0 - a_0;
    dd_v db0 = bf0 - b_0;
    dd_v t0  = da0 + db0;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  th0   = _mm256_permute_pd(s0, 0b0101);
    dd_v  tl0   = _mm256_permute_pd(t0, 0b0101);
    dd_v  c0    = t0 + th0;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v f2s0 = s0 + c0;
    dd_v f2z0 = f2s0 - s0;
    dd_v f2t0 = c0 - f2z0;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  w0    = tl0 + f2t0;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v f3s0 = f2s0 + w0;
    dd_v f3z0 = f3s0 - f2s0;
    dd_v f3t0 = w0 - f3z0;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dst.f[0] = _mm256_unpacklo_pd(f3s0, f3t0);
    dst.f[1] = _ia_add_dd(a.f[1], b.f[1]);
    dst.f[2] = _ia_add_dd(a.f[2], b.f[2]);
    dst.f[3] = _ia_add_dd(a.f[3], b.f[3]);

    return dst;
}

inline static ddi_4 f4(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif
    dd_v af0 = a.f[0];
    dd_v af1 = a.f[1];
    dd_v af2 = a.f[2];
    dd_v af3 = a.f[3];

    dd_v bf0 = b.f[0];
    dd_v bf1 = b.f[1];
    dd_v bf2 = b.f[2];
    dd_v bf3 = b.f[3];

    dd_v s0  = af0 + bf0;
    dd_v s1  = af1 + bf1;
    dd_v s2  = af2 + bf2;
    dd_v s3  = af3 + bf3;

    dd_v a_0 = s0 - bf0;
    dd_v a_1 = s1 - bf1;
    dd_v a_2 = s2 - bf2;
    dd_v a_3 = s3 - bf3;

    dd_v b_0 = s0 - a_0;
    dd_v b_1 = s1 - a_1;
    dd_v b_2 = s2 - a_2;
    dd_v b_3 = s3 - a_3;

    dd_v da0 = af0 - a_0;
    dd_v da1 = af1 - a_1;
    dd_v da2 = af2 - a_2;
    dd_v da3 = af3 - a_3;

    dd_v db0 = bf0 - b_0;
    dd_v db1 = bf1 - b_1;
    dd_v db2 = bf2 - b_2;
    dd_v db3 = bf3 - b_3;

    dd_v t0  = da0 + db0;
    dd_v t1  = da1 + db1;
    dd_v t2  = da2 + db2;
    dd_v t3  = da3 + db3;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  th0   = _mm256_permute_pd(s0, 0b0101);
    dd_v  th1   = _mm256_permute_pd(s1, 0b0101);
    dd_v  th2   = _mm256_permute_pd(s2, 0b0101);
    dd_v  th3   = _mm256_permute_pd(s3, 0b0101);

    dd_v  tl0   = _mm256_permute_pd(t0, 0b0101);
    dd_v  tl1   = _mm256_permute_pd(t1, 0b0101);
    dd_v  tl2   = _mm256_permute_pd(t2, 0b0101);
    dd_v  tl3   = _mm256_permute_pd(t3, 0b0101);

    dd_v  c0    = t0 + th0;
    dd_v  c1    = t1 + th1;
    dd_v  c2    = t2 + th2;
    dd_v  c3    = t3 + th3;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v f2s0 = s0 + c0;
    dd_v f2s1 = s1 + c1;
    dd_v f2s2 = s2 + c2;
    dd_v f2s3 = s3 + c3;

    dd_v f2z0 = f2s0 - s0;
    dd_v f2z1 = f2s1 - s1;
    dd_v f2z2 = f2s2 - s2;
    dd_v f2z3 = f2s3 - s3;

    dd_v f2t0 = c0 - f2z0;
    dd_v f2t1 = c1 - f2z1;
    dd_v f2t2 = c2 - f2z2;
    dd_v f2t3 = c3 - f2z3;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  w0    = tl0 + f2t0;
    dd_v  w1    = tl1 + f2t1;
    dd_v  w2    = tl2 + f2t2;
    dd_v  w3    = tl3 + f2t3;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v f3s0 = f2s0 + w0;
    dd_v f3s1 = f2s1 + w1;
    dd_v f3s2 = f2s2 + w2;
    dd_v f3s3 = f2s3 + w3;

    dd_v f3z0 = f3s0 - f2s0;
    dd_v f3z1 = f3s1 - f2s1;
    dd_v f3z2 = f3s2 - f2s2;
    dd_v f3z3 = f3s3 - f2s3;

    dd_v f3t0 = w0 - f3z0;
    dd_v f3t1 = w1 - f3z1;
    dd_v f3t2 = w2 - f3z2;
    dd_v f3t3 = w3 - f3z3;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dst.f[0] = _mm256_unpacklo_pd(f3s0, f3t0);
    dst.f[1] = _mm256_unpacklo_pd(f3s1, f3t1);
    dst.f[2] = _mm256_unpacklo_pd(f3s2, f3t2);
    dst.f[3] = _mm256_unpacklo_pd(f3s3, f3t3);

    return dst;
}

inline static ddi_4 f5(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif
    dd_v af0 = a.f[0];
    dd_v af1 = a.f[1];
    dd_v af2 = a.f[2];
    dd_v af3 = a.f[3];

    dd_v bf0 = b.f[0];
    dd_v bf1 = b.f[1];
    dd_v bf2 = b.f[2];
    dd_v bf3 = b.f[3];

    dd_v s0  = af0 + bf0;
    dd_v s1  = af1 + bf1;
    dd_v s2  = af2 + bf2;
    dd_v s3  = af3 + bf3;

    dd_v a_0 = s0 - bf0;
    dd_v a_1 = s1 - bf1;
    dd_v a_2 = s2 - bf2;
    dd_v a_3 = s3 - bf3;

    dd_v b_0 = s0 - a_0;
    dd_v b_1 = s1 - a_1;
    dd_v b_2 = s2 - a_2;
    dd_v b_3 = s3 - a_3;

    dd_v da0 = af0 - a_0;
    dd_v da1 = af1 - a_1;
    dd_v da2 = af2 - a_2;
    dd_v da3 = af3 - a_3;

    dd_v db0 = bf0 - b_0;
    dd_v db1 = bf1 - b_1;
    dd_v db2 = bf2 - b_2;
    dd_v db3 = bf3 - b_3;

    dd_v t0  = da0 + db0;
    dd_v t1  = da1 + db1;
    dd_v t2  = da2 + db2;
    dd_v t3  = da3 + db3;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v thA = _mm256_unpackhi_pd(s0, s1);
    dd_v thB = _mm256_unpackhi_pd(s2, s3);

    dd_v tlA = _mm256_unpackhi_pd(t0, t1);
    dd_v tlB = _mm256_unpackhi_pd(t2, t3);

    dd_v sloA = _mm256_unpacklo_pd(s0, s1);
    dd_v sloB = _mm256_unpacklo_pd(s2, s3);

    dd_v tloA = _mm256_unpacklo_pd(t0, t1);
    dd_v tloB = _mm256_unpacklo_pd(t2, t3);

    dd_v cA = tloA + thA;
    dd_v cB = tloB + thB;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v f2sA = sloA + cA;
    dd_v f2sB = sloB + cB;

    dd_v f2zA = f2sA - sloA;
    dd_v f2zB = f2sB - sloB;

    dd_v f2tA = cA - f2zA;
    dd_v f2tB = cB - f2zB;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  wA = tlA + f2tA;
    dd_v  wB = tlB + f2tB;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v f3sA = f2sA + wA;
    dd_v f3sB = f2sB + wB;

    dd_v f3zA = f3sA - f2sA;
    dd_v f3zB = f3sB - f2sB;

    dd_v f3tA = wA - f3zA;
    dd_v f3tB = wB - f3zB;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dst.f[0] = _mm256_unpacklo_pd(f3sA, f3tA);
    dst.f[1] = _mm256_unpackhi_pd(f3sA, f3tA);
    dst.f[2] = _mm256_unpacklo_pd(f3sB, f3tB);
    dst.f[3] = _mm256_unpackhi_pd(f3sB, f3tB);

    return dst;
}

typedef __m256i i256;
typedef union {
    ddi_4 v;
    dd_I   f[4];
    i256   i[4];
} vec256d;

inline static ddi_4 f6(ddi_4 _a, ddi_4 _b) {
    vec256d a;
    a.v = _a;
    vec256d b;
    b.v = _b;
    vec256d dst;
    int j;
    int i;

    for (j = 0; j <= 3; ++j) {
        i = j * 64;
        dst.f[i / 64] = _ia_add_dd(a.f[i / 64], b.f[i / 64]);
    }

    return dst.v;
}

inline static ddi_4 f7(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dd_I af0_0_ = a.f[0];
    dd_I af0_1_ = a.f[1];
    dd_I af0_2_ = a.f[2];
    dd_I af0_3_ = a.f[3];

    dd_I bf0_0_ = b.f[0];
    dd_I bf0_1_ = b.f[1];
    dd_I bf0_2_ = b.f[2];
    dd_I bf0_3_ = b.f[3];

    dd_I _b_0_ = -_mm256_permute4x64_pd(bf0_0_, 0b01001110);

    dd_v  ah_0_ = _mm256_unpacklo_pd(af0_0_, af0_0_);
    dd_v  al_0_ = _mm256_unpackhi_pd(af0_0_, af0_0_);
    dd_v  bh_0_ = _mm256_unpacklo_pd(bf0_0_, _b_0_);
    dd_v  bl_0_ = _mm256_unpackhi_pd(bf0_0_, _b_0_);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_3_0_  = ah_0_ * bh_0_;
    dd_v t_3_0_  = _mm256_fmsub_pd(ah_0_, bh_0_, s_3_0_);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_0_ = al_0_ * bl_0_;
    dd_v  tl1_0_ = _mm256_fmadd_pd(ah_0_, bl_0_, tl0_0_);
    dd_v  cl2_0_ = _mm256_fmadd_pd(al_0_, bh_0_, tl1_0_);
    dd_v  cl3_0_ = t_3_0_ + cl2_0_;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_4_0_ = s_3_0_ + cl3_0_;
    dd_v z_4_0_ = s_4_0_ - s_3_0_;
    dd_v t_4_0_ = cl3_0_ - z_4_0_;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif
    __m256d _r_up_1_0_ = _mm256_unpacklo_pd(s_4_0_, t_4_0_);
    __m256d _r_up_2_0_ = _mm256_unpackhi_pd(s_4_0_, t_4_0_);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_5_0_  = ah_0_ * (-bh_0_);
    dd_v t_5_0_  = _mm256_fmsub_pd(ah_0_, -bh_0_, s_5_0_);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_2_0_ = al_0_ * (-bl_0_);
    dd_v  tl1_2_0_ = _mm256_fmadd_pd(ah_0_, -bl_0_, tl0_2_0_);
    dd_v  cl2_2_0_ = _mm256_fmadd_pd(al_0_, -bh_0_, tl1_2_0_);
    dd_v  cl3_2_0_ = t_5_0_ + cl2_2_0_;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_6_0_ = s_5_0_ + cl3_2_0_;
    dd_v z_6_0_ = s_6_0_ - s_5_0_;
    dd_v t_6_0_ = cl3_2_0_ - z_6_0_;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    __m256d _r_lo_1_0_ = _mm256_unpacklo_pd(s_6_0_, t_6_0_);
    __m256d _r_lo_2_0_ = _mm256_unpackhi_pd(s_6_0_, t_6_0_);

    /* Create -inf vector */
    dd_v minf = _mm256_set1_pd(-1.0/0.0);

    dd_v mask1_7_0_ = _mm256_cmp_pd(_r_up_1_0_, _r_up_2_0_, _CMP_GE_OQ);
    dd_v mask2_7_0_ = _mm256_cmp_pd(_r_up_1_0_, _r_up_2_0_, _CMP_LE_OQ);

    mask1_7_0_ = _mm256_unpacklo_pd(mask1_7_0_, mask1_7_0_);
    mask2_7_0_ = _mm256_unpacklo_pd(mask2_7_0_, mask2_7_0_);

    dd_v _a_7_0_ = _mm256_blendv_pd(minf, _r_up_1_0_, mask1_7_0_);
    dd_v _b_7_0_ = _mm256_blendv_pd(minf, _r_up_2_0_, mask2_7_0_);

    dd_I r_up_0_ = _mm256_max_pd(_a_7_0_, _b_7_0_);

    dd_v mask1_8_0_ = _mm256_cmp_pd(_r_lo_1_0_, _r_lo_2_0_, _CMP_GE_OQ);
    dd_v mask2_8_0_ = _mm256_cmp_pd(_r_lo_1_0_, _r_lo_2_0_, _CMP_LE_OQ);

    mask1_8_0_ = _mm256_unpacklo_pd(mask1_8_0_, mask1_8_0_);
    mask2_8_0_ = _mm256_unpacklo_pd(mask2_8_0_, mask2_8_0_);

    dd_v _a_8_0_ = _mm256_blendv_pd(minf, _r_lo_1_0_, mask1_8_0_);
    dd_v _b_8_0_ = _mm256_blendv_pd(minf, _r_lo_2_0_, mask2_8_0_);

    dd_I r_lo_0_ = _mm256_max_pd(_a_8_0_, _b_8_0_);

    /* Reorder result to keep lower bound in the lower half of vectors */
    dd_I c1_0_ = _mm256_permute2f128_pd(r_lo_0_, r_up_0_, 0b00100000);
    dd_I c2_0_ = _mm256_permute2f128_pd(r_lo_0_, r_up_0_, 0b00110001);

    dd_v mask1_9_0_ = _mm256_cmp_pd(c1_0_, c2_0_, _CMP_GE_OQ);
    dd_v mask2_9_0_ = _mm256_cmp_pd(c1_0_, c2_0_, _CMP_LE_OQ);

    mask1_9_0_ = _mm256_unpacklo_pd(mask1_9_0_, mask1_9_0_);
    mask2_9_0_ = _mm256_unpacklo_pd(mask2_9_0_, mask2_9_0_);

    dd_v _a_9_0_ = _mm256_blendv_pd(minf, c1_0_, mask1_9_0_);
    dd_v _b_9_0_ = _mm256_blendv_pd(minf, c2_0_, mask2_9_0_);

    // ======

    dd_I _b_1_ = -_mm256_permute4x64_pd(bf0_1_, 0b01001110);

    dd_v  ah_1_ = _mm256_unpacklo_pd(af0_1_, af0_1_);
    dd_v  al_1_ = _mm256_unpackhi_pd(af0_1_, af0_1_);
    dd_v  bh_1_ = _mm256_unpacklo_pd(bf0_1_, _b_1_);
    dd_v  bl_1_ = _mm256_unpackhi_pd(bf0_1_, _b_1_);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_3_1_  = ah_1_ * bh_1_;
    dd_v t_3_1_  = _mm256_fmsub_pd(ah_1_, bh_1_, s_3_1_);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_1_ = al_1_ * bl_1_;
    dd_v  tl1_1_ = _mm256_fmadd_pd(ah_1_, bl_1_, tl0_1_);
    dd_v  cl2_1_ = _mm256_fmadd_pd(al_1_, bh_1_, tl1_1_);
    dd_v  cl3_1_ = t_3_1_ + cl2_1_;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_4_1_ = s_3_1_ + cl3_1_;
    dd_v z_4_1_ = s_4_1_ - s_3_1_;
    dd_v t_4_1_ = cl3_1_ - z_4_1_;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif
    __m256d _r_up_1_1_ = _mm256_unpacklo_pd(s_4_1_, t_4_1_);
    __m256d _r_up_2_1_ = _mm256_unpackhi_pd(s_4_1_, t_4_1_);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_5_1_  = ah_1_ * (-bh_1_);
    dd_v t_5_1_  = _mm256_fmsub_pd(ah_1_, -bh_1_, s_5_1_);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_2_1_ = al_1_ * (-bl_1_);
    dd_v  tl1_2_1_ = _mm256_fmadd_pd(ah_1_, -bl_1_, tl0_2_1_);
    dd_v  cl2_2_1_ = _mm256_fmadd_pd(al_1_, -bh_1_, tl1_2_1_);
    dd_v  cl3_2_1_ = t_5_1_ + cl2_2_1_;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_6_1_ = s_5_1_ + cl3_2_1_;
    dd_v z_6_1_ = s_6_1_ - s_5_1_;
    dd_v t_6_1_ = cl3_2_1_ - z_6_1_;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    __m256d _r_lo_1_1_ = _mm256_unpacklo_pd(s_6_1_, t_6_1_);
    __m256d _r_lo_2_1_ = _mm256_unpackhi_pd(s_6_1_, t_6_1_);

    /* Create -inf vector */

    dd_v mask1_7_1_ = _mm256_cmp_pd(_r_up_1_1_, _r_up_2_1_, _CMP_GE_OQ);
    dd_v mask2_7_1_ = _mm256_cmp_pd(_r_up_1_1_, _r_up_2_1_, _CMP_LE_OQ);

    mask1_7_1_ = _mm256_unpacklo_pd(mask1_7_1_, mask1_7_1_);
    mask2_7_1_ = _mm256_unpacklo_pd(mask2_7_1_, mask2_7_1_);

    dd_v _a_7_1_ = _mm256_blendv_pd(minf, _r_up_1_1_, mask1_7_1_);
    dd_v _b_7_1_ = _mm256_blendv_pd(minf, _r_up_2_1_, mask2_7_1_);

    dd_I r_up_1_ = _mm256_max_pd(_a_7_1_, _b_7_1_);

    dd_v mask1_8_1_ = _mm256_cmp_pd(_r_lo_1_1_, _r_lo_2_1_, _CMP_GE_OQ);
    dd_v mask2_8_1_ = _mm256_cmp_pd(_r_lo_1_1_, _r_lo_2_1_, _CMP_LE_OQ);

    mask1_8_1_ = _mm256_unpacklo_pd(mask1_8_1_, mask1_8_1_);
    mask2_8_1_ = _mm256_unpacklo_pd(mask2_8_1_, mask2_8_1_);

    dd_v _a_8_1_ = _mm256_blendv_pd(minf, _r_lo_1_1_, mask1_8_1_);
    dd_v _b_8_1_ = _mm256_blendv_pd(minf, _r_lo_2_1_, mask2_8_1_);

    dd_I r_lo_1_ = _mm256_max_pd(_a_8_1_, _b_8_1_);

    /* Reorder result to keep lower bound in the lower half of vectors */
    dd_I c1_1_ = _mm256_permute2f128_pd(r_lo_1_, r_up_1_, 0b00100000);
    dd_I c2_1_ = _mm256_permute2f128_pd(r_lo_1_, r_up_1_, 0b00110001);

    dd_v mask1_9_1_ = _mm256_cmp_pd(c1_1_, c2_1_, _CMP_GE_OQ);
    dd_v mask2_9_1_ = _mm256_cmp_pd(c1_1_, c2_1_, _CMP_LE_OQ);

    mask1_9_1_ = _mm256_unpacklo_pd(mask1_9_1_, mask1_9_1_);
    mask2_9_1_ = _mm256_unpacklo_pd(mask2_9_1_, mask2_9_1_);

    dd_v _a_9_1_ = _mm256_blendv_pd(minf, c1_1_, mask1_9_1_);
    dd_v _b_9_1_ = _mm256_blendv_pd(minf, c2_1_, mask2_9_1_);

    // ======

    dd_I _b_2_ = -_mm256_permute4x64_pd(bf0_2_, 0b01001110);

    dd_v  ah_2_ = _mm256_unpacklo_pd(af0_2_, af0_2_);
    dd_v  al_2_ = _mm256_unpackhi_pd(af0_2_, af0_2_);
    dd_v  bh_2_ = _mm256_unpacklo_pd(bf0_2_, _b_2_);
    dd_v  bl_2_ = _mm256_unpackhi_pd(bf0_2_, _b_2_);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_3_2_  = ah_2_ * bh_2_;
    dd_v t_3_2_  = _mm256_fmsub_pd(ah_2_, bh_2_, s_3_2_);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_2_ = al_2_ * bl_2_;
    dd_v  tl1_2_ = _mm256_fmadd_pd(ah_2_, bl_2_, tl0_2_);
    dd_v  cl2_2_ = _mm256_fmadd_pd(al_2_, bh_2_, tl1_2_);
    dd_v  cl3_2_ = t_3_2_ + cl2_2_;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_4_2_ = s_3_2_ + cl3_2_;
    dd_v z_4_2_ = s_4_2_ - s_3_2_;
    dd_v t_4_2_ = cl3_2_ - z_4_2_;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif
    __m256d _r_up_1_2_ = _mm256_unpacklo_pd(s_4_2_, t_4_2_);
    __m256d _r_up_2_2_ = _mm256_unpackhi_pd(s_4_2_, t_4_2_);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_5_2_  = ah_2_ * (-bh_2_);
    dd_v t_5_2_  = _mm256_fmsub_pd(ah_2_, -bh_2_, s_5_2_);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_2_2_ = al_2_ * (-bl_2_);
    dd_v  tl1_2_2_ = _mm256_fmadd_pd(ah_2_, -bl_2_, tl0_2_2_);
    dd_v  cl2_2_2_ = _mm256_fmadd_pd(al_2_, -bh_2_, tl1_2_2_);
    dd_v  cl3_2_2_ = t_5_2_ + cl2_2_2_;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_6_2_ = s_5_2_ + cl3_2_2_;
    dd_v z_6_2_ = s_6_2_ - s_5_2_;
    dd_v t_6_2_ = cl3_2_2_ - z_6_2_;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    __m256d _r_lo_1_2_ = _mm256_unpacklo_pd(s_6_2_, t_6_2_);
    __m256d _r_lo_2_2_ = _mm256_unpackhi_pd(s_6_2_, t_6_2_);

    /* Create -inf vector */

    dd_v mask1_7_2_ = _mm256_cmp_pd(_r_up_1_2_, _r_up_2_2_, _CMP_GE_OQ);
    dd_v mask2_7_2_ = _mm256_cmp_pd(_r_up_1_2_, _r_up_2_2_, _CMP_LE_OQ);

    mask1_7_2_ = _mm256_unpacklo_pd(mask1_7_2_, mask1_7_2_);
    mask2_7_2_ = _mm256_unpacklo_pd(mask2_7_2_, mask2_7_2_);

    dd_v _a_7_2_ = _mm256_blendv_pd(minf, _r_up_1_2_, mask1_7_2_);
    dd_v _b_7_2_ = _mm256_blendv_pd(minf, _r_up_2_2_, mask2_7_2_);

    dd_I r_up_2_ = _mm256_max_pd(_a_7_2_, _b_7_2_);

    dd_v mask1_8_2_ = _mm256_cmp_pd(_r_lo_1_2_, _r_lo_2_2_, _CMP_GE_OQ);
    dd_v mask2_8_2_ = _mm256_cmp_pd(_r_lo_1_2_, _r_lo_2_2_, _CMP_LE_OQ);

    mask1_8_2_ = _mm256_unpacklo_pd(mask1_8_2_, mask1_8_2_);
    mask2_8_2_ = _mm256_unpacklo_pd(mask2_8_2_, mask2_8_2_);

    dd_v _a_8_2_ = _mm256_blendv_pd(minf, _r_lo_1_2_, mask1_8_2_);
    dd_v _b_8_2_ = _mm256_blendv_pd(minf, _r_lo_2_2_, mask2_8_2_);

    dd_I r_lo_2_ = _mm256_max_pd(_a_8_2_, _b_8_2_);

    /* Reorder result to keep lower bound in the lower half of vectors */
    dd_I c1_2_ = _mm256_permute2f128_pd(r_lo_2_, r_up_2_, 0b00100000);
    dd_I c2_2_ = _mm256_permute2f128_pd(r_lo_2_, r_up_2_, 0b00110001);

    dd_v mask1_9_2_ = _mm256_cmp_pd(c1_2_, c2_2_, _CMP_GE_OQ);
    dd_v mask2_9_2_ = _mm256_cmp_pd(c1_2_, c2_2_, _CMP_LE_OQ);

    mask1_9_2_ = _mm256_unpacklo_pd(mask1_9_2_, mask1_9_2_);
    mask2_9_2_ = _mm256_unpacklo_pd(mask2_9_2_, mask2_9_2_);

    dd_v _a_9_2_ = _mm256_blendv_pd(minf, c1_2_, mask1_9_2_);
    dd_v _b_9_2_ = _mm256_blendv_pd(minf, c2_2_, mask2_9_2_);

    // ======

    dd_I _b_3_ = -_mm256_permute4x64_pd(bf0_3_, 0b01001110);

    dd_v  ah_3_ = _mm256_unpacklo_pd(af0_3_, af0_3_);
    dd_v  al_3_ = _mm256_unpackhi_pd(af0_3_, af0_3_);
    dd_v  bh_3_ = _mm256_unpacklo_pd(bf0_3_, _b_3_);
    dd_v  bl_3_ = _mm256_unpackhi_pd(bf0_3_, _b_3_);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_3_3_  = ah_3_ * bh_3_;
    dd_v t_3_3_  = _mm256_fmsub_pd(ah_3_, bh_3_, s_3_3_);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_3_ = al_3_ * bl_3_;
    dd_v  tl1_3_ = _mm256_fmadd_pd(ah_3_, bl_3_, tl0_3_);
    dd_v  cl2_3_ = _mm256_fmadd_pd(al_3_, bh_3_, tl1_3_);
    dd_v  cl3_3_ = t_3_3_ + cl2_3_;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_4_3_ = s_3_3_ + cl3_3_;
    dd_v z_4_3_ = s_4_3_ - s_3_3_;
    dd_v t_4_3_ = cl3_3_ - z_4_3_;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif
    __m256d _r_up_1_3_ = _mm256_unpacklo_pd(s_4_3_, t_4_3_);
    __m256d _r_up_2_3_ = _mm256_unpackhi_pd(s_4_3_, t_4_3_);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_5_3_  = ah_3_ * (-bh_3_);
    dd_v t_5_3_  = _mm256_fmsub_pd(ah_3_, -bh_3_, s_5_3_);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_2_3_ = al_3_ * (-bl_3_);
    dd_v  tl1_2_3_ = _mm256_fmadd_pd(ah_3_, -bl_3_, tl0_2_3_);
    dd_v  cl2_2_3_ = _mm256_fmadd_pd(al_3_, -bh_3_, tl1_2_3_);
    dd_v  cl3_2_3_ = t_5_3_ + cl2_2_3_;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_6_3_ = s_5_3_ + cl3_2_3_;
    dd_v z_6_3_ = s_6_3_ - s_5_3_;
    dd_v t_6_3_ = cl3_2_3_ - z_6_3_;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    __m256d _r_lo_1_3_ = _mm256_unpacklo_pd(s_6_3_, t_6_3_);
    __m256d _r_lo_2_3_ = _mm256_unpackhi_pd(s_6_3_, t_6_3_);

    /* Create -inf vector */

    dd_v mask1_7_3_ = _mm256_cmp_pd(_r_up_1_3_, _r_up_2_3_, _CMP_GE_OQ);
    dd_v mask2_7_3_ = _mm256_cmp_pd(_r_up_1_3_, _r_up_2_3_, _CMP_LE_OQ);

    mask1_7_3_ = _mm256_unpacklo_pd(mask1_7_3_, mask1_7_3_);
    mask2_7_3_ = _mm256_unpacklo_pd(mask2_7_3_, mask2_7_3_);

    dd_v _a_7_3_ = _mm256_blendv_pd(minf, _r_up_1_3_, mask1_7_3_);
    dd_v _b_7_3_ = _mm256_blendv_pd(minf, _r_up_2_3_, mask2_7_3_);

    dd_I r_up_3_ = _mm256_max_pd(_a_7_3_, _b_7_3_);

    dd_v mask1_8_3_ = _mm256_cmp_pd(_r_lo_1_3_, _r_lo_2_3_, _CMP_GE_OQ);
    dd_v mask2_8_3_ = _mm256_cmp_pd(_r_lo_1_3_, _r_lo_2_3_, _CMP_LE_OQ);

    mask1_8_3_ = _mm256_unpacklo_pd(mask1_8_3_, mask1_8_3_);
    mask2_8_3_ = _mm256_unpacklo_pd(mask2_8_3_, mask2_8_3_);

    dd_v _a_8_3_ = _mm256_blendv_pd(minf, _r_lo_1_3_, mask1_8_3_);
    dd_v _b_8_3_ = _mm256_blendv_pd(minf, _r_lo_2_3_, mask2_8_3_);

    dd_I r_lo_3_ = _mm256_max_pd(_a_8_3_, _b_8_3_);

    /* Reorder result to keep lower bound in the lower half of vectors */
    dd_I c1_3_ = _mm256_permute2f128_pd(r_lo_3_, r_up_3_, 0b00100000);
    dd_I c2_3_ = _mm256_permute2f128_pd(r_lo_3_, r_up_3_, 0b00110001);

    dd_v mask1_9_3_ = _mm256_cmp_pd(c1_3_, c2_3_, _CMP_GE_OQ);
    dd_v mask2_9_3_ = _mm256_cmp_pd(c1_3_, c2_3_, _CMP_LE_OQ);

    mask1_9_3_ = _mm256_unpacklo_pd(mask1_9_3_, mask1_9_3_);
    mask2_9_3_ = _mm256_unpacklo_pd(mask2_9_3_, mask2_9_3_);

    dd_v _a_9_3_ = _mm256_blendv_pd(minf, c1_3_, mask1_9_3_);
    dd_v _b_9_3_ = _mm256_blendv_pd(minf, c2_3_, mask2_9_3_);

    dst.f[0] = _mm256_max_pd(_a_9_0_, _b_9_0_);
    dst.f[1] = _mm256_max_pd(_a_9_1_, _b_9_1_);
    dst.f[2] = _mm256_max_pd(_a_9_2_, _b_9_2_);
    dst.f[3] = _mm256_max_pd(_a_9_3_, _b_9_3_);

    return dst;
}


inline static ddi_4 f8(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    dd_I af0_0 = a.f[0];
    dd_I af0_1 = a.f[1];
    dd_I af0_2 = a.f[2];
    dd_I af0_3 = a.f[3];

    dd_I bf0_0 = b.f[0];
    dd_I bf0_1 = b.f[1];
    dd_I bf0_2 = b.f[2];
    dd_I bf0_3 = b.f[3];

    dd_I _b_0 = -_mm256_permute4x64_pd(bf0_0, 0b01001110);
    dd_I _b_1 = -_mm256_permute4x64_pd(bf0_1, 0b01001110);
    dd_I _b_2 = -_mm256_permute4x64_pd(bf0_2, 0b01001110);
    dd_I _b_3 = -_mm256_permute4x64_pd(bf0_3, 0b01001110);

    dd_v  ah_0 = _mm256_unpacklo_pd(af0_0, af0_0);
    dd_v  ah_1 = _mm256_unpacklo_pd(af0_1, af0_1);
    dd_v  ah_2 = _mm256_unpacklo_pd(af0_2, af0_2);
    dd_v  ah_3 = _mm256_unpacklo_pd(af0_3, af0_3);

    dd_v  al_0 = _mm256_unpackhi_pd(af0_0, af0_0);
    dd_v  al_1 = _mm256_unpackhi_pd(af0_1, af0_1);
    dd_v  al_2 = _mm256_unpackhi_pd(af0_2, af0_2);
    dd_v  al_3 = _mm256_unpackhi_pd(af0_3, af0_3);

    dd_v  bh_0 = _mm256_unpacklo_pd(bf0_0, _b_0);
    dd_v  bh_1 = _mm256_unpacklo_pd(bf0_1, _b_1);
    dd_v  bh_2 = _mm256_unpacklo_pd(bf0_2, _b_2);
    dd_v  bh_3 = _mm256_unpacklo_pd(bf0_3, _b_3);

    dd_v  bl_0 = _mm256_unpackhi_pd(bf0_0, _b_0);
    dd_v  bl_1 = _mm256_unpackhi_pd(bf0_1, _b_1);
    dd_v  bl_2 = _mm256_unpackhi_pd(bf0_2, _b_2);
    dd_v  bl_3 = _mm256_unpackhi_pd(bf0_3, _b_3);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_3_0  = ah_0 * bh_0;
    dd_v s_3_1  = ah_1 * bh_1;
    dd_v s_3_2  = ah_2 * bh_2;
    dd_v s_3_3  = ah_3 * bh_3;

    dd_v t_3_0  = _mm256_fmsub_pd(ah_0, bh_0, s_3_0);
    dd_v t_3_1  = _mm256_fmsub_pd(ah_1, bh_1, s_3_1);
    dd_v t_3_2  = _mm256_fmsub_pd(ah_2, bh_2, s_3_2);
    dd_v t_3_3  = _mm256_fmsub_pd(ah_3, bh_3, s_3_3);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_0 = al_0 * bl_0;
    dd_v  tl0_1 = al_1 * bl_1;
    dd_v  tl0_2 = al_2 * bl_2;
    dd_v  tl0_3 = al_3 * bl_3;

    dd_v  tl1_0 = _mm256_fmadd_pd(ah_0, bl_0, tl0_0);
    dd_v  tl1_1 = _mm256_fmadd_pd(ah_1, bl_1, tl0_1);
    dd_v  tl1_2 = _mm256_fmadd_pd(ah_2, bl_2, tl0_2);
    dd_v  tl1_3 = _mm256_fmadd_pd(ah_3, bl_3, tl0_3);

    dd_v  cl2_0 = _mm256_fmadd_pd(al_0, bh_0, tl1_0);
    dd_v  cl2_1 = _mm256_fmadd_pd(al_1, bh_1, tl1_1);
    dd_v  cl2_2 = _mm256_fmadd_pd(al_2, bh_2, tl1_2);
    dd_v  cl2_3 = _mm256_fmadd_pd(al_3, bh_3, tl1_3);

    dd_v  cl3_0 = t_3_0 + cl2_0;
    dd_v  cl3_1 = t_3_1 + cl2_1;
    dd_v  cl3_2 = t_3_2 + cl2_2;
    dd_v  cl3_3 = t_3_3 + cl2_3;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_4_0 = s_3_0 + cl3_0;
    dd_v s_4_1 = s_3_1 + cl3_1;
    dd_v s_4_2 = s_3_2 + cl3_2;
    dd_v s_4_3 = s_3_3 + cl3_3;

    dd_v z_4_0 = s_4_0 - s_3_0;
    dd_v z_4_1 = s_4_1 - s_3_1;
    dd_v z_4_2 = s_4_2 - s_3_2;
    dd_v z_4_3 = s_4_3 - s_3_3;

    dd_v t_4_0 = cl3_0 - z_4_0;
    dd_v t_4_1 = cl3_1 - z_4_1;
    dd_v t_4_2 = cl3_2 - z_4_2;
    dd_v t_4_3 = cl3_3 - z_4_3;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif
    __m256d _r_up_1_0 = _mm256_unpacklo_pd(s_4_0, t_4_0);
    __m256d _r_up_1_1 = _mm256_unpacklo_pd(s_4_1, t_4_1);
    __m256d _r_up_1_2 = _mm256_unpacklo_pd(s_4_2, t_4_2);
    __m256d _r_up_1_3 = _mm256_unpacklo_pd(s_4_3, t_4_3);

    __m256d _r_up_2_0 = _mm256_unpackhi_pd(s_4_0, t_4_0);
    __m256d _r_up_2_1 = _mm256_unpackhi_pd(s_4_1, t_4_1);
    __m256d _r_up_2_2 = _mm256_unpackhi_pd(s_4_2, t_4_2);
    __m256d _r_up_2_3 = _mm256_unpackhi_pd(s_4_3, t_4_3);

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_5_0  = ah_0 * (-bh_0);
    dd_v s_5_1  = ah_1 * (-bh_1);
    dd_v s_5_2  = ah_2 * (-bh_2);
    dd_v s_5_3  = ah_3 * (-bh_3);

    dd_v t_5_0  = _mm256_fmsub_pd(ah_0, -bh_0, s_5_0);
    dd_v t_5_1  = _mm256_fmsub_pd(ah_1, -bh_1, s_5_1);
    dd_v t_5_2  = _mm256_fmsub_pd(ah_2, -bh_2, s_5_2);
    dd_v t_5_3  = _mm256_fmsub_pd(ah_3, -bh_3, s_5_3);

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    dd_v  tl0_2_0 = al_0 * (-bl_0);
    dd_v  tl0_2_1 = al_1 * (-bl_1);
    dd_v  tl0_2_2 = al_2 * (-bl_2);
    dd_v  tl0_2_3 = al_3 * (-bl_3);

    dd_v  tl1_2_0 = _mm256_fmadd_pd(ah_0, -bl_0, tl0_2_0);
    dd_v  tl1_2_1 = _mm256_fmadd_pd(ah_1, -bl_1, tl0_2_1);
    dd_v  tl1_2_2 = _mm256_fmadd_pd(ah_2, -bl_2, tl0_2_2);
    dd_v  tl1_2_3 = _mm256_fmadd_pd(ah_3, -bl_3, tl0_2_3);

    dd_v  cl2_2_0 = _mm256_fmadd_pd(al_0, -bh_0, tl1_2_0);
    dd_v  cl2_2_1 = _mm256_fmadd_pd(al_1, -bh_1, tl1_2_1);
    dd_v  cl2_2_2 = _mm256_fmadd_pd(al_2, -bh_2, tl1_2_2);
    dd_v  cl2_2_3 = _mm256_fmadd_pd(al_3, -bh_3, tl1_2_3);

    dd_v  cl3_2_0 = t_5_0 + cl2_2_0;
    dd_v  cl3_2_1 = t_5_1 + cl2_2_1;
    dd_v  cl3_2_2 = t_5_2 + cl2_2_2;
    dd_v  cl3_2_3 = t_5_3 + cl2_2_3;

#ifdef ROUND_TO_NEAREST
    int _fround = fegetround();
    fesetround(FE_TONEAREST);
#endif

    dd_v s_6_0 = s_5_0 + cl3_2_0;
    dd_v s_6_1 = s_5_1 + cl3_2_1;
    dd_v s_6_2 = s_5_2 + cl3_2_2;
    dd_v s_6_3 = s_5_3 + cl3_2_3;

    dd_v z_6_0 = s_6_0 - s_5_0;
    dd_v z_6_1 = s_6_1 - s_5_1;
    dd_v z_6_2 = s_6_2 - s_5_2;
    dd_v z_6_3 = s_6_3 - s_5_3;

    dd_v t_6_0 = cl3_2_0 - z_6_0;
    dd_v t_6_1 = cl3_2_1 - z_6_1;
    dd_v t_6_2 = cl3_2_2 - z_6_2;
    dd_v t_6_3 = cl3_2_3 - z_6_3;

#ifdef ROUND_TO_NEAREST
    fesetround(_fround);
#endif

    __m256d _r_lo_1_0 = _mm256_unpacklo_pd(s_6_0, t_6_0);
    __m256d _r_lo_1_1 = _mm256_unpacklo_pd(s_6_1, t_6_1);
    __m256d _r_lo_1_2 = _mm256_unpacklo_pd(s_6_2, t_6_2);
    __m256d _r_lo_1_3 = _mm256_unpacklo_pd(s_6_3, t_6_3);

    __m256d _r_lo_2_0 = _mm256_unpackhi_pd(s_6_0, t_6_0);
    __m256d _r_lo_2_1 = _mm256_unpackhi_pd(s_6_1, t_6_1);
    __m256d _r_lo_2_2 = _mm256_unpackhi_pd(s_6_2, t_6_2);
    __m256d _r_lo_2_3 = _mm256_unpackhi_pd(s_6_3, t_6_3);

    /* Create -inf vector */
    dd_v minf = _mm256_set1_pd(-1.0/0.0);

    dd_v mask1_7_0 = _mm256_cmp_pd(_r_up_1_0, _r_up_2_0, _CMP_GE_OQ);
    dd_v mask1_7_1 = _mm256_cmp_pd(_r_up_1_1, _r_up_2_1, _CMP_GE_OQ);
    dd_v mask1_7_2 = _mm256_cmp_pd(_r_up_1_2, _r_up_2_2, _CMP_GE_OQ);
    dd_v mask1_7_3 = _mm256_cmp_pd(_r_up_1_3, _r_up_2_3, _CMP_GE_OQ);

    dd_v mask2_7_0 = _mm256_cmp_pd(_r_up_1_0, _r_up_2_0, _CMP_LE_OQ);
    dd_v mask2_7_1 = _mm256_cmp_pd(_r_up_1_1, _r_up_2_1, _CMP_LE_OQ);
    dd_v mask2_7_2 = _mm256_cmp_pd(_r_up_1_2, _r_up_2_2, _CMP_LE_OQ);
    dd_v mask2_7_3 = _mm256_cmp_pd(_r_up_1_3, _r_up_2_3, _CMP_LE_OQ);

    mask1_7_0 = _mm256_unpacklo_pd(mask1_7_0, mask1_7_0);
    mask1_7_1 = _mm256_unpacklo_pd(mask1_7_1, mask1_7_1);
    mask1_7_2 = _mm256_unpacklo_pd(mask1_7_2, mask1_7_2);
    mask1_7_3 = _mm256_unpacklo_pd(mask1_7_3, mask1_7_3);

    mask2_7_0 = _mm256_unpacklo_pd(mask2_7_0, mask2_7_0);
    mask2_7_1 = _mm256_unpacklo_pd(mask2_7_1, mask2_7_1);
    mask2_7_2 = _mm256_unpacklo_pd(mask2_7_2, mask2_7_2);
    mask2_7_3 = _mm256_unpacklo_pd(mask2_7_3, mask2_7_3);

    dd_v _a_7_0 = _mm256_blendv_pd(minf, _r_up_1_0, mask1_7_0);
    dd_v _a_7_1 = _mm256_blendv_pd(minf, _r_up_1_1, mask1_7_1);
    dd_v _a_7_2 = _mm256_blendv_pd(minf, _r_up_1_2, mask1_7_2);
    dd_v _a_7_3 = _mm256_blendv_pd(minf, _r_up_1_3, mask1_7_3);

    dd_v _b_7_0 = _mm256_blendv_pd(minf, _r_up_2_0, mask2_7_0);
    dd_v _b_7_1 = _mm256_blendv_pd(minf, _r_up_2_1, mask2_7_1);
    dd_v _b_7_2 = _mm256_blendv_pd(minf, _r_up_2_2, mask2_7_2);
    dd_v _b_7_3 = _mm256_blendv_pd(minf, _r_up_2_3, mask2_7_3);

    dd_I r_up_0 = _mm256_max_pd(_a_7_0, _b_7_0);
    dd_I r_up_1 = _mm256_max_pd(_a_7_1, _b_7_1);
    dd_I r_up_2 = _mm256_max_pd(_a_7_2, _b_7_2);
    dd_I r_up_3 = _mm256_max_pd(_a_7_3, _b_7_3);

    dd_v mask1_8_0 = _mm256_cmp_pd(_r_lo_1_0, _r_lo_2_0, _CMP_GE_OQ);
    dd_v mask1_8_1 = _mm256_cmp_pd(_r_lo_1_1, _r_lo_2_1, _CMP_GE_OQ);
    dd_v mask1_8_2 = _mm256_cmp_pd(_r_lo_1_2, _r_lo_2_2, _CMP_GE_OQ);
    dd_v mask1_8_3 = _mm256_cmp_pd(_r_lo_1_3, _r_lo_2_3, _CMP_GE_OQ);

    dd_v mask2_8_0 = _mm256_cmp_pd(_r_lo_1_0, _r_lo_2_0, _CMP_LE_OQ);
    dd_v mask2_8_1 = _mm256_cmp_pd(_r_lo_1_1, _r_lo_2_1, _CMP_LE_OQ);
    dd_v mask2_8_2 = _mm256_cmp_pd(_r_lo_1_2, _r_lo_2_2, _CMP_LE_OQ);
    dd_v mask2_8_3 = _mm256_cmp_pd(_r_lo_1_3, _r_lo_2_3, _CMP_LE_OQ);

    mask1_8_0 = _mm256_unpacklo_pd(mask1_8_0, mask1_8_0);
    mask1_8_1 = _mm256_unpacklo_pd(mask1_8_1, mask1_8_1);
    mask1_8_2 = _mm256_unpacklo_pd(mask1_8_2, mask1_8_2);
    mask1_8_3 = _mm256_unpacklo_pd(mask1_8_3, mask1_8_3);

    mask2_8_0 = _mm256_unpacklo_pd(mask2_8_0, mask2_8_0);
    mask2_8_1 = _mm256_unpacklo_pd(mask2_8_1, mask2_8_1);
    mask2_8_2 = _mm256_unpacklo_pd(mask2_8_2, mask2_8_2);
    mask2_8_3 = _mm256_unpacklo_pd(mask2_8_3, mask2_8_3);

    dd_v _a_8_0 = _mm256_blendv_pd(minf, _r_lo_1_0, mask1_8_0);
    dd_v _a_8_1 = _mm256_blendv_pd(minf, _r_lo_1_1, mask1_8_1);
    dd_v _a_8_2 = _mm256_blendv_pd(minf, _r_lo_1_2, mask1_8_2);
    dd_v _a_8_3 = _mm256_blendv_pd(minf, _r_lo_1_3, mask1_8_3);

    dd_v _b_8_0 = _mm256_blendv_pd(minf, _r_lo_2_0, mask2_8_0);
    dd_v _b_8_1 = _mm256_blendv_pd(minf, _r_lo_2_1, mask2_8_1);
    dd_v _b_8_2 = _mm256_blendv_pd(minf, _r_lo_2_2, mask2_8_2);
    dd_v _b_8_3 = _mm256_blendv_pd(minf, _r_lo_2_3, mask2_8_3);

    dd_I r_lo_0 = _mm256_max_pd(_a_8_0, _b_8_0);
    dd_I r_lo_1 = _mm256_max_pd(_a_8_1, _b_8_1);
    dd_I r_lo_2 = _mm256_max_pd(_a_8_2, _b_8_2);
    dd_I r_lo_3 = _mm256_max_pd(_a_8_3, _b_8_3);

    /* Reorder result to keep lower bound in the lower half of vectors */
    dd_I c1_0 = _mm256_permute2f128_pd(r_lo_0, r_up_0, 0b00100000);
    dd_I c1_1 = _mm256_permute2f128_pd(r_lo_1, r_up_1, 0b00100000);
    dd_I c1_2 = _mm256_permute2f128_pd(r_lo_2, r_up_2, 0b00100000);
    dd_I c1_3 = _mm256_permute2f128_pd(r_lo_3, r_up_3, 0b00100000);

    dd_I c2_0 = _mm256_permute2f128_pd(r_lo_0, r_up_0, 0b00110001);
    dd_I c2_1 = _mm256_permute2f128_pd(r_lo_1, r_up_1, 0b00110001);
    dd_I c2_2 = _mm256_permute2f128_pd(r_lo_2, r_up_2, 0b00110001);
    dd_I c2_3 = _mm256_permute2f128_pd(r_lo_3, r_up_3, 0b00110001);

    dd_v mask1_9_0 = _mm256_cmp_pd(c1_0, c2_0, _CMP_GE_OQ);
    dd_v mask1_9_1 = _mm256_cmp_pd(c1_1, c2_1, _CMP_GE_OQ);
    dd_v mask1_9_2 = _mm256_cmp_pd(c1_2, c2_2, _CMP_GE_OQ);
    dd_v mask1_9_3 = _mm256_cmp_pd(c1_3, c2_3, _CMP_GE_OQ);

    dd_v mask2_9_0 = _mm256_cmp_pd(c1_0, c2_0, _CMP_LE_OQ);
    dd_v mask2_9_1 = _mm256_cmp_pd(c1_1, c2_1, _CMP_LE_OQ);
    dd_v mask2_9_2 = _mm256_cmp_pd(c1_2, c2_2, _CMP_LE_OQ);
    dd_v mask2_9_3 = _mm256_cmp_pd(c1_3, c2_3, _CMP_LE_OQ);

    mask1_9_0 = _mm256_unpacklo_pd(mask1_9_0, mask1_9_0);
    mask1_9_1 = _mm256_unpacklo_pd(mask1_9_1, mask1_9_1);
    mask1_9_2 = _mm256_unpacklo_pd(mask1_9_2, mask1_9_2);
    mask1_9_3 = _mm256_unpacklo_pd(mask1_9_3, mask1_9_3);

    mask2_9_0 = _mm256_unpacklo_pd(mask2_9_0, mask2_9_0);
    mask2_9_1 = _mm256_unpacklo_pd(mask2_9_1, mask2_9_1);
    mask2_9_2 = _mm256_unpacklo_pd(mask2_9_2, mask2_9_2);
    mask2_9_3 = _mm256_unpacklo_pd(mask2_9_3, mask2_9_3);

    dd_v _a_9_0 = _mm256_blendv_pd(minf, c1_0, mask1_9_0);
    dd_v _a_9_1 = _mm256_blendv_pd(minf, c1_1, mask1_9_1);
    dd_v _a_9_2 = _mm256_blendv_pd(minf, c1_2, mask1_9_2);
    dd_v _a_9_3 = _mm256_blendv_pd(minf, c1_3, mask1_9_3);

    dd_v _b_9_0 = _mm256_blendv_pd(minf, c2_0, mask2_9_0);
    dd_v _b_9_1 = _mm256_blendv_pd(minf, c2_1, mask2_9_1);
    dd_v _b_9_2 = _mm256_blendv_pd(minf, c2_2, mask2_9_2);
    dd_v _b_9_3 = _mm256_blendv_pd(minf, c2_3, mask2_9_3);

    dst.f[0] = _mm256_max_pd(_a_9_0, _b_9_0);
    dst.f[1] = _mm256_max_pd(_a_9_1, _b_9_1);
    dst.f[2] = _mm256_max_pd(_a_9_2, _b_9_2);
    dst.f[3] = _mm256_max_pd(_a_9_3, _b_9_3);

    return dst;
}

inline static ddi_4 f9(ddi_4 a, ddi_4 b) {
    ddi_4 dst;

    __m256d af0 = a.f[0];
    __m256d af1 = a.f[1];
    __m256d af2 = a.f[2];
    __m256d af3 = a.f[3];

    __m256d bf0 = b.f[0];
    __m256d bf1 = b.f[1];
    __m256d bf2 = b.f[2];
    __m256d bf3 = b.f[3];

    __m256d tmpa0 = _mm256_shuffle_pd(af0, af1, 0x0);
    __m256d tmpa1 = _mm256_shuffle_pd(af0, af1, 0xF);
    __m256d tmpa2 = _mm256_shuffle_pd(af2, af3, 0x0);
    __m256d tmpa3 = _mm256_shuffle_pd(af2, af3, 0xF);

    __m256d tmpb0 = _mm256_shuffle_pd(bf0, bf1, 0x0);
    __m256d tmpb1 = _mm256_shuffle_pd(bf0, bf1, 0xF);
    __m256d tmpb2 = _mm256_shuffle_pd(bf2, bf3, 0x0);
    __m256d tmpb3 = _mm256_shuffle_pd(bf2, bf3, 0xF);

    __m256d a_0 = _mm256_permute2f128_pd(tmpa0, tmpa2, 0x20);
    __m256d a_1 = _mm256_permute2f128_pd(tmpa1, tmpa3, 0x20);
    __m256d a_2 = _mm256_permute2f128_pd(tmpa0, tmpa2, 0x31);
    __m256d a_3 = _mm256_permute2f128_pd(tmpa1, tmpa3, 0x31);

    __m256d b_0 = _mm256_permute2f128_pd(tmpb0, tmpb2, 0x20);
    __m256d b_1 = _mm256_permute2f128_pd(tmpb1, tmpb3, 0x20);
    __m256d b_2 = _mm256_permute2f128_pd(tmpb0, tmpb2, 0x31);
    __m256d b_3 = _mm256_permute2f128_pd(tmpb1, tmpb3, 0x31);

    // ===================================================================

    __m256d neg_b_0 = -b_0;
    __m256d neg_b_1 = -b_1;
    __m256d neg_b_2 = -b_2;
    __m256d neg_b_3 = -b_3;

    __m256d s_3_0 = a_0 * b_0;
    __m256d s_3_1 = a_0 * neg_b_2;
    __m256d s_3_2 = a_2 * b_2;
    __m256d s_3_3 = a_2 * neg_b_0;

    __m256d t_3_0 = _mm256_fmsub_pd(a_0, b_0, s_3_0);
    __m256d t_3_1 = _mm256_fmsub_pd(a_0, neg_b_2, s_3_1);
    __m256d t_3_2 = _mm256_fmsub_pd(a_2, b_2, s_3_2);
    __m256d t_3_3 = _mm256_fmsub_pd(a_2, neg_b_0, s_3_3);

    __m256d tl0_0 = a_1 * b_1;
    __m256d tl0_1 = a_1 * neg_b_3;
    __m256d tl0_2 = a_3 * b_3;
    __m256d tl0_3 = a_3 * neg_b_1;

    __m256d tl1_0 = _mm256_fmadd_pd(a_0, b_1, tl0_0);
    __m256d tl1_1 = _mm256_fmadd_pd(a_0, neg_b_3, tl0_1);
    __m256d tl1_2 = _mm256_fmadd_pd(a_2, b_3, tl0_2);
    __m256d tl1_3 = _mm256_fmadd_pd(a_2, neg_b_1, tl0_3);

    __m256d cl2_0 = _mm256_fmadd_pd(a_1, b_0, tl1_0);
    __m256d cl2_1 = _mm256_fmadd_pd(a_1, neg_b_2, tl1_1);
    __m256d cl2_2 = _mm256_fmadd_pd(a_3, b_2, tl1_2);
    __m256d cl2_3 = _mm256_fmadd_pd(a_3, neg_b_0, tl1_3);

    __m256d cl3_0 = t_3_0 + cl2_0;
    __m256d cl3_1 = t_3_1 + cl2_1;
    __m256d cl3_2 = t_3_2 + cl2_2;
    __m256d cl3_3 = t_3_3 + cl2_3;

    __m256d s_4_0 = s_3_0 + cl3_0;
    __m256d s_4_1 = s_3_1 + cl3_1;
    __m256d s_4_2 = s_3_2 + cl3_2;
    __m256d s_4_3 = s_3_3 + cl3_3;

    __m256d z_4_0 = s_4_0 - s_3_0;
    __m256d z_4_1 = s_4_1 - s_3_1;
    __m256d z_4_2 = s_4_2 - s_3_2;
    __m256d z_4_3 = s_4_3 - s_3_3;

    __m256d t_4_0 = cl3_0 - z_4_0;
    __m256d t_4_1 = cl3_1 - z_4_1;
    __m256d t_4_2 = cl3_2 - z_4_2;
    __m256d t_4_3 = cl3_3 - z_4_3;

    __m256d s_5_0 = a_0 * neg_b_0;
    __m256d s_5_1 = a_0 * b_2;
    __m256d s_5_2 = a_2 * neg_b_2;
    __m256d s_5_3 = a_2 * b_0;

    __m256d t_5_0 = _mm256_fmsub_pd(a_0, neg_b_0, s_5_0);
    __m256d t_5_1 = _mm256_fmsub_pd(a_0, b_2, s_5_1);
    __m256d t_5_2 = _mm256_fmsub_pd(a_2, neg_b_2, s_5_2);
    __m256d t_5_3 = _mm256_fmsub_pd(a_2, b_0, s_5_3);

    __m256d tl0_2_0 = a_1 * neg_b_1;
    __m256d tl0_2_1 = a_1 * b_3;
    __m256d tl0_2_2 = a_3 * neg_b_3;
    __m256d tl0_2_3 = a_3 * b_1;

    __m256d tl1_2_0 = _mm256_fmadd_pd(a_0, neg_b_1, tl0_2_0);
    __m256d tl1_2_1 = _mm256_fmadd_pd(a_0, b_3, tl0_2_1);
    __m256d tl1_2_2 = _mm256_fmadd_pd(a_2, neg_b_3, tl0_2_2);
    __m256d tl1_2_3 = _mm256_fmadd_pd(a_2, b_1, tl0_2_3);

    __m256d cl2_2_0 = _mm256_fmadd_pd(a_1, neg_b_0, tl1_2_0);
    __m256d cl2_2_1 = _mm256_fmadd_pd(a_1, b_2, tl1_2_1);
    __m256d cl2_2_2 = _mm256_fmadd_pd(a_3, neg_b_2, tl1_2_2);
    __m256d cl2_2_3 = _mm256_fmadd_pd(a_3, b_0, tl1_2_3);

    __m256d cl3_2_0 = t_5_0 + cl2_2_0;
    __m256d cl3_2_1 = t_5_1 + cl2_2_1;
    __m256d cl3_2_2 = t_5_2 + cl2_2_2;
    __m256d cl3_2_3 = t_5_3 + cl2_2_3;

    __m256d s_6_0 = s_5_0 + cl3_2_0;
    __m256d s_6_1 = s_5_1 + cl3_2_1;
    __m256d s_6_2 = s_5_2 + cl3_2_2;
    __m256d s_6_3 = s_5_3 + cl3_2_3;

    __m256d z_6_0 = s_6_0 - s_5_0;
    __m256d z_6_1 = s_6_1 - s_5_1;
    __m256d z_6_2 = s_6_2 - s_5_2;
    __m256d z_6_3 = s_6_3 - s_5_3;

    __m256d t_6_0 = cl3_2_0 - z_6_0;
    __m256d t_6_1 = cl3_2_1 - z_6_1;
    __m256d t_6_2 = cl3_2_2 - z_6_2;
    __m256d t_6_3 = cl3_2_3 - z_6_3;

    __m256d minf = _mm256_set1_pd(-1.0/0.0);

    __m256d mask17_01 = _mm256_cmp_pd(s_4_0, s_4_1, _CMP_GE_OQ);
    __m256d mask17_23 = _mm256_cmp_pd(s_4_2, s_4_3, _CMP_GE_OQ);
    __m256d mask27_01 = _mm256_cmp_pd(s_4_0, s_4_1, _CMP_LE_OQ);
    __m256d mask27_23 = _mm256_cmp_pd(s_4_2, s_4_3, _CMP_LE_OQ);

    __m256d a7_0 = _mm256_blendv_pd(minf, s_4_0, mask17_01);
    __m256d a7_1 = _mm256_blendv_pd(minf, t_4_0, mask17_01);
    __m256d a7_2 = _mm256_blendv_pd(minf, s_4_2, mask17_23);
    __m256d a7_3 = _mm256_blendv_pd(minf, t_4_2, mask17_23);

    __m256d b7_0 = _mm256_blendv_pd(minf, s_4_1, mask27_01);
    __m256d b7_1 = _mm256_blendv_pd(minf, t_4_1, mask27_01);
    __m256d b7_2 = _mm256_blendv_pd(minf, s_4_3, mask27_23);
    __m256d b7_3 = _mm256_blendv_pd(minf, t_4_3, mask27_23);

    __m256d rup_0 = _mm256_max_pd(a7_0, b7_0);
    __m256d rup_1 = _mm256_max_pd(a7_1, b7_1);
    __m256d rup_2 = _mm256_max_pd(a7_2, b7_2);
    __m256d rup_3 = _mm256_max_pd(a7_3, b7_3);

    __m256d mask18_01 = _mm256_cmp_pd(s_6_0, s_6_1, _CMP_GE_OQ);
    __m256d mask18_23 = _mm256_cmp_pd(s_6_2, s_6_3, _CMP_GE_OQ);
    __m256d mask28_01 = _mm256_cmp_pd(s_6_0, s_6_1, _CMP_LE_OQ);
    __m256d mask28_23 = _mm256_cmp_pd(s_6_2, s_6_3, _CMP_LE_OQ);

    __m256d a8_0 = _mm256_blendv_pd(minf, s_6_0, mask18_01);
    __m256d a8_1 = _mm256_blendv_pd(minf, t_6_0, mask18_01);
    __m256d a8_2 = _mm256_blendv_pd(minf, s_6_2, mask18_23);
    __m256d a8_3 = _mm256_blendv_pd(minf, t_6_2, mask18_23);

    __m256d b8_0 = _mm256_blendv_pd(minf, s_6_1, mask28_01);
    __m256d b8_1 = _mm256_blendv_pd(minf, t_6_1, mask28_01);
    __m256d b8_2 = _mm256_blendv_pd(minf, s_6_3, mask28_23);
    __m256d b8_3 = _mm256_blendv_pd(minf, t_6_3, mask28_23);

    __m256d rlo_0 = _mm256_max_pd(a8_0, b8_0);
    __m256d rlo_1 = _mm256_max_pd(a8_1, b8_1);
    __m256d rlo_2 = _mm256_max_pd(a8_2, b8_2);
    __m256d rlo_3 = _mm256_max_pd(a8_3, b8_3);

    __m256d mask19_01 = _mm256_cmp_pd(rlo_0, rlo_2, _CMP_GE_OQ);
    __m256d mask19_23 = _mm256_cmp_pd(rup_0, rup_2, _CMP_GE_OQ);
    __m256d mask29_01 = _mm256_cmp_pd(rlo_0, rlo_2, _CMP_LE_OQ);
    __m256d mask29_23 = _mm256_cmp_pd(rup_0, rup_2, _CMP_LE_OQ);

    __m256d a9_0 = _mm256_blendv_pd(minf, rlo_0, mask19_01);
    __m256d a9_1 = _mm256_blendv_pd(minf, rlo_1, mask19_01);
    __m256d a9_2 = _mm256_blendv_pd(minf, rup_0, mask19_23);
    __m256d a9_3 = _mm256_blendv_pd(minf, rup_1, mask19_23);

    __m256d b9_0 = _mm256_blendv_pd(minf, rlo_2, mask29_01);
    __m256d b9_1 = _mm256_blendv_pd(minf, rlo_3, mask29_01);
    __m256d b9_2 = _mm256_blendv_pd(minf, rup_2, mask29_23);
    __m256d b9_3 = _mm256_blendv_pd(minf, rup_3, mask29_23);

    __m256d res_0 = _mm256_max_pd(a9_0, b9_0);
    __m256d res_1 = _mm256_max_pd(a9_1, b9_1);
    __m256d res_2 = _mm256_max_pd(a9_2, b9_2);
    __m256d res_3 = _mm256_max_pd(a9_3, b9_3);

    // =================================================================

    __m256d tmpres0 = _mm256_shuffle_pd(res_0, res_1, 0x0);
    __m256d tmpres1 = _mm256_shuffle_pd(res_0, res_1, 0xF);
    __m256d tmpres2 = _mm256_shuffle_pd(res_2, res_3, 0x0);
    __m256d tmpres3 = _mm256_shuffle_pd(res_2, res_3, 0xF);

    __m256d finres_0 = _mm256_permute2f128_pd(tmpres0, tmpres2, 0x20);
    __m256d finres_1 = _mm256_permute2f128_pd(tmpres1, tmpres3, 0x20);
    __m256d finres_2 = _mm256_permute2f128_pd(tmpres0, tmpres2, 0x31);
    __m256d finres_3 = _mm256_permute2f128_pd(tmpres1, tmpres3, 0x31);

    dst.f[0] = finres_0;
    dst.f[1] = finres_1;
    dst.f[2] = finres_2;
    dst.f[3] = finres_3;

    return dst;
}