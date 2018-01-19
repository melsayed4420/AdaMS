/*
 *  AdaMS Project (C) Mohamed ElSayed
 *  m.elsayed4420@gmail.com
 *  LowLeveCode.blogspot.com
 *  
 *  File : AdaMS-vm.h
 *  AdaMS VM functions prototypes
 *  */

#ifndef ADAMS_VM_H
#define ADAMS_VM_H

#include "AdaMS-arch.h"
registers regs;
flags_ flags;
/*
 * a liked list to be used in variables implementation
 * works like follows:
 *  -> when the interpreter reads DEF it will fetech the next instruction to find the type of the variable
 *  ..  then it will create a node it the linked list to store the 3 things
 *      1- the variable name
 *      2- key of the variable, to be used in memory, since it can only deal with integers
 * */

/*
 * instructions functions prototypes
 * */

/*
 * move a value from register to another or immediate value to a regester
 * @params :
 *      dest : the register to be increased
 *      src : the source, register or immediate value
 * */
void mov(u_int8 dest, u_int8 src);


/*
 * add an integeral value from a register/immediate to another regester
 * @params : 
 *      dest : the register to be increased 
 *      src : the source register
 * */
void add(u_int8 dest, u_int8 src);


/*
 * subtract some an integral value from a regester
 * 
 * evaluate (right - left) and store the value in the left register
 * */
void sub(u_int8 left, const u_int8 right);


/*
 * evaluate "left*right" and store the result in the left register
 * */
void mul(u_int8 left, const u_int8 right);


/*
 * evaluate "left/right" and store the result in the left register
 * */
void _div(u_int8 left, const u_int8 right);


/* 
 * psuh the current value in the passed register to the stack
 * */
void push(const u_int8);


/*
 * pop the last value in the stack to the passed register
 * */
void pop(u_int8);


/*
 * increase the value of the passed register by 1
 * */
void inc(u_int8);


/*
 * decreasing the value of the passed register by 1
 * */
void dec(u_int8);


/*
 * defining a variable
 * */
void def(u_int8 type, char* value, int key);


/*
 * printing a value of a variable or a single character
 * */
void put(u_int8);


/*
 * compare two registers and set the flags accorging to the result
 * cmp is able ro compare a register with another or with immediate value (int or char)
 * */
void cmp(u_int8, u_int8);


/*
 * jump (set the ip) to the passed memory address
 * */
void jmp(u_int8);


/*
 * compares rhs to lfs, the flags are set according to the rhs
 * if its greater then JA, JAE, JNE are set
 * if its less then JB and JBE, JNE are set
 * JE is set when lfs = rhs *mr obvious was here*
 * */
void cmp(u_int8, u_int8);

#endif
