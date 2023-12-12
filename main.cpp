#include <iostream>  
#include <conio.h>   
using namespace std;

// Nodo
struct Arbol//Estructura principal del arbol
{
    int datoainsertar;//Es el dato que se guarda en el nodo, del usuario
    struct Arbol *ladoizquierdo;
    struct Arbol *ladoderecho;
    struct Arbol *Nodopadre;
};

struct Arbol *nodoRaiz;

// & pasa el puntero por referencia en lugar de por valor, y se pueda modificar
void insertar(Arbol *&arbol, int dato, Arbol *padre);
void mostrarArbol(Arbol *, int);
void buscar(Arbol *, int);
////////////////////////
void eliminar(Arbol *, int);
void verificaHijos(Arbol *);
Arbol *retornaNodoMasIzquierdo(Arbol *);
void reemplazoNodoEliminar(Arbol *, Arbol *);
int profundidad(Arbol *);
void preOrden(Arbol* arbol);
void InOrden(Arbol*arbol);
void PosOrden(Arbol*arbol);

Arbol *arbol = NULL; // creamos el arbol

int main()
{
    int valor;  
    int opcion;
    while (opcion != 9)
    {
        system("color f8");
        system("cls");  
        cout << " \n\n\n\n\t\t\t*****  Practcica de Examen Final  ****\n\n";
        cout << " \t\t\t\t1. Insertar nodo al arbol                                  \n";
        cout << " \t\t\t\t2. Mostrar Arbol                             \n";
        cout << " \t\t\t\t3. Buscar                                    \n";
        cout << " \t\t\t\t4. Eliminar                                  \n";
        cout << " \t\t\t\t5. Profundidad                               \n";
        cout << " \t\t\t\t6. Mostrar Preorden                          \n";
        cout << " \t\t\t\t7. Mostrar inorden                           \n";
         cout << " \t\t\t\t8. Mostrar Posorden                         \n";
        cout << " \t\t\t\t9. Salir                                     \n";
        cout << " \t\t\t\tdigite la opcion:";
        cin >> opcion;
        switch (opcion)
        {
        case 1: //      insertar
            system("cls");
            cout << " \n\n\n\n\t\t\t******  Insertar    ******\n\n";
            cout << " \t\t\tIngrese el valor a insertar: ";
            cin >> valor;
            insertar(arbol, valor, NULL);
            getch();
            break;

        case 2: //      mostrar todo el Arbol
            system("cls");
            cout << " \n\n\n\n\t\t\t******  Mostrar todo el Arbol   ******\n\n";
            mostrarArbol(arbol, 0);
            getch();
            break;

        case 3: //      Buscar
            system("cls");
            cout << " \n\n\n\n\t\t\t******   Buscar     ******\n\n";
            cout << " \t\t\tIngrese el valor a buscar: ";
            cin >> valor;
            buscar(arbol, valor);
            getch();
            break;

        case 4: //      eliminar
            system("cls");
            cout << " \n\n\n\n\t\t\t******  Eliminar   ******\n\n";
            cout << " \t\t\tIngrese el valor a eliminar: ";
            cin >> valor;
            eliminar(arbol, valor);
            getch();
            break;

        case 5: //      Profundidd del arbol
            system("cls");
            cout << " \n\n\n\n\t\t\t******   Profundidad   ******\n\n";
            cout << " \t\t\tLa profundidad del Arbol es: " << profundidad(arbol) << " !!!\n\n\n";
            getch();
            system("exit");
            break;
            
        case 6: //      mostrar preorden
            system("cls");
            cout << " \n\n\n\n\t\t\t******  Mostrar el preorden del arbol   ******\n\n";
            preOrden(arbol);
            getch();
            break;
            
        case 7: //      mostrar inorden
            system("cls");
            cout << " \n\n\n\n\t\t\t******  Mostrar el inorden del arbol   ******\n\n";
            InOrden(arbol);
            getch();
            break;

        case 8: //      mostrar Posorden
            system("cls");
            cout << " \n\n\n\n\t\t\t******  Mostrar el Posorden del arbol   ******\n\n";
            PosOrden(arbol);
            getch();
            break;
        case 9: //      salir del sistema
            system("cls");
            cout << " \n\n\n\n\t\t\t******  Saliendo del Sistema ******\n\n";
            getch();
            system("exit");
            break;

        default: //     digito opcion incorrecta
            system("cls");
            cout << " \n\n\n\n\t\t****** Digite una opcion valida del menu !!! ******\n\n";
            getch();
            break;

        } // switch
    }     // while

    return 0;
}

