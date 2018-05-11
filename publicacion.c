#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "utn.h"

/** \brief
 * \param array EPublicacion*
 * \param limite int
 * \return int
 *
 */
int publicacion_init(EPublicacion* array,int limite)
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

int publicacion_mostrarDebug(EPublicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %d\n",array[i].idPublicacion, array[i].descripcion, array[i].isEmpty);
        }
    }
    return retorno;
}

int publicacion_mostrar(EPublicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - %d - %s - %d\n",array[i].idPublicacion, array[i].descripcion, array[i].isEmpty);
        }
    }
    return retorno;
}

int publicacion_alta(EPublicacion* array,int limite)
{
    int retorno = -1;
    int i;
    int auxId;
    int auxRubro;
    char auxDesc[65];
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidInt("\nID de usuario? ","\nId invalida",&auxId,0,9999999,2))
            {
                if(!getValidInt("\nIngrese el rubro 1-electro 2-jardineria.","Rubro no valido", &auxRubro,1,2,2))
                {
                    if(!getValidString("ingrese descripcion.(max 64 caracteres)","Cadena no valida","Exceso de caracteres. MAX 64", auxDesc, 64, 2))
                    {
                        retorno = 0;
                        strcpy(array[i].descripcion,auxDesc);
                        array[i].idCliente=auxId;
                        array[i].rubro=auxRubro;
                        //------------------------------
                        //------------------------------
                        array[i].idPublicacion = proximoId();
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


int publicacion_baja(EPublicacion* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPublicacion==id)
            {
                array[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}




int publicacion_modificacion(EPublicacion* array,int limite, int id)
{
    int retorno = -1;
    int i;
    char buffer[50];
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPublicacion==id)
            {
                if(!getValidString("\nNombre? ","\nEso no es un descripcion","El maximo es 40",buffer,40,2))
                {
                    retorno = 0;
                    strcpy(array[i].descripcion,buffer);
                    //------------------------------
                    //------------------------------
                }
                else
                {
                    retorno = -3;
                }
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int publicacion_ordenar(EPublicacion* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    EPublicacion auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].descripcion,array[i+1].descripcion) > 0 && orden) || (strcmp(array[i].descripcion,array[i+1].descripcion) < 0 && !orden)) //******
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

/*int buscarLugarLibre(EPublicacion* array,int limite)
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
}*/


/*int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}*/
int publicacion_pausar(EPublicacion* array,int limite, int id)
{
    int retorno = -1;
    int i;
    char buffer[50];
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPublicacion==id)
            {
                if(!getValidInt("Ingrese el ID de la publicacion"))
                {
                    retorno = 0;
                    strcpy(array[i].descripcion,buffer);
                    //------------------------------
                    //------------------------------
                }
                else
                {
                    retorno = -3;
                }
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
