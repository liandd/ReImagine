#include <bits/stdc++.h>

using namespace std;

int main(){
    char c = 'a';
    int num = 23;
    float dec = 14.56;
    double dec1=23.8765757655;
    char cadena[] = "Hola Mundo";

    printf("Este es un caracter unico: %c\n", c);
    printf("Este es un entero con signo: %d\n", num);
    printf("Este es un entero sin signo: %u\n", num);
    printf("Este es un entero en base octal: %o\n", num);
    printf("Este es un entero en base hexadecimal: %x\n", num);
    printf("Este es un numero real en coma flotante con exponente: %e\n", dec);//notación científica
    printf("Este es un numero real con coma flotante sin exponente: %f\n", dec);//notación normal
    printf("Esta es una cadena: %s\n", cadena); //no sirve para imprimir strings, tienen que ser un arreglo de caracteres.
    printf("Este es un decimal con 20 numeros despues de la coma: %.20f\n", dec1);
    /*%d   imprime una variable int en formato decimal.
     %ld  imprime un long int en decimal.
     %c   imprime un caracter.
     %s   imprime una cadena de caracteres.
     %f   imprime un float o double.
     %e   igual que %f, pero utilizando notacion exponencial.
     %g   utiliza %f o %e dependiendo de cual es mas conveniente.
     %o   imprime un entero en octal.
     %x   imprime un entero en hexadecimal.
     %%   imprime el caracter %.
     \n   caracter de nueva linea, salta al siguiente renglón.
     \t   caracter tabulador, avanza hasta la siguiente columna de tabulación.
     \a   caracter de alarma, genera un sonido "beep" en la consola.*/
     /*scanf ( " %s", variable );
     fgets( variable, tamano_variable, stdin );
     while (scanf_s("%d %d %d %d", &(a), &(b), &(c), &(d))
            printf("We need %d truck%s and %d boat%s.\n", nt, (nt == 1) ? "" : "s", nb, (nb == 1) ? "" : "s");*/
     printf("%%");




return 0;
}
