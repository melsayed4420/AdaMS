/*
 *  AdaMS Project (C) Mohamed ElSayed
 *  m.elsayed4420@gmail.com
 *  LowLeveCode.blogspot.com
 *  
 *  File : AdaMS-arch.h
 *  AdaMS Project's VM architecture
 *  */

#ifndef ADAMS_ARCH_H
#define ADAMS_ARCH_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK 1000

/*bool definition*/

typedef enum {false, true} bool;

/* some other useful typedefs */
typedef unsigned long int u_int8;
/* the stack pointer and the instruction pointer
 * they are mainly use to itarate through the stack and the memoty
 * */

extern u_int8 sp;      // stack pointer
extern u_int8 ip;      //instructions pointer

/* the memory, where all structures gonna be loaded
 * the stack, already well know
 * */

extern u_int8 *memory;
extern u_int8 stack[MAX_STACK];


/* the control flow flags */

typedef struct {
    bool je;
    bool ja;
    bool jb;
    bool jbe;
    bool jae;
    bool jne;
    bool cf;
}flags_;

/* AdaMS instructions
 * the general instructinos
 * */

#define HALT        0xc000      //[x]
#define MOV         0xc001      //[x]
#define ADD         0xc002      //[x]
#define SUB         0xc003      //[x]
#define MUL         0xc004      //[x]
#define DIV         0xc005      //[x]
#define PUSH        0xc006      //[x]
#define POP         0xc007      //[x]
#define INC         0xc008      //[x]
#define DEC         0xc009      //[x]
#define DEF         0xc010      
#define SRT         0xc011
#define INT         0xc012
#define PUT         0xc013      //[x]

// 10 valuse are reserved for any comming instruction

/* control flow instructions */

#define CMP         0xc021
#define JMP         0xc022
#define JE          0xc023
#define JA          0xc024
#define JB          0xc025
#define JAE         0xc026
#define JBE         0xc027
#define JNE         0xc028
#define STC         0xc029
#define CLC         0xc030
#define NEW_LINE    0xc031
/*
 * AdaMS general purpos registers
 * */

#define AX          0xc1
#define BX          0xc2
#define CX          0xc3
#define DX          0xc4
#define EX          0xc5

/*
 * a structure to hold the real values of the registers
 * */

typedef struct{
    u_int8 ax;
    u_int8 bx;
    u_int8 cx;
    u_int8 dx;
    u_int8 ex;
}registers;


#endif
