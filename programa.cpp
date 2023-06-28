#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int validarTelefono(int telefono){
    string telefonoStr = to_string(telefono);
    while (telefonoStr.length() != 9){
        cout << "El número de telefono debe tener 9 digitos. Inténtelo nuevamente: ";
        cin >> telefono;
        telefonoStr = to_string(telefono);
    }
    return telefono;
}
class Persona{
    private:
    string clave;
    protected:
    string correoelec;
    public:
    string codigo;
    string nombre;
    int telefono;
    Persona(string nombre, string codigo):nombre(nombre),codigo(codigo){}
    Persona(string nombre,string codigo,int telefono,string clave,string correoelec){
        this->nombre=nombre;
        this->codigo=codigo;
        this->telefono=telefono;
        this->clave=clave;
        this->correoelec=correoelec;
    }
    friend ostream& operator << (ostream& os, Persona& per){
        os << "Nombre: " << per.nombre << endl;
        os << "Codigo: " << per.codigo << endl;
        os << "Telefono: " << per.telefono << endl;
        os << "Correo Electronico: " << per.correoelec << endl;
        return os;
    }
    void agregarEnarchivo();
};

class ClienteIndividual:public Persona{
    string nivel;
    public:
    float desc;
    ClienteIndividual(string nombre, string codigo, int telefono, string clave, string correoelec): Persona(nombre, codigo, telefono, clave, correoelec){
        nivel = "C";
        desc = 3/100;
    }
    void nivelA(){
        if(nivel == "A"){
            cout << "Ya se encuentra en categoria A\n";
        }
        else{nivel = "A";}
    }
    void nivelB(){
        if(nivel == "B"){
            cout << "Ya se encuentra en categoria B\n";
        }
        else{nivel = "B";}
    }
    void nivelC(){
        if(nivel == "C"){
            cout << "Ya se encuentra en categoria C\n";
        }
        else{nivel = "C";}
    }
    void nivelD(){
        if(nivel == "D"){
            cout << "Ya se encuentra en categoria D\n";
        }
        else{nivel = "D";}
    }
    void agregarEnarchivo(){
        ofstream archivo("clientes_individuales.csv");
        if (archivo.is_open()){
            archivo << nombre << "," << codigo << "," << telefono << "," << correoelec << "," << nivel << endl;
            archivo.close();
            cout << "El cliente individual se ha agregado correctamente al archivo." << endl;
        } 
        else{
            cout << "Error al abrir el archivo." << endl;
        }
    }
    float getDescuento(){
        return desc;
    }
};

class ClienteCorporativo:public Persona{
    string nivel;
    public:
    float desc;
    ClienteCorporativo(string nombre, string codigo, int telefono, string clave, string correoelec): Persona(nombre, codigo, telefono, clave, correoelec){
        nivel = "C";
        desc = 10/100;
    }
    void nivelA(){
        if(nivel == "A"){
            cout << "Ya se encuentra en categoria A\n";
        }
        else{nivel = "A";}
    }
    void nivelB(){
        if(nivel == "B"){
            cout << "Ya se encuentra en categoria B\n";
        }
        else{nivel = "B";}
    }
    void nivelC(){
        if(nivel == "C"){
            cout << "Ya se encuentra en categoria C\n";
        }
        else{nivel = "C";}
    }
    void nivelD(){
        if(nivel == "D"){
            cout << "Ya se encuentra en categoria D\n";
        }
        else{nivel = "D";}
    }
    void agregarEnarchivo(){
        ofstream archivo("clientes_corporativos.csv");
        if (archivo.is_open()){
            archivo << codigo << "," << nombre << "," << telefono << "," << correoelec << "," << nivel << endl;
            archivo.close();
            cout << "El cliente individual se ha agregado correctamente al archivo." << endl;
        } 
        else{
            cout << "Error al abrir el archivo." << endl;
        }
    }
    float getDescuento(){
        return desc;
    }
};

class Vendedor:public Persona{
    public:
    float salario;
    Vendedor(string nombre, string codigo, float salario):Persona(nombre,codigo){
        this->salario=salario;
    }
};

class Producto;

class GestorVenta{
public:
    float calcularTotal(const Producto& producto, float descuento);
};

class Producto{
private:
    string nombre;
    float precio;
    int stock;
    static int contadorProductos;
public:
    Producto(const string& nombre, float precio, int stock) : nombre(nombre), precio(precio), stock(stock) {
        contadorProductos++;
    }
    void agregarStock(int cantidad) {
        stock += cantidad;
    }
    void modificarPrecio(float nuevoPrecio){
        precio = nuevoPrecio;
    }
    static int aumentarCantidad() {
        contadorProductos++;
    }
    friend float GestorVenta::calcularTotal(const Producto& producto, float descuento);
};

float GestorVenta::calcularTotal(const Producto& producto, float descuento) {
    float total = (producto.precio * producto.stock) * (descuento);
    return total;
}