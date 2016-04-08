#include <iostream> 
#include <math.h> 
#include <vector> 
#include <ctime>
#include <chrono>
#include <stdlib.h> 

using namespace std;

void generarpeleas(int n, int pactual, int inicio,
                   vector<vector<int>> &matrizpeleas){
  if (n == 1) {
    // El caso n = 1 es trivial.
    matrizpeleas[pactual][inicio] = 1;
  } else if (n == 2) {
    // El caso n = 2 es trivial.
    matrizpeleas[pactual][inicio] = 1;
    matrizpeleas[pactual][inicio+1] = 2;
  } else {
    // Nos aseguramos de que las dos partes peleen entre si.
    for (int j=0; j< n; j++) {
      if (j < n/2) {
        matrizpeleas[pactual][inicio + j] = 1;
      } else {
        matrizpeleas[pactual][inicio + j] = 2;
      }
    }
    // Resolvemos el subproblema para cada mitad.
    generarpeleas(n / 2, pactual+1, inicio, matrizpeleas);
    generarpeleas((n + 1) / 2, pactual+1, n/2 + inicio, matrizpeleas);
  }
}

void kaioken (int n){
  int cpeleas = ceil(log2(n));
  cout << cpeleas << endl;

  if (n == 1) {
    // Si hay 1 solo guerrero, el problema ya esta resuelto.
    return;
  } else if (n == 2) {
    cout << 1 << " " << 2 << endl;
  } else {
    vector<vector<int>> matrizpeleas(cpeleas, vector<int>(n,1));
    int pactual = 0;
    for (int i = 0; i < n; i++) {
      if (i < n/2) {
        matrizpeleas[pactual][i] = 1;
      } else {
        matrizpeleas[pactual][i] = 2;
      }
    }

    generarpeleas(n / 2, pactual+1, 0, matrizpeleas);
    generarpeleas((n + 1) / 2, pactual+1, n/2, matrizpeleas);

    // Imprimo la matriz
    for (int i = 0; i < cpeleas; i++) {
      for (int j = 0; j < n; j++) {
        cout << matrizpeleas[i][j];
        if (j != n-1) cout << " ";
      }
      cout << endl;
    }
  }
}	


int main() {
  int k;
  std::cin >> k;

  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  kaioken(k); // Resolvemos el problema.
  end = std::chrono::system_clock::now();

  std::chrono::duration<double> segundos = end - start;
  #ifdef TOMAR_TIEMPO
  std::cerr << segundos.count();
  #endif

  return 0;
}

