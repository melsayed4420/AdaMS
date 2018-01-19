/*
 *  AdaMS Project (C) Mohamed ElSayed
 *  m.elsayed4420@gmail.com
 *  LowLevelCode.blogspot.com
 *  
 *  File : AdaMS-cg.c
 *  AdaMS Interpreter - The code generator
 *  */

#include "AdaMS-arch.h"
#include "AdaMS-std.h"
#include "AdaMS-cg.h"

u_int8 m_counter = 0;
int lp = 0;     //load pointer, will be used to iterate through program[] while loading the program in there

var* v_head;
var* var_insert(char* var_name, char* var_s_value, u_int8 var_i_value)
{
    var* added = (var*) malloc(sizeof(var));
    added->var_name = var_name;
    added->var_s_value = var_s_value;
    added->var_i_value = var_i_value;
    added->var_id = ++m_counter;

    added->next = v_head;
    v_head = added;
}

var* var_search(char* var_name)
{
    var* temp =v_head;

    if(v_head==NULL)
        return NULL;

    while(temp != NULL)
    {
        if(!strcmp(temp->var_name, var_name))
        {
            return temp;
        } 
        else
        {
            temp = temp->next;
        }
    }

}




lab* l_head;
lab* lab_insert(char* lab_name)
{
    lab* added = (lab*) malloc(sizeof(lab));
    added->lab_name = lab_name;
    added->jmp_adrs = lp+1;
    added->id = ++m_counter;

    added->next = l_head;
    l_head = added;
}

lab* lab_search(char* lab_name)
{
    lab* temp = l_head;

    if(l_head==NULL)
        return NULL;

    while(temp != NULL)
    {
        if(!strcmp(temp->lab_name, lab_name))
        {
            return temp;
        } 
        else
        {
            temp = temp->next;
        }
    }

}

