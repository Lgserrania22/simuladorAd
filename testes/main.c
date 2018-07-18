/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: aluno
 *
 * Created on 18 de Julho de 2018, 14:31
 */

#include <stdio.h>
#include <stdlib.h>


#define MALLOC(x) ((x *) malloc (sizeof(x)))
/*
 * 
 */



struct FilaPct_ {
        long double tempoChegada;
        long double tempoSaida;
        struct FilaPct_ * prox;
};

typedef struct FilaPct_ FilaPct;

void insereOrdenado(FilaPct **fila, long double tempoChegada, long double tempoSaida){
    
    FilaPct *p, *q, *aux;
    if(*fila == NULL){
        (*fila) = MALLOC(FilaPct);
        (*fila)->tempoChegada = tempoChegada;
        (*fila)->tempoSaida = tempoSaida;
        (*fila)->prox = NULL;
    }else{
        
        if((*fila)->tempoSaida > tempoSaida){
            aux = MALLOC(FilaPct);
            aux->tempoChegada = tempoChegada;
            aux->tempoSaida = tempoSaida;
            aux->prox = (*fila);
            (*fila) = aux;
            return;
        }
        
        q = (*fila);
        p = q->prox;
        
        while((p->tempoSaida < tempoSaida) && (p->prox != NULL)){
            q = p;
            p = p->prox;
        }
        
        if(p->prox != NULL){
            aux = MALLOC(FilaPct);
            aux->tempoChegada = tempoChegada;
            aux->tempoSaida = tempoSaida;
            q->prox = aux;
            aux->prox = p;
        }else{
            if(p->tempoSaida > tempoSaida){
                aux = MALLOC(FilaPct);
                aux->tempoChegada = tempoChegada;
                aux->tempoSaida = tempoSaida;
                q->prox = aux;
                aux->prox = p;
            }else{
                aux = MALLOC(FilaPct);
                aux->tempoChegada = tempoChegada;
                aux->tempoSaida = tempoSaida;
                p->prox = aux;
                aux->prox = NULL;
            }
        }

    }
    
    //printf("%Lf", fila->tempoChegada);
    
}

long double retiraFila(FilaPct **fila){
    
    FilaPct *p, *q, *aux;
    long double tempo;
    if(*fila == NULL){
        return -1;
    }else{        
        tempo = (*fila)->tempoSaida;
        (*fila) = (*fila)->prox;
        
        return tempo;
    }
    
}

void imprimeFila(FilaPct *fila){
    
    FilaPct *aux;
    aux = fila;
    while(aux != NULL){
        printf("\n%Lf", aux->tempoSaida);
        aux = aux->prox;
    }
}

int main(int argc, char** argv) {
    
    FilaPct * cabeca = NULL;
    
    insereOrdenado(&cabeca, 0 , 3);
    insereOrdenado(&cabeca, 2 , 1);
    insereOrdenado(&cabeca, 2 , 2);
    insereOrdenado(&cabeca, 2 , 8);
    //insereOrdenado(&cabeca, 2 , 4);
    

    //printf("\n%Lf", cabeca->tempoSaida);
    //printf("\n%Lf", cabeca->prox->tempoSaida);
    

/*
    cabeca->tempoChegada = 0.0;
    cabeca->tempoSaida = 0;
    
    cauda->tempoChegada = 1;
    cauda->tempoSaida = 1;
    
    cabeca->prox = cauda;
    
    FilaPct * teste = cabeca->prox;
    
    teste->tempoChegada = 2;
    
    printf("%.15Lf", cabeca->tempoChegada);
    printf("\n%.15Lf", cauda->tempoChegada);
    
*/
    return (EXIT_SUCCESS);
}

