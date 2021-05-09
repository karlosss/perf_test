#include "common.h"
#include "funs.h"

ddi_4 ddi40, ddi41, ddi42, ddi43, ddi44, ddi45, ddi46, ddi47, ddi48, ddi49, ddi410, ddi411, ddi412;

static void f1_lat() {
    for(int i = 0; i < BENCHMARK_ITER; ++i){
        ddi40 = f1(ddi40, ddi41);
        ddi40 = f1(ddi40, ddi42);
        ddi40 = f1(ddi40, ddi41);
        ddi40 = f1(ddi40, ddi42);
        ddi40 = f1(ddi40, ddi41);
        ddi40 = f1(ddi40, ddi42);
        ddi40 = f1(ddi40, ddi41);
        ddi40 = f1(ddi40, ddi42);
        ddi40 = f1(ddi40, ddi41);
        ddi40 = f1(ddi40, ddi42);
        ddi40 = f1(ddi40, ddi41);
        ddi40 = f1(ddi40, ddi42);
        ddi40 = f1(ddi40, ddi41);
        ddi40 = f1(ddi40, ddi42);
        ddi40 = f1(ddi40, ddi41);
        ddi40 = f1(ddi40, ddi42);
    }
    out_ddi4[0] = ddi40;
}

static void f1_gap() {
    for(int i = 0; i < BENCHMARK_ITER; ++i){
        ddi41 = f1(ddi41, ddi40);
        ddi42 = f1(ddi42, ddi40);
        ddi43 = f1(ddi43, ddi40);
        ddi44 = f1(ddi44, ddi40);

        ddi45 = f1(ddi45, ddi40);
        ddi46 = f1(ddi46, ddi40);
        ddi47 = f1(ddi47, ddi40);
        ddi48 = f1(ddi48, ddi40);

        ddi49 = f1(ddi49, ddi40);
        ddi410 = f1(ddi410, ddi40);
        ddi411 = f1(ddi411, ddi40);
        ddi412 = f1(ddi412, ddi40);
    }
    out_ddi4[1] = ddi41;
    out_ddi4[2] = ddi42;
    out_ddi4[3] = ddi43;
    out_ddi4[4] = ddi44;
    out_ddi4[5] = ddi45;
    out_ddi4[6] = ddi46;
    out_ddi4[7] = ddi47;
    out_ddi4[8] = ddi48;
    out_ddi4[9] = ddi49;
    out_ddi4[10] = ddi410;
    out_ddi4[11] = ddi411;
    out_ddi4[12] = ddi412;
}

static void f2_lat() {
    for(int i = 0; i < BENCHMARK_ITER; ++i){
        ddi40 = f2(ddi40, ddi41);
        ddi40 = f2(ddi40, ddi42);
        ddi40 = f2(ddi40, ddi41);
        ddi40 = f2(ddi40, ddi42);
        ddi40 = f2(ddi40, ddi41);
        ddi40 = f2(ddi40, ddi42);
        ddi40 = f2(ddi40, ddi41);
        ddi40 = f2(ddi40, ddi42);
        ddi40 = f2(ddi40, ddi41);
        ddi40 = f2(ddi40, ddi42);
        ddi40 = f2(ddi40, ddi41);
        ddi40 = f2(ddi40, ddi42);
        ddi40 = f2(ddi40, ddi41);
        ddi40 = f2(ddi40, ddi42);
        ddi40 = f2(ddi40, ddi41);
        ddi40 = f2(ddi40, ddi42);
    }
    out_ddi4[0] = ddi40;
}

