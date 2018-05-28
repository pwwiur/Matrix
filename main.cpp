#include <iostream>
#include "dist/Matrix.h"

using namespace std;

int main(){
    // matrix 3x4 initialization for strings
    Matrix<string> mat(3, 4);

    // setting columns
    mat[0][0] = "Name";
    mat[1][0] = "LastName";
    mat[2][0] = "Email";

    // setting rows
    mat[0][1] = "Amir";
    mat[1][1] = "Forstai";
    mat[2][1] = "pwwiur@yahoo.com";

    mat[0][2] = "Ali";
    mat[1][2] = "Hajizadeh";
    mat[2][2] = "example@mail.com";

    mat[0][3] = "Hossein";
    mat[1][3] = "Kazemi";
    mat[2][3] = "example@mail.com";

    // array dump
    mat.dump.array();

    // table dump
    mat.dump.table();

    // matrix dump
    mat.dump.matrix();

    // getting information of Name in the first row
    cout << "Name: " << mat("Name") << endl;

    // getting information of Name in the second row
    cout << "Name: " << mat("Name", 2) << endl;


    return 0;
}
