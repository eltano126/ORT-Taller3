#include "laberinto.h"
#include "posicion.h"

Laberinto::Laberinto()
{
	_texto=new char[MAXTEXT];
	strcpy(_texto,TITULO);
	_left=0;
	_top=0;
	_right=0;
	_bottom=0;
	_f=0;
	_c=0;
	_x=1;
	_random=0;
	_alto_lab=ALTO_LAB;
	_ancho_lab=ANCHO_LAB;
	for(_f=0;_f<ALTO_LAB;_f++)
	{
		for(_c=0;_c<ANCHO_LAB;_c++)
		{
			_mapa[_f][_c]=NULL;
		}
	}
	_listo=false;
	_ingreso=false;
	_entrada=false;
	_salida=false;
}

Laberinto::~Laberinto()
{
	if(_texto)
		delete[]_texto;
	for(_f=0;_f<ALTO_LAB;_f++)
	{
		for(_c=0;_c<ANCHO_LAB;_c++)
		{
			if(_mapa[_f][_c])
				delete _mapa[_f][_c];
		}
	}
}

void Laberinto::Limpiar()
{
	_listo=false;
	_ingreso=false;
	_entrada=false;
	_salida=false;
	_x=1;

	cleardevice();

	for (int _f=0;_f<ALTO_LAB;_f++)
	{
		for(int _c=0;_c<ANCHO_LAB;_c++)
		{
			if(_mapa[_f][_c])
			{
				delete _mapa[_f][_c];
				_mapa[_f][_c] = NULL;
			} 
		} 
	}
}

void Laberinto::MostrarTexto()
{
	setcolor(GREEN);
	outtextxy(500,10,_texto);
}

void Laberinto::MostrarTextoSalida()
{
	outtextxy(500,600,"Ganaste!");
}

void Laberinto::MostrarTextoSinSalida()
{
	outtextxy(500,600,"Perdiste!");
}

void Laberinto::CargarFijo(Laberinto*l,int mapaTexto[][ANCHO_LAB])
{
	MostrarTexto();
	_top=80;
	_bottom=95;
	for(_f=0;_f<ALTO_LAB;_f++)
	{
		_left=10;
		_right=25;
		for(_c=0;_c<ANCHO_LAB;_c++)
		{
			if(mapaTexto[_f][_c]==0)
			{
				_mapa[_f][_c]=new Pared(l,_c,_f);
				_mapa[_f][_c]->Dibujar();
				/*Para testear la creaci�n de los objetos
				cout<<_mapa[_f][_c]->getTipo();*/
			}
			else
			{
				_mapa[_f][_c]=new Camino(l,_c,_f);
				/*Para testear la creaci�n de los objetos
				cout<<_mapa[_f][_c]->getTipo();*/
			}
			_left=_right;
			_right=_left+15;
		}
		cout<<endl;
		_top=_bottom;
		_bottom=_bottom+15;
	}
}

void Laberinto::CargarRandom(Laberinto*l,int mapaTexto[][ANCHO_LAB])
{
	MostrarTexto();
	randomize();

	//Borde superior
	for(_c=0;_c<ANCHO_LAB;_c++)
	{
		_mapa[0][_c] = new Pared(l,_c,0);
		_mapa[0][_c]->Dibujar();
	}

	//Borde inferior
	for(_c=0;_c<ANCHO_LAB;_c++)
	{
		_mapa[ALTO_LAB-1][_c] = new Pared(l,_c,ALTO_LAB-1);
		_mapa[ALTO_LAB-1][_c]->Dibujar();
	}

	//Borde izquierdo
	for(_f=1;_f<ALTO_LAB-1;_f++)
	{
		_random = (rand() % 100) + 1;

		//Obligo a generar entrada
		if(!_entrada && _f==ALTO_LAB-2) 
		{ 
			_mapa[_f][0] = new Camino(l,0, _f);
		} 
		else
		{
			//Si arriba hay pared
			if(_mapa[_f-1][0]->getTipo()=='P')
			{
				if(_random<20)
				{ 
					_mapa[_f][0] = new Camino(l,0, _f);
					_entrada = true;
				}
				else
				{ 
					_mapa[_f][0] = new Pared(l,0, _f);
					_mapa[_f][0]->Dibujar();
				}
			}else
			{
				//Evito 2 entradas juntas
				_mapa[_f][0] = new Pared(l,0, _f);
				_mapa[_f][0]->Dibujar();
			}
		}
	}

	//Centro
	for(_c=1;_c<ANCHO_LAB-1;_c++)
	{
		for(_f=1; _f<ALTO_LAB-1;_f++)
		{
			_random = rand() % 100;
			if(_random>15)
			{
				//Evito generar mucho camino
				if(_mapa[_f-1][_c]->getTipo()=='C' 
				&& _mapa[_f-1][_c-1]->getTipo()=='C' 
				&& _mapa[_f][_c-1]->getTipo()=='C')
				{
					_mapa[_f][_c] = new Pared(l,_c, _f);
					_mapa[_f][_c]->Dibujar();
				}
				else
				{
					_mapa[_f][_c] = new Camino(l,_c, _f);
				}
			}
			else
			{
				_mapa[_f][_c] = new Pared(l,_c, _f);
				_mapa[_f][_c]->Dibujar();
			}
		}
	} 

	//Borde derecho
	for(_f=1;_f<ALTO_LAB-1;_f++)
	{
		_random = (rand() % 100) + 1;
		
		//Evito laberinto sin salida
		if(!_salida && _f == ALTO_LAB-2)
		{
			//_mapa[_f][ANCHO_LAB-1] = new Camino(l,ANCHO_LAB-1, _f);
		}
		else
		{
			//Si a la izquierda hay pared
			if(_mapa[_f][ANCHO_LAB-2]->getTipo()=='P')
			{
				_mapa[_f][ANCHO_LAB-1] = new Pared(l,ANCHO_LAB-1, _f);
				_mapa[_f][ANCHO_LAB-1]->Dibujar();
			}
			else
			{
				if(!_salida && _random<20)
				{
					_mapa[_f][ANCHO_LAB-1] = new Camino(l,ANCHO_LAB-1, _f);
					_salida = true;
				}
				else
				{
					_mapa[_f][ANCHO_LAB-1] = new Pared(l,ANCHO_LAB-1, _f);
					_mapa[_f][ANCHO_LAB-1]->Dibujar();
				}
			}
		}
	}

	//Guardo el laberinto generado
	for(int _f=0;_f<ALTO_LAB;_f++)
	{
		for(int _c=0;_c<ANCHO_LAB;_c++)
		{
			if(_mapa[_f][_c]->getTipo()=='P')
			{
				mapaTexto[_f][_c]=0;
			}
			else
			{
				mapaTexto[_f][_c]=1;
			}
		}
	}
}

