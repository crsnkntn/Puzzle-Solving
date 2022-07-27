#include <iostream>

int main () {
    int rings[7][16] = {
        {23, 19, 3, 2, 3, 27, 20, 11, 27, 10, 19, 10, 13, 10, 2, 15},
        {5, 10, 5, 1, 24, 2, 10, 9, 7, 3, 12, 24, 10, 9, 22, 9},
        {0, 16, 0, 17, 0, 2, 0, 2, 0, 10, 0, 15, 0, 6, 0, 9},
        {1, 11, 27, 14, 5, 5, 7, 8, 24, 8, 3, 6, 15, 22, 6, 1},
        {0, 10, 0, 2, 0, 22, 0, 2, 0, 17, 0, 15, 0, 14, 0, 5},
        {3, 1, 6, 10, 6, 10, 2, 6, 10, 4, 1, 5, 5, 4, 8, 6},
        {0, 6, 10, 0, 10, 0, 10, 0, 6, 0, 13, 0, 3, 0, 3}
    };

    for (int two = 0; two < 16; two++) {
        for (int three = 0; three < 16; three++) {
            for (int four = 0; four < 16; four++) {
                // Check every column
                bool column_failure_flag = false;
                for (int col = 0; !column_failure_flag && col < 16; col++) {
                    int sum = rings[0][col];
                    sum += (rings[2][(two + col) % 16] == 0) ? rings[1][col] : rings[2][(two + col) % 16];
                    sum += (rings[4][(three + col) % 16] == 0) ? rings[3][(two + col) % 16] : rings[4][(three + col) % 16];
                    sum += (rings[6][(four + col) % 16] == 0) ? rings[5][(three + col) % 16] : rings[6][(four + col) % 16];
                    if (sum != 40) {
                        std::cout << two << " " << three << " " << four << std::endl;
                        column_failure_flag = true;
                        break;
                    }
                }
                if (!column_failure_flag) {
                    std::cout << "counter-clockwise rotations for each layer: 0 " << two << " " << 
                        three << " " << four << std::endl;
                    return 1;
                }
            }
        }
    }
}