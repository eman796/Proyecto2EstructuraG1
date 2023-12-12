#include <iostream>  
#include <conio.h>   
using namespace std;

// Nodo
struct Arbol
{
    int informacion;
    struct Arbol *ptrIzquierda;
    struct Arbol *ptrDerecha;
    struct Arbol *ptrPadre;
};

struct Arbol *nodoRaiz;

// & pasa el puntero por referencia en lugar de por valor, y se pueda modificar
void insertarNodo(Arbol *&arbol, int dato, Arbol *ptrPadre);
void mostrarTodoArbol(Arbol *, int);
void buscarNodo(Arbol *, int);
void eliminarNodo(Arbol *, int);
void verificaHijos(Arbol *);
Arbol *retornaNodoMasIzquierdo(Arbol *);
void reemplazoNodoEliminar(Arbol *, Arbol *);
int profundidadArbol(Arbol *);
void MostrarpreOrden(Arbol*arbol);
void MostrarInOrden(Arbol*arbol);
void MostrarPosOrden(Arbol*arbol);

Arbol *arbol = NULL; // creamos el arbol a partir del coso Arbol

int main()
{
    int valor; //Valor digitado por el usuario
    int opcion; //Opcion digitado por el usuario
    while (opcion != 9)//Mientras la opcion
    {
        system("color f5");
        system("cls");  
        cout << " \n\n\n\n\t\t\t*****  Proyecto Final 2  ****\n\n";
        cout << " \t\t\t\t1. Insertar                                  \n";
        cout << " \t\t\t\t2. Mostrar                             \n";
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
            cin >> valor;//Registramos el valor ingresado por el usuario al nodo
            insertarNodo(arbol, valor, NULL);//Pide 1. Arbol donde se insertara el valor,2. Valor a insertar, 3. Puntero padre
            getch();
            break;

        case 2: //      mostrar todo el Arbol
            system("cls");
            cout << " \n\n\n\n\t\t\t******  Mostrar todo el Arbol   ******\n\n";
            mostrarTodoArbol(arbol, 0);//Mostramos el arbol sin ningun espacio
            getch();
            break;

        case 3: //      Buscar
            system("cls");
            cout << " \n\n\n\n\t\t\t******   Buscar     ******\n\n";
            cout << " \t\t\tIngrese el valor a buscar: ";
            cin >> valor;
            buscarNodo(arbol, valor);//Buscamos un valor proporcionado por el usuario en el arbol
            getch();
            break;

        case 4: //      eliminar
            system("cls");
            cout << " \n\n\n\n\t\t\t******  Eliminar   ******\n\n";
            cout << " \t\t\tIngrese el valor a eliminar: ";
            cin >> valor;
            eliminarNodo(arbol, valor);//Eliminamos un valor digitado por el usuario
            getch();
            break;

        case 5: //      Profundidd del arbol
            system("cls");
            cout << " \n\n\n\n\t\t\t******   Profundidad   ******\n\n";
            cout << " \t\t\tLa profundidad del Arbol es: " << profundidadArbol(arbol) << " !!!\n\n\n";//Mediante el metodo "profundadadArbol()]", mostramos la profundidad que tiene el árbol
            getch();
            system("exit");//Damos la orden de salida
            break;
            
        case 6: //      mostrar preorden
            system("cls");
            cout << " \n\n\n\n\t\t\t******  Mostrar el preorden del arbol   ******\n\n";
            MostrarpreOrden(arbol);//Mostramos el arbol en preorden
            getch();
            break;
            
        case 7: //      mostrar inorden
            system("cls");
            cout << " \n\n\n\n\t\t\t******  Mostrar el inorden del arbol   ******\n\n";
            MostrarInOrden(arbol);//Mostramos arbol en orden
            getch();
           break;

        case 8: //      mostrar Posorden
            system("cls");
            cout << " \n\n\n\n\t\t\t******  Mostrar el Posorden del arbol   ******\n\n";
            MostrarPosOrden(arbol);//Mostramos el arbol en PosOrden
            getch();
            break;
        case 9: //      salir del sistema
            system("cls");
            cout << " \n\n\n\n\t\t\t******  Saliendo del Sistema ******\n\n";
            getch();
            system("exit");//Salimos del sistema
            break;

        default: //     el error de capa 8 digito una opcion incorrecta
            system("cls");
            cout << " \n\n\n\n\t\t****** Digite una opcion valida del menu !!! ******\n\n";
            getch();
            break;

        } // switch
    }     // while

    return 0;//fin del main
}



