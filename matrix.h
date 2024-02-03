#include <iostream>
#include <cstdlib>
#include <cassert>
#include <initializer_list>
/*template <typename T>

T add(T a, T b){
	return a + b;
}
*/
/*
class vec{
public:
	T* data;
	int size;
	vec(int size){
		this->data = new T[size];
		this->size = size;
	}
	vec* operator+(const vec& other){
		vec *r = new vec(this->size);
		for(int i=0; i<this->size; i++){
			r->data[i] = this->data[i] + other.data[i]; 
		}
		return r;
	}
};
*/

template <typename T>
class matrix{
public:
	T *data;
	int col;
	int row;
	int size;
	
	matrix(int col , int row){
		this->data = new T[col * row];
		this->col = col;
		this->row = row;
		this->size = col * row;
	}
	void print(){
		for(int i=0; i<this->col; i++){
			for(int j=0; j<this->row; j++)
				std::cout << *(this->data + this->row * i + j ) << "  ";
			std::cout << std::endl;
		}
	}
	void operator=(const T& other){
		for(int i=0; i<this->size; i++){
			*(this->data + i) = other;
		}
	}
	void operator=(const std::initializer_list<T>& other){
		int i=0;
		for(T x: other){
			*(this->data + i) = x;
			i++;
		}
	}


	void rand(int Sv, int Fv){
		for(int i=0; i<this->size; i++){
			*(this->data + i) = ::rand() % (Fv - Sv + 1) + Sv;
		}
	}

	matrix<T> operator+(const matrix<T>& other){
//		matrix<T> *r = new matrix<T>(this->col, this->row);  //ptr type
		matrix<T> r(this->col, this->row);
		for(int i=0; i<this->size; i++){
			*(r.data + i) = *(this->data + i) + *(other.data + i);
		}
		return r;
	}


	matrix<T> operator-(const matrix<T>& other){
		matrix<T> r(this->col, this->row);
		for(int i=0; i<this->size; i++){
			*(r.data + i) = *(this->data + i) - *(other.data + i);
		}
		return r;
	}

	matrix<T> operator*(const matrix<T>& other){
		matrix<T> r(this->col, this->row);
		for(int i=0; i<this->size; i++){
			*(r.data + i) = *(this->data + i) * *(other.data + i);
		}
		return r;
	}

	matrix<T> operator/(const matrix<T>& other){
		matrix<T> r(this->col, this->row);
		for(int i=0; i<this->size; i++){
			*(r.data + i) = *(this->data + i) / *(other.data + i);
		}
		return r;
	}

	void operator-=(const T& other){
		for(int i=0; i<this->size; i++)
			*(this->data + i) -= other;
	}

	void operator+=(const T& other){
		for(int i=0; i<this->size; i++)
			*(this->data + i) += other;
	}

	void operator*=(const T& other){
		for(int i=0; i<this->size; i++)
			*(this->data + i) *= other;
	}

	void operator/=(const T& other){
		for(int i=0; i<this->size; i++)
			*(this->data + i) /= other;
	}


	matrix<T> dot(const matrix<T>& other){
		if(this->row != other.col){
			std::cout << "Error: row and col unmatched !!" << std::endl;
			assert(0);
		}
		matrix<T> r(this->col, other.row);
		r = 0;	
	for(int i=0; i<this->col; i++)
		for(int k=0; k<this->row; k++)
			for(int j=0; j<other.row; j++)
				*(r.data + r.row * i + j) += *(this->data + this->row * i + k) * *(other.data + other.row * k + j);
	return r;
	}
	
	matrix<T> operator~(){
		matrix <T> r(this->row, this->col);
		for(int i=0; i<this->col; i++)
			for(int j=0; j<this->row; j++)
				*(r.data + r.row * j + i) = *(this->data + this->row * i + j);
		return r;
	}

};
