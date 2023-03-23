//
// Created by Raz_Z and Gal_V on 3/23/2023.
//
#include "osm.h"
#include <ctime>
#include <sys/time.h>
#define UNROOL 9
#define MSFACTOR 1e3
#define NSFACTOR 1e9
#define ONE 1

double calc_res(timeval* start, timeval* end, int iterations){
    unsigned int sec_diff = (end->tv_sec - start->tv_sec) * NSFACTOR;
    int msec_dff = (end->tv_usec - start->tv_usec) * MSFACTOR;
    return (sec_diff + msec_dff) / (double) (iterations * UNROOL);
}


double osm_operation_time(unsigned int iterations)
{
    timeval *tv_start = new timeval;
    timeval *tv_end = new timeval;
    std::time_t now = std::time(nullptr);
    struct tm local = *std::localtime(&now);
    gettimeofday (tv_start, &local);
    int num = 0;
    for (unsigned int i = 0; i<iterations; i++){
        num + ONE;num + ONE;num + ONE;
        num + ONE;num + ONE;num + ONE;
        num + ONE;num + ONE;num + ONE;
    }
    gettimeofday (tv_end, &local);
    return calc_res(tv_start, tv_end, iterations);
}

void empty_function(){}

double osm_function_time(unsigned int iterations)
{
    timeval *tv_start = new timeval;
    timeval *tv_end = new timeval;
    std::time_t now = std::time(nullptr);
    struct tm local = *std::localtime(&now);
    gettimeofday (tv_start, &local);
    for (unsigned int i = 0; i<iterations; i++){
        empty_function();empty_function();empty_function();
        empty_function();empty_function();empty_function();
        empty_function();empty_function();empty_function();
    }
    gettimeofday (tv_end, &local);
    return calc_res(tv_start, tv_end, iterations);
}

double osm_syscall_time(unsigned int iterations)
{
    timeval *tv_start = new timeval;
    timeval *tv_end = new timeval;
    std::time_t now = std::time(nullptr);
    struct tm local = *std::localtime(&now);
    gettimeofday (tv_start, &local);
    for (unsigned int i = 0; i<iterations; i++){
        OSM_NULLSYSCALL;
    }
    gettimeofday (tv_end, &local);
    return calc_res(tv_start, tv_end, iterations);
}


