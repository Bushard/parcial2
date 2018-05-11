#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    //------------
    int cuit;
    int idCliente;
    int isEmpty;
}ECliente;
#endif // CLIENTE_H_INCLUDED


int cliente_init(ECliente* array,int limite);
int cliente_mostrar(ECliente* array,int limite);
int cliente_mostrarDebug(ECliente* array,int limite);
int cliente_alta(ECliente* array,int limite);
int cliente_modificacion(ECliente* array,int limite, int id);
int cliente_ordenar(ECliente* array,int limite, int orden);
int buscarLugarLibre(ECliente* array,int limite);
int proximoId();


