#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "instruction.h"
#include "loader.h"
#include "ALU.h"

int mult(int *Result, int imm, int Srag) {
    if (Srag == 0) {
        return *Result;
    } else if (Srag == 1) {
        return imm;
    } else {
        return -1;  
    }
}

int main() {
    char *buffer[9] = {NULL};
    int count = 0;

    load(buffer, &count);

    int pc = 0;

    while (pc < count) {
        print_instruction(buffer, pc);
        decoder(buffer, pc);
        pc++;
        sleep(1);
    }

    for (int j = 0; j < count; j++) {
        free(buffer[j]);
    }

    int RA=0;
    int RB=0;

    ALU(RA, RB, int op, &Result, &Carry);

    int x=mult( &Result, imm, Srag);

    printf("The result = %d",x);


    return 0;
}








