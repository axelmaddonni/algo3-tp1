#include <iostream>
#include <utility>
#include <vector>

std::vector<int> solve(std::vector<std::pair<int, int>> puntos, int t) {
  int n = puntos.size();
  int i = 0;  // a quien le disparo
  int j = 0;  // primero a matar
  std::vector<int> res;
  while (j < n) {
    i = j;		
    while (i < n - 1 &&
           puntos[i+1].first + t >= puntos[j].first) {
      i++;
    }
    res.push_back(i + 1);
    i++;
    j = i;
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
  std::vector<int> es = solve(puntos, t);
  std::cout << es.size() << std::endl;
  for (unsigned int i = 0; i < es.size(); i++) {
    if (i != es.size()-1) {
      std::cout << es[i] << " ";
    }
    else {
      std::cout << es[i] << " " << std::endl;
    }
  }
  return 0;
}