static void f2_gap() {
    for(int i = 0; i < BENCHMARK_ITER; ++i){
        ddi41 = f2(ddi41, ddi40);
        ddi42 = f2(ddi42, ddi40);
        ddi43 = f2(ddi43, ddi40);
        ddi44 = f2(ddi44, ddi40);

        ddi45 = f2(ddi45, ddi40);
        ddi46 = f2(ddi46, ddi40);
        ddi47 = f2(ddi47, ddi40);
        ddi48 = f2(ddi48, ddi40);

        ddi49 = f2(ddi49, ddi40);
        ddi410 = f2(ddi410, ddi40);
        ddi411 = f2(ddi411, ddi40);
        ddi412 = f2(ddi412, ddi40);
    }
    out_ddi4[1] = ddi41;
    out_ddi4[2] = ddi42;
    out_ddi4[3] = ddi43;
    out_ddi4[4] = ddi44;
    out_ddi4[5] = ddi45;
    out_ddi4[6] = ddi46;
    out_ddi4[7] = ddi47;
    out_ddi4[8] = ddi48;
    out_ddi4[9] = ddi49;
    out_ddi4[10] = ddi410;
    out_ddi4[11] = ddi411;
    out_ddi4[12] = ddi412;
}

static void f3_lat() {
    for(int i = 0; i < BENCHMARK_ITER; ++i){
        ddi40 = f3(ddi40, ddi41);
        ddi40 = f3(ddi40, ddi42);
        ddi40 = f3(ddi40, ddi41);
        ddi40 = f3(ddi40, ddi42);
        ddi40 = f3(ddi40, ddi41);
        ddi40 = f3(ddi40, ddi42);
        ddi40 = f3(ddi40, ddi41);
        ddi40 = f3(ddi40, ddi42);
        ddi40 = f3(ddi40, ddi41);
        ddi40 = f3(ddi40, ddi42);
        ddi40 = f3(ddi40, ddi41);
        ddi40 = f3(ddi40, ddi42);
        ddi40 = f3(ddi40, ddi41);
        ddi40 = f3(ddi40, ddi42);
        ddi40 = f3(ddi40, ddi41);
        ddi40 = f3(ddi40, ddi42);
    }
    out_ddi4[0] = ddi40;
}

static void f3_gap() {
    for(int i = 0; i < BENCHMARK_ITER; ++i){
        ddi41 = f3(ddi41, ddi40);
        ddi42 = f3(ddi42, ddi40);
        ddi43 = f3(ddi43, ddi40);
        ddi44 = f3(ddi44, ddi40);

        ddi45 = f3(ddi45, ddi40);
        ddi46 = f3(ddi46, ddi40);
        ddi47 = f3(ddi47, ddi40);
        ddi48 = f3(ddi48, ddi40);

        ddi49 = f3(ddi49, ddi40);
        ddi410 = f3(ddi410, ddi40);
        ddi411 = f3(ddi411, ddi40);
        ddi412 = f3(ddi412, ddi40);
    }
    out_ddi4[1] = ddi41;
    out_ddi4[2] = ddi42;
    out_ddi4[3] = ddi43;
    out_ddi4[4] = ddi44;
    out_ddi4[5] = ddi45;
    out_ddi4[6] = ddi46;
    out_ddi4[7] = ddi47;
    out_ddi4[8] = ddi48;
    out_ddi4[9] = ddi49;
    out_ddi4[10] = ddi410;
    out_ddi4[11] = ddi411;
    out_ddi4[12] = ddi412;
}

static void f4_lat() {
    for(int i = 0; i < BENCHMARK_ITER; ++i){
        ddi40 = f4(ddi40, ddi41);
        ddi40 = f4(ddi40, ddi42);
        ddi40 = f4(ddi40, ddi41);
        ddi40 = f4(ddi40, ddi42);
        ddi40 = f4(ddi40, ddi41);
        ddi40 = f4(ddi40, ddi42);
        ddi40 = f4(ddi40, ddi41);
        ddi40 = f4(ddi40, ddi42);
        ddi40 = f4(ddi40, ddi41);
        ddi40 = f4(ddi40, ddi42);
        ddi40 = f4(ddi40, ddi41);
        ddi40 = f4(ddi40, ddi42);
        ddi40 = f4(ddi40, ddi41);
        ddi40 = f4(ddi40, ddi42);
        ddi40 = f4(ddi40, ddi41);
        ddi40 = f4(ddi40, ddi42);
    }
    out_ddi4[0] = ddi40;
}

