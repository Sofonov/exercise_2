#pragma once
#include <cstdlib>

template <class T>

class My_smart_ptr
{
	T* ptr;
	unsigned * ref_count;

public:
	
	My_smart_ptr(T *ptr):ptr(ptr)
	{
		ref_count = new unsigned;
		*ref_count = 1;
	}
	
	My_smart_ptr(const My_smart_ptr & sptr) 
	{
		ptr = sptr.ptr;
		ref_count = sptr.ref_count;
		++(*ref_count);
	}
	
	void DE()
	{
		--(*ref_count);
		if (ref_count == 0) 
		{
			delete ptr;
			delete ref_count;
			ptr = NULL;
			ref_count = NULL;
		}
	}
	
	T operator*()
	{
		return *ptr;
	}
	
	T* operator ->()
	{
		return ptr;
	}

	My_smart_ptr & operator=(const My_smart_ptr & sptr) 
	{
		
		if (*ref_count > 0)
		{
			DE();
		}
		if (this != &sptr)
		{
			ptr = sptr.ptr;
			ref_count = sptr.ref_count;
			++(*ref_count);
		}
		return *this;
	}
	
	bool operator==(const My_smart_ptr & sptr)
	{
		return ptr == sptr.ptr;
	}

	bool operator!=(const My_smart_ptr & sptr)
	{
		return !(ptr == sptr.ptr);
	}

	~My_smart_ptr()
	{
		DE() ;
	}
};

 