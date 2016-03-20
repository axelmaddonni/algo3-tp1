#include <iostream>
#include <utility>
#include <vector>


std::vector<std::vector<int> > solve(std::vector<std::pair<int, int> > puntos) {
    return std::vector<std::vector<int> >();
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int> > puntos;

    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        puntos.push_back(std::make_pair(x, y));
    }
    std::vector<std::vector<int> > solucion = solve(puntos);
    std::cout << solucion.size() << std::endl;
    for (int i = 0; i < solucion.size(); i++) {
        const std::vector<int>& iesimo_kamehameha = solucion[i];
        std::cout << iesimo_kamehameha.size() << " ";
        for (int j = 0; j < iesimo_kamehameha.size(); j++) {
            std::cout << iesimo_kamehameha[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
