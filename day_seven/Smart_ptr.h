#pragma once
#include <iostream>
using namespace std;

template<class T>
class Smart_ptr
{
public:
	constexpr Smart_ptr() noexcept = default;
	constexpr Smart_ptr(T* p);
	Smart_ptr(const Smart_ptr<T>& orig);                // Ç³¿½±´
	Smart_ptr<T>& operator=(const Smart_ptr<T>& rhs);   // Ç³¿½±´
	~Smart_ptr();
	bool isempty() {
		if (ptr == nullptr)
			return true;
		else
			return false;
	}

	int use_count_();

	void reset(T* p = nullptr) noexcept {
		T* old_p = std::exchange(ptr, p);
		delete old_p;
	}

	T* release() noexcept {
		return std::exchange(ptr, nullptr);
	}

	T* get() const noexcept { return ptr; }
	operator bool() const noexcept { return bool(get()); }
	T& operator*() const noexcept { return *get(); }
	T* operator->() { return ptr; }

private:
	T* ptr = nullptr;
	int* use_count;
};

template<class T>
inline constexpr Smart_ptr<T>::Smart_ptr(T* p)
{
	try
	{
		ptr = p;
		use_count = new int(1);
	}
	catch (const std::exception&)
	{
		delete ptr;
		ptr = nullptr;
		use_count = nullptr;
		cout << "Allocate memory for use_count fails." << endl;
		exit(1);
	}
}

template<class T>
inline Smart_ptr<T>::Smart_ptr(const Smart_ptr<T>& orig)
{
	ptr = orig.ptr;
	use_count = orig.use_count;
	++(*use_count);
	cout << "Copy constructor is called!" << endl;
}

template<class T>
inline Smart_ptr<T>& Smart_ptr<T>::operator=(const Smart_ptr<T>& rhs)
{
	++(*rhs.use_count);
	if (--(*use_count) == 0) {
		delete ptr;
		delete use_count;
		cout << "Left side object is deleted!" << endl;
	}
	ptr = rhs.ptr;
	use_count = rhs.use_count;
	cout << "Assignment operator overloaded is called!" << endl;
	return *this;
}

template<class T>
inline Smart_ptr<T>::~Smart_ptr()
{
	if (--(*use_count) == 0)
	{
		delete ptr;
		delete use_count;
		ptr = nullptr;
		use_count = nullptr;
		cout << "Destructor is called!" << endl;
	}
}

template<class T>
inline int Smart_ptr<T>::use_count_()
{
	return *use_count;
}