u_int8* interpret(char* filename)
{
    char* whole_code = 0;       //the whole source code
    char* data = 0;             //the data section
    char* code = 0;             //the code section
    int data_len = 0;

    char* mark_1 = ".DATA";
    char* mark_2 = ".CODE";

    long file_length = 0;   //the length of the file, to allocate the memory for *buffer correctly
    FILE* f;
    f = fopen(filename, "r");
    assert(f != NULL);      //make sure that the file has been loaded successfully

    fseek(f, 0, SEEK_END);  //move the stream pointer to the end of the file
    file_length = ftell(f); //get the pointer position aka the file length
    fseek(f, 0, SEEK_SET);  //set the pointer back to the beginning
    whole_code = (char*) malloc(file_length * sizeof(char*));      //allocate the memory

    fread(whole_code, 1, file_length, f);     //read file_length bytes from the f stream and store it in code
    fclose(f);      //close f

    u_int8 *program = (u_int8*) malloc(file_length*sizeof(u_int8*)*3);
    assert(program);

    char* right;
    char* left = strstr(whole_code, mark_1); //set left to points to the first exsistance of mark_1
    if(left)
    {
        left+=strlen(mark_1);               //increase it to point right after the mark
        right = strstr(left, mark_2);       //point to the other mark
        if(right)
        {
            data_len = right - left;        //
            data = (char*) malloc(data_len * sizeof(char*) + 1);
            memcpy(data, left, data_len);
            data[data_len] = 0;
        }
    }

    char *d_buffer;
    
    d_buffer = strtok(data, " \n\r");
    while(d_buffer != NULL)
    {
        
    }

    

    right = strstr(whole_code, mark_2);
    if(right)
    {
        right+=strlen(mark_2);
        code = right;
    }

    char* buffer;
    
    buffer = strtok(code, " \n\r");

    while(buffer != NULL)
    {
        if(!strcmp(buffer, "HALT")) program[lp++] = HALT;
        else if(!strcmp(buffer, "ADD")) program[lp++] = ADD;
        else if(!strcmp(buffer, "MOV")) program[lp++] = MOV;
        else if(!strcmp(buffer, "SUB")) program[lp++] = SUB;
        else if(!strcmp(buffer, "MUL")) program[lp++] = MUL;
        else if(!strcmp(buffer, "NEW_LINE")) program[lp++] = NEW_LINE;
        else if(!strcmp(buffer, "DIV")) program[lp++] = DIV;
        else if(!strcmp(buffer, "PUSH")) program[lp++] = PUSH;
        else if(!strcmp(buffer, "POP")) program[lp++] = POP;
        else if(!strcmp(buffer, "INC")) program[lp++] = INC;
        else if(!strcmp(buffer, "DEC")) program[lp++] = DEC;
        else if(!strcmp(buffer, "PUT")) program[lp++] = PUT;
        else if(!strcmp(buffer, "CMP")) program[lp++] = CMP;
        else if(!strcmp(buffer, "JMP")){
            char* temp_buff = strtok(NULL, " \n\r");
            lab* find = lab_search(temp_buff);
            if(find != NULL)
            {
                program[lp++] = JMP;
                program[lp++]= find->jmp_adrs;
            }
            else
                puts("error");
        }
        else if(!strcmp(buffer, "JE"))
        {
            char* temp_buff = strtok(NULL, " \n\r");
            lab* find = lab_search(temp_buff);
            if(find != NULL)
            {
                program[lp++] = JE;
                program[lp++]= find->jmp_adrs;
            }
            else
                puts("error");
        }
        else if(!strcmp(buffer, "JA"))
        {
            char* temp_buff = strtok(NULL, " \n\r");
            lab* find = lab_search(temp_buff);
            if(find != NULL)
            {
                program[lp++] = JA;
                program[lp++]= find->jmp_adrs;
            }
            else
                puts("error");
        }
        else if(!strcmp(buffer, "JB"))
        {
            char* temp_buff = strtok(NULL, " \n\r");
            lab* find = lab_search(temp_buff);
            if(find != NULL)
            {
                program[lp++] = JB;
                program[lp++]= find->jmp_adrs;
            }
            else
                puts("error");
        }
        else if(!strcmp(buffer, "JAE"))
        {
            char* temp_buff = strtok(NULL, " \n\r");
            lab* find = lab_search(temp_buff);
            if(find != NULL)
            {
                program[lp++] = JAE;
                program[lp++]= find->jmp_adrs;
            }
            else
                puts("error");
        }
        else if(!strcmp(buffer, "JBE"))
        {
            char* temp_buff = strtok(NULL, " \n\r");
            lab* find = lab_search(temp_buff);
            if(find != NULL)
            {
                program[lp++] = JBE;
                program[lp++]= find->jmp_adrs;
            }
            else
                puts("error");
        }
        else if(!strcmp(buffer, "JNE"))
        {
            char* temp_buff = strtok(NULL, " \n\r");
            lab* find = lab_search(temp_buff);
            if(find != NULL)
            {
                program[lp++] = JNE;
                program[lp++]= find->jmp_adrs;
            }
            else
                puts("error");
        }
        else if(!strcmp(buffer, "STC")) program[lp++] = STC;
        else if(!strcmp(buffer, "CLC")) program[lp++] = CLC;

        else if(!strcmp(buffer, "AX")) program[lp++] = AX;
        else if(!strcmp(buffer, "BX")) program[lp++] = BX;
        else if(!strcmp(buffer, "CX")) program[lp++] = CX;
        else if(!strcmp(buffer, "DX")) program[lp++] = DX;
        else if(!strcmp(buffer, "EX")) program[lp++] = EX;
        else if (is_num(buffer)) program[lp++] = atoi(buffer);
        else if(is_jmp(buffer)){
            lab* new = lab_insert(buffer);
            program[lp++] = new->id;
        }

        buffer = strtok(NULL, " \n\r");
    }

    return program;
}
