#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "streal.h" 
char s;
double x;
int i = 0;
int j = 0;
    int IsDelimeter(char c) {// Ищет символы-разделители
    if(strchr(" =",c)!=0)
        return 1;
        return 0;
    }

    int IsOperator(char c) {
    if ( strchr("+-/*()",c)!=0)
        return 1;
        return 0;
    }

    int Priority(char s) { // Определяет приоритет оператора
        switch(s)
      {
        case '(': return 1;
        case ')': return 1;
        case '+': return 2;
        case '-': return 2;
        case '*': return 3;
        case '/': return 3;
        default : return 6;
      }
    }
    char convertor( char* str_in, char* str_out) {  
        int linelen = strlen(str_in);
        int linelen1 = strlen(str_out);
        for(i = 0; i < linelen; i++) {	    
            if (!IsOperator(str_in[i])) {
                str_out[j]=str_in[i]; // Добавляем каждый символ
                    ++j;
            } 
                else  if (str_in[i]=='(') { // Если символ-открывающаяся скобка  
                  	  st_push((double)str_in[i]);   
                } 
                else if (str_in[i] == ')' ) { // Если символ - закрывающаяся скобка
                { //ВЫписываем все операторы до открывающей скобки в строку
                         s = (char)st_pop();
                while(s!='(') {
                     str_out[j]=' ';
                     str_out[j+1]=s;
                    // str_out[j+1]=' ';
                     j=j+2;
                      s=(char)st_pop();
                   }
                }
        }
                else { // Если любой другой оператор
                    str_out[j] = ' ';
                        ++j;
                    if (!st_empty() && Priority(str_in[i]) <= Priority((char)st_top())) {
                        str_out[j]=(char)st_pop();
                        str_out[j+1]=' ';
                        j=j+2;
                    }                         
                        st_push((double)str_in[i]);
                }            
                }  
                while (!st_empty()) {
                    str_out[j]=' '; 
                    str_out[j+1]=(char)st_pop();  
                        j=j+2;
                }  
             
                    str_out[j]=' '; 
                    str_out[j+1]='='; 
                    str_out[j+2]='\0'; 
                    printf("Result : %s\n",str_out);
    }
