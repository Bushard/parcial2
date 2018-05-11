#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"

/** \brief
 * \param array ECliente*
 * \param limite int
 * \return int
 *
 */
int cliente_init(ECliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int cliente_mostrarDebug(ECliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %d\n",array[i].idCliente, array[i].nombre, array[i].isEmpty);
        }
    }
    return retorno;
}

int cliente_mostrar(ECliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] -ID: %d -Nombre: %s -Apellido %s -CUIT: %d -isEmpty %d\n",array[i].idCliente, array[i].nombre, array[i].apellido,array[i].cuit, array[i].isEmpty);
        }
    }
    return retorno;
}

int cliente_alta(ECliente* array,int limite)
{
    int retorno = -1;
    int i;
    char auxNombre[50];
    char auxApellido[50];
    int auxCuit;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","\nEl maximo son 50 letras",auxNombre,50,2))
            {
                if(!getValidString("\nApellido? ", "\nApellido no valido","\nEl maximo son 50 letras",auxApellido,50,2))
                {
                        if(!getValidInt("Ingrese su cuit","Solo numerico!", &auxCuit,0,9999999,2))
                        {
                            retorno = 0;
                            strcpy(array[i].nombre, auxNombre);
                            strcpy(array[i].apellido, auxApellido);
                            array[i].cuit = auxCuit;
                            //------------------------------
                            array[i].idCliente = proximoId();
                            array[i].isEmpty = 0;

                        }


                }

            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


int cliente_baja(ECliente* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==id)
            {
                array[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}




int cliente_modificacion(ECliente* array,int limite, int id)
{
    int retorno = -1;
    int i;
    char auxNombre[50];
    char auxApellido[50];
    int auxCuit;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==id)
            {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","\nEl maximo son 50 letras",auxNombre,50,2))
            {
                if(!getValidString("\nApellido? ", "\nApellido no valido","\nEl maximo son 50 letras",auxApellido,50,2))
                {
                    //getString("Ingrese un cuit: XX-XXXXXXXX-X ", auxCuit);

                        if(!getValidInt("Ingrese su cuit","Solo numerico!", &auxCuit,0,9999999,2))
                        {
                            retorno = 0;
                            strcpy(array[i].nombre, auxNombre);
                            strcpy(array[i].apellido, auxApellido);
                            array[i].cuit = auxCuit;

                        }
                        else
                        {
                            retorno = -3;
                        }
                 }
              }
              }
        retorno = 0;
        break;
        }

    }
    return retorno;
}

int cliente_ordenar(ECliente* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    ECliente auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

int buscarLugarLibre(ECliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}
