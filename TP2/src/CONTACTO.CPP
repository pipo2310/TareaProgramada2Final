#include "Contacto.h"
#include <sstream>

using namespace std;
Contacto::Contacto() {}

Contacto::Contacto(std::string nombre, std::string apellido, std::string tipo, std::string email)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->tipo = tipo;
    this->email = email;
}
Contacto::Contacto(std::string nombre, std::string apellido, std::string tipo, std::string email,std::multimap<string,int> num)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->tipo = tipo;
    this->email = email;
    this->numeros = num;
}
void Contacto::setData(string n,string a,string t,string e)
{
    nombre=n;
    apellido=a;
    tipo=t;
    email=e;
}
void Contacto::setNombre(string n)
{
    nombre=n;
}
void Contacto::setApellido(string a)
{
    apellido=a;
}
void Contacto::setTipo(string t)
{
    tipo=t;
}
void Contacto::setEmail(string e)
{
    email=e;
}
string Contacto::getData()
{
    stringstream os;
    os<<"Nombre: "<<nombre<<"\nApellido: "<<apellido<<"\nTipo: "<<tipo<<"\nEmail: "<<email<<"\n"<<endl;
    return os.str();
}



