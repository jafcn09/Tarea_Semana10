#include <iostream>
#include <cstdlib>
using namespace std;


struct Fila {
	int capacidad;
	int *datos;
	int primero;
	int ultimo;
	int nItems; 
};


void crearFila( struct Fila *f, int c ) { 
	f->capacidad = c;
	f->datos = (int*) malloc (f->capacidad * sizeof(int));
	f->primero = 0;
	f->ultimo = -1;
	f->nItems = 0; 

}


void insertar(struct Fila *f, int v) {

	if(f->ultimo == f->capacidad-1)
		f->ultimo = -1;

	f->ultimo++;
	f->datos[f->ultimo] = v; // incrementa ultimo e inserta
	f->nItems++; // un item insertado a la fila

}


int remover( struct Fila *f ) { 

	int temp = f->datos[f->primero++]; // coge el valor e incrementa el primero

	if(f->primero == f->capacidad)
		f->primero = 0;

	f->nItems--;  // un item retirado
	return temp;

}

int estaVacia( struct Fila *f ) { // retorna verdadero si a fila está vacía

	return (f->nItems==0);
}

int estaLlena( struct Fila *f ) { // retorna verdadero si la fila está llena

	return (f->nItems == f->capacidad);
}

void mostrarFila(struct Fila *f){

	int cont, i;

	for ( cont=0, i= f->primero; cont < f->nItems; cont++){

		printf("%.2i\t",f->datos[i++]);

		if (i == f->capacidad)
			i=0;

	}
	printf("\n\n");
}




int main()
{
    int opcion, capa;
	float valor;
	struct Fila unaFila;

	// crea la fila
	printf("\ncapacidad de la  fila? ");
	scanf("%d",&capa);
	crearFila(&unaFila, capa);

    while(1){
    
    		printf("\n1 - insertar elemento\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Salir\n\nopcion? ");
    		scanf("%d", &opcion);
    		switch(opcion){
            
            case 0: exit(0);
            case 1: 
                if (estaLlena(&unaFila))
                {
                    printf("\nFila llena\n\n"); 
                
                }
                else {
                    valor=rand()%100;
                    cout<<"Valor del elemento a ser inserido? "<<valor<<endl;
                    insertar(&unaFila,valor);
                }
                break;
            case 2:
                if (estaVacia(&unaFila)){
                    printf("\nFila vacia\n\n");
                }
                else {
                  valor = remover(&unaFila);
                  printf("\n%1f removido com exito \n\n", valor) ; 
                }
                break;
            case 3: // mostrar fila
                if (estaVacia(&unaFila))
                {  
                    printf("\nFila vacia!!!\n\n");
                }
                else {
                    printf("\nContenido de la fila => ");
					mostrarFila(&unaFila);

                }
				break;
			default:
				printf("\nopcion Invalida\n\n");

        }
    }

    return 0;
}