#include <iostream>
#include <vector>
#include "Contacto.h"
#include "VectorContactos.h"

using namespace std;

int main()
{
    int resp=1000;
    VectorContactos *contcs=new VectorContactos();
    while(resp!=0)
    {
        cout<<"Que desea hacer:\n1. Agregar contacto.\n2. Mostrar contactos.\n3. Mostrar Contactos de un tipo.\n4. Mostrar Datos de un contacto basado en nombre y apellido.\n5. Modificar Datos.\n6. Agregar numero.\n7. Borre Contacto.\n0. Terminar"<<endl;
        cin>>resp;

        if(resp==1)
        {
            string nombre="";
            string apellido="";
            string tipo="";
            string email="";
            string categoria="";
            string tipoTel="";
            int tel=0;
            cout<<"De el nombre del contacto: "<<endl;
            cin>>nombre;
            cout<<"El apellido: "<<endl;
            cin>>apellido;
            cout<<"Que tipo de contacto esta agregando(familiar, trabajo, amigo, comercial, profesional) "<<endl;
            cin>>tipo;
            cout<<"Cual es el email: "<<endl;
            cin>>email;
            cout<<"Cual es el tipo de telefono(cel,casa,oficina) "<<endl;
            cin>>tipoTel;
            cout<<"Cual es el numero de telefono "<<endl;
            cin>>tel;
            multimap<string,int>mapa;
            mapa.insert(std::make_pair(tipoTel, tel));
            contcs->inserte(Contacto(nombre,apellido,tipo,email,mapa));

        }

        else if(resp==2)
        {
            contcs->show();

        }
        else if (resp==3)

        {
            string n="";
            cout<<"Ingrese el tipo de contacto deseado a consultar (familiar, trabajo, amigo, comercial, profesional)"<<endl;
            cin>>n;
            contcs->mostrarTipo(n);

        }
        else if (resp==4)
        {
            string n="";
            string a="";
            cout<<"Ingrese el nombre"<<endl;
            cin>>n;
            cout<<"Ingrese el apellido"<<endl;
            cin>>a;
            contcs->mostrarDatosContacto(n,a);
        }
        else if(resp==5)
        {
            contcs->modificarDatos();
        }else if(resp==6)
        {
            contcs->agregarTelefono();
        }else if(resp==7)
        {
            string nom="";
            string ape="";
            cout<<"Ingrese el nombre del contacto a borrar"<<endl;
            cin>>nom;
            cout<<"Ingrese el apellido del contacto a borrar"<<endl;
            cin>>ape;
            contcs->borreContacto(nom,ape);
        }
    }
}