static void f4_gap() {
    for(int i = 0; i < BENCHMARK_ITER; ++i){
        ddi41 = f4(ddi41, ddi40);
        ddi42 = f4(ddi42, ddi40);
        ddi43 = f4(ddi43, ddi40);
        ddi44 = f4(ddi44, ddi40);

        ddi45 = f4(ddi45, ddi40);
        ddi46 = f4(ddi46, ddi40);
        ddi47 = f4(ddi47, ddi40);
        ddi48 = f4(ddi48, ddi40);

        ddi49 = f4(ddi49, ddi40);
        ddi410 = f4(ddi410, ddi40);
        ddi411 = f4(ddi411, ddi40);
        ddi412 = f4(ddi412, ddi40);
    }
    out_ddi4[1] = ddi41;
    out_ddi4[2] = ddi42;
    out_ddi4[3] = ddi43;
    out_ddi4[4] = ddi44;
    out_ddi4[5] = ddi45;
    out_ddi4[6] = ddi46;
    out_ddi4[7] = ddi47;
    out_ddi4[8] = ddi48;
    out_ddi4[9] = ddi49;
    out_ddi4[10] = ddi410;
    out_ddi4[11] = ddi411;
    out_ddi4[12] = ddi412;
}

static void f5_lat() {
    for(int i = 0; i < BENCHMARK_ITER; ++i){
        ddi40 = f5(ddi40, ddi41);
        ddi40 = f5(ddi40, ddi42);
        ddi40 = f5(ddi40, ddi41);
        ddi40 = f5(ddi40, ddi42);
        ddi40 = f5(ddi40, ddi41);
        ddi40 = f5(ddi40, ddi42);
        ddi40 = f5(ddi40, ddi41);
        ddi40 = f5(ddi40, ddi42);
        ddi40 = f5(ddi40, ddi41);
        ddi40 = f5(ddi40, ddi42);
        ddi40 = f5(ddi40, ddi41);
        ddi40 = f5(ddi40, ddi42);
        ddi40 = f5(ddi40, ddi41);
        ddi40 = f5(ddi40, ddi42);
        ddi40 = f5(ddi40, ddi41);
        ddi40 = f5(ddi40, ddi42);
    }
    out_ddi4[0] = ddi40;
}

static void f5_gap() {
    for(int i = 0; i < BENCHMARK_ITER; ++i){
        ddi41 = f5(ddi41, ddi40);
        ddi42 = f5(ddi42, ddi40);
        ddi43 = f5(ddi43, ddi40);
        ddi44 = f5(ddi44, ddi40);

        ddi45 = f5(ddi45, ddi40);
        ddi46 = f5(ddi46, ddi40);
        ddi47 = f5(ddi47, ddi40);
        ddi48 = f5(ddi48, ddi40);

        ddi49 = f5(ddi49, ddi40);
        ddi410 = f5(ddi410, ddi40);
        ddi411 = f5(ddi411, ddi40);
        ddi412 = f5(ddi412, ddi40);
    }
    out_ddi4[1] = ddi41;
    out_ddi4[2] = ddi42;
    out_ddi4[3] = ddi43;
    out_ddi4[4] = ddi44;
    out_ddi4[5] = ddi45;
    out_ddi4[6] = ddi46;
    out_ddi4[7] = ddi47;
    out_ddi4[8] = ddi48;
    out_ddi4[9] = ddi49;
    out_ddi4[10] = ddi410;
    out_ddi4[11] = ddi411;
    out_ddi4[12] = ddi412;
}

static void f6_lat() {
    for(int i = 0; i < BENCHMARK_ITER; ++i){
        ddi40 = f6(ddi40, ddi41);
        ddi40 = f6(ddi40, ddi42);
        ddi40 = f6(ddi40, ddi41);
        ddi40 = f6(ddi40, ddi42);
        ddi40 = f6(ddi40, ddi41);
        ddi40 = f6(ddi40, ddi42);
        ddi40 = f6(ddi40, ddi41);
        ddi40 = f6(ddi40, ddi42);
        ddi40 = f6(ddi40, ddi41);
        ddi40 = f6(ddi40, ddi42);
        ddi40 = f6(ddi40, ddi41);
        ddi40 = f6(ddi40, ddi42);
        ddi40 = f6(ddi40, ddi41);
        ddi40 = f6(ddi40, ddi42);
        ddi40 = f6(ddi40, ddi41);
        ddi40 = f6(ddi40, ddi42);
    }
    out_ddi4[0] = ddi40;
}

