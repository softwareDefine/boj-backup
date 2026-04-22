#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

void rotateFace(vector<char>& face, bool clockwise) {
    vector<char> temp(9);
    if (clockwise) {
        temp[0] = face[6];
        temp[1] = face[3];
        temp[2] = face[0];
        temp[3] = face[7];
        temp[4] = face[4];
        temp[5] = face[1];
        temp[6] = face[8];
        temp[7] = face[5];
        temp[8] = face[2];
    } else {
        temp[0] = face[2];
        temp[1] = face[5];
        temp[2] = face[8];
        temp[3] = face[1];
        temp[4] = face[4];
        temp[5] = face[7];
        temp[6] = face[0];
        temp[7] = face[3];
        temp[8] = face[6];
    }
    face = temp;
}

void rotateFront(vector<vector<char>>& cube, bool clockwise) {
    // Rotate the front face (face 2)
    rotateFace(cube[2], clockwise);

    // Positions on adjacent faces
    int U_idx[] = {6, 7, 8}; // U
    int R_idx[] = {0, 3, 6}; // R
    int D_idx[] = {2, 1, 0}; // D
    int L_idx[] = {8, 5, 2}; // L

    vector<char> temp(3);

    if (clockwise) {
        // Save U[6], U[7], U[8]
        for (int i = 0; i < 3; ++i) {
            temp[i] = cube[0][U_idx[i]];
        }
        // U <- L
        for (int i = 0; i < 3; ++i) {
            cube[0][U_idx[i]] = cube[1][L_idx[(2 - i)]];
        }
        // L <- D
        for (int i = 0; i < 3; ++i) {
            cube[1][L_idx[(2 - i)]] = cube[5][D_idx[i]];
        }
        // D <- R
        for (int i = 0; i < 3; ++i) {
            cube[5][D_idx[i]] = cube[3][R_idx[(2 - i)]];
        }
        // R <- temp (U)
        for (int i = 0; i < 3; ++i) {
            cube[3][R_idx[(2 - i)]] = temp[i];
        }
    } else {
        // Counter-clockwise
        // Save U[6], U[7], U[8]
        for (int i = 0; i < 3; ++i) {
            temp[i] = cube[0][U_idx[i]];
        }
        // U <- R
        for (int i = 0; i < 3; ++i) {
            cube[0][U_idx[i]] = cube[3][R_idx[(2 - i)]];
        }
        // R <- D
        for (int i = 0; i < 3; ++i) {
            cube[3][R_idx[(2 - i)]] = cube[5][D_idx[i]];
        }
        // D <- L
        for (int i = 0; i < 3; ++i) {
            cube[5][D_idx[i]] = cube[1][L_idx[(2 - i)]];
        }
        // L <- temp (U)
        for (int i = 0; i < 3; ++i) {
            cube[1][L_idx[(2 - i)]] = temp[i];
        }
    }
}

void rotateBack(vector<vector<char>>& cube, bool clockwise) {
    // Rotate the back face (face 4)
    rotateFace(cube[4], clockwise);

    // Positions on adjacent faces
    int U_idx[] = {2, 1, 0}; // U
    int R_idx[] = {8, 5, 2}; // R
    int D_idx[] = {6, 7, 8}; // D
    int L_idx[] = {0, 3, 6}; // L

    vector<char> temp(3);

    if (clockwise) {
        // Save U[2], U[1], U[0]
        for (int i = 0; i < 3; ++i) {
            temp[i] = cube[0][U_idx[i]];
        }
        // U <- L
        for (int i = 0; i < 3; ++i) {
            cube[0][U_idx[i]] = cube[1][L_idx[(2 - i)]];
        }
        // L <- D
        for (int i = 0; i < 3; ++i) {
            cube[1][L_idx[(2 - i)]] = cube[5][D_idx[i]];
        }
        // D <- R
        for (int i = 0; i < 3; ++i) {
            cube[5][D_idx[i]] = cube[3][R_idx[(2 - i)]];
        }
        // R <- temp (U)
        for (int i = 0; i < 3; ++i) {
            cube[3][R_idx[(2 - i)]] = temp[i];
        }
    } else {
        // Counter-clockwise
        // Save U[2], U[1], U[0]
        for (int i = 0; i < 3; ++i) {
            temp[i] = cube[0][U_idx[i]];
        }
        // U <- R
        for (int i = 0; i < 3; ++i) {
            cube[0][U_idx[i]] = cube[3][R_idx[(2 - i)]];
        }
        // R <- D
        for (int i = 0; i < 3; ++i) {
            cube[3][R_idx[(2 - i)]] = cube[5][D_idx[i]];
        }
        // D <- L
        for (int i = 0; i < 3; ++i) {
            cube[5][D_idx[i]] = cube[1][L_idx[(2 - i)]];
        }
        // L <- temp (U)
        for (int i = 0; i < 3; ++i) {
            cube[1][L_idx[(2 - i)]] = temp[i];
        }
    }
}

