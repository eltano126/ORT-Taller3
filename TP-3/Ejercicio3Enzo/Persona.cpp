#include "Persona.h"

using namespace std;

Persona::Persona(const char* nombre, int edad, char estadocivil){
	
	//_nombre = NULL;    no se porque puso esto brian!!
	_nombre = new char[30];
	setNombre(nombre);
	_edad = edad;
	_estado_civil = estadocivil;

}

void Persona::setNombre(const char* nombre){
	
	//ESTO NO SE PORQUE ESTA
	if(_nombre){
		delete []_nombre;
	}

	_nombre = new char[strlen(nombre)+1];
	strcpy(_nombre,nombre);

}

void Persona::verTodo(){
	cout << "Nombre: " << _nombre << endl;
	cout << "Edad: " << _edad << endl;
	cout << "Estado Civil: " << _estado_civil << endl;
}