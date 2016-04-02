#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Tablero {
public:
  Tablero(int k);
  ~Tablero();

  bool EstaVivo(int androide);
  void Matar(vector<int> androides);
  vector<vector<int> > Solucion();
  bool Solucionado();
  int Vivos();

private:
  vector<vector<int> > solucion;
  vector<bool> vivos;
  int cant_vivos;
};

Tablero::Tablero(int k): solucion(), vivos(k, true), cant_vivos(k) {}

Tablero::~Tablero() {}

bool Tablero::EstaVivo(int androide){
  return vivos[androide];
}

void Tablero::Matar(vector<int> androides){
  solucion.push_back(androides);
  for (unsigned int i = 0; i < androides.size(); i++)
    vivos[androides[i]] = false;
  cant_vivos -= androides.size();
}

vector<vector<int> > Tablero::Solucion(){
  return solucion;
}

bool Tablero::Solucionado(){
  unsigned int total = 0;
  for(unsigned int i = 0; i < solucion.size(); i++)
    total += solucion[i].size();
  return total == vivos.size();
}

int Tablero::Vivos(){
  return cant_vivos;
}

#endif