void rotateLeft(vector<vector<char>>& cube, bool clockwise) {
    // Rotate the left face (face 1)
    rotateFace(cube[1], clockwise);

    // Positions on adjacent faces
    int U_idx[] = {0, 3, 6}; // U
    int F_idx[] = {0, 3, 6}; // F
    int D_idx[] = {0, 3, 6}; // D
    int B_idx[] = {8, 5, 2}; // B

    vector<char> temp(3);

    if (clockwise) {
        // Save U[0], U[3], U[6]
        for (int i = 0; i < 3; ++i) {
            temp[i] = cube[0][U_idx[i]];
        }
        // U <- B
        for (int i = 0; i < 3; ++i) {
            cube[0][U_idx[i]] = cube[4][B_idx[(2 - i)]];
        }
        // B <- D
        for (int i = 0; i < 3; ++i) {
            cube[4][B_idx[(2 - i)]] = cube[5][D_idx[i]];
        }
        // D <- F
        for (int i = 0; i < 3; ++i) {
            cube[5][D_idx[i]] = cube[2][F_idx[i]];
        }
        // F <- temp (U)
        for (int i = 0; i < 3; ++i) {
            cube[2][F_idx[i]] = temp[i];
        }
    } else {
        // Counter-clockwise
        // Save U[0], U[3], U[6]
        for (int i = 0; i < 3; ++i) {
            temp[i] = cube[0][U_idx[i]];
        }
        // U <- F
        for (int i = 0; i < 3; ++i) {
            cube[0][U_idx[i]] = cube[2][F_idx[i]];
        }
        // F <- D
        for (int i = 0; i < 3; ++i) {
            cube[2][F_idx[i]] = cube[5][D_idx[i]];
        }
        // D <- B
        for (int i = 0; i < 3; ++i) {
            cube[5][D_idx[i]] = cube[4][B_idx[(2 - i)]];
        }
        // B <- temp (U)
        for (int i = 0; i < 3; ++i) {
            cube[4][B_idx[(2 - i)]] = temp[i];
        }
    }
}

void rotateRight(vector<vector<char>>& cube, bool clockwise) {
    // Rotate the right face (face 3)
    rotateFace(cube[3], clockwise);

    // Positions on adjacent faces
    int U_idx[] = {8, 5, 2}; // U
    int F_idx[] = {8, 5, 2}; // F
    int D_idx[] = {8, 5, 2}; // D
    int B_idx[] = {6, 3, 0}; // B

    vector<char> temp(3);

    if (clockwise) {
        // Save U[8], U[5], U[2]
        for (int i = 0; i < 3; ++i) {
            temp[i] = cube[0][U_idx[i]];
        }
        // U <- F
        for (int i = 0; i < 3; ++i) {
            cube[0][U_idx[i]] = cube[2][F_idx[i]];
        }
        // F <- D
        for (int i = 0; i < 3; ++i) {
            cube[2][F_idx[i]] = cube[5][D_idx[i]];
        }
        // D <- B
        for (int i = 0; i < 3; ++i) {
            cube[5][D_idx[i]] = cube[4][B_idx[(2 - i)]];
        }
        // B <- temp (U)
        for (int i = 0; i < 3; ++i) {
            cube[4][B_idx[(2 - i)]] = temp[i];
        }
    } else {
        // Counter-clockwise
        // Save U[8], U[5], U[2]
        for (int i = 0; i < 3; ++i) {
            temp[i] = cube[0][U_idx[i]];
        }
        // U <- B
        for (int i = 0; i < 3; ++i) {
            cube[0][U_idx[i]] = cube[4][B_idx[(2 - i)]];
        }
        // B <- D
        for (int i = 0; i < 3; ++i) {
            cube[4][B_idx[(2 - i)]] = cube[5][D_idx[i]];
        }
        // D <- F
        for (int i = 0; i < 3; ++i) {
            cube[5][D_idx[i]] = cube[2][F_idx[i]];
        }
        // F <- temp (U)
        for (int i = 0; i < 3; ++i) {
            cube[2][F_idx[i]] = temp[i];
        }
    }
}

void rotateUp(vector<vector<char>>& cube, bool clockwise) {
    // Rotate the up face (face 0)
    rotateFace(cube[0], clockwise);

    // Positions on adjacent faces
    int B_idx[] = {2,1,0}; // B
    int R_idx[] = {2,1,0}; // R
    int F_idx[] = {2,1,0}; // F
    int L_idx[] = {2,1,0}; // L

    vector<char> temp(3);

    if (clockwise) {
        // Save B[2,1,0]
        for (int i = 0; i < 3; ++i) {
            temp[i] = cube[4][B_idx[i]];
        }
        // B <- L
        for (int i = 0; i < 3; ++i) {
            cube[4][B_idx[i]] = cube[1][L_idx[i]];
        }
        // L <- F
        for (int i = 0; i < 3; ++i) {
            cube[1][L_idx[i]] = cube[2][F_idx[i]];
        }
        // F <- R
        for (int i = 0; i < 3; ++i) {
            cube[2][F_idx[i]] = cube[3][R_idx[i]];
        }
        // R <- temp (B)
        for (int i = 0; i < 3; ++i) {
            cube[3][R_idx[i]] = temp[i];
        }
    } else {
        // Counter-clockwise
        // Save B[2,1,0]
        for (int i = 0; i < 3; ++i) {
            temp[i] = cube[4][B_idx[i]];
        }
        // B <- R
        for (int i = 0; i < 3; ++i) {
            cube[4][B_idx[i]] = cube[3][R_idx[i]];
        }
        // R <- F
        for (int i = 0; i < 3; ++i) {
            cube[3][R_idx[i]] = cube[2][F_idx[i]];
        }
        // F <- L
        for (int i = 0; i < 3; ++i) {
            cube[2][F_idx[i]] = cube[1][L_idx[i]];
        }
        // L <- temp (B)
        for (int i = 0; i < 3; ++i) {
            cube[1][L_idx[i]] = temp[i];
        }
    }
}