/*
    metodo insertar un dato
*/
void insertar(Arbol *&nodo, int valor, Arbol *padre)
{
    if (nodo == NULL)//el nodo viene vacio
    {
        Arbol *nuevoNodo = new Arbol();// CREAMOS NODO
        nuevoNodo->datoainsertar = valor;//Se accede a las propiedades
        nuevoNodo->ladoderecho = NULL;//
        nuevoNodo->ladoizquierdo = NULL;
        nuevoNodo->Nodopadre = padre;
        nodo = nuevoNodo;//tenga el valor del nuevo
        if (nodoRaiz == NULL)
        {
            nodoRaiz = nuevoNodo;//nodo inicial
        }
        cout << "\n\n\t\t\tSe agrego el dato al Arbol satisfactoriamente !";
    }
    else
    {
        if (valor < nodo->datoainsertar)
        {
            insertar(nodo->ladoizquierdo, valor, nodo);
        }
        else if (valor > nodo->datoainsertar)
        {
            insertar(nodo->ladoderecho, valor, nodo);
        }
        else
        {
            cout << "\n\n\t\t\tAtencion, el nodo ya se encuentra en el Arbol no se puede guardar !";
        }
    }
}

/*
    metodo mostrar Arbol
*/
void mostrarArbol(Arbol *nodo, int espacio)
{
    if (nodo != NULL)
    {

        if (nodo->ladoderecho != NULL)
        {
            mostrarArbol(nodo->ladoderecho, espacio + 5);
        }
        for (int i = 0; i < espacio; i++)
        {
            cout << " ";
        }
        cout << nodo->datoainsertar << "\n";
        if (nodo->ladoizquierdo != NULL)
        {
            mostrarArbol(nodo->ladoizquierdo, espacio + 5);
        }
    }
    if (nodoRaiz == NULL)
    {
        cout << "\n\n\t\t\tAtencion, el Arbol esta vacio !\n\n";
    }
}

/*
    metodo buscar
*/
void buscar(Arbol *nodo, int valor)
{
    if (nodo != NULL)
    {
        if (nodo->datoainsertar == valor)
        {
            cout << "\n\n\t\t\tEl dato si esta en el Arbol [" << nodo->datoainsertar << "] !!";
        }
        else if (valor < nodo->datoainsertar)
        {
            buscar(nodo->ladoizquierdo, valor);
        }
        else if (valor > nodo->datoainsertar)
        {
            buscar(nodo->ladoderecho, valor);
        }
    }
    else if (nodoRaiz != NULL && nodo == NULL)
    {
        cout << "\n\n\t\t\tEl dato buscado no esta en el Arbol !!!\n\n";
    }
    if (nodoRaiz == NULL)
    {
        cout << "\n\n\t\t\tAtencion, el Arbol esta vacio !!!\n\n";
    }
}

/*
    metodo eliminar
*/
void eliminar(Arbol *nodo, int valor)
{
    if (nodo != NULL)
    {
        if (nodo->datoainsertar == valor)
        {
            verificaHijos(nodo);
            cout << "\n\n\t\t\tSe elimino el dato satisfactoriamente !";
        }
        else if (valor < nodo->datoainsertar)
        {
            eliminar(nodo->ladoizquierdo, valor);
        }
        else if (valor > nodo->datoainsertar)
        {
            eliminar(nodo->ladoderecho, valor);
        }
    }
    else if (nodoRaiz != NULL && nodo == NULL)
    {
        cout << "\n\n\t\t\tEl dato a eliminar no esta en el Arbol !!!\n\n";
    }
    if (nodoRaiz == NULL)
    {
        cout << "\n\n\t\t\tAtencion, el Arbol esta vacio !!!\n\n";
    }
}

