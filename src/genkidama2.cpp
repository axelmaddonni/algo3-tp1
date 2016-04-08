#include <iostream>
#include <utility>
#include <vector>
#include <ctime>
#include <chrono>

std::vector<int> solve(std::vector<std::pair<int, int>> puntos, int t) {
  int n = puntos.size();
  int i = 0;  // a quien le disparo
  int j = 0;  // primero a matar
  std::vector<int> res;
  while (j < n) {
    i = j;		
    // Elijo al ultimo el elemento que sirve para abarcar todos hasta el primero.
    while (i < n - 1 &&
           puntos[i+1].first + t >= puntos[j].first) {
      i++;
    }
    res.push_back(i + 1);
    i++;
    j = i;
    // Avanzo todos los elementos que abarcamos.
    while (j < n  && puntos[j].second <= puntos[i-1].second + t) {
      j++;
    }
  }
  return res;
}

int main() {
  int n, t;
  std::cin >> n >> t;

  std::vector<std::pair<int, int>> puntos;

  for (int i = 0; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    puntos.push_back(std::make_pair(x, y));
  }

  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  std::vector<int> es = solve(puntos, t); // Resolvemos el problema.
  end = std::chrono::system_clock::now();

  std::cout << es.size() << std::endl;
  for (unsigned int i = 0; i < es.size(); i++) {
    std::cout << es[i] << " ";
  }
  std::cout << std::endl;

  std::chrono::duration<double> segundos = end - start;
  #ifdef TOMAR_TIEMPO
  std::cerr << segundos.count();
  #endif

  return 0;
}