void insertarNodo(Arbol *&nodo, int valor, Arbol *ptrPadre)//    metodo usado para insertar un dato
{
    if (nodo == NULL)//Si el nodo esta vacio
    {
        Arbol *nuevoNodo = new Arbol();// CREAMOS NODO
        nuevoNodo->informacion = valor;//Se accede a las propiedades
        nuevoNodo->ptrDerecha = NULL;//Damos nula la propiedad derecha del arbol
        nuevoNodo->ptrIzquierda = NULL;//Damos nula la propiedad izquierda del arbol
        nuevoNodo->ptrPadre = ptrPadre;//Se iguala el puntero padre al puntero padre del argumento de la funcion
        nodo = nuevoNodo;//tenga el valor del nuevo nodo
        if (nodoRaiz == NULL)//Si no hay nada en el nodo raiz
        {
            nodoRaiz = nuevoNodo;//nodo inicial
        }
        cout << "\n\n\t\t\tSe agrego el dato al Arbol satisfactoriamente !";
    }
    else
    {
        if (valor < nodo->informacion)//Si el valor digitado por el usuario es menor que la informacion ya guardada
        {
            insertarNodo(nodo->ptrIzquierda, valor, nodo);//Se inserta el nodo a laizquierdda
        }
        else if (valor > nodo->informacion)// Si el valor digitado por el usuario es mayor que la informacion ya guardada
        {
            insertarNodo(nodo->ptrDerecha, valor, nodo);//El nodo se insertya en la parte derecha
        }
        else//Si el valor digitado es igual al de la informacion guardada
        {
            cout << "\n\n\t\t\tAtencion, el nodo ya se encuentra en el Arbol no se puede guardar !";
        }
    }
}


void mostrarTodoArbol(Arbol *nodo, int espacio)//Este metodo se encarga de mostrar el arbol
{
    if (nodo != NULL)//Si el noso de la funcion (arbol) no tiene nada
    {

        if (nodo->ptrDerecha != NULL)//Si la parte derecha del nodo esta nula
        {
            mostrarTodoArbol(nodo->ptrDerecha, espacio + 5);//Se muestra la parte derecha del nodo
        }
        for (int i = 0; i < espacio; i++)
        {
            cout << " ";
        }
        cout << nodo->informacion << "\n";//Se itera la informacion en el arbol
        if (nodo->ptrIzquierda != NULL)//Si la pare derecha del nodo está nula
        {
            mostrarTodoArbol(nodo->ptrIzquierda, espacio + 5);//Se muestra la parte izquierda de la parte izquierda
        }
    }
    if (nodoRaiz == NULL)//Si el nodo raiz esta vacio
    {
        cout << "\n\n\t\t\tAtencion, el Arbol esta vacio !\n\n";
    }
}


void buscarNodo(Arbol *nodo, int valor)//Metodo buscar: El usuario da un valor y, con este, se buscan coincidencias dentro del arbol
{
    if (nodo != NULL)//Si el nodo no es nulo (Hay datos en él)
    {
        if (nodo->informacion == valor)//Si la informacion del nodo es igual al valor (Hay una coincidencia dentro del arbol)
        {
            cout << "\n\n\t\t\tEl dato si esta en el Arbol [" << nodo->informacion << "] !!";
        }
        else if (valor < nodo->informacion)//Si el valor es menor que el nodo con informacion
        {
            buscarNodo(nodo->ptrIzquierda, valor);//Se busca en la parte izquierda el valor
        }
        else if (valor > nodo->informacion)//Si el valor es mayor que el nodo con informacion
        {
            buscarNodo(nodo->ptrDerecha, valor);//Se busca en la parte derecha el valor digitado por el usuario
        }
    }
    else if (nodoRaiz != NULL && nodo == NULL)//Si el nodo raiz no es nulo y el arbol es nulo (No hay coincidencias de datos)
    {
        cout << "\n\n\t\t\tEl dato buscado no esta en el Arbol !!!\n\n";
    }
    if (nodoRaiz == NULL)//Si el nodo raiz es nulo
    {
        cout << "\n\n\t\t\tAtencion, el Arbol esta vacio !!!\n\n";
    }
}


void eliminarNodo(Arbol *nodo, int valor)//Metodo eliminar: Elimina un valor especificado por el usuario
{
    if (nodo != NULL)//Si el arbol no esta nulo
    {
        if (nodo->informacion == valor)//Si el valor coincide a los datos guardados
        {
            verificaHijos(nodo);//Verificamod la cantidad de hijos que tiene este nodo
            cout << "\n\n\t\t\tSe elimino el dato satisfactoriamente !";
        }
        else if (valor < nodo->informacion)///SI el valor es menor que la informacion ya guardada
        {
            eliminarNodo(nodo->ptrIzquierda, valor);//Se elimina la parte izquierda del arbol
        }
        else if (valor > nodo->informacion)//Si la cosa es al revez
        {
            eliminarNodo(nodo->ptrDerecha, valor);//Se elimina la parte derecha
        }
    }
    else if (nodoRaiz != NULL && nodo == NULL)//Si no se encuentra el valor buscado
    {
        cout << "\n\n\t\t\tEl dato a eliminar no esta en el Arbol !!!\n\n";
    }
    if (nodoRaiz == NULL)//Si no hay nada en el nodo raiz:
    {
        cout << "\n\n\t\t\tAtencion, el Arbol esta vacio !!!\n\n";
    }
}

