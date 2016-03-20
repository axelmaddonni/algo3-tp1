#include <iostream>

int b(int i, int j) {
    return 0;
}

int main() {
    int n;
    std::cin >> n;

    int p;

    std::cout << p;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << b(i, j) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
