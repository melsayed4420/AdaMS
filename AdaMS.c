/*
 *  AdaMS Project (C) Mohamed ElSayed
 *  m.elsayed4420@gmail.com
 *  LowLeveCode.blogspot.com
 *  
 *  File : AdaMS.c
 *  The main source file
 *  */

#include "AdaMS-vm.h"
#include <stdio.h>
#include <string.h>
#include "AdaMS-cg.h"

void showFlags(){
    printf("\nJA : %d\nJAE : %d\nJB : %d\nJBE : %d\nJE : %d\nJNE : %d\n",
            flags.ja, flags.jae, flags.jb, flags.jbe, flags.je, flags.jne);
}

int main(int argc, char** argv)
{
    u_int8* memory = interpret("tri.ms");


    while(*(memory+ip) != HALT)
    {
        switch(memory[ip])
        {
            case MOV:
                mov(memory[++ip], memory[ip+2]);
                break;

            case PUT:
                put(memory[++ip]);
                break;

            case ADD:
                add(memory[++ip], memory[ip+2]);
                break;

            case SUB:
                sub(memory[++ip], memory[ip+2]);
                break;

            case MUL:
                mul(memory[++ip], memory[ip+2]);
                break;

            case DIV:
                _div(memory[++ip], memory[ip+2]);
                break;

            case PUSH:
                push(memory[++ip]);
                break;

            case POP:
                pop(memory[++ip]);
                break;

            case INC:
                inc(memory[++ip]);
                break;

            case DEC:
                dec(memory[++ip]);
                break;

            case JMP:
                jmp(memory[++ip]);
                --ip;
                break;

            case CMP:
                cmp(memory[++ip], memory[ip+2]);
                break;

            case JE:
                if(flags.je==true)
                {
                    jmp(memory[++ip]);
                    --ip;
                }
                break; 

            case JNE:
                if(flags.jne==true)
                {
                    jmp(memory[++ip]);
                    --ip;
                }
                break;

            case JAE:
                if(flags.jae==true)
                {
                    jmp(memory[++ip]);
                    --ip;
                }
                break; 

            case JA:
                if(flags.ja==true)
                {
                    jmp(memory[++ip]);
                    --ip;
                }
                break;

            case JB:
                if(flags.jb==true)
                {
                    jmp(memory[++ip]);
                    --ip;
                }
                break; 

            case JBE:
                if(flags.jbe==true)
                {
                    jmp(memory[++ip]);
                    --ip;
                }
                break;

        }
        ip++;
    }
    return 0;
}
