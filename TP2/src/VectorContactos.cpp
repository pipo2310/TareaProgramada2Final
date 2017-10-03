#include "VectorContactos.h"
#include "Contacto.h"
#include <iostream>
#include <algorithm>

using namespace std;
struct menorQue
{
    inline bool operator() (const Contacto& con1, const Contacto& con2)
    {
        if (con1.apellido != con2.apellido)
        {
            return con1.apellido < con2.apellido;
        }
        return con1.nombre < con2.nombre;
    }
};

VectorContactos::VectorContactos()
{
    //ctor
}

VectorContactos::~VectorContactos()
{
    //dtor
}
void VectorContactos::inserte(Contacto c)
{
    vecCont.push_back(c);
}

void VectorContactos::show()
{
    std::vector<Contacto>::iterator it;
    sort(vecCont.begin(), vecCont.end(), menorQue());
    std::multimap<string,int>::iterator ite;
    for(it=vecCont.begin(); it<vecCont.end(); it++)
    {
        cout<<"Nombre: "<<it->nombre<<"\nApellido: "<<it->apellido<<"\nTipo: "<<it->tipo<<"\nEmail: "<<it->email<<endl;
        for (ite =it->numeros.begin(); ite != it->numeros.end(); ++ite)
        {
            cout << "Tipo telefono = "<<ite->first << "\nNumero = " << ite->second<<"\n"<<endl;
        }
    }

}
void VectorContactos::agregarTelefono()
{
    string nom="";
    string tipoTel="";
    int tel=0;
    cout<<"Ingrese el nombre del contacto al cual va agregar el numero"<<endl;
    cin>>nom;
    cout<<"Cual es el tipo de telefono(cel,casa,oficina)"<<endl;
    cin>>tipoTel;
    cout<<"Ingrese el numero"<<endl;
    cin>>tel;
    std::vector<Contacto>::iterator it;
    for(it=vecCont.begin(); it<vecCont.end(); it++)
    {
        if(it->nombre==nom)
        {
            it->numeros.insert(std::make_pair(tipoTel, tel));
        }
    }
}

void VectorContactos::mostrarTipo(string t)
{
    std::vector<Contacto>::iterator it;
    for(it=vecCont.begin(); it<vecCont.end(); it++)
    {
        if (it->tipo==t)
        {
            vecContTipo.push_back(*it);
        }
    }
    sort(vecContTipo.begin(), vecContTipo.end(), menorQue());
    cout<<"Los contactos de tipo "<<t<<" son "<<endl;
    for(it=vecContTipo.begin(); it<vecContTipo.end(); it++)
    {
        cout<<"Nombre: "<<it->nombre<<"\nApellido: "<<it->apellido<<"\n"<<endl;
    }
}
void VectorContactos::mostrarDatosContacto(string n,string a)
{
    std::vector<Contacto>::iterator it;
    std::multimap<string,int>::iterator ite;
    for(it=vecCont.begin(); it<vecCont.end(); it++)
    {
        if(it->nombre==n&&it->apellido==a)
        {
            cout<<it->getData()<<endl;
            for (ite =it->numeros.begin(); ite != it->numeros.end(); ++ite)
            {
                cout << "Tipo telefono = "<<ite->first << "\nNumero = " << ite->second<<"\n"<<endl;
            }
        }
    }
}
void VectorContactos::modificarDatos()
{
    std::vector<Contacto>::iterator it;
    int data=0;
    cout<<"Ingrese el dato que desea modificar\n1. Nombre\n2. Apellido\n3. Tipo\n 4. Email"<<endl;
    cin>>data;
    string datoViejo="";
    string datoNuevo="";
    if (data==1)
    {
        cout<<"Ingrese el nombre a cambiar"<<endl;
        cin>>datoViejo;
        cout<<"Ingrese el nombre nuevo"<<endl;
        cin>>datoNuevo;
    }
    else if(data==2)
    {
        cout<<"Ingrese el nombre de la persona cuyo apellido desea cambiar"<<endl;
        cin>>datoViejo;
        cout<<"Ingrese el apellido nuevo"<<endl;
        cin>>datoNuevo;
    }
    else if(data==3)
    {
        cout<<"Ingrese el nombre de la persona cuyo tipo desea cambiar"<<endl;
        cin>>datoViejo;
        cout<<"Ingrese el tipo nuevo"<<endl;
        cin>>datoNuevo;
    }
    else if(data==4)
    {
        cout<<"Ingrese el nombre de la persona cuyo email desea cambiar"<<endl;
        cin>>datoViejo;
        cout<<"Ingrese el email nuevo"<<endl;
        cin>>datoNuevo;
    }

    for(it=vecCont.begin(); it<vecCont.end(); it++)
    {
        if(it->nombre==datoViejo)
        {
            if(data==1)
            {
                it->setNombre(datoNuevo);
            }
            else if(data==2)
            {
                it->setApellido(datoNuevo);
            }
            else if(data==3)
            {
                it->setTipo(datoNuevo);
            }
            else if(data==4)
            {
                it->setEmail(datoNuevo);
            }
        }
    }
}
void VectorContactos::borreContacto(string n,string a)
{
    int contador=0;
    bool encontrado=false;
    std::vector<Contacto>::iterator it;
    for(it=vecCont.begin(); it<vecCont.end(); it++)
    {
        if(it->nombre==n&&it->apellido==a)
        {
            encontrado=true;
        }
        if(!encontrado)
        {
            contador++;
        }
    }
    it=vecCont.begin();
    vecCont.erase(it+contador);
}


