#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "SubContratado.h"

class Vendedor: public SubContratado{
	float _porcentaje;
public:
	Vendedor(const char* nombre, float porcentaje, float tarifa, float nohoras);
	void setPorcentaje(float porcentaje); //Extiende
	void verTodo(); //Especializa
	float calcularPago(); //Especializa
};

#endif