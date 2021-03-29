#ifndef DEEPPTR_H
#define DEEPPTR_H

#include<typeinfo>

template<class T>
class DeepPtr
{
private:
    T* punt;
public:
    DeepPtr(T* = 0);
    DeepPtr(const DeepPtr&);
    DeepPtr& operator=(const DeepPtr&);
    ~DeepPtr();
    T& operator*() const;
    T* operator->() const;
    bool operator==(const DeepPtr&) const;
    bool operator!=(const DeepPtr&) const;
};

template<class T>
DeepPtr<T>::DeepPtr(T * p): punt(p)  {}

template<class T>
DeepPtr<T>::DeepPtr(const DeepPtr & dp){
    punt = dp.punt != 0 ? dp.punt->clone() : 0;
}

template<class T>
DeepPtr<T> &DeepPtr<T>::operator=(const DeepPtr & dp)
{
    if(this != &dp){
        delete punt;//se faccio delete su nullptr non succede nulla
        punt = dp.punt != 0 ? dp.punt->clone() : nullptr;
    }
    return *this;
}

template<class T>
DeepPtr<T>::~DeepPtr()
{
    delete punt;
}

template<class T>
T &DeepPtr<T>::operator*() const
{
    return *punt;
}

template<class T>
T *DeepPtr<T>::operator->() const
{
    return punt;
}

template<class T>
bool DeepPtr<T>::operator==(const DeepPtr & dp) const
{
    if(typeid (*punt) != typeid (*dp.punt))
        return false;
    return *punt == *dp.punt;
}

template<class T>
bool DeepPtr<T>::operator!=(const DeepPtr & dp) const
{
    if(typeid (*punt) != typeid (*dp.punt))
        return true;
    return !(*punt == *dp.punt);
}


#endif // DEEPPTR_H