void verificaHijos(Arbol *nodo)//Se usa en el matodo que elimina nodos para verificar cuatos hijos tiene el arbol a eliminar
{
    if (nodo->ptrIzquierda && nodo->ptrDerecha)//Si hay hihjos al lado derecho y al izquierdo
    {
        Arbol *nodoMasIzquierdo = retornaNodoMasIzquierdo(nodo->ptrDerecha);
        nodo->informacion = nodoMasIzquierdo->informacion;
        verificaHijos(nodoMasIzquierdo);
    }
    else if (nodo->ptrIzquierda)
    { // si existe hijo izquierdo
        reemplazoNodoEliminar(nodo, nodo->ptrIzquierda);
        nodo->ptrIzquierda = NULL;
        nodo->ptrDerecha = NULL;
        nodo->ptrPadre = NULL;
        delete nodo;
    }
    else if (nodo->ptrDerecha)
    { // si existe hijo derecho
        reemplazoNodoEliminar(nodo, nodo->ptrDerecha);
        nodo->ptrIzquierda = NULL;
        nodo->ptrDerecha = NULL;
        nodo->ptrPadre = NULL;
        delete nodo;
    }
    else
    { // si no tiene hijos, es hoja

        reemplazoNodoEliminar(nodo, NULL);
        nodo->ptrIzquierda = NULL;
        nodo->ptrDerecha = NULL;
        nodo->ptrPadre = NULL;
        delete nodo;
    }
}


Arbol *retornaNodoMasIzquierdo(Arbol *nodo)//Devuelve el nodo mas izquierdo
{
    if (nodo == NULL)
    { // arbol vacio
        return NULL;
    }
    if (nodo->ptrIzquierda)
    { // si tiene hijo izquierdo
        return retornaNodoMasIzquierdo(nodo->ptrIzquierda);
    }
    else
    { // si no tiene hijo izquierdo, retorna mismo nodo
        return nodo;
    }
}


void reemplazoNodoEliminar(Arbol *nodo, Arbol *nuevoNodo)//Si el nodo a eliminar tiene 1 hijo, se reemplaza este nodo eliminado
{
   
    if (nodo->ptrPadre && nodo->ptrPadre != NULL)
    { // si existe el padre, al padre se le asigna el nieto

        if (nodo->ptrPadre->ptrIzquierda) // SI existe un hijo izquierdo del padre
        {
            if (nodo->informacion == nodo->ptrPadre->ptrIzquierda->informacion)
            { // si es hijo del lado izquierdo
                nodo->ptrPadre->ptrIzquierda = nuevoNodo;
            }
        }
        if (nodo->ptrPadre->ptrDerecha) // existe el hijo derecho del padre
        {
            if (nodo->informacion == nodo->ptrPadre->ptrDerecha->informacion)
            { // si es hijo del lado derecho
                nodo->ptrPadre->ptrDerecha = nuevoNodo;
            }
        }
    }
     if (nuevoNodo)
    {                                   // si existe nuevo nodo a reemplazar
        nuevoNodo->ptrPadre = nodo->ptrPadre; // asignamos nuevo padre, al nieto
    }
}

//preorden
void MostrarpreOrden(Arbol*arbol){
	if(arbol==NULL){
		return;
	}
	else{
		cout<<arbol->informacion<< " - ";
		MostrarpreOrden(arbol->ptrIzquierda);
		MostrarpreOrden(arbol->ptrDerecha);
	}
}
//InOrden
void MostrarInOrden(Arbol*arbol){
	if(arbol==NULL){
		return;
	}
	else{
		MostrarInOrden(arbol->ptrIzquierda);
		cout<<arbol->informacion<< " - ";
		MostrarInOrden(arbol->ptrDerecha);
	
	}
}

void MostrarPosOrden(Arbol*arbol){
	if(arbol==NULL){
		return;
	}
	else {
		MostrarPosOrden(arbol->ptrIzquierda);
		MostrarPosOrden(arbol->ptrDerecha);
		cout<<arbol->informacion<< " - ";
		
	}
}


int profundidadArbol(Arbol *nodo)//Mide la profundidad de un arbol
{
    if (nodo != NULL)//Si el nodo no es nulo
    {
        int izq = profundidadArbol(nodo->ptrIzquierda);//Mide la profundidad del lado izquierdo
        int der = profundidadArbol(nodo->ptrDerecha);//Mide la profundidad del lado derecho
        if (izq > der)//Si el lado izquierdo es mayor al derecho
        {
            return izq + 1;//]Retorna el lado izquierdo adicionado a 1
        }
        else//SI el lado derechoi es mayor al izquierdo
        {
            return der + 1;//Retorna el lado derecho +1
        }
    }
    else//Si son iguales:
    {
        return 0 - 1;//Retorna -1
    }
    if (nodoRaiz == NULL)//Si el nodo nazi es nulo
    {
        cout << "\n\n\t\t\tAtencion, el Arbol esta vacio !\n\n";
    }
    
}
