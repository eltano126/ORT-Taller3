#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
using namespace std;
class Empleado{
	char _nombre[21];
public:
	Empleado();
	Empleado(const char* nombre);
	void setNombre(const char* nombre);
	const char* getNombre();
	float calcularPago();
	virtual void verTodo() = 0;
};

#endif