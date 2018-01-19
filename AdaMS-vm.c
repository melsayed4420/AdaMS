/*
 *  AdaMS Project (C) Mohamed ElSayed
 *  m.elsayed4420@gmail.com
 *  LowLeveCode.blogspot.com
 *  
 *  File : AdaMS-vm.c
 *  AdaMS VM functions implementation
 *  */

#include "AdaMS-vm.h"


u_int8 ip = 0;
u_int8 sp = 0;

u_int8 stack[MAX_STACK];

static u_int8 m_counter  = 0;

void push(u_int8 val)
{
    switch (val)
    {
        case 0xc1:
            stack[sp++]=regs.ax;
            break;

        case 0xc2:
            stack[sp++]=regs.bx;
            break;

        case 0xc3:
            stack[sp++]=regs.cx;
            break;

        case 0xc4:
            stack[sp++]=regs.dx;
            break;

        case 0xc5:
            stack[sp++]=regs.ex;
            break;

        default:
            stack[sp++]=val;
            break;
    }
}

void pop(u_int8 val)
{
    switch (val)
    {
        case 0xc1:
            regs.ax = stack[--sp];
            break;

        case 0xc2:
            regs.bx = stack[--sp];
            break;

        case 0xc3:
            regs.cx = stack[--sp];
            break;

        case 0xc4:
            regs.dx = stack[--sp];
            break;

        case 0xc5:
            regs.cx = stack[--sp];
            break;
    }
}

void mov(u_int8 dest, u_int8 src)
{
    push(src);

    switch(dest)
    {
        case 0xc1:
            pop(AX);
            break;

        case 0xc2:
            pop(BX);
            break;

        case 0xc3:
            pop(CX);
            break;

        case 0xc4:
            pop(DX);
            break;

        case 0xc5:
            pop(EX);
            break;
    }
}


void add(u_int8 dest, u_int8 src)
{
    push(src);

    switch(dest)
    {
        case 0xc1:
            regs.ax += stack[--sp];
            break;

        case 0xc2:
            regs.bx += stack[--sp];
            break;

        case 0xc3:
            regs.cx += stack[--sp];
            break;

        case 0xc4:
            regs.dx += stack[--sp];
            break;

        case 0xc5:
            regs.ex += stack[--sp];
            break;
    }
}


void sub(u_int8 dest, u_int8 src)
{
    push(src);

    switch(dest)
    {
        case 0xc1:
            regs.ax -= stack[--sp];
            break;

        case 0xc2:
            regs.bx -= stack[--sp];
            break;

        case 0xc3:
            regs.cx -= stack[--sp];
            break;

        case 0xc4:
            regs.dx -= stack[--sp];
            break;

        case 0xc5:
            regs.ex -= stack[--sp];
            break;
    }
}



void mul(u_int8 dest, u_int8 src)
{
    push(src);

    switch(dest)
    {
        case 0xc1:
            regs.ax *= stack[--sp];
            break;

        case 0xc2:
            regs.bx *= stack[--sp];
            break;

        case 0xc3:
            regs.cx *= stack[--sp];
            break;

        case 0xc4:
            regs.dx *= stack[--sp];
            break;

        case 0xc5:
            regs.ex *= stack[--sp];
            break;
    }
}


void _div(u_int8 dest, u_int8 src)
{
    push(src);

    switch(dest)
    {
        case 0xc1:
            regs.ax /= stack[--sp];
            break;

        case 0xc2:
            regs.bx /= stack[--sp];
            break;

        case 0xc3:
            regs.cx /= stack[--sp];
            break;

        case 0xc4:
            regs.dx /= stack[--sp];
            break;

        case 0xc5:
            regs.ex /= stack[--sp];
            break;
    }
}


void inc(u_int8 reg)
{
    switch (reg)
    {
        case 0xc1:
            regs.ax++;
            break;

        case 0xc2:
            regs.bx++;
            break;

        case 0xc3:
            regs.cx++;
            break;

        case 0xc4:
            regs.dx++;
            break;

        case 0xc5:
            regs.ex++;
            break;
    }
}


void dec(u_int8 reg)
{
    switch (reg)
    {
        case 0xc1:
            regs.ax--;
            break;

        case 0xc2:
            regs.bx--;
            break;

        case 0xc3:
            regs.cx--;
            break;

        case 0xc4:
            regs.dx--;
            break;

        case 0xc5:
            regs.ex--;
            break;
    }
}


void put(u_int8 val)
{
    switch(val)
    {
        case 0xc1:
            printf("%d", regs.ax);
            break;

        case 0xc2:
            printf("%d", regs.bx);
            break;

        case 0xc3:
            printf("%d", regs.cx);
            break;

        case 0xc4:
            printf("%d", regs.dx);
            break;

        case 0xc5:
            printf("%d", regs.ex);
            break;
            
        case 0xc031:
            printf("\n");
            break;

        default:
            printf("%c", (char)val);
            break;
    }
}


void jmp(u_int8 address)
{
    ip = address;
}


void cmp(u_int8 rhs, u_int8 lhs)
{
    u_int8 rhs_temp = 0;
    u_int8 lhs_temp = 0;

    switch(rhs)
    {        
        case 0xc1:
            rhs_temp = regs.ax;
            break;

        case 0xc2:
            rhs_temp = regs.bx;
            break;

        case 0xc3:
            rhs_temp = regs.cx;
            break;

        case 0xc4:
            rhs_temp = regs.dx;
            break;

        case 0xc5:
            rhs_temp = regs.ex;
            break;

        default:
            rhs_temp = rhs;
            break;
    }


    switch(lhs)
    {        
        case 0xc1:
            lhs_temp = regs.ax;
            break;

        case 0xc2:
            lhs_temp = regs.bx;
            break;

        case 0xc3:
            lhs_temp = regs.cx;
            break;

        case 0xc4:
            lhs_temp = regs.dx;
            break;

        case 0xc5:
            lhs_temp = regs.ex;
            break;

        default:
            lhs_temp = lhs;
            break;
    }


    if(rhs_temp < lhs_temp)
    {
        flags.ja = true;
        flags.je = false;
        flags.jae = true;
        flags.jb = false;
        flags.jbe = false;
        flags.jne = true;
    }
    else if(rhs_temp > lhs_temp)
    {
        flags.ja = false;
        flags.je = false;
        flags.jae = false;
        flags.jb = true;
        flags.jbe = true;
        flags.jne = true;
    }
    else if(rhs_temp == lhs_temp)
    {
        flags.ja = false;
        flags.je = true;
        flags.jae = true;
        flags.jb = false;
        flags.jbe = true;
        flags.jne = false;
    }
}
