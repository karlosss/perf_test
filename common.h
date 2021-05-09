#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <xmmintrin.h>
#include <immintrin.h>

#define LEN 1024
#define BENCHMARK_ITER 5000

using namespace std;

typedef __m256d dd_v;
typedef __m256d dd_I;

typedef struct {
    __m256d f[4];
} ddi_4;

typedef struct {
    string name;
    void (*fn)();
    double ops;
} fn_t;

extern ddi_4* in_ddi4;
extern ddi_4* out_ddi4;
extern ddi_4 ddi40, ddi41, ddi42, ddi43, ddi44, ddi45, ddi46, ddi47, ddi48, ddi49, ddi410, ddi411, ddi412;

extern vector<fn_t> functions;

void benchmark();
void init();

static void register_functions();
