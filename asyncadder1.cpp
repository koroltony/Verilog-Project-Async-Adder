#include "asyncadder.h"
#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <stdio.h>

asyncadder *top = NULL;
vluint64_t main_time = 0;

double sc_time_stamp () {
    return main_time;
}

bool test = true;
int main(int argc, char** argv, char** env){
    top = new asyncadder;

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    top->trace(m_trace, 5);
    m_trace->open("waveform1.vcd");

    top->a = 0;
    top->b = 0;

    printf("time a b y\r\n");


while (!Verilated::gotFinish()){
    if (main_time <= 30){
        top->a = rand() % 255;
        top->b = rand() % 255;
    }
    else {
        top->a = rand() % 255;
        top->b = -4;
    }
    top->eval();
    m_trace->dump(main_time);

    if (top->y==top->a+top->b){
        test = true;
    }
    else {
        test = false;
    }

    printf("%5ld %3d %3d %4d %s\r\n",main_time,top->a,top->b,top->y,test ? "true" : "false");

    if (main_time >= 31){
        break;
    }
        main_time++;
}
    m_trace->close();
    delete top;
    exit(0);
}