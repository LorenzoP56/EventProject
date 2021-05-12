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
    T* getPunt() const;
};

/**
 * @brief metodo per ottenere il puntatore a T
 * @return puntatore punt
 */
template<class T>
T* DeepPtr<T>::getPunt() const{
    return punt;
}

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
        delete punt;//ok anche se nullptr
        punt = dp.punt != 0 ? dp.punt->clone() : nullptr;
    }
    return *this;
}

template<class T>
DeepPtr<T>::~DeepPtr()
{
    delete punt;
}
/**
 * @brief ridefinizione operatore di dereferenzione
 */
template<class T>
T &DeepPtr<T>::operator*() const
{
    return *punt;
}
/**
 * @brief ridefinizione operatore ->
 */
template<class T>
T *DeepPtr<T>::operator->() const
{
    return punt;
}
/**
 * @brief ridefinizione operatore di uguaglianza
 */
template<class T>
bool DeepPtr<T>::operator==(const DeepPtr & dp) const
{
    if(typeid (*punt) != typeid (*dp.punt))
        return false;
    return *punt == *dp.punt;
}
/**
 * @brief ridefinizione operatore di disuguaglianza
 */
template<class T>
bool DeepPtr<T>::operator!=(const DeepPtr & dp) const
{
    if(typeid (*punt) != typeid (*dp.punt))
        return true;
    return !(*punt == *dp.punt);
}


#endif // DEEPPTR_H