/*
   verifica si el nodo a aliminar tiene 2 hijos
   , 1 hijo, o no tiene ninguno
*/
void verificaHijos(Arbol *nodo)
{
    if (nodo->ladoizquierdo && nodo->ladoderecho)
    { // si tiene hijo izquiero y derecho
        Arbol *nodoMasIzquierdo = retornaNodoMasIzquierdo(nodo->ladoderecho);
        nodo->datoainsertar = nodoMasIzquierdo->datoainsertar;
        verificaHijos(nodoMasIzquierdo);
    }
    else if (nodo->ladoizquierdo)
    { // si existe hijo izquierdo
        reemplazoNodoEliminar(nodo, nodo->ladoizquierdo);
        nodo->ladoizquierdo = NULL;
        nodo->ladoderecho = NULL;
        nodo->Nodopadre = NULL;
        delete nodo;
    }
    else if (nodo->ladoderecho)
    { // si existe hijo derecho
        reemplazoNodoEliminar(nodo, nodo->ladoderecho);
        nodo->ladoizquierdo = NULL;
        nodo->ladoderecho = NULL;
        nodo->Nodopadre = NULL;
        delete nodo;
    }
    else
    { // si no tiene hijos, es hoja

        reemplazoNodoEliminar(nodo, NULL);
        nodo->ladoizquierdo = NULL;
        nodo->ladoderecho = NULL;
        nodo->Nodopadre = NULL;
        delete nodo;
    }
}

/*
   retorna nodo mas izquierdo
*/
Arbol *retornaNodoMasIzquierdo(Arbol *nodo)
{
    if (nodo == NULL)
    { // arbol vacio
        return NULL;
    }
    if (nodo->ladoizquierdo)
    { // si tiene hijo izquierdo
        return retornaNodoMasIzquierdo(nodo->ladoizquierdo);
    }
    else
    { // si no tiene hijo izquierdo, retorna mismo nodo
        return nodo;
    }
}

/*
   reemplazo nodo a eliminar, cuando tiene 1 hijo
*/
void reemplazoNodoEliminar(Arbol *nodo, Arbol *nuevoNodo)
{
   
    if (nodo->Nodopadre && nodo->Nodopadre != NULL)
    { // si existe el padre, al padre se le asigna el nieto

        if (nodo->Nodopadre->ladoizquierdo) // existe el hijo izquierdo del padre
        {
            if (nodo->datoainsertar == nodo->Nodopadre->ladoizquierdo->datoainsertar)
            { // si es hijo del lado izquierdo
                nodo->Nodopadre->ladoizquierdo = nuevoNodo;
            }
        }
        if (nodo->Nodopadre->ladoderecho) // existe el hijo derecho del padre
        {
            if (nodo->datoainsertar == nodo->Nodopadre->ladoderecho->datoainsertar)
            { // si es hijo del lado derecho
                nodo->Nodopadre->ladoderecho = nuevoNodo;
            }
        }
    }
     if (nuevoNodo)
    {                                   // si existe nuevo nodo a reemplazar
        nuevoNodo->Nodopadre = nodo->Nodopadre; // asignamos nuevo padre, al nieto
    }
}

//preorden
void preOrden(Arbol*arbol){
	if(arbol==NULL){

	}
	else{
		cout<<arbol->datoainsertar<< " - ";
		preOrden(arbol->ladoizquierdo);
		preOrden(arbol->ladoderecho);

	}
}
//Inorden
void InOrden(Arbol*arbol){
	if(arbol==NULL){
		return;
	}
	else{
		InOrden(arbol->ladoizquierdo);
		cout<<arbol->datoainsertar<< " - ";
		InOrden(arbol->ladoderecho);
	
	}
}

void PosOrden(Arbol*arbol){
	if(arbol==NULL){
		return;
	}
	else {
		PosOrden(arbol->ladoizquierdo);
		PosOrden(arbol->ladoderecho);
		cout<<arbol->datoainsertar<< " - ";
		
	}
}

/*
    Profundidad del Arbol
*/
int profundidad(Arbol *nodo)
{
    if (nodo != NULL)
    {
        int izq = profundidad(nodo->ladoizquierdo);
        int der = profundidad(nodo->ladoderecho);
        if (izq > der)
        {
            return izq + 1;
        }
        else
        {
            return der + 1;
        }
    }
    else
    {
        return 0 - 1;
    }
    if (nodoRaiz == NULL)
    {
        cout << "\n\n\t\t\tAtencion, el Arbol esta vacio !\n\n";
    }
    
}
