#include "container.h"

template <class Type>
Container<Type>::Container():
    info(nullptr), capacity(0), numberOfElements(0) {}

template <class Type>
Container<Type>::Container(const Container &c){
    deepCopy(c);
}

template <class Type>
Type* Container<Type>::deepCopy(const Container &c){
    Type* aux = new Type*[c.numberOfElements];
    for (int i = 0; i < numberOfElements; i++){
        aux[i] = c.info[i];
    }
    return aux;
}

/* Costruttore di copia alternativo questo non utilizza l'operatore di =
 * deepCopy(c) no istruzioni aggiuntive  per aggiornare numberOfElements
 *
 * Soluzione proposta da Ranzato info = deepCopy(c) + aggiornare il campo numberOfElements manualmente
 * template<class Type>
void Container<Type>::deepCopy(const Container &c){
    numberOfElements = capacity = c.numberOfElements;
    if(capacity == 0){
        info = NULL;
    }
    else{
        info = new Type* [capacity];
    }
    for (int i = 0; i < numberOfElements; i++){
        info[i] = c.info[i];
    }
}
*/

template <class Type>
Container<Type>::~Container(){
    if (info!=NULL)
        delete[] info;
}

template <class Type>
int Container<Type>::size() const {
    return numberOfElements;
}

template<class Type>
int Container<Type>::getCapacity() const{
    return capacity;
}

template <class Type>
bool Container<Type>::isEmpty() const{
    if(numberOfElements == 0){
        return true;
    }
    else return false;
}

template <class Type>
void Container<Type>::clear(){
    if(info != NULL){
        delete[] info;
    }
    else {
        numberOfElements = capacity = 0;
        info = NULL;
    }
}

template <class Type>
const Type& Container<Type>::get(int index) const{
    if (index < 0 || index >= numberOfElements){
        throw std::out_of_range("Container::get(int index), index is out of range");
    }
    return info[index];
}

template <class Type>
void Container<Type>::set(int index, const Type& value){
    if (index < 0 || index >= numberOfElements){
        throw std::out_of_range("Container::see(int index, Type& value), index is out of range");
    }
    info[index] = value;
}

template <class Type>
void Container<Type>::insert(int index, Type value){

    if(numberOfElements == capacity){
        resize();
    }
    if(index < 0 || index > numberOfElements){
        throw std::out_of_range("Container::insert(int index, Type Value), index is out of range)");
    }
    for(int i = numberOfElements;  i > index; i--){
        info[i] = info[i-1];
    }
    info[index] = value;
    numberOfElements++;
}

template<class Type>
void Container<Type>::remove(int index){
    if(index < 0 || index >= numberOfElements){
        throw std::out_of_range("Container::remove(int index), index is out of range)");
    }
    for(int i = index; i < numberOfElements -1; i++){
        info[i] = info [i+1];
    }
    numberOfElements --;
}

template <class Type>
void Container<Type>::push_back(Type value){
    insert(numberOfElements, value);
}

template <class Type>
void Container<Type>::resize(){
    capacity = capacity*2;
    Type* aux = new Type [capacity];
    for(int j = 0; j < numberOfElements; j++){
        aux[j] = info[j];
    }
    if(info!=NULL){
        delete [] info;
    }
    info = aux;
}

template <class Type>
Type& Container<Type>::operator [](int index){
    if (index < 0 || index >= numberOfElements){
        throw std::out_of_range("Container::operator[](int index), index is out of range");
    }
    return info[index];
}

template <class Type>
const Type& Container<Type>::operator [](int index) const {
    if (index < 0 || index >= numberOfElements){
        throw std::out_of_range("Container::operator[](int index), index is out of range");
    }
    return info[index];
}

template<class Type>
Container<Type> &Container<Type>::operator = (const Container &c){
    if(this!=&c){
        if(info!=NULL){
            delete[] info;
        }
        info = deepCopy(c);
        numberOfElements = c.numberOfElements;
    }
    return* this;
}

template<class Type>
bool Container<Type>::operator ==(const Container &c) const{
    if(numberOfElements != c.numberOfElements){
        return false; //perché i due contenitori hanno #elementi diverso
    }
    for(int i = 0; i < numberOfElements; i++){
        if(info[i]!=c.info[i]){
            return false;
        }
    }
    return true;
}

template<class Type>
typename Container<Type>::Iterator Container<Type>::begin() const{
    return Iterator(this);
}

template<class Type>
typename Container<Type>::Iterator Container<Type>::end() const{
    return Iterator(info + numberOfElements);
}

template<class Type>
Container<Type>::Iterator::Iterator(Type *p):pointer(p){}

template<class Type>
Type& Container<Type>::Iterator::operator*() const{
    return *pointer;
}

template<class Type>
Type* Container<Type>::Iterator::operator ->() const{
    return pointer;
}

template<class Type>
typename Container<Type>::Iterator &Container<Type>::Iterator::operator ++(){
    pointer ++;
    return *this;
}

template<class Type>
typename Container<Type>::Iterator &Container<Type>::Iterator::operator --(){
    pointer --;
    return *this;
}

template<class Type>
bool Container<Type>::Iterator::operator ==(const Container<Type>::Iterator &i) const{
    return pointer == i.pointer;
}

template<class Type>
bool Container<Type>::Iterator::operator !=(const Container<Type>::Iterator &i) const{
    return pointer != i.pointer;
}
