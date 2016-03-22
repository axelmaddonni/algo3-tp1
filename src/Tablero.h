#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Tablero {
public:
	Tablero(vector<pair<int, int> > p);
	//Tablero(Tablero& t);
	~Tablero();

	bool EstaVivo(int androide);
	void Matar(vector<int> androides);
	vector<pair<int, int> > Puntos();
	vector<vector<int> > Solucion();
	bool Solucionado();
	int Vivos();

private:
	vector<pair<int, int> > puntos;
	vector<vector<int> > solucion;
	vector<int> vivos;
	int cant_vivos;
};

Tablero::Tablero(vector<pair<int, int> > p): puntos(p), solucion(), vivos(p.size(), true), cant_vivos(p.size()) {}

Tablero::~Tablero() {}

bool Tablero::EstaVivo(int androide){
	return vivos[androide];
}

void Tablero::Matar(vector<int> androides){
	solucion.push_back(androides);
	for(int i = 0; i < androides.size(); i++) vivos[androides[i]] = false;
	cant_vivos -= androides.size();
}

vector<pair<int, int> > Tablero::Puntos(){
	return puntos;
}

vector<vector<int> > Tablero::Solucion(){
	return solucion;
}

bool Tablero::Solucionado(){
	int total = 0;
	for(int i=0; i < solucion.size(); i++) total += solucion[i].size();
	return total == puntos.size();
}

int Tablero::Vivos(){
	return cant_vivos;
}

#endif