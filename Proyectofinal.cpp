#include <iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;

struct costoporArticulo{ 
    string nombre;
    int cantidad;
    double precio;
    double costoporArt;
};

void leerdatos (int cant, costoporArticulo producto[]){/*Se crea la función que captura los
datos introducidos por teclado*/
        for (int i = 0; i < cant; i++)
        {
            cout<<"Introduzca el nombre del producto "<<i+1<<endl;
            cin>>producto[i].nombre;
            cout<<"Introduzca la cantidad de producto "<<i+1<<" que lleva"<<endl;
            cin>>producto[i].cantidad;
            while ((producto[i].cantidad)<0){/*Se valida la cantidad de producto que el 
            usuario puede ingresar, para que no ingrese cantidades negativas*/
            cout<<"Introduzca la cantidad de producto "<<i+1<<" que lleva"<<endl;
            cout<<"Tienen que ser valores positivos"<<endl;
            cin>>producto[i].cantidad;
            }
            cout<<"Introduzca el precio del producto "<<i+1<<endl;
            cin>>producto[i].precio;
            while ((producto[i].precio)<0){/*Se valida el precio del producto también, para
            que el usuario no ingrese cantidades negativas*/
            cout<<"Introduzca precio del producto "<<i+1<<endl;
            cout<<"Tienen que ser valores positivos"<<endl;
            cin>>producto[i].precio;}
        }  
}

void costounitario(int cant, costoporArticulo producto[]){/*Función para calcular el 
costo total por artículo*/

    for (int i = 0; i < cant; i++)
    {
        (producto[i].costoporArt)=(producto[i].precio)*(producto[i].cantidad);
    }
}

double total (int cant, costoporArticulo producto[]){/*Función para calcular la suma total,
sumando cada costo por artículo*/
    double suma=0;
    double costototal;
    for (int i = 0; i < cant; i++)
    {
        suma=suma+producto[i].costoporArt;
    }
    costototal=suma;
    return costototal;
}

void mostrardatos (int cant, double sumatotal, costoporArticulo producto[]){/*Función
para mostrar los datos del arreglo*/
        
        cout<<endl;
        cout<<"Compra realizada por el cliente: "<<endl;
        for (int i = 0; i < cant; i++)
   
        {
            cout<<"Nombre del producto "<<i+1<<": ";
            cout<<producto[i].nombre<<endl;
            cout<<"Cantidad de producto que lleva: ";
            cout<<producto[i].cantidad<<endl;
            cout<<"Precio del producto: $";
            cout<<producto[i].precio<<endl;
            cout<<"Compra total del artículo: $";
            cout<<producto[i].costoporArt<<endl;
            cout<<endl;
        }  
        cout<<"Su compra total es de: $"<<sumatotal;
}

int main(){ /*Función main*/
    int cant;
    double sumatotal;
    costoporArticulo nombre, cantidad, precio, costoporArt; 
    cout<<"Ingrese la cantidad de productos que desea enlistar"<<endl;
    cin>>cant;
    /*Llamada a las funciones*/
    costoporArticulo producto[cant];
    leerdatos (cant, producto);
    costounitario (cant, producto);
    sumatotal=total (cant, producto); /*Se ingresa en otra variable el valor
    retornado para luego utilizarlo en la siguiente función*/
    mostrardatos (cant, sumatotal, producto);
}

