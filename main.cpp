#include "ptr.h"
#include <iostream>


int main()
{
	double a;
	My_smart_ptr<double> aptr(&a);
	a = 5.;
	std::cout << *aptr << std::endl;
	
	My_smart_ptr<double> bptr(&a);
	std::cout << *bptr << std::endl;
	
	My_smart_ptr<double> d = new double(10);
	
	if (bptr != d)
	{
		std::cout << *d << std::endl;
	}
	

	d = aptr;
	
	if (bptr == d) 
	{
		std::cout << *d << std::endl;
	}
	
	
	system("pause");
	
}