#include<iostream>

using namespace std;

class Complex{
	int real, imag;
	
	public:
		Complex(int r = 0, int i = 0) : real(r), imag(i){}
		
		Complex operator+(const Complex&b) const{
		   Complex z(real + b.real, imag + b.imag);
		   return z;
		}
		
		Complex operator-(const Complex&b) const{
		   Complex z(real - b.real, imag - b.imag);
		   return z;
		}
		
		Complex operator*(const Complex&b) const{
			Complex z(real*b.real - imag*b.imag, real*b.imag + imag*b.real);
			return z;
		}
		
		Complex operator/(const Complex&b) const{
		    Complex z((real*b.real + imag*b.imag)/(b.real*b.real + b.imag*b.imag),
			(imag*b.real - real*b.imag)/(b.real*b.real + b.imag*b.imag));
			return z;
		}
		
		Complex& operator+=(const Complex&b){
			this->real += b.real;
			this->imag += b.imag;
			return *this;
			}
			
		Complex& operator-=(const Complex&b){
		    this->real -= b.real;
			this->imag -= b.imag;
			return *this;
			}
		
		friend ostream& operator<<(ostream& os, const Complex b)
	{
		os << b.real << " + i." << b.imag;
		return os;
	} 
	};
		
		
int main()
{
	Complex A;
	Complex B(3, 4);
	Complex C(1, 5);
	Complex D(4, 2);
	Complex E(1, 3);
	A = B*C + (D - E);
     cout << "So phuc A: " << A;
	return 0;
}
	
			
			
			
			
			