void rotateDown(vector<vector<char>>& cube, bool clockwise) {
    // Rotate the down face (face 5)
    rotateFace(cube[5], clockwise);

    // Positions on adjacent faces
    int B_idx[] = {6,7,8}; // B
    int R_idx[] = {6,7,8}; // R
    int F_idx[] = {6,7,8}; // F
    int L_idx[] = {6,7,8}; // L

    vector<char> temp(3);

    if (clockwise) {
        // Save B[6,7,8]
        for (int i = 0; i < 3; ++i) {
            temp[i] = cube[4][B_idx[i]];
        }
        // B <- R
        for (int i = 0; i < 3; ++i) {
            cube[4][B_idx[i]] = cube[3][R_idx[i]];
        }
        // R <- F
        for (int i = 0; i < 3; ++i) {
            cube[3][R_idx[i]] = cube[2][F_idx[i]];
        }
        // F <- L
        for (int i = 0; i < 3; ++i) {
            cube[2][F_idx[i]] = cube[1][L_idx[i]];
        }
        // L <- temp (B)
        for (int i = 0; i < 3; ++i) {
            cube[1][L_idx[i]] = temp[i];
        }
    } else {
        // Counter-clockwise
        // Save B[6,7,8]
        for (int i = 0; i < 3; ++i) {
            temp[i] = cube[4][B_idx[i]];
        }
        // B <- L
        for (int i = 0; i < 3; ++i) {
            cube[4][B_idx[i]] = cube[1][L_idx[i]];
        }
        // L <- F
        for (int i = 0; i < 3; ++i) {
            cube[1][L_idx[i]] = cube[2][F_idx[i]];
        }
        // F <- R
        for (int i = 0; i < 3; ++i) {
            cube[2][F_idx[i]] = cube[3][R_idx[i]];
        }
        // R <- temp (B)
        for (int i = 0; i < 3; ++i) {
            cube[3][R_idx[i]] = temp[i];
        }
    }
}

bool isSolved(vector<vector<char>>& cube) {
    for (int f = 0; f < 6; ++f) {
        char color = cube[f][0];
        for (int i = 1; i < 9; ++i) {
            if (cube[f][i] != color) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line == "ENDOFINPUT") break;
        if (line != "START") continue;

        vector<vector<char>> cube(6, vector<char>(9));

        // Read the cube configuration
        // Lines 1-3: U
        for (int i = 0; i < 3; ++i) {
            getline(cin, line);
            line.erase(remove(line.begin(), line.end(), ' '), line.end());
            for (int j = 0; j < 3; ++j) {
                cube[0][i * 3 + j] = line[j];
            }
        }
        // Lines 4-6: L, F, R, B
        for (int i = 0; i < 3; ++i) {
            getline(cin, line);
            vector<string> parts;
            string temp;
            for (char c : line) {
                if (c != ' ') {
                    temp += c;
                } else if (!temp.empty()) {
                    parts.push_back(temp);
                    temp = "";
                }
            }
            if (!temp.empty()) {
                parts.push_back(temp);
            }
            // Should have 4 parts
            for (int f = 0; f < 4; ++f) {
                for (int j = 0; j < 3; ++j) {
                    cube[f + 1][i * 3 + j] = parts[f][j];
                }
            }
        }
        // Lines 7-9: D
        for (int i = 0; i < 3; ++i) {
            getline(cin, line);
            line.erase(remove(line.begin(), line.end(), ' '), line.end());
            for (int j = 0; j < 3; ++j) {
                cube[5][i * 3 + j] = line[j];
            }
        }

        // Read operations
        while (getline(cin, line)) {
            if (line == "END") break;
            if (line.empty()) continue;
            // Parse operation
            string face, dir;
            size_t pos = line.find(' ');
            face = line.substr(0, pos);
            dir = line.substr(pos + 1);
            bool clockwise = (dir == "right");

            if (face == "front") {
                rotateFront(cube, clockwise);
            } else if (face == "back") {
                rotateBack(cube, clockwise);
            } else if (face == "left") {
                rotateLeft(cube, clockwise);
            } else if (face == "right") {
                rotateRight(cube, clockwise);
            } else if (face == "top") {
                rotateUp(cube, clockwise);
            } else if (face == "bottom") {
                rotateDown(cube, clockwise);
            }
        }

        // Check if solved
        if (isSolved(cube)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
