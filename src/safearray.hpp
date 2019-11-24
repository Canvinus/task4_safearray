////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief     Safearray class methods definition
/// \author    Sergey Shershakov
/// \version   0.2.0
/// \date      30.01.2017
///            This is a part of the course "Algorithms and Data Structures" 
///            provided by  the School of Software Engineering of the Faculty 
///            of Computer Science at the Higher School of Economics.
///
/// This file contains templates of the method of the class Safearray.
/// This file is not going to be used w/o its main counterpart, safearray.h.
/// Since the file is used only through safearray.h, which has its own "include 
/// watcher", we add no addition "watcher" here.
///
////////////////////////////////////////////////////////////////////////////////

// #ifndef    // No need to have a watcher here!


// we have to indicate that methods of the class Safearray are also inside the namespace xi
namespace xi {

template<class T>
SafeArray<T>::SafeArray(const size_t cap)
{
    _capacity = cap;

       if (cap == 0)
           _storage = nullptr;
       else
           _storage = new T[cap];
}

template<class T>
SafeArray<T>::SafeArray(const xi::SafeArray<T> &safearr)
{
    _capacity = safearr.getCapacity();

    if (_capacity == 0)
        _storage = nullptr;
    else
        _storage = new T[_capacity];
    for (int i = 0; i < _capacity; ++i)
        _storage[i] = safearr._storage[i];
}

template<class T>
SafeArray<T>::~SafeArray()
{
    delete[] _storage;
}

template<class T>
size_t SafeArray<T>::getCapacity() const
{
    return _capacity;
}

template<class T>
void SafeArray<T>::checkBounds(size_t index) const
{
    if (index >= _capacity)
        throw std::out_of_range("Index is out of bounds.");
}

template<class T>
const T &SafeArray<T>::operator[](size_t k) const
{
    checkBounds(k);
    return _storage[k];
}

template<class T>
T &SafeArray<T>::operator[](size_t k)
{
    checkBounds(k);
    return _storage[k];
}

template<class T>
SafeArray <T> &SafeArray<T>::operator=(const SafeArray <T> &arr)
{
    _capacity = arr._capacity;

    delete[] _storage;

    if (_capacity == 0)
        _storage = nullptr;
    else
        _storage = new T[_capacity];

    for (int i = 0; i < _capacity; ++i)
        _storage[i] = arr._storage[i];

    return *this;
}

} // namespace xi
