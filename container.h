#ifndef CONTAINER_H
#define CONTAINER_H
#include <iterator>
#include<stdexcept>

template <class Type>

class Container{

private:
    Type* info;
    int capacity;
    int numberOfElements;
    void resize ();
    Type* deepCopy(const Container &c);

public:

    /**
     * @brief costruttore di default di un vettore vuoto
     */
    Container();

    /**
     * @brief costruttore di copia
     */
    Container(const Container & c);

    /**
     * @brief distruttore, libera lo spazio allocato dal vettore
     */
    ~ Container();

    /**
     * @brief funzione che ritorna il numero di elementi presenti all'interno del vettore
     * @return numberOfElements
     */
    int size () const;

    /**
     * @brief funzione che ritorna la capacità massima del vettore
     * @return capacity
     */
    int getCapacity () const;

    /**
     * @brief funzione che ritorna il numero di elementi presenti  nel vettore
     * @return numberOfElements
     */
    int getNumberOfElements () const;

    /**
     * @brief funzione booleana per capire se il vettore è vuoto
     * @return true sse il vettore è vuoto, false altrimenti
     */
    bool isEmpty() const;

    /**
     * @brief rimuove tutti gli elementi dal vettore
     */
    void clear();

    /**
     * @brief ritorna l'elemento salvata in una specifica posizione del vettore
     * se tale posizione esiste, altrimenti ritorna un errore
     * @return elemento[index] sse esiste
     */
    const Type& get (int index) const;

    /**
     * @brief sostituisce l'elemento in posizione index con il nuovo valore, sse
     * tale posizione esiste nell'array altrimenti ritorna un errore
     */
    void set (int index, const Type &value);

    /**
     * @brief inserisce un elemento in posizione index, shiftando tutti gli altri
     * a destra di uno
     */
    void insert (int index, Type value);

    /**
     * @brief rimuove dall'array l'elemento in posizione index, sse esso esiste
     * altrimenti ritorna un errore se la posizione non esiste nel vettore
     */
    void remove (int index);

    /**
     * @brief aggiunge in coda al vettore un nuovo elemento
     */
    void push_back (Type value);

    /**
     * @brief overloading operatore [] nel casto di vettore non costante
     */
    Type& operator [] (int index);

    /**
     * @brief overloading operatore [] nel caso di vettore costante
     */
    const Type& operator [](int  index) const;

    int search (const Type& Value) const;

    /* FUNZIONI DA IMPLEMENTARE AL BISOGNO

         * @brief overloading operatore + per concatenare due vettori

        Container operator+ (const Container & c) const;


         * @brief aggiunge aggiunge tutti gli elementi di 'c' in coda al vettore

        Container & operator += (const Container & c);


         * @brief aggiunge in coda al vettore un nuovo elemento

        Container & operator += (const Type & value);

*/
    /**
     * @brief overloading operator =
     * @return Container
    */
    Container & operator = (const Container& c);

    /**
     * @brief overloading operator ==
     * @return false sse info!=c, true altrimenti
    */
    bool operator == (const Container& c) const;

    class Iterator{
       private:
           Type* pointer;
       public:
           Iterator(Type* p);
           Type& operator* () const;
           Type* operator -> () const;
           Iterator& operator++ ();
           Iterator& operator++ (int);
           Iterator& operator-- ();
           Iterator& operator-- (int);
           bool operator == (const Iterator& i) const;
           bool operator != (const Iterator& i) const;
       };

       Iterator begin ();
       Iterator end ();
       void erase (Iterator position);
};

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
    if (info)
        delete [] info;
}

template <class Type>
int Container<Type>::size() const {
    return numberOfElements;
}

template<class Type>
int Container<Type>::getCapacity() const{
    return capacity;
}

template<class Type>
int Container<Type>::getNumberOfElements() const{
    return numberOfElements;
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
    for(int i = 0; i<=numberOfElements; i++){
        remove(i);
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
    if(index < 0 || index > numberOfElements){
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
    capacity = std::max(1,capacity*2);
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
int Container<Type>::search(const Type& Value)const{
    int pos = -1;
    bool flag = false;

    for(int i = 0; i<numberOfElements && !flag; i++){
        if(info[i]==Value){
            pos = i;
            flag = true;
        }
    }

    return pos;
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
typename Container<Type>::Iterator Container<Type>::begin(){
    return Iterator(info);
}

template<class Type>
typename Container<Type>::Iterator Container<Type>::end(){
    return Iterator(info+numberOfElements);
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

template<class Type>
typename Container<Type>::Iterator &Container<Type>::Iterator::operator++(int){
    pointer++;
    return *this;
}

template<class Type>
typename Container<Type>::Iterator &Container<Type>::Iterator::operator--(int){
    pointer--;
    return *this;
}

template<class Type>
void Container<Type>::erase(Container::Iterator position){
    int aux = 0;
    Iterator p = begin();
    while(p != position){
        p++;
        aux++;
    }
    remove(aux);
}
#endif
