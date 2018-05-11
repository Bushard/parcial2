#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
typedef struct
{
    char descripcion[65];
    int idCliente;
    int rubro;
    int estado;
    //------------
    int idPublicacion;
    int isEmpty;
}EPublicacion;
#endif // PUBLICACION_H_INCLUDED


int publicacion_init(EPublicacion* array,int limite);
int publicacion_mostrar(EPublicacion* array,int limite);
int publicacion_mostrarDebug(EPublicacion* array,int limite);
int publicacion_alta(EPublicacion* array,int limite);
int publicacion_modificacion(EPublicacion* array,int limite, int id);
int publicacion_ordenar(EPublicacion* array,int limite, int orden);
int buscarLugarLibrePublicacion(EPublicacion* array,int limite);
int proximoId();


