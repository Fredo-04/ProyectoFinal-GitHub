#pragma once
#include <iostream>
using namespace std;

class Persona{
    private:
    string clave;
    protected:
    string correoelec;
    public:
    string codigo;
    string nombre;
    int telefono;
    Persona(string nombre,string codigo,int telefono,string clave,string correoelec){
        this->nombre=nombre;
        this->codigo=codigo;
        this->telefono=telefono;
        this->clave=clave;
        this->correoelec=correoelec;
    }
    friend ostream& operator << (ostream& os, Persona& per){
        
    }
};

class ClienteIndividual:public Persona{

};

class ClienteCorporativo:public Persona{
    
};