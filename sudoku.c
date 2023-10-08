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
  int filas [10];
  //int columnas [10];

  for(int i = 0; i < 9; i++){
    filas[i] = 0;
  }

  for(int m = 0; m < 9; m++)
  {
    for(int i = 0; i < 9; i++){
      filas[i] = 0;
    }
    
    for(int t = 0; t < 9; t++)
    {
      int aux = n->sudo[m][t];
      if(filas[aux] == 1 && aux > 0){
        //return 0;
      }
      filas[aux] = 1;
    }
  }
  

  

  return 1;
}


List* get_adj_nodes(Node* n){
  List* list=createList();
  
  for(int i = 0; i < 9; i++)
  {
    for(int t = 0; t < 9; t++)
    {
      if(n->sudo[i][t] == 0 ){
        for(int k = 1; k < 10; k++){
          Node * aux = copy(n);
          aux->sudo[i][t] = k;
          pushBack(list,aux);
        }
      }
    }
  }
  return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
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