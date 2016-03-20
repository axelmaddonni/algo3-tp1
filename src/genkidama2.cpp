#include <iostream>
#include <utility>
#include <vector>


std::vector<int> solve(std::vector<std::pair<int, int> > puntos, int t) {
    return std::vector<int>();
}

int main() {
    int n, t;
    std::cin >> n >> t;

    std::vector<std::pair<int, int> > puntos;

    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        puntos.push_back(std::make_pair(x, y));
    }
    std::vector<int> es = solve(puntos, t);
    std::cout << es.size() << std::endl;
    for (int i = 0; i < es.size(); i++) {
        std::cout << es[i] << " ";
    }

    return 0;
}
