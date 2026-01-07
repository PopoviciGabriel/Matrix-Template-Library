#include <iostream>
#include "Matrix.h"

int main() {
    // -----------------------------
    // 1. Test constructori
    // -----------------------------
    Matrix<int, 2, 2> A;              // Default constructor
    Matrix<int, 2, 2> B{1, 2, 3, 4};  // Constructor cu initializer_list
    Matrix<int, 2, 2> C = B;          // Copy constructor

    std::cout << "A (default):\n" << A << "\n";
    std::cout << "B (init list):\n" << B << "\n";
    std::cout << "C (copy of B):\n" << C << "\n";

    // -----------------------------
    // 2. Test operator()
    // -----------------------------
    A(0,0) = 10;
    A(1,1) = 20;

    std::cout << "A dupa modificari cu operator():\n" << A << "\n";

    // -----------------------------
    // 3. Test operator+ si operator-
    // -----------------------------
    Matrix<int, 2, 2> D = B + C;
    Matrix<int, 2, 2> E = B - C;

    std::cout << "D = B + C:\n" << D << "\n";
    std::cout << "E = B - C:\n" << E << "\n";

    // -----------------------------
    // 4. Test operator* (matrice 2x2 * 2x2)
    // -----------------------------
    Matrix<int, 2, 2> F = B * C;

    std::cout << "F = B * C:\n" << F << "\n";

    // -----------------------------
    // 5. Test operator* cu alte dimensiuni
    //    Exemplu: (2x3) * (3x2)
    // -----------------------------
    Matrix<int, 2, 3> M1{1, 2, 3,
                         4, 5, 6};

    Matrix<int, 3, 2> M2{7, 8,
                         9, 10,
                         11, 12};

    auto M3 = M1 * M2;

    std::cout << "M1 (2x3):\n" << M1 << "\n";
    std::cout << "M2 (3x2):\n" << M2 << "\n";
    std::cout << "M3 = M1 * M2 (rezultat 2x2):\n" << M3 << "\n";

    // -----------------------------
    // 6. Test transpose()
    // -----------------------------
    std::cout << "Transpose(B):\n" << B.transpose() << "\n";

    // -----------------------------
    // 7. Test determinant (2x2)
    // -----------------------------
    std::cout << "Det(B) = " << B.determinant() << "\n\n";

    // -----------------------------
    // 8. Test inversa (2x2)
    // -----------------------------
    try {
        Matrix<double, 2, 2> G{1, 2, 3, 4};
        std::cout << "G:\n" << G << "\n";
        std::cout << "Inversa(G):\n" << G.inversa() << "\n";
    } 
    catch(const std::exception& e) {
        std::cout << "Eroare: " << e.what() << "\n";
    }

    // -----------------------------
    // 9. Test inversa cu o matrice singulară
    // -----------------------------
    try {
        Matrix<double, 2, 2> H{1, 2,
                               2, 4}; // determinant = 0 => singulara
        std::cout << "Inversa(H):\n" << H.inversa() << "\n";
    } 
    catch(const std::exception& e) {
        std::cout << "Eroare (asteptata pentru matrice singulara): " << e.what() << "\n";
    }

    return 0;
}
