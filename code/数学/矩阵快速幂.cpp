#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <iostream>

#define matrixSize 7
#define mod 2147493647

using namespace std;

struct Matrix{
    long long data[matrixSize][matrixSize];

    Matrix(){ //默认构造单位矩阵
        for(int i = 0;i < matrixSize;i++)
            for(int j = 0;j < matrixSize;j++)
                data[i][j] = (i == j) ? 1 : 0;
    }
    Matrix(const long long data[][matrixSize]){
        memcpy(this->data,data,sizeof(this->data));
    }

    void clear(){ //化为零矩阵
        memset(this->data,0,sizeof(this->data));
    }

    Matrix operator * (const Matrix &ot){ //右乘矩阵ot
        Matrix result;
        result.clear();
        for(int i = 0;i < matrixSize;i++)
            for(int j = 0;j < matrixSize;j++)
                for(int k = 0;k < matrixSize;k++){
                    result.data[i][j] += (data[i][k] * ot.data[k][j]) % mod;
                    result.data[i][j] %= mod;
                }
        return result;
    }
    Matrix operator ^ (long long pow){ //矩阵快速幂(pow <= 0 返回单位矩阵)
        Matrix result;
        Matrix matrix = Matrix(this->data);
        if(pow <= 0) return result;
        while(pow){
            if(pow & 1) result = matrix * result;
            matrix = matrix * matrix;
            pow >>= 1;
        }
        return result;
    }
};
struct Vector{ //行向量
    long long data[matrixSize];

    Vector(){
        memset(data,0,sizeof(data));
    }
    Vector(const long long data[]){
        memcpy(this->data,data,sizeof(this->data));
    }

    Vector operator * (const Matrix &ot){ //右乘ot
        Vector result;
        for(int i = 0;i < matrixSize;i++)
            for(int j = 0;j < matrixSize;j++){
                result.data[i] += (data[j] * ot.data[j][i]) % mod;
                result.data[i] %= mod;
            }
        return result;
    }
};

int t;
long long n;
long long shiftMatrix[][matrixSize]{
    1, 1, 0, 0, 0, 0, 0,
    2, 0, 0, 0, 0, 0, 0,
    1, 0, 1, 0, 0, 0, 0,
    4, 0, 4, 1, 0, 0, 0,
    6, 0, 6, 3, 1, 0, 0,
    4, 0, 4, 3, 2, 1, 0,
    1, 0, 1, 1, 1, 1, 1
};
long long initVector[matrixSize]{
    0, 0, 16, 8, 4, 2, 1
};

int main(){
    scanf("%d",&t);
    while(t--){
        Vector vec = Vector(initVector);
        scanf("%lld %lld %lld",&n,&vec.data[1],&vec.data[0]);
        if(n <= 2) printf("%lld\n",vec.data[n % 2] % mod);
        else{
            vec = vec * (Matrix(shiftMatrix) ^ (n - 2));
            printf("%lld\n",vec.data[0]);
        }
    }
    return 0;
}

//Recursive sequence
//2021-5-16