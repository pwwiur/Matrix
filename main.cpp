#include <iostream>
#include "dist/Matrix.h"

using namespace std;

int main(){
    // matrix 3x4 initialization for strings
    Matrix<string> mat(4, 3);

    // setting columns
    mat[0][0] = "Name";
    mat[0][1] = "LastName";
    mat[0][2] = "Email";

    // setting rows
    mat[1][0] = "Amir";
    mat[1][1] = "Forstai";
    mat[1][2] = "pwwiur@yahoo.com";

    mat[2][0] = "Ali";
    mat[2][1] = "Hajizadeh";
    mat[2][2] = "example@mail.com";

    mat[3][0] = "Hossein";
    mat[3][1] = "Kazemi";
    mat[3][2] = "example@mail.com";

    // array dump
    mat.dump.array();

    // table dump
    mat.dump.table();

    // matrix dump
    mat.dump.matrix();

    // getting information of Name in the first row
    cout << "Name: " << mat[1]["Name"] << endl;

    // getting information of Name in the second row
    cout << "Name: " << mat[2]["Name"] << endl;


    return 0;
}
