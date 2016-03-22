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

vector<Tablero> encontrar_sucesores(Tablero t) {
	vector<Tablero> sucesores;
	vector<pair<int, int> > puntos = t.Puntos();
	int n = puntos.size();
	bool unico_vivo = (t.Vivos() == 1);

	for(int i = 0; i < n; i++){
		if(t.EstaVivo(i)){
			if(unico_vivo){
				Tablero sucesor(t);
				vector<int> derrotados;
				derrotados.push_back(i);
				sucesor.Matar(derrotados);
				sucesores.push_back(sucesor);
				break;
			}else{
				double x_1 = puntos[i].first;
				double y_1 = puntos[i].second;
				vector<double> pendientes(n, 0);
				for(int j = 0; j < n; j++) {
					double pendiente = 0;
					if(j != i && t.EstaVivo(j)){
						double x_2 = puntos[j].first;
						double y_2 = puntos[j].second;				
						if(x_2 != x_1) pendiente = (y_2-y_1) / (x_2-x_1); //guarda con esto, hay que hacer algo despues
						pendientes[j] = pendiente;
					}
				}

				for(int j = 0; j < n; j++){
					if(j != i && t.EstaVivo(j)){
						Tablero sucesor(t);
						vector<int> derrotados;
						derrotados.push_back(i);
						derrotados.push_back(j);
						for(int k = 0; k < n; k++){
							if(k != i && k != j && t.EstaVivo(k) && pendientes[k] == pendientes[j]){
								if(mismo_cuadrante(puntos[i], puntos[j], puntos[k])) derrotados.push_back(k);
							}
						}
						sucesor.Matar(derrotados);
						sucesores.push_back(sucesor);
					}
				}
			}
	    }
    }

    return sucesores;
}

void bt(Tablero t, int k) {
	if(k < mejor) { //El subarbol es aceptable
		if(t.Solucionado()){
			mejor = k;
			mejor_sol = t.Solucion();
		} else{
			vector<Tablero> sucesores = encontrar_sucesores(t);
			for(int i = 0; i < sucesores.size(); i++) bt(sucesores[i], k+1);
		}
	}
}

vector<vector<int> > solve(vector<pair<int, int> > puntos) {
	Tablero inicial(puntos);
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
