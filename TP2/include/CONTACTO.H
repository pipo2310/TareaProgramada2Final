#ifndef CONTACTO_H
#define CONTACTO_H
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>


using namespace std;

//Propósito: ver dos formas para sobrecargar el operador de comparación
class Contacto
{
public:
	Contacto();
	Contacto(string n, string a, string t, string e);
	Contacto(string n, string a, string t, string e,multimap<string,int>);
	string getData();
	void setData(string,string,string,string);
	void setData(string,string,string,string,multimap<string,int>);
	void setNombre(string);
	void setApellido(string);
	void setTipo(string);
	void setEmail(string);
	 string nombre;
     string apellido;
     string tipo;
     string email;
     multimap<string,int> numeros;

};


#endif // ESTUDIANTE_H
