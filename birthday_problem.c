#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define K 30
#define DAYS_ARR_SIZE 365

double calcProbabilidadTeorica(int s);
double calcProbabilidadEmpirica(int s, int k);
double calcErrorRelativo(double t, double p);
bool realizarExperimento(int s);

double calcProbabilidadTeorica(int s){
    if(s >=1 && s <= 365){ 
        double p = 1;
        int days = DAYS_ARR_SIZE;
        for(int i = 1; i<s;i++){
            p *= ((double)(--days))/DAYS_ARR_SIZE;
        }
        return p;
    }
    return 0;
}

double calcProbabilidadEmpirica(int s, int k){
    int i, n;
    double p;

    i = n = 0;
    srand(time(NULL));

    while(i < k){
      if(realizarExperimento(s)){
          n++;
      }
      i++;
    }

    p = ((double)n) / k;
    
    return p;
}

double calcErrorRelativo(double t, double p){
    double d = fabs(t-p) / t;
    return d;
}

bool realizarExperimento(int s){
  bool daysArr[DAYS_ARR_SIZE];
  for(int idx = 0; idx < DAYS_ARR_SIZE; idx++){
    daysArr[idx] = false;
  }

  bool result = true;
  int i = 0;
  int selected;
  double r;

  while(i < s){
    r = ((double)rand()) / (double)RAND_MAX;
    selected = round(r * DAYS_ARR_SIZE);
    if(daysArr[selected]){
      result = false;
      break;
      
    } else {
      daysArr[selected] = true;
    }
    i++;
  }

  return result;
}

int main() {
    int s; // cantidad de personas en el experimento
    int k; // cantidad de veces que se corre el experimento
    double t; // probabilidad teorica
    double p; // probabilidad empirica
    double d; // error relativo

    printf("Digite la cantidad de personas en el experimento: ");
    scanf("%d", &s);

    printf("Digite la cantidad de veces que desea que se repita el experimento: ");
    scanf("%d", &k);

    
    t = calcProbabilidadTeorica(s);

    p = calcProbabilidadEmpirica(s, k);
    d = calcErrorRelativo(t, p);
    

    printf("Probabilidad teorica: %f \n", t);
    printf("Probabilidad empirica:  %f \n", p);
    printf("Error relativo:  %f \n", d);
    printf("Repeticiones del experimento: %d \n", k);

    return 0;
}