//
// Created by Raz_Z and Gal_V on 3/23/2023.
//
#include "osm.h"
#include <ctime>
#include <sys/time.h>
#define UNROOL 9
#define MSFACTOR 1000
#define ONE 1

double osm_operation_time(unsigned int iterations)
{
    timeval *tv_start = new timeval;
    timeval *tv_end = new timeval;
    std::time_t now = std::time(nullptr);
    struct tm local = *std::localtime(&now);
    gettimeofday (tv_start, &local);
    int num = 0;
    for (int i = 0; i<iterations; i++){
        num + ONE;num + ONE;num + ONE;
        num + ONE;num + ONE;num + ONE;
        num + ONE;num + ONE;num + ONE;
    }
    gettimeofday (tv_end, &local);
    int res  = tv_end->tv_usec - tv_start->tv_usec;
    return (res * MSFACTOR) / (double) (UNROOL*iterations);
}

void empty_function(){}

double osm_function_time(unsigned int iterations)
{
    timeval *tv_start = new timeval;
    timeval *tv_end = new timeval;
    std::time_t now = std::time(nullptr);
    struct tm local = *std::localtime(&now);
    gettimeofday (tv_start, &local);
    for (int i = 0; i<iterations; i++){
        empty_function();empty_function();empty_function();
        empty_function();empty_function();empty_function();
        empty_function();empty_function();empty_function();
    }
    gettimeofday (tv_end, &local);
    int res  = tv_end->tv_usec - tv_start->tv_usec;
    return (res * MSFACTOR) / (double) (UNROOL*iterations);
}

double osm_syscall_time(unsigned int iterations)
{
    timeval *tv_start = new timeval;
    timeval *tv_end = new timeval;
    std::time_t now = std::time(nullptr);
    struct tm local = *std::localtime(&now);
    gettimeofday (tv_start, &local);
    for (int i = 0; i<iterations; i++){
        OSM_NULLSYSCALL;
    }
    gettimeofday (tv_end, &local);
    int res  = tv_end->tv_usec - tv_start->tv_usec;
    return (res * MSFACTOR) / (double) (UNROOL*iterations);
}


