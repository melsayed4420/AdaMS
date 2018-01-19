/*
 *  AdaMS Project (C) Mohamed ElSayed
 *  m.elsayed4420@gmail.com
 *  LowLeveCode.blogspot.com
 *  
 *  File : AdaMS-cg.h
 *  AdaMS Interpreter - The code generator
 *  */

#ifndef ADAMS_CG_H
#define ADAMS_CG_H

#include "AdaMS-arch.h"

extern u_int8 m_counter;

/*
 * a struct to store the
 *  -> the vaules of the the variables
 *  -> key for each variable, to access the variable using it
 *  -> a string contains the variable name
 *  */

struct Var{
    char* var_name;
    u_int8 var_i_value;
    char* var_s_value;
    int var_id;
    struct Var *next;    
};
typedef struct Var var;

// a pointer points to the head of the variables linked list
extern var *v_head;

/*
 * linked list control functions
 * */

// inserting a new variable
var* var_insert(char*, char*, u_int8);

//searching for a certain variable in the list
var* var_search(char*);



struct Labels {
    char* lab_name;
    u_int8 jmp_adrs;
    int id;
    struct Labels *next;
};

typedef struct Labels lab;

extern lab* l_head;

lab* lab_insert(char*);

lab* lab_search(char*);


//the interpreter
u_int8* interpret(char*);




#endif
