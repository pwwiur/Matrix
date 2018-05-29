#ifndef Matrix_H
#define Matrix_H
#include <iostream>
#include <string>
using namespace std;

template<class T> class Matrix{
    private:
        T* arr;

        bool checkXY(int x, int y);
        void error(int err = -1, string details = "");
        class Proxy {
            public:
                Proxy(T* _arr, int width, int x);
                T& operator[](short int y);
            private:
                T* _arr;
                int width, x;
        };
        class Dump{
            private:
                Matrix* m;
            public:
                Dump(Matrix* m);
                void array();
                void table();
                void matrix();
        };

    public:
        int width, height;
        Dump dump = Dump(this);

        Matrix(int x, int y);
        Proxy operator[](int x);
        T& operator() (T key, int n = 1);
        /*void set(int x, int y, T value);
        void cset(int x, int y, char value);
        T get(int x, int y);*/
};





//-- Template class implementation
template<class T> Matrix<T>::Matrix(int width, int height){
    arr = new T[width * height];
    this->width = width;
    this->height = height;
}

template<class T> void Matrix<T>::error(int err, string details){
    string errText;
    switch(err){
        case 0:
            errText = "Error while searching '" + details + "'";
            break;
        case -1:
        default:
            errText = "An error has been occured with matrix";
    }
    cout << errText;
    exit(EXIT_FAILURE);
}

template<class T> T& Matrix<T>::operator() (T key, int n) {
    for(int i = 0; i < width; i++){
        if(arr[i] == key)
            return arr[i + width * n];
    }
    error(0, key);
}
/*
template<class T> void Matrix<T>::set(int x, int y, T value){
    if(checkXY(x, y))
        arr[y + width * x] = value;
}

template<class T> void Matrix<T>::cset(int x, int y, char value){
    if(checkXY(x, y))
        arr[y + width * x] += value;
}

template<class T> T Matrix<T>::get(int x, int y){
    if(checkXY(x, y))
        return arr[y + width * x];
}
*/
template<class T> bool Matrix<T>::checkXY(int x, int y){
    return x >= 0 && x < width && y >= 0 && y < height;
}


template<class T> Matrix<T>::Proxy::Proxy(T* _arr, int width, int x) : _arr(_arr), width(width), x(x){}

template<class T> T& Matrix<T>::Proxy::operator[](short int y){
    return _arr[y+width*x];
}

template<class T> typename Matrix<T>::Proxy Matrix<T>::operator[](int x){
    return Proxy(arr, width, x);
}



template<class T> Matrix<T>::Dump::Dump(Matrix* m) : m(m){}

template<class T> void Matrix<T>::Dump::array(){
    cout << "Array view: " << endl;
    for(int i = 0; i < m->width * m->height; i++){
        cout << "arr[" << i << "]: " << m->arr[i] << endl;
    }
}

template<class T> void Matrix<T>::Dump::table(){
    cout << endl << "Table view: " << endl;
    int column[m->width];
    int length = 0;
    for(int i = 0; i < m->width; i++){
        cout << m->arr[i] << "            ";;
        column[i] = m->arr[i].length() + 12;
        length += column[i];
    }
    cout << endl;
    for(int i = 0; i < length; i++){
        cout << "-";
    }
    cout << endl;
    for(int i = m->width; i < m->width * m->height; i++){
        int border = m->arr[i].length();
        bool etc = false;
        if(border > column[i % 3])
            etc = true;

        for(int j = 0; j < column[i % 3]; j++){
            if(j > border){
                cout << " ";
            }
            else{
                if(j < (column[i % 3] - (etc ? 3 : 0)))
                    cout << m->arr[i][j];
                else
                    cout << ".";
            }
        }
        cout << " ";
        if((i + 1) % m->width == 0)
            cout << endl;
    }
}

template<class T> void Matrix<T>::Dump::matrix(){
    cout << endl << "Matrix view: " << endl;
    int column[m->width];
    int length = 0;
    for(int i = 0; i < m->width; i++){
        column[i] = m->arr[i].length() + 12;
        length += column[i];
    }
    cout << "-";
    for (int i = 0; i < length + 2; i++){
        cout << " ";
    }
    cout << "-";
    cout << endl;
    cout << "|";
    cout << " ";
    for(int i = 0; i < m->width; i++){
        cout << m->arr[i] << "            ";
    }
    cout << " ";
    cout << "|";
    cout << endl;
    for(int i = m->width; i < m->width * m->height; i++){
        if(i % m->width == 0)
            cout << "| ";
        int border = m->arr[i].length();
        bool etc = false;
        if(border > column[i % 3])
            etc = true;

        for(int j = 0; j < column[i % 3]; j++){
            if(j > border){
                cout << " ";
            }
            else{
                if(j < (column[i % 3] - (etc ? 4 : 0)))
                    cout << m->arr[i][j];
                else{
                    cout << "...";
                    break;
                }
            }
        }
        cout << " ";
        if((i + 1) % m->width == 0){
            cout << " |";
            cout << endl;
        }
    }
    cout << "-";
    for (int i = 0; i < length + 2; i++){
        cout << " ";
    }
    cout << "-";
    cout << endl;
}

#endif // Matrix_H
