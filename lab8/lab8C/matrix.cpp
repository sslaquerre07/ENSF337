/*
 *  File Name: matrix.cpp
 *  Assignment: Lab 8 Exercise C
 *  Lab section: 03
 *  Completed by: Samuel Laquerre
 *  Submission Date: Nov 7th,2023
 */


#include "matrix.h"

Matrix::Matrix(int r, int c):rowsM(r), colsM(c)
{
    matrixM = new double* [rowsM];
    assert(matrixM != NULL);
    
    for(int i=0; i < rowsM; i++){
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
    }
    sum_rowsM = new double[rowsM];
    assert(sum_rowsM != NULL);
    
    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);
}


Matrix::~Matrix()
{
    destroy();
}

Matrix::Matrix(const Matrix& source)
{
    copy(source);
}

Matrix& Matrix::operator= (const Matrix& rhs)
{
    if(&rhs != this){
        destroy();
        copy(rhs);
    }
   
    return *this;
}

double Matrix::get_sum_col(int i) const
{
    assert(i >= 0 && i < colsM);
    return sum_colsM[i];
}

double Matrix::get_sum_row(int i) const
{
    assert(i >= 0 && i < rowsM);
    return sum_rowsM[i];
}


void Matrix::sum_of_rows()const
{
   for(int i = 0; i < rowsM; i++){
        double sum = 0;
        for(int j = 0; j < colsM; j++){
            sum += matrixM[i][j];
        }
        sum_rowsM[i] = sum;
   }
}

void Matrix::sum_of_cols()const
{
    for(int i = 0; i < colsM; i++){
        double sum = 0;
        for(int j = 0; j < rowsM; j++){
            sum += matrixM[j][i];
        }
        sum_colsM[i] = sum;
    }
}

void Matrix::copy(const Matrix& source)
{
    if(source.matrixM == NULL){
        matrixM = NULL;
        sum_rowsM = NULL;
        sum_colsM = NULL;
        rowsM = 0;
        colsM = 0;
        return;
    }
    
    rowsM = source.rowsM;
    colsM = source.colsM;
    
    sum_rowsM = new double[rowsM];
    assert(sum_rowsM != NULL);
    
    
    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);
    
    matrixM = new double*[rowsM];
    assert(matrixM !=NULL);
    for(int i =0; i < rowsM; i++){
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
    }
    for(int i = 0; i < rowsM; i++){
        for(int j = 0; j < colsM; j++){
            matrixM[i][j] = source.matrixM[i][j];
        }
    }
    for(int i=0;i<rowsM;i++){
        sum_rowsM[i] = source.sum_rowsM[i];
    }
    for(int i=0;i<colsM;i++){
        sum_colsM[i] = source.sum_colsM[i];
    }
}

    

void Matrix::destroy()
{
    delete [] sum_colsM;
    delete [] sum_rowsM;
    for(int i = 0;i<rowsM;i++){
        delete [] matrixM[i];
    }
    delete [] matrixM;
}
