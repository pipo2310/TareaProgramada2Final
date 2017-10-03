#ifndef VECTORCONTACTOS_H
#define VECTORCONTACTOS_H
#include <vector>
#include "Contacto.h"

class VectorContactos
{
public:
    VectorContactos();
    virtual ~VectorContactos();
    void inserte(Contacto c);
    void show();
    void mostrarTipo(string);
    void mostrarDatosContacto(string,string);
    void modificarDatos();
    void agregarTelefono();
    void borreContacto(string,string);
protected:

private:
    vector<Contacto> vecCont;
    vector<Contacto> vecContTipo;
};

#endif // VECTORCONTACTOS_H
