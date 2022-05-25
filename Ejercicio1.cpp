#include <iostream>
#include "conio.h"
#include <stdlib.h>

using namespace std;

void Torre(int a, int b, int c, int aux){
if( a > 0) {
Torre(a-1, b, aux, c);
cout <<"\nSe va a  mover el anillo desde la torre" << b << " Hasta" << c;
Torre(a-1, aux, c, b);
}

}
int main(){
int a;
cout <<"Cuantos anillos desea ingresar?";
cin >> a;
Torre(a,1,2,3);


}