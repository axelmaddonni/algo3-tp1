#include <iostream> 
#include <math.h> 
#include <vector> 
#include <stdlib.h> 

using namespace std;

void generarpeleas(int n, int pactual, int inicio,
                   vector<vector<int>> &matrizpeleas, int cpeleas){
  if (n == 1) {
    matrizpeleas[pactual][inicio] = 1;
  } else if (n == 2) {
    matrizpeleas[pactual][inicio] = 1;
    matrizpeleas[pactual][inicio+1] = 2;
  } else {
    for (int j=0; j< n; j++) {
      if (j < n/2) {
        matrizpeleas[pactual][inicio + j] = 1;
      } else {
        matrizpeleas[pactual][inicio + j] = 2;
      }
    }
    if (pactual != cpeleas - 1) {
      generarpeleas(n/2, pactual+1, inicio,
                    matrizpeleas, cpeleas);
      generarpeleas(n/2 + ((n%2 == 1) ? 1 : 0), pactual+1, n/2 + inicio,
                    matrizpeleas, cpeleas);
    }
  }
}

void kaioken (int n){
  int cpeleas = ceil(log2(n));
  cout << cpeleas << endl;

  if (n == 1) {
    cout << 1 << endl;
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

    generarpeleas(n/2, pactual+1, 0,
                  matrizpeleas, cpeleas);
    generarpeleas(n/2 + ((n%2 == 1) ? 1 : 0), pactual+1, n/2,
                  matrizpeleas, cpeleas);

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

  kaioken (k);

  return 0;
}

