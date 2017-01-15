#include <cstdio>

const int seq[6][4][6] = {{{1,2,3,4,5,6}, {1,3,5,2,4,6}, {1,5,4,3,2,6}, {1,4,2,5,3,6}},
                        {{2,6,3,4,1,5}, {2,3,1,6,4,5}, {2,1,4,3,6,5}, {2,4,6,1,3,5}},
                        {{3,1,2,5,6,4}, {3,2,6,1,5,4}, {3,6,5,2,1,4}, {3,5,1,6,2,4}},
                        {{4,2,1,6,5,3}, {4,1,5,2,6,3}, {4,5,6,1,2,3}, {4,6,2,5,1,3}},
                        {{5,1,3,4,6,2}, {5,3,6,1,4,2}, {5,6,4,3,1,2}, {5,4,1,6,3,2}},
                        {{6,2,4,3,5,1}, {6,4,5,2,3,1}, {6,5,3,4,2,1}, {6,3,2,5,4,1}}};

char cube1[10] = {0}, cube2[10] = {0};

int main() {
    while ((cube1[1] = getchar()) != EOF) {
        for (int i = 2; i <= 6; ++i)
            cube1[i] = getchar();
        for (int i = 1; i <= 6; ++i)
            cube2[i] = getchar();
        getchar();
        bool f = 0;
        for (int i = 0; i < 6; ++i) {
            if (f) break;
            for (int j = 0; j < 4; ++j) {
                bool f2 = 1;
                for (int k = 0; k < 6; ++k) {
                    if (cube2[seq[i][j][k]] != cube1[k + 1]) {
                        f2 = 0; break;
                    }
                }
                if (f2) {
                    f = 1; break;
                }
            }
        }
        if (f) printf("TRUE\n");
        else printf("FALSE\n");
    }
    return 0;
}