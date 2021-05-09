#pragma once

#include "common.h"
#include "random_range.h"
#include "bench_funs.h"

ddi_4* in_ddi4 = (ddi_4*) aligned_alloc(32, LEN*sizeof(ddi_4));
ddi_4* out_ddi4 = (ddi_4*) aligned_alloc(32, LEN*sizeof(ddi_4));
vector<fn_t> functions;

void add_function(string name, void (*fn)(), double ops) {
    fn_t f;
    f.name = name;
    f.fn = fn;
    f.ops = ops;
    functions.push_back(f);
}

void init() {
    for(int i = 0; i < LEN; ++i) {
        for(int j = 0; j < 4; ++j) {
            in_ddi4[i].f[j] = getRandomDDI();
        }
    }

    register_functions();
}

void register_functions() {
//    add_function("f1_lat", f1_lat, 16);
//    add_function("f1_gap", f1_gap, 12);
//    add_function("f2_lat", f2_lat, 16);
//    add_function("f2_gap", f2_gap, 12);
//    add_function("f3_lat", f3_lat, 16);
//    add_function("f3_gap", f3_gap, 12);
//    add_function("f4_lat", f4_lat, 16);
//    add_function("f4_gap", f4_gap, 12);
//    add_function("f5_lat", f5_lat, 16);
//    add_function("f5_gap", f5_gap, 12);
//    add_function("f6_lat", f6_lat, 16);
//    add_function("f6_gap", f6_gap, 12);
//    add_function("f7_lat", f7_lat, 16);
//    add_function("f7_gap", f7_gap, 12);
//    add_function("f8_lat", f8_lat, 16);
//    add_function("f8_gap", f8_gap, 12);
    add_function("f9_lat", f9_lat, 16);
    add_function("f9_gap", f9_gap, 12);
}
