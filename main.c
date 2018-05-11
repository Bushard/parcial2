#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"
#include "utn.h"
#define QTY_CLIENTE 10
#define QTY_PUBLICACIONES 100

int main()
{
    ECliente arrayClientes[QTY_CLIENTE];
    EPublicacion arrayPublicaciones[QTY_PUBLICACIONES];
    int menu;
    int auxiliarId;
    cliente_init(arrayClientes,QTY_CLIENTE);
    publicacion_init(arrayPublicaciones, QTY_PUBLICACIONES);
    do
    {
        getValidInt("1.Alta Cliente\n2.Modificar dato de cliente \n3.Baja de cliente\n4.Publicar\n5.Paudar publicacion\n6.Reanudar publicacion\n7.Imprimir clientes\n8.Imprimir publicaciones\n9.Informar cliente\n10.Informar Publicaciones.\n11.Salir\n",
                    "\nNo valida\n",&menu,1,11,1);
        switch(menu)
        {
            case 1:
                cliente_alta(arrayClientes,QTY_CLIENTE);
                break;
            case 2:
                cliente_mostrar(arrayClientes, QTY_CLIENTE);
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                cliente_modificacion(arrayClientes,QTY_CLIENTE,auxiliarId);

                break;
            case 3:
                cliente_mostrar(arrayClientes, QTY_CLIENTE);
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                cliente_baja(arrayClientes,QTY_CLIENTE,auxiliarId);
                break;
            case 4:
                cliente_mostrar(arrayClientes, QTY_CLIENTE);
                publicacion_alta(arrayPublicaciones, QTY_PUBLICACIONES);
                break;
            case 5:
                cliente_ordenar(arrayClientes,QTY_CLIENTE,0);
                break;
            case 6:
                cliente_mostrar(arrayClientes,QTY_CLIENTE);
                //cliente_mostrarDebug(arrayClientes,QTY_CLIENTE);
                break;
        }

    }while(menu != 11);

    return 0;
}