static void f6_gap() {
    for(int i = 0; i < BENCHMARK_ITER; ++i){
        ddi41 = f6(ddi41, ddi40);
        ddi42 = f6(ddi42, ddi40);
        ddi43 = f6(ddi43, ddi40);
        ddi44 = f6(ddi44, ddi40);

        ddi45 = f6(ddi45, ddi40);
        ddi46 = f6(ddi46, ddi40);
        ddi47 = f6(ddi47, ddi40);
        ddi48 = f6(ddi48, ddi40);

        ddi49 = f6(ddi49, ddi40);
        ddi410 = f6(ddi410, ddi40);
        ddi411 = f6(ddi411, ddi40);
        ddi412 = f6(ddi412, ddi40);
    }
    out_ddi4[1] = ddi41;
    out_ddi4[2] = ddi42;
    out_ddi4[3] = ddi43;
    out_ddi4[4] = ddi44;
    out_ddi4[5] = ddi45;
    out_ddi4[6] = ddi46;
    out_ddi4[7] = ddi47;
    out_ddi4[8] = ddi48;
    out_ddi4[9] = ddi49;
    out_ddi4[10] = ddi410;
    out_ddi4[11] = ddi411;
    out_ddi4[12] = ddi412;
}

static void f7_lat() {
    for(int i = 0; i < BENCHMARK_ITER; ++i){
        ddi40 = f7(ddi40, ddi41);
        ddi40 = f7(ddi40, ddi42);
        ddi40 = f7(ddi40, ddi41);
        ddi40 = f7(ddi40, ddi42);
        ddi40 = f7(ddi40, ddi41);
        ddi40 = f7(ddi40, ddi42);
        ddi40 = f7(ddi40, ddi41);
        ddi40 = f7(ddi40, ddi42);
        ddi40 = f7(ddi40, ddi41);
        ddi40 = f7(ddi40, ddi42);
        ddi40 = f7(ddi40, ddi41);
        ddi40 = f7(ddi40, ddi42);
        ddi40 = f7(ddi40, ddi41);
        ddi40 = f7(ddi40, ddi42);
        ddi40 = f7(ddi40, ddi41);
        ddi40 = f7(ddi40, ddi42);
    }
    out_ddi4[0] = ddi40;
}

static void f7_gap() {
    for(int i = 0; i < BENCHMARK_ITER; ++i){
        ddi41 = f7(ddi41, ddi40);
        ddi42 = f7(ddi42, ddi40);
        ddi43 = f7(ddi43, ddi40);
        ddi44 = f7(ddi44, ddi40);

        ddi45 = f7(ddi45, ddi40);
        ddi46 = f7(ddi46, ddi40);
        ddi47 = f7(ddi47, ddi40);
        ddi48 = f7(ddi48, ddi40);

        ddi49 = f7(ddi49, ddi40);
        ddi410 = f7(ddi410, ddi40);
        ddi411 = f7(ddi411, ddi40);
        ddi412 = f7(ddi412, ddi40);
    }
    out_ddi4[1] = ddi41;
    out_ddi4[2] = ddi42;
    out_ddi4[3] = ddi43;
    out_ddi4[4] = ddi44;
    out_ddi4[5] = ddi45;
    out_ddi4[6] = ddi46;
    out_ddi4[7] = ddi47;
    out_ddi4[8] = ddi48;
    out_ddi4[9] = ddi49;
    out_ddi4[10] = ddi410;
    out_ddi4[11] = ddi411;
    out_ddi4[12] = ddi412;
}

