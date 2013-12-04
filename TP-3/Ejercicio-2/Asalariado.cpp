#include "Asalariado.h"
#include <iostream>
using namespace std;

Asalariado::Asalariado(const char* nombre, float sueldoMensual):Empleado(nombre){
	_sueldomensual = sueldoMensual;
}
	
float Asalariado::getSueldoMensual(){ //Extiende
	return _sueldomensual;
}

float Asalariado::calcularPago(){ //Especializa
	return _sueldomensual;
}
	
void Asalariado::verTodo(){ //Especializa
	Empleado::verTodo();
	cout << "Sueldo: " << calcularPago() << endl; 
}