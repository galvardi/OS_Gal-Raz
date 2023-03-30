//
// Created by Raz_Z and Gal_V on 3/23/2023.
//
#include "osm.h"
#include <ctime>
#include <sys/time.h>
// Unrolling factor
#define UNROOL 9
// factor from milliseconds to nanoseconds
#define MSFACTOR 1e3
// factor from seconds to nanoseconds
#define NSFACTOR 1e9
// operation to be preformed for timing
#define OPERATION num++

double calc_res(timeval* start, timeval* end, unsigned long iterations){
    long long sec_diff = (end->tv_sec - start->tv_sec) * NSFACTOR;
    long long msec_dff = (end->tv_usec - start->tv_usec) * MSFACTOR;
    return (long double) (sec_diff + msec_dff) / ((long long) iterations *
    UNROOL);
}

double osm_operation_time(unsigned int iterations)
{
    struct timeval tv_start{}, tv_end{};
    if (gettimeofday (&tv_start, nullptr) == -1){
        return -1;
    }
    int num = 0;
    for (unsigned int i = 0; i<iterations; i++){
        OPERATION;OPERATION;OPERATION;
        OPERATION;OPERATION;OPERATION;
        OPERATION;OPERATION;OPERATION;
    }
    if (gettimeofday (&tv_end, nullptr) == -1){
        return -1;
    }
    return calc_res(&tv_start, &tv_end, iterations);
}

void empty_function(){}

double osm_function_time(unsigned int iterations)
{
    struct timeval tv_start{}, tv_end{};
    if (gettimeofday (&tv_start, nullptr) == -1){
        return -1;
    }
    for (unsigned int i = 0; i<iterations; i++){
        empty_function();empty_function();empty_function();
        empty_function();empty_function();empty_function();
        empty_function();empty_function();empty_function();
    }
    if (gettimeofday (&tv_end, nullptr) == -1){
        return -1;
    }
    return calc_res(&tv_start, &tv_end, iterations);
}

double osm_syscall_time(unsigned int iterations)
{
    struct timeval tv_start{}, tv_end{};
    if (gettimeofday (&tv_start, nullptr) == -1){
        return -1;
    }
    for (unsigned int i = 0; i<iterations; i++){
        OSM_NULLSYSCALL;
    }
    if (gettimeofday (&tv_end, nullptr) == -1){
        return -1;
    }
    return calc_res(&tv_start, &tv_end, iterations);
}


