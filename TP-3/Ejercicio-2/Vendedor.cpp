#include "Vendedor.h"
#include <iostream>
using namespace std;

Vendedor::Vendedor(const char* nombre, float porcentaje, float tarifa, float nohoras):SubContratado(nombre, tarifa, nohoras){
	_porcentaje = porcentaje;
}

void Vendedor::setPorcentaje(float porcentaje){ //Extiende
	_porcentaje = porcentaje;
}

void Vendedor::verTodo(){ //Especializa
	SubContratado::verTodo();
	cout << "Sueldo + Comision: " << calcularPago() << endl;
}
	
float Vendedor::calcularPago(){ //Especializa
	float basico = SubContratado::calcularPago();
	float comision = basico * _porcentaje / 100;
	return (basico + comision);
}