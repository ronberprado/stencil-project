// Ronber Jonathan T. Prado - G01
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// D:\NASM\nasm -fwin64 asmfunc1.asm

extern void x86stencil(size_t ARRAY_SIZE, int* x, int* y);
extern void SIMDstencil(size_t ARRAY_SIZE, int* x, int* y);

void stencil(size_t size, int* x, int* y) {
    for (int i = 0; i < size; i++) {
        y[i] = x[i - 3] + x[i - 2] + x[i - 1] + x[i] + x[i + 1] + x[i + 2] + x[i + 3];
    }
}

double c_logic(size_t arraySize) {
    const size_t ARRAY_SIZE = arraySize;
    const size_t ARRAY_BYTES = ARRAY_SIZE * sizeof(int);

    //declare array
    int* X, * Y;
    X = (int*)malloc(ARRAY_BYTES);
    Y = (int*)malloc(ARRAY_BYTES);

    // timer variables
    clock_t start, end;

    // array initialize
    for (int i = 0; i < ARRAY_SIZE; i++) {
        X[i] = i + 1;  // initialize 1 to ARRAY_SIZE
        Y[i] = 0;      // initialize 0
    }

    // flush out cache
    stencil(ARRAY_SIZE, X, Y);

    // time here
    start = clock();
    stencil(ARRAY_SIZE, X, Y);
    end = clock();
    double time_taken = ((double)(end - start)) * 1e3 / CLOCKS_PER_SEC;
    // printf("C function will take %f microsecons for array size %zu\n", time_taken, ARRAY_SIZE);

    // error checking
    size_t err_count = 0;
    for (int i = 3; i < 8; i++) {  // check 5 elements only
        if ((X[i - 3] + X[i - 2] + X[i - 1] + X[i] + X[i + 1] + X[i + 2] + X[i + 3]) != Y[i])
            err_count++;
    }
    printf("Error count: %zu |  ", err_count);

    printf("Vector Y: ");
    for (int i = 3; i < 8; i++) {
        printf("%d ", Y[i]);
    }
    printf("\n");

    // free memory
    //free(X);
    //free(Y);

    return time_taken;
}

double x86_logic(size_t arraySize) {
    const size_t ARRAY_SIZE = arraySize;
    const size_t ARRAY_BYTES = ARRAY_SIZE * sizeof(int);

    //declare array
    int* X, * Y;
    X = (int*)malloc(ARRAY_BYTES);
    Y = (int*)malloc(ARRAY_BYTES);

    // timer variables
    clock_t start, end;

    // array initialize
    for (int i = 0; i < ARRAY_SIZE; i++) {
        X[i] = i + 1;  // initialize 1 to ARRAY_SIZE
        Y[i] = 0;      // initialize 0
    }

    // flush out cache
    x86stencil(ARRAY_SIZE, X, Y);

    // time here
    start = clock();
    x86stencil(ARRAY_SIZE, X, Y);
    end = clock();
    double time_taken = ((double)(end - start)) * 1e3 / CLOCKS_PER_SEC;
    // printf("x86 function will take %f microsecons for array size %zu\n", time_taken, ARRAY_SIZE);

    // error checking
    size_t err_count = 0;
    for (int i = 3; i < 8; i++) {  // check 5 elements only
        if ((X[i - 3] + X[i - 2] + X[i - 1] + X[i] + X[i + 1] + X[i + 2] + X[i + 3]) != Y[i])
            err_count++;
    }
    printf("Error count: %zu |  ", err_count);

    printf("Vector Y: ");
    for (int i = 3; i < 8; i++) {
        printf("%d ", Y[i]);
    }
    printf("\n");

    // free memory
    //free(X);
    //free(Y);

    return time_taken;
}