void Laberinto::ContenidoAString(FILE *&Arch,int mapaTexto[][ANCHO_LAB]) 
{

	for(int _f=0;_f<ALTO_LAB;_f++)
	{
		for(int _c=0;_c<ANCHO_LAB;_c++)
		{
			if(_c==ANCHO_LAB-1)
			{
				fprintf(Arch,"%d\n",mapaTexto[_f][_c]);
			}
			else
			{
				fprintf(Arch,"%d,",mapaTexto[_f][_c]);
			}
		}
	}
}

void Laberinto::Recorrer(char opcion)
{
	while (!_listo && _x < ALTO_LAB-1)
	{
		if (_mapa[_x][0]->esValida()) //Si la posicion es v�lida encontr� una entrada
		{
			switch(opcion)
			{
				case '1':
				_listo = Visitar(_x,0);
				break;

				case '2':
				_listo = Visitar2(_x,0);
				break;

				case '3':
				_listo = Visitar3(_x,0);
				break;
			}
		}
		_x++;
	}

	if(_listo) 
	{
		MostrarTextoSalida();
	} 
	else
	{
		MostrarTextoSinSalida();
	}
	cin.get();
}

bool Laberinto::Visitar(int x, int y)
{
	delay(50);
		
	((Camino*)_mapa[x][y])->CambiarEstado(VISITADO);
	_mapa[x][y]->Dibujar();
	
	if(y == ANCHO_LAB-1)
	{
	   _listo = true;
	}

	//Derecha
	if(!_listo && _mapa[x][y+1]->esValida())
	{
	  _listo = Visitar(x, y+1);
	}

	//Arriba
	if(!_listo && _mapa[x-1][y]->esValida())
	{
	  _listo = Visitar(x-1, y);
	}

	//Abajo
	if(!_listo && _mapa[x+1][y]->esValida())
	{
	   _listo = Visitar(x+1, y);
	}

	//Atras
	if(!_listo && y -1 > 0)
	{ 
		if(!_listo && _mapa[x][y-1]->esValida())
		{
			_listo = Visitar(x, y-1);
		}
	}

	if(!_listo)
	{
		((Camino*)_mapa[x][y])->CambiarEstado(DESCARTADO);
		delay(30);
		_mapa[x][y]->Dibujar();
	}

	return _listo;
}

bool Laberinto::Visitar2(int x, int y)
{
	delay(50);
		
	((Camino*)_mapa[x][y])->CambiarEstado(VISITADO);
	_mapa[x][y]->Dibujar();
	
	if(y == ANCHO_LAB-1)
	{
	   _listo = true;
	}

	//Arriba
	if(!_listo && _mapa[x-1][y]->esValida())
	{
	  _listo = Visitar2(x-1, y);
	}

	//Derecha
	if(!_listo && _mapa[x][y+1]->esValida())
	{
	  _listo = Visitar2(x, y+1);
	}

	//Abajo
	if(!_listo && _mapa[x+1][y]->esValida())
	{
	   _listo = Visitar2(x+1, y);
	}

	//Atras
	if(!_listo && y -1 > 0)
	{ 
		if(!_listo && _mapa[x][y-1]->esValida())
		{
			_listo = Visitar2(x, y-1);
		}
	}

	if(!_listo)
	{
		((Camino*)_mapa[x][y])->CambiarEstado(DESCARTADO);
		delay(30);
		_mapa[x][y]->Dibujar();
	}

	return _listo;
}

bool Laberinto::Visitar3(int x, int y)
{
	delay(50);
		
	((Camino*)_mapa[x][y])->CambiarEstado(VISITADO);
	_mapa[x][y]->Dibujar();
	
	if(y == ANCHO_LAB-1)
	{
	   _listo = true;
	}

	//Abajo
	if(!_listo && _mapa[x+1][y]->esValida())
	{
	   _listo = Visitar3(x+1, y);
	}

	//Arriba
	if(!_listo && _mapa[x-1][y]->esValida())
	{
	  _listo = Visitar3(x-1, y);
	}

	//Derecha
	if(!_listo && _mapa[x][y+1]->esValida())
	{
	  _listo = Visitar3(x, y+1);
	}

	//Atras
	if(!_listo && y -1 > 0)
	{ 
		if(!_listo && _mapa[x][y-1]->esValida())
		{
			_listo = Visitar3(x, y-1);
		}
	}

	if(!_listo)
	{
		((Camino*)_mapa[x][y])->CambiarEstado(DESCARTADO);
		delay(30);
		_mapa[x][y]->Dibujar();
	}

	return _listo;
}