#include <stdio.h>
#include <string.h>
// STRUCTURES
/*
typedef struct vector{
    float *vector;
    int n;
} Vector;

int main(){
    Vector v1;
    v1.vector = (float[]){1,4.83,1};
    v1.n = 3;
    return 0;
}
*/

/*
struct SuperHero{
    char *poder;
    int nivel;
    float nivel_poder;
    char *name;
};

int main(){
    system("cls");
    struct SuperHero flash;

    flash.poder = "SuperPower";
    flash.nivel = 5;
    flash.nivel_poder = 8.9;
    flash.name = "Hulk";

    struct SuperHero Superman;
    Superman.poder = "Force";
    Superman.nivel_poder = 22;
    Superman.name = "Clark";

    printf("%s\n", Superman.poder);
    return 0;
}
*/

/*
struct Cat{
    char *name;
    int age;
    float weight;
    char *color;
};

int main(){
    system("cls");
    struct Cat Goddy;

    Goddy.name = "Goddy";
    Goddy.age = 5;
    Goddy.weight = 8.9;
    Goddy.color = "Black";

    printf("Hi %s\n :)", Goddy.name);
    return 0;
}
*/

/*
typedef struct Perceptron{
    float *weights;
    float bias;
    int n;
} Perceptron;

float predict(Perceptron *p, float *data){
    float dot = 0;
    for (int i=0; i<p->n; i++){
        dot = (p-> weights[i])*data[i];
    }

    float result = dot + p->bias;
    return result>0? 1 : 0; 
}

int main(){
    system("cls");
    float data[5] ={1,3.3,1,2.2,2.4};
    Perceptron *p;
    p->weights = (float[]){0.4,-0.4,-0.2,-0.8,-0.1};
    p->bias = 0.2;
    p->n = 5;

    int result = predict(p,data);
    printf("%d\n", result);
}
*/


int main(){
    printf("Hello World");
    return 0;
}