#include <iostream>
#include "Empleado.h"
#include "Asalariado.h"
#include "SubContratado.h"
#include "Vendedor.h"
using namespace std;

void main(){

	Empleado *vecE[5];

	for(int i=0;i<5;i++){
		vecE[i] = NULL;
	}

	vecE[0]= new Asalariado("Rodolfo Gomez",2500);
	vecE[1]= new SubContratado("Adolfo Perez", 30, 30);
	vecE[2]= new SubContratado("Pandolfo Lopez", 50, 40);
	vecE[3]= new Vendedor("Teodolfo Fernandez", 7, 40, 40);
	vecE[4]= new Vendedor("Juansolfo Alvarez", 10, 40, 40);

	for (int i = 0 ; i < 4; i++)  // Ver todo de cada puntero
	{
	vecE[i] -> verTodo ();
	cout << endl;
	}


	for(int i=0;i<5;i++){  // libera cada puntero siempre y cuando no sea NULL
		if(vecE[i]){
			delete vecE[i];
		}
	}

	getchar();
}