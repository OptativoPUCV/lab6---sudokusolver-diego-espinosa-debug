#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){

  for(int m = 0; m < 9; m++)
  {
    int filas [10] = {0};
    for(int t = 0; t < 9; t++)
    {
      int aux = n->sudo[m][t];
      if(filas[aux] == 1 && aux > 0){
        return 0;
      }
      filas[aux] = 1;
    }
  }

  for(int m = 0; m < 9; m++)
  {
    int columnas [10] = {0};
    for(int t = 0; t < 9; t++)
    {
      int aux = n->sudo[t][m];
      if(columnas[aux] == 1 && aux > 0){
        return 0;
      }
      columnas[aux] = 1;
    }
  }

  for(int k = 0; k < 6; k++){ 
    int subMatriz [10] = {0};
    
    for(int p=0;p<9;p++){
      int i=3*(k/3) + (p/3) ;
      int j=3*(k%3) + (p%3) ;

      int aux = n->sudo[i][j];
      if(subMatriz[aux] == 1 && aux > 0){
        return 0;
      }
      subMatriz[aux] = 1;
    }
  }
  


  return 1;
}


List* get_adj_nodes(Node* n){
  List* list=createList();
  int filaVacia = -1;
  int columnaVacia = -1;

  for(int fila = 0; fila < 9; fila++){
    for(int columna = 0; columna < 9; columna++){
      if(n->sudo[fila][columna] == 0){
        filaVacia = fila;
        columnaVacia = columna;
        break;
      }
    }
    if(filaVacia != -1){
      break;
    }
  }
    if(filaVacia != -1 && columnaVacia != -1){
      for(int num = 1 ; num <= 9; num++){
        Node* new_node = copy(n);
        new_node->sudo[filaVacia][columnaVacia] = num;

        if(is_valid(new_node)){
          pushBack(list,new_node);
        }else{
          free(new_node);
        }
      }
    }

  return list;
}


int is_final(Node* n){
  for(int k =  0;k < 9; k++){
    for(int h = 0; h < 9;h++){
      if(n->sudo[k][h] == 0) return 0;
    }
  }
  
   return 1;
}

Node* DFS(Node* initial, int* cont){
   /*Stack* S = createStack();
  push(S, initial);
  cont = 0;*/
  
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/