#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int array_limite[10];
int consumo = 0,producao = 0,controle = 0;
bool consumidor_livre, produtor_livre;

void *produtor(){
  for (int i = 0;i < 10;i++){
    if(controle < 5){
      array_limite[i] = i;
      printf("O produtor produziu o elemento %i\n",i);
      producao++;
      controle++;
      sleep(rand() % 6 + 1);
    }
  }
}

void *consumidor(){
  int aux = 0,i = 0;
  while(true){
    if(consumo != producao){
      printf("O consumidor consumiu o elemento %i\n",array_limite[i]);
      array_limite[i] = aux;
      consumo++;
      i++;
      controle--;
      sleep(rand() % 10 + 1);
    }
  }
}

int main() {
  pthread_t pid, pid2;
  pthread_create(&pid,NULL,produtor,NULL);
  pthread_create(&pid2,NULL,consumidor,NULL);
  pthread_exit(NULL);
}