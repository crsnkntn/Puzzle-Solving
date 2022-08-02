#include <iostream>
#include <utility>
#include <vector>

class RotationPuzzle {
    private:
        std::vector<std::pair<int, int>> layer1 = {{27, 2}, {20, 10}, {11, 9}, {27, 7}, 
            {10, 3}, {19, 12}, {10, 24}, {13, 10}, {10, 9}, {2, 22}, {15, 9}, {23, 5}, 
            {19, 10}, {3, 5}, {2, 1}, {3, 24}};
        std::vector<std::pair<int, int>> layer2 = {{0, 6}, {9, 1}, {0, 1}, {16, 11}, {0, 27},
            {17, 14}, {0, 5}, {2, 5}, {0, 7}, {2, 8}, {0, 24}, {10, 8}, {0, 3}, {15, 6}, {0, 15}, {6, 22}};
        std::vector<std::pair<int, int>> layer3 = {{22, 10}, {0, 2}, {2, 6}, {0, 10}, {17, 4}, {0, 1}, {15, 5},
            {0, 5}, {14, 4}, {0, 8}, {5, 6}, {0, 3}, {10, 1}, {0, 6}, {2, 10}, {0, 6}};
        std::vector<int> layer4 = {10, 0, 10, 0, 10, 0, 6, 0, 13, 0, 3, 0, 3, 0, 6, 0};

        int layer1_index = 0, layer2_index = 0, layer3_index = 0, layer4_index = 0;
    public:
        RotationPuzzle () {}

        std::vector<int> get_solution () {
            std::vector<int> r {layer1_index, layer2_index, layer3_index, layer4_index};
            return r;
        }

        bool check_current_rotation () {
            auto mod = [] (int a, int b) {return (a + b) % 16;};

            for (int offset = 0; offset < 16; offset++) {
                int sum = layer1[mod(layer1_index, offset)].first;
                sum += (layer2[mod(layer2_index, offset)].first == 0) 
                    ? layer1[mod(layer1_index, offset)].second : layer2[mod(layer2_index, offset)].first;
                sum += (layer3[mod(layer3_index, offset)].first == 0) 
                    ? layer2[mod(layer2_index, offset)].second : layer3[mod(layer3_index, offset)].first;
                sum += (layer4[mod(layer4_index, offset)] == 0) 
                    ? layer3[mod(layer3_index, offset)].second : layer4[mod(layer4_index, offset)];
                if (sum != 40)
                    return false;
            }
            return true;
        }

        void solve () {
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 16; j++) {
                    for (int k = 0; k < 16; k++) {
                        for (int l = 0; l < 16; l++) {
                            layer1_index += i;
                            layer2_index += j;
                            layer3_index += k;
                            layer4_index += l;
                            if (check_current_rotation())
                                return;
                            layer1_index -= i;
                            layer2_index -= j;
                            layer3_index -= k;
                            layer4_index -= l;
                        }
                    }
                }
            }
        }


};

// The Program outputs 0  6  7  6
int main () {
    RotationPuzzle rp;
    rp.solve();
    std::vector<int> v = rp.get_solution();
    for (auto i : v)
        std::cout << i << std::endl;
}