double simd_logic(size_t arraySize) {
    const size_t ARRAY_SIZE = arraySize;
    const size_t ARRAY_BYTES = ARRAY_SIZE * sizeof(int);

    //declare array
    int* X, * Y;
    X = (int*)malloc(ARRAY_BYTES);
    Y = (int*)malloc(ARRAY_BYTES);

    // timer variables
    clock_t start, end;

    // array initialize
    for (int i = 0; i < ARRAY_SIZE; i++) {
        X[i] = i + 1;  // initialize 1 to ARRAY_SIZE
        Y[i] = 0;      // initialize 0
    }

    // flush out cache
    SIMDstencil(ARRAY_SIZE, X, Y);

    // time here
    start = clock();
    SIMDstencil(ARRAY_SIZE, X, Y);
    end = clock();
    double time_taken = ((double)(end - start)) * 1e3 / CLOCKS_PER_SEC;
    // printf("SIMD function will take %f microsecons for array size %zu\n", time_taken, ARRAY_SIZE);

    // error checking
    size_t err_count = 0;
    for (int i = 3; i < 8; i++) {  // check 5 elements only
        if ((X[i - 3] + X[i - 2] + X[i - 1] + X[i] + X[i + 1] + X[i + 2] + X[i + 3]) != Y[i])
            err_count++;
    }
    printf("Error count: %zu |  ", err_count);

    printf("Vector Y: ");
    for (int i = 3; i < 8; i++) {
        printf("%d ", Y[i]);
    }
    printf("\n");

    // free memory
    //free(X);
    //free(Y);

    return time_taken;
}

void c_print(size_t arraySize) {
    const size_t array_size = arraySize;
    int numberOfRuns = 30;
    double c_time_results[30];
    double c_total_result = 0;

    printf("C PROGRAM\n");
    for (int i = 0; i < numberOfRuns; i++) {
        printf("Run %d: ", i + 1);
        c_time_results[i] = c_logic(array_size);
        c_total_result += c_time_results[i];
    }

    printf("\nRun results (%d runs):\n", numberOfRuns);
    for (int i = 0; i < numberOfRuns; i++)
        printf("Run %d - %f\n", i + 1, c_time_results[i]);

    double c_aveResult = c_total_result / numberOfRuns;
    printf("The C average run time result (%d runs) for array size of %zu is %f microseconds\n",
        numberOfRuns, array_size, c_aveResult);
}

void x86_print(size_t arraySize) {
    const size_t array_size = arraySize;
    int numberOfRuns = 30;
    double x86_time_results[30];
    double x86_total_result = 0;

    printf("x86-64 PROGRAM\n");
    for (int i = 0; i < numberOfRuns; i++) {
        printf("Run %d: ", i + 1);
        x86_time_results[i] = x86_logic(array_size);
        x86_total_result += x86_time_results[i];
    }

    printf("\nRun results (%d runs):\n", numberOfRuns);
    for (int i = 0; i < numberOfRuns; i++)
        printf("Run %d - %f\n", i + 1, x86_time_results[i]);

    double x86_aveResult = x86_total_result / numberOfRuns;
    printf("The x86-64 average run time result (%d runs) for array size of %zu is %f microseconds\n",
        numberOfRuns, array_size, x86_aveResult);
}

void simd_print(size_t arraySize) {
    const size_t array_size = arraySize;
    int numberOfRuns = 30;
    double simd_time_results[30];
    double simd_total_result = 0;

    printf("x86 SIMD PROGRAM\n");
    for (int i = 0; i < numberOfRuns; i++) {
        printf("Run %d: ", i + 1);
        simd_time_results[i] = simd_logic(array_size);
        simd_total_result += simd_time_results[i];
    }

    printf("\nRun results (%d runs):\n", numberOfRuns);
    for (int i = 0; i < numberOfRuns; i++)
        printf("Run %d - %f\n", i + 1, simd_time_results[i]);

    double simd_aveResult = simd_total_result / numberOfRuns;
    printf("The x86 SIMD average run time result (%d runs) for array size of %zu is %f microseconds\n",
        numberOfRuns, array_size, simd_aveResult);
}

int main() {
    const size_t size_20 = 1 << 20;
    const size_t size_24 = 1 << 24;
    const size_t size_28 = 1 << 28;

    c_print(size_20);
    //c_print(size_24);
    //c_print(size_28);

    //x86_print(size_20);
    //x86_print(size_24);
    //x86_print(size_28);

    //simd_print(size_20);
    //simd_print(size_24);
    //simd_print(size_28);

    return 0;
}
