//
// Created by Raz_Z on 3/23/2023.
//
#include <iostream>
#include "osm.h"
#define ITER 1e9

int main(){
    double one_operation_time = osm_operation_time(ITER);
    double empty_func_call_time= osm_function_time(ITER);
    double trap_time= osm_syscall_time(ITER);

    std::cout <<  "arithmetic op: " << one_operation_time << std::endl;
    std::cout << "empty func: " << empty_func_call_time << std::endl;
    std::cout << "trap: " << trap_time << std::endl;

    return 0;
};

