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
  for(int i= 0;i<9;i++){
    int arreglo[10]={0};
    for(int j=0;j<9;j++){
      int lugar = n->sudo[i][j];
      if(lugar!=0){
        if (arreglo[lugar]==0){
          arreglo[lugar]=1;
        }else{
          return 0;
        }
      }
      
    }
  }
for(int i= 0;i<9;i++){
    int arreglo[10]={0};
    for(int j=0;j<9;j++){
      int lugarco = n->sudo[i][j];
      if(lugarco!=0){
        if (arreglo[lugarco]==0){
          arreglo[lugarco]=1;
        }else{
          return 0;
        }
      }
      
    }
  }
  int i =4;
  int arreglo[10]={0};
  for(int j =0;j<9;j++){
    int h=3*(i/3)+(j/3);
    int k=3*(i%3)+(j%3);
    int matriz=n->sudo[k][h];
    if (matriz != 0){
      if (arreglo[matriz]==0){
        arreglo[matriz]=1;
      }else{
        return 0;
      }
    }
  }

  
    return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();
  int fila;
    int columna;
    for(fila=0;fila<9;fila++){
      int num;
      for (columna=0;columna<9;columna ++){
        if(n->sudo[fila][columna]==0){
          for(num=1;num<10;num++){
            n->sudo[fila][columna]=num;
            if(is_valid(n)){
              Node* Adyacentee=copy(n);
              pushBack(list, Adyacentee);
            }
          }
          n->sudo[fila][columna]=0;
          return list;
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