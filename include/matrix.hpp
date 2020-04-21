// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_MATRIX_HPP_
#define INCLUDE_MATRIX_HPP_

template <class T>
class Matrix
{
 int x, y;
 T** ptr;

public:
 Matrix()
 {
 x = 0;
 y = 0;
 ptr = nullptr;
 }

 Matrix(int a, int b)
 {
  x = a;
  y = b;
  ptr = new T * [x];
  for (int i = 0; i < x; i++)
   ptr[i] = new T[y];
  for (int i = 0; i < x; i++)
   for (int j = 0; j < y; j++)
    ptr[i][j] = 0;
 }

 Matrix(const Matrix<T>& cpy)
 {
  x = cpy.x;
  y = cpy.y;
  ptr = new T * [x];
  for (int i = 0; i < x; i++)
   ptr[i] = new T[y];
  for (int i = 0; i < x; i++)
   for (int j = 0; j < y; j++)
    ptr[i][j] = cpy.ptr[i][j];
 }

 T* operator[](int i) const
 {
  return ptr[i];
 }

 Matrix<T>& operator= (Matrix<T>& mtr)
 {
  for (int i = 0; i < x; i++)
   delete[]ptr[i];
  delete[]ptr;
  x = mtr.x;
  y = mtr.y;
  ptr = new T * [x];
  for (int i = 0; i < x; i++)
   ptr[i] = new T[y];
  for (int i = 0; i < x; i++)
   for (int j = 0; j < y; j++)
    ptr[i][j] = mtr.ptr[i][j];
  return *this;
 }

  friend bool operator==(const Matrix<T>& mtr1, const Matrix<T>& mtr2)
 {
  if (mtr1.get_rows() == mtr2.get_rows()
      && mtr1.get_columns() == mtr2.get_columns())
  {
   for (int i = 0; i < mtr1.x; i++)
    for (int j = 0; j < mtr2.y; j++)
          if (mtr1.ptr[i][j] != mtr2.ptr[i][j])
       return false;
      return true;
  } else {
   return false;
  }
 }

 friend bool operator!=(const Matrix<T>& mtr1, const Matrix<T>& mtr2)
 {
  return !(mtr1 == mtr2);
 }

 friend Matrix<T> operator+(const Matrix<T>& mtr1, const Matrix<T>& mtr2)
 {
  Matrix<T> mtr3(mtr1.x, mtr1.y);
  for (int i = 0; i < mtr1.x; i++)
   for (int j = 0; j < mtr1.y; j++)
    mtr3.ptr[i][j] = mtr1.ptr[i][j] + mtr2.ptr[i][j];
  return mtr3;
 }

 friend Matrix<T> operator-(const Matrix<T>& mtr1, const Matrix<T>& mtr2)
 {
  Matrix<T> mtr3(mtr1.x, mtr1.y);
  for (int i = 0; i < mtr1.x; i++)
   for (int j = 0; j < mtr1.y; j++)
    mtr3.ptr[i][j] = mtr1.ptr[i][j] - mtr2.ptr[i][j];
  return mtr3;
 }

 friend Matrix<T> operator-(const Matrix<T>& mtr1, const Matrix<T>& mtr2)
 {
  Matrix<T> mtr3(mtr1.x, mtr2.y);
  for (int i = 0; i < mtr3.x; i++)
   for (int j = 0; j < mtr3.y; j++)
   {
    int sum = 0;
    for (int k = 0; k < mtr3.y; k++)
     sum += mtr1.ptr[i][k] * mtr2.ptr[k][j];
    mtr3[i][j] = sum;
   }
  return mtr3;
 }

 Matrix<T> & Inverse()
 {
  Matrix<T> mtr(x, y);
  for (int i = 0; i < x; i++)
   for (int j = 0; j < y; j++)
   {
    mtr.ptr[i][j] = 1 / this->ptr[i][j];
   }
  return mtr;
 }

 int get_rows() const
 {
  return x;
 }

 int get_columns() const
 {
  return y;
 }
};

#endif // INCLUDE_MATRIX_HPP_