static void f8_lat() {
    for(int i = 0; i < BENCHMARK_ITER; ++i){
        ddi40 = f8(ddi40, ddi41);
        ddi40 = f8(ddi40, ddi42);
        ddi40 = f8(ddi40, ddi41);
        ddi40 = f8(ddi40, ddi42);
        ddi40 = f8(ddi40, ddi41);
        ddi40 = f8(ddi40, ddi42);
        ddi40 = f8(ddi40, ddi41);
        ddi40 = f8(ddi40, ddi42);
        ddi40 = f8(ddi40, ddi41);
        ddi40 = f8(ddi40, ddi42);
        ddi40 = f8(ddi40, ddi41);
        ddi40 = f8(ddi40, ddi42);
        ddi40 = f8(ddi40, ddi41);
        ddi40 = f8(ddi40, ddi42);
        ddi40 = f8(ddi40, ddi41);
        ddi40 = f8(ddi40, ddi42);
    }
    out_ddi4[0] = ddi40;
}

static void f8_gap() {
    for(int i = 0; i < BENCHMARK_ITER; ++i){
        ddi41 = f8(ddi41, ddi40);
        ddi42 = f8(ddi42, ddi40);
        ddi43 = f8(ddi43, ddi40);
        ddi44 = f8(ddi44, ddi40);

        ddi45 = f8(ddi45, ddi40);
        ddi46 = f8(ddi46, ddi40);
        ddi47 = f8(ddi47, ddi40);
        ddi48 = f8(ddi48, ddi40);

        ddi49 = f8(ddi49, ddi40);
        ddi410 = f8(ddi410, ddi40);
        ddi411 = f8(ddi411, ddi40);
        ddi412 = f8(ddi412, ddi40);
    }
    out_ddi4[1] = ddi41;
    out_ddi4[2] = ddi42;
    out_ddi4[3] = ddi43;
    out_ddi4[4] = ddi44;
    out_ddi4[5] = ddi45;
    out_ddi4[6] = ddi46;
    out_ddi4[7] = ddi47;
    out_ddi4[8] = ddi48;
    out_ddi4[9] = ddi49;
    out_ddi4[10] = ddi410;
    out_ddi4[11] = ddi411;
    out_ddi4[12] = ddi412;
}

static void f9_lat() {
    for(int i = 0; i < BENCHMARK_ITER; ++i){
        ddi40 = f9(ddi40, ddi41);
        ddi40 = f9(ddi40, ddi42);
        ddi40 = f9(ddi40, ddi41);
        ddi40 = f9(ddi40, ddi42);
        ddi40 = f9(ddi40, ddi41);
        ddi40 = f9(ddi40, ddi42);
        ddi40 = f9(ddi40, ddi41);
        ddi40 = f9(ddi40, ddi42);
        ddi40 = f9(ddi40, ddi41);
        ddi40 = f9(ddi40, ddi42);
        ddi40 = f9(ddi40, ddi41);
        ddi40 = f9(ddi40, ddi42);
        ddi40 = f9(ddi40, ddi41);
        ddi40 = f9(ddi40, ddi42);
        ddi40 = f9(ddi40, ddi41);
        ddi40 = f9(ddi40, ddi42);
    }
    out_ddi4[0] = ddi40;
}

static void f9_gap() {
    for(int i = 0; i < BENCHMARK_ITER; ++i){
        ddi41 = f9(ddi41, ddi40);
        ddi42 = f9(ddi42, ddi40);
        ddi43 = f9(ddi43, ddi40);
        ddi44 = f9(ddi44, ddi40);

        ddi45 = f9(ddi45, ddi40);
        ddi46 = f9(ddi46, ddi40);
        ddi47 = f9(ddi47, ddi40);
        ddi48 = f9(ddi48, ddi40);

        ddi49 = f9(ddi49, ddi40);
        ddi410 = f9(ddi410, ddi40);
        ddi411 = f9(ddi411, ddi40);
        ddi412 = f9(ddi412, ddi40);
    }
    out_ddi4[1] = ddi41;
    out_ddi4[2] = ddi42;
    out_ddi4[3] = ddi43;
    out_ddi4[4] = ddi44;
    out_ddi4[5] = ddi45;
    out_ddi4[6] = ddi46;
    out_ddi4[7] = ddi47;
    out_ddi4[8] = ddi48;
    out_ddi4[9] = ddi49;
    out_ddi4[10] = ddi410;
    out_ddi4[11] = ddi411;
    out_ddi4[12] = ddi412;
}