#ifndef PROFESOR_H
#define PROFESOR_H
#include "persona.h"

class Profesor: public Persona{
private:
	char _departamento[30]; // Analista, Control, Quimica
	char _categoria[20]; // Titular, Suplente etc., de departamento
public:
	Profesor( const char* nombre, int edad, char estadocivil, const char* departamento, const char* categoria);
	void verTodo(); // muestra todos los datos del profesor
	const char* getCategoria(){return _categoria;}
	char getTipo(){return 'P';} // devuelve ‘P’ de profesor
};

#endif