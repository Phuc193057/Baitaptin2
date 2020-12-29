#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

class DT{
	private:
		int n;
		double* a;
	public:
		DT()
		{
			this->n = 0;
			this->a = NULL;
		}
		
		DT(int n1)
		{
			this->n = n1;
			this->a = new double[ n1 + 1 ];
		}
		
		~DT()
		{
			this->n = 0;
			delete this->a;
		}
		
		friend ostream& operator<<(ostream& os, const DT& d)
		{
		  os << "Cac he so: ";
		  for(int i = 0;i <= d.n; i++)
		  os << d.a[i] << " ";
		  return os;
		}
		
		friend istream& operator>>(istream& is, DT& d)
		{
		   cout << endl << "Bac da thuc: ";
		   cin >> d.n;
		   d.a = new double[d.n + 1];
		   cout << "Nhap cac he so da thuc: ";
		   
		   for(int i = 0;i <= d.n; i++ )
		   {
		     cout << endl << "He so bac " << i <<" = ";
			 is >> d.a[i];
		   }
		   return is;
		}
		   
		friend DT operator-(const DT& d)
		{
			DT p;
			p.n = d.n;
			for(int i = 0; i<= p.n; i++)
			p.a[i] = -d.a[i];
			return p;
		}
		
		friend void copy(DT &d1, DT d2)
		{
			d1.n = d2.n;
			for(int i = 0; i<= d1.n; i++)
			d1.a[i] = d2.a[i];
		}

		
		friend DT operator+(DT d1, DT d2)
		{
			DT d;
			int k,i;
            k = d1.n > d2.n ? d1.n : d2.n ;
            for (i=0;i<=k ;++i)
              if (i<=d1.n && i<=d2.n) d.a[i] = d1.a[i] + d2.a[i];
              else if (i<=d1.n) d.a[i] = d1.a[i];
              else d.a[i] = d2.a[i];
            i = k;
            while (i>0 && d.a[i]==0.0)
			i--;
			d.n = i;
			return d;
		}
		
		friend DT operator-(DT d1,DT d2)
		{
	         return (d1 + (-d2));
		}
		
		friend DT operator*(DT d1, DT d2)
		{
		   DT d;
		   d.n = d1.n + d2.n;
		   int k = d.n;
		   for(int i=0 ;i<= k; i++)
		   d.a[i] = 0;
		   for(int i = 0; i<= d1.n; i++)
		      for(int j = 0; j<= d2.n; j++)
		         d.a[i + j] = d1.a[i]*d2.a[j];
		
		    return d;
		}
		
		friend double operator^(DT d, double x)
		{
			double tong, t = 1.0;
			for(int i = 0; i<= d.n; i++)
			{
				tong += d.a[i]*t;
				t*=x;
			}
			
			return tong;
		}
		

double F(DT d, double x)
{
	double tong, t = 1.0;
			for(int i = 0; i<= d.n; i++)
			{
				tong += d.a[i]*t;
				t*=x;
			}
			
			return tong;
}

};

int main()
{
	DT p,q,r,s,f;
	double x;
	cout << endl << "Nhap da thuc P: ";
	cin >> p;
	cout << endl << "Nhap da thuc Q: ";
	cin >> q;
	cout << endl << "Nhap da thuc R: ";
	cin >> r;
	cout << endl << "Nhap da thuc S: ";
	cin >> s;
	cout << endl << "Nhap so thuc x: ";
	cin >> x;
	copy(f,-(p + q)*(r - s));
	cout << f;
	cout << endl << "Da thuc F: " << f;
	cout << endl << "x= " << x;
	double g = f^x;
	cout << endl << "f(x)= " << g;

	return 0;
}
