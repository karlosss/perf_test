#pragma once

#include "common.h"
#include "tsc_x86.h"

#define WARMUP_ITER 3000

void set_globals() {
    ddi40 = in_ddi4[0];
    ddi41 = in_ddi4[1];
    ddi42 = in_ddi4[2];
    ddi43 = in_ddi4[3];
    ddi44 = in_ddi4[4];
    ddi45 = in_ddi4[5];
    ddi46 = in_ddi4[6];
    ddi47 = in_ddi4[7];
    ddi48 = in_ddi4[8];
    ddi49 = in_ddi4[9];
    ddi410 = in_ddi4[10];
    ddi411 = in_ddi4[11];
    ddi412 = in_ddi4[12];
}

double benchFun(void (*fn)()) {
    myInt64 start, end;

    for(int i = 0; i < WARMUP_ITER; ++i){
        fn();
    }

    start = start_tsc();
    fn();
    end = stop_tsc(start);

    return end;
}

void benchmark() {
    for(int i = 0; i < functions.size(); ++i) {
        set_globals();
        cout << functions[i].name << " " << benchFun(functions[i].fn) / functions[i].ops / BENCHMARK_ITER << " cycles" << endl;
    }
}
