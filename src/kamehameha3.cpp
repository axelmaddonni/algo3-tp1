#include <iostream>
#include <utility>
#include <vector>
#include "Tablero.h"

using namespace std;

int mejor;
vector<vector<int> > mejor_sol;

bool mismo_cuadrante(pair<int, int> pi, pair<int, int> pj, pair<int, int> pk){
  int x_i = pi.first;
  int y_i = pi.second;
  int x_j = pj.first;
  int y_j = pj.second;
  int x_k = pk.first;
  int y_k = pk.second;

  if((x_j - x_i >= 0 && x_k - x_i >= 0) || (x_j - x_i <= 0 && x_k - x_i <= 0)){
    if((y_j - y_i >= 0 && y_k - y_i >= 0) || (y_j - y_i <= 0 && y_k - y_i <= 0)){
      return true;
    }
  }
  return false;
}

void bt(Tablero t, int s) {
  if(s < mejor) { //El subarbol es aceptable
    if(t.Solucionado()){
      mejor = s;
      mejor_sol = t.Solucion();
    } else{
      vector<pair<int, int> > puntos = *(t.Puntos());
      int n = puntos.size();

      for(int i=0; i<n; i++){
        if(t.EstaVivo(i)){
          if(t.Vivos() == 1){
            vector<int> derrotados;
            derrotados.push_back(i);
            t.Matar(derrotados);
            bt(t, s+1);
            break;
          }
          for(int j=0; j<n; j++){
            if(j != i && t.EstaVivo(j)){
              Tablero sucesor(t);
              vector<int> derrotados;
              derrotados.push_back(i);
              derrotados.push_back(j);
              double x_i = puntos[i].first;
              double y_i = puntos[i].second;
              double x_j = puntos[j].first;
              double y_j = puntos[j].second;
              for(int k = 0; k < n; k++){
                if(k != i && k != j && t.EstaVivo(k)){
                  double x_k = puntos[k].first;
                  double y_k = puntos[k].second;
                  if(x_i != x_j && y_i != y_j){
                    double cociente_x = (x_k - x_i) / (x_j - x_i); 
                    double cociente_y = (y_k - y_i) / (y_j - y_i); 
                    if(cociente_x == cociente_y && mismo_cuadrante(puntos[i], puntos[j], puntos[k])) derrotados.push_back(k);
                  }else{
                    bool al_vertical = (x_k == x_i && x_k == x_j);
                    bool al_horizontal = (y_k == y_i && y_k == y_j);
                    if((al_vertical || al_horizontal) && mismo_cuadrante(puntos[i], puntos[j], puntos[k])) derrotados.push_back(k);
                  }
                }
              }
              sucesor.Matar(derrotados);
              bt(sucesor, s+1);
            }
          }
        }
      }
    }
  }
}

vector<vector<int> > solve(vector<pair<int, int> > puntos) {
  Tablero inicial(&puntos);
  mejor = puntos.size();
  bt(inicial, 0);

  return mejor_sol;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int> > puntos;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        puntos.push_back(make_pair(x, y));
    }
    vector<vector<int> > solucion = solve(puntos);
    cout << solucion.size() << endl;
    for (int i = 0; i < solucion.size(); i++) {
        const vector<int>& iesimo_kamehameha = solucion[i];
        cout << iesimo_kamehameha.size() << " ";
        for (int j = 0; j < iesimo_kamehameha.size(); j++) {
            cout << iesimo_kamehameha[j] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
