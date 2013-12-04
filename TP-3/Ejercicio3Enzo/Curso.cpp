#include "Curso.h"

int contador;
char * nombre;

using namespace std;

Curso::Curso(){
	_opcion =0;
	for (int i=0; i<MAX; i++) {
		_vecPersona[i] = NULL;
	}
}

Curso::~Curso(){
	if(nombre){ 
		delete []nombre;
	}
	for (int i=0; i<MAX;i++) {
		if(_vecPersona[i]){
			delete _vecPersona[i];
		}
	}
}

int Curso::obtenerOpcion(){
	return _opcion;
}

void Curso::generarMenu(){
	cout << "------------------------------------------" << endl;
	cout << "1. Alta de un Alumno" << endl;
	cout << "2. Alta de un Profesor" << endl;
	cout << "3. Mostrar Todos los Datos" << endl;
	cout << "4. Mostrar Nombre Profesor y Categoria" << endl;
	cout << "5. Mostrar Nombre Alumno y Estado" << endl;
	cout << "6. Salir" << endl;
	cout << "------------------------------------------" << endl;

	cout << "Ingrese su Opcion: ";
	cin >> _opcion;
}

void Curso::Procesar(){
	contador = -1;
	generarMenu();

}