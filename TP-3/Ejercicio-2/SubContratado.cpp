#include "SubContratado.h"
#include <iostream>
using namespace std;

SubContratado::SubContratado(const char* nombre, float tarifa, float nohoras):Empleado(nombre){
	_tarifa = tarifa;
	_nohoras = nohoras;
}

void SubContratado::setTarifa(float tarifa){ //Extiende
	_tarifa = tarifa;
}

void SubContratado::setHoras(float nohoras){ //Extiende
	_nohoras = nohoras;
}

void SubContratado::verTodo(){ //Especializa
	Empleado::verTodo();
	cout << "Tarifa: " << _tarifa << endl << "No. Horas: " << _nohoras << endl << "Sueldo: " << SubContratado::calcularPago() << endl;
}
	
float SubContratado::calcularPago(){ //Especializa
	return (_tarifa * _nohoras);
}