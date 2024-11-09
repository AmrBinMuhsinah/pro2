#include<stdio.h>
#include"ALU.h"

void ALU(int RA, int RB, int op, int *Result, int *Carry) {
    
    Carry = 0;

    if (op == 0) {
        int sum = RA + RB;
        *Result = sum;

        if (sum > 1) {
            *Carry = 1;
        }

    } else if (op == 1) {
        int diff = RA - RB;
        *Result = diff;

    } else {
        printf("Invalid operation code.\n");
    }
}


