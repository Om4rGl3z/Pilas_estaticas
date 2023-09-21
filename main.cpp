#include <iostream>
using namespace std;
const int TAM=100;

class Empleado
{
private:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    int Sueldo;
    string ReportaA;

public:
    Empleado() {}
    Empleado(int ClvEmp,string N,string D, int S, string RptA): ClaveEmpleado(ClvEmp), Nombre(N),Domicilio(D),Sueldo(S),ReportaA(RptA) {}

    void Imprime()
    {
        cout<<"Clave de Empleado: "<<ClaveEmpleado<<endl;
        cout<<"Nombre: "<<Nombre<<endl;
        cout<<"Domicilio: "<<Domicilio<<endl;
        cout<<"Sueldo: "<<Sueldo<<endl;
        cout<<"Reporta ante: "<<ReportaA<<endl;
    }
    void CambiaDomic(string NuevoDom)
    {
        Domicilio = NuevoDom;
    }
    void CambiaReportaA(string NueRpt)
    {
        ReportaA = NueRpt;
    }
    void ActualizarSueldo(int NueSld)
    {
        Sueldo = NueSld;
    }
    void CambiarClave(int NuevaClave)
    {
        ClaveEmpleado = NuevaClave;
    }


    // ==
    bool operator ==(Empleado& e1)
    {
        return (ClaveEmpleado==e1.ClaveEmpleado);
    }




    // <<  Va estar dentro de Imprime
    friend ostream& operator <<(ostream& o, Empleado& E)
    {
        o<<"\nClave: "<<E.ClaveEmpleado;
        o<<"\nNombre: "<<E.Nombre;
        o<<"\nDomicilio: "<<E.Domicilio;
        o<<"\nSueldo: "<<E.Sueldo;
        o<<"\nSe reporta ante: "<<E.ReportaA;
        cout<<endl;
        return o;

    }


    // >>, Va a estar dentro de cambia
    friend istream& operator >>(istream& a,Empleado& e)
    {
        cout<<"Ingrese  Clave: ";
        a>>e.ClaveEmpleado;
        cout<<"Ingrese Nombre: ";
        a>>e.Nombre;
        cout<<"Ingrese Sueldo: ";
        a>>e.Sueldo;
        cout<<"Ingrese  Domicilio: ";
        a>>e.Domicilio;
        cout<<"Ingrese  Reporta a: ";
        a>>e.ReportaA;
        cout<<endl;

        return a;
    }

    //  + ocupa friend porque manipula los datos privados
    friend Empleado operator + (Empleado& E1, Empleado& E2)
    {
        return Empleado(0, "", "", E1.Sueldo + E2.Sueldo, "");

    }


    friend bool operator<(const Empleado& em1, const Empleado& em2)
    {
        return (em1.Sueldo < em2.Sueldo);
    }

    friend bool operator>(const Empleado& em1, const Empleado& em2)
    {
        return (em1.Sueldo > em2.Sueldo);
    }

    friend bool operator!=(const Empleado& em1, const Empleado& em2)
    {
        return (em1.Nombre != em2.Nombre);
    }


};

//****************************Definicion de la clase Pila****************************
//***********************************************************************************
class Pila
{
private:
    Empleado datos[TAM];
    int ult;
    bool elimina(int pos)
    {
        if(vacia() || pos<0 || pos>ult)
        {
            std::cout<<"\n error de eliminacion";
            return true;
        }
        int i=pos;
        while(i<ult)
        {
            datos[i]=datos[i+1];
            i++;
        }
        ult--;
        return false;
    }
    int inserta(Empleado& elem, int pos)
    {
        if(llena()|| pos<0 || pos>ult+1)
        {
            std::cout<<"\n Error de insercion";
            return 0;
        }
        int i=ult+1;
        while(i>pos)
        {
            datos[i]=datos[i-1];
            i--;
        }
        datos[pos]=elem;
        ult++;
        return 1;
    }
public:
    Pila():ult(-1) {}
    bool vacia()const
    {
        if(ult==-1)
            return true;
        return false;
    }
    bool llena()const
    {
        if(ult==TAM-1)
            return true;
        return false;
    }

    int ultimo()const
    {
        return ult;
    }

    friend std::ostream& operator<<(std::ostream & o, Pila& L)
    {
        int i=0;
        std::cout<<"\n";
        while(i<=L.ultimo())
        {
            ;
            o<<L.datos[i];
            i++;
        }
        return o;
    }

    void PUSH(Empleado& elem)
    {
        inserta(elem,ultimo()+1);
    }
    Empleado& POP()
    {
        ult--;
        return datos[ult+1];
    }

    Empleado& TOP()
    {
        return datos[ult];
    }

};
//*************************************************************************************



//****************************Metodo principal****************************
//***********************************************************************************
int main()
{
    Pila Mipila;
    Empleado x;







    int opc=0;

    do
    {
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Top\n";
        cout<<"4. Salir\n";
        cin>>opc;
        switch(opc)
        {
        case 1:
            cout<<"Push\n";
            cin>>x;
            Mipila.PUSH(x);
            cout<<endl;
            break;
        case 2:
            //Comprobar si hay elemento
            if(!Mipila.vacia())
            {
                cout<<Mipila.POP();
                cout<<endl;
            }
            else
            {

                cout<<endl;
                cout<<"Pila vacia\n";
                cout<<endl;
            }
            break;
        case 3:
            //Comprobar si hay elemento
            if(!Mipila.vacia())
            {
                cout<<Mipila.TOP();
                cout<<endl;
            }
            else
            {
                cout<<endl;
                cout<<"Pila vacia\n";
                cout<<endl;
            }
            break;
        }
    }
    while(opc!=4);


    return 0;
}
//***********************************************************************************
