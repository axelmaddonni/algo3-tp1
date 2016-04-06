#include <iostream>
#include <utility>
#include <vector>
#include <ctime>
#include <chrono>

#include "Tablero.h"

int mejor;
vector<vector<int>> mejor_sol;
std::vector<pair<int, int>> puntos;
int n;

bool mismo_cuadrante(pair<int, int> pi, pair<int, int> pj, pair<int, int> pk) {
  int x_i = pi.first;
  int y_i = pi.second;
  int x_j = pj.first;
  int y_j = pj.second;
  int x_k = pk.first;
  int y_k = pk.second;

  if((x_j >= x_i && x_k >= x_i) || (x_j <= x_i && x_k <= x_i)){
    if((y_j >= y_i && y_k >= y_i) || (y_j <= y_i && y_k <= y_i)){
      return true;
    }
  }
  return false;
}

void backtracking(Tablero t, int s) {
  if(s >= mejor) return;  // El subarbol no es aceptable
  if(t.Solucionado()) {
    mejor = s;
    mejor_sol = t.Solucion();
  } else {
    for (int i = 0; i < n; i++) {
      if (t.EstaVivo(i)) {
        if (t.Vivos() == 1) {
          vector<int> derrotados;
          derrotados.push_back(i);
          t.Matar(derrotados);
          backtracking(t, s+1);
          break;
        }
        for (int j = 0; j < n; j++) {
          if(j != i && t.EstaVivo(j)){
            Tablero sucesor(t);
            std::vector<int> derrotados;
            derrotados.push_back(i);
            derrotados.push_back(j);
            derrotados.reserve(n);
            double x_i = puntos[i].first;
            double y_i = puntos[i].second;
            double x_j = puntos[j].first;
            double y_j = puntos[j].second;
            for (int k = 0; k < n; k++) {
              if(k != i && k != j && t.EstaVivo(k)) {
                double x_k = puntos[k].first;
                double y_k = puntos[k].second;
                if (x_i != x_j && y_i != y_j) {
                  double cociente_x = (x_k - x_i) / (x_j - x_i); 
                  double cociente_y = (y_k - y_i) / (y_j - y_i); 
                  if (cociente_x == cociente_y &&
                      mismo_cuadrante(puntos[i], puntos[j], puntos[k]))
                    derrotados.push_back(k);
                } else {
                  bool al_vertical = (x_k == x_i && x_k == x_j);
                  bool al_horizontal = (y_k == y_i && y_k == y_j);
                  if ((al_vertical || al_horizontal) &&
                      mismo_cuadrante(puntos[i], puntos[j], puntos[k]))
                    derrotados.push_back(k);
                }
              }
            }
            sucesor.Matar(derrotados);
            backtracking(sucesor, s+1);
            if (mejor == s+1) return;
          }
        }
      }
    }
  }
}

vector<vector<int> > solve(vector<pair<int, int> > ptos) {
  puntos = ptos;
  Tablero inicial(n);
  mejor = puntos.size();
  backtracking(inicial, 0);

  return mejor_sol;
}

int main() {
  std::cin >> n;
  std::vector<pair<int, int>> ptos;

  for (int i = 0; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    ptos.push_back(make_pair(x, y));
  }
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  // Resolvemos el problema.
  std::vector<std::vector<int>> solucion = solve(ptos); 
  end = std::chrono::system_clock::now();

  std::cout << solucion.size() << endl;
  for (unsigned int i = 0; i < solucion.size(); i++) {
    const vector<int>& iesimo_kamehameha = solucion[i];
    std::cout << iesimo_kamehameha.size() << " ";
    for (unsigned int j = 0; j < iesimo_kamehameha.size(); j++) {
      std::cout << iesimo_kamehameha[j] + 1 << " ";
    }
    std::cout << endl;
  }

  std::chrono::duration<double> segundos = end - start;
  #ifdef TOMAR_TIEMPO
  std::cerr << segundos.count();
  #endif

  return 0;
}
