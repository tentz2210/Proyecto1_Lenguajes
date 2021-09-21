#include <stdio.h>

double calcProbabilidadTeorica(int s);
double calcProbabilidadEmpirica(int s, int k);
double calcErrorRelativo(double t, double p);
int realizarExperimento(int s);
int factorial(int n);


double calcProbabilidadTeorica(int s){
    return 0.0;
    // to do
}

double calcProbabilidadEmpirica(int s, int k){
    return 0.0;
    // to do
}

double calcErrorRelativo(double t, double p){
    return 0.0;
    // to do
}

int realizarExperimento(int s){
    return 0;
    // to do
}

int factorial(int n){
    if(n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }

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