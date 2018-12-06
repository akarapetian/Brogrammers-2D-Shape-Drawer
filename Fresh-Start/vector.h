#ifndef VECTOR_H_
#define VECTOR_H_



/*!
* vector class that holds all of our shape objects
*/
template <typename Type>
class vector
{
    public:

    /*!
    * default constructor for the vector
    */
    vector(); //constructor

    /*!
    * alternate constructor for the vector
    */
    vector(int s); //alt constructor, s is the capacity

    /*!
    * copy constructor for the vector
    */
    vector(const vector&v); //copy constructor

    /*!
    * overloaded copy assignment
    */
    vector<Type>& operator=(const vector<Type>& v)//copy assignment
    {
        resize(v.size_v);
        reserve(v.capacity_v);

        for(int i = 0; i < v.size_v; i++)
        {
            elem[i] = v.elem[i];
        }

        return *this;
    }

    /*!
    * move constructor for the vector
    */
    vector(vector &&v); //move constructor

    /*!
    * overloaded assignment for move constructor
    */
    vector<Type>& operator=(vector<Type> &&v) //move assignment
    {
        size_v = v.size_v;
        capacity_v = v.capacity_v;

        elem = v.elem;

        v.size_v = 0;
        v.elem = nullptr;

        return *this;
    }

    /*!
    * deletes the vector and all dynamically allocated data
    */
    ~vector();

    /*!
    * return index operator templated
    */
    Type& operator[](int n) //return index operator
    {
        if(n >= size_v)
        {
            //throw error
        }

        return elem[n];
    }

    /*!
    * constant templated return index operator
    */
    const Type& operator[](int n) const //return index operator
    {
        if(n >= size_v)
        {
            //throw error
        }

        return elem[n];
    }

    /*!
    * returns the constant current size of the vector
    */
    int size() const; //the current size of vector

    /*!
    * returns the capacity of the vector as a constant
    */
    int capacity() const; //current availible space

    /*!
    * resizes the vector
    */
    void resize(int newsize); //grow capacity

    /*!
    * adds an element and pushes it back into the list
    */
    void push_back(Type val); //add element

    /*!
    * reserves more space for the vector
    */
    void reserve(int newalloc); //get more space

    /*!
    * Typedef
    */
    using iterator = Type*;

    /*!
    * Typedef
    */
    using const_iterator = const Type*;

    /*!
    * points to the first element
    */
    iterator begin(); //points to first element

    /*!
    * points to the first element as a constant iterator
    */
    const_iterator begin() const;

    /*!
    * points to the last element
    */
    iterator end(); //points to one beyond last element

    /*!
    * points to the last element as a constant iterator
    */
    const_iterator end() const;

    /*!
    * inserts a new element into the list
    */
    iterator insert(iterator p, const Type& v); //insert a new element v before p

    /*!
    * deletes an element in the list
    */
    iterator erase(iterator p); //remove element pointed to by p


    private:

    /*!
    * int variable that contains the number of elements stored
    */
    int size_v; //# of elements stored in vector

    /*!
    * int variable that contains the number of open spaces that can possibly be stored in the vector
    */
    int capacity_v; //# of elements that can be possibly stored in the vector

    /*!
    * pointer to the elements
    */
    Type* elem; //pointer to the elements
};

template <typename Type>
using iterator = Type*;

template <typename Type>
using const_iterator = const Type*;

//default constructor
template <typename Type>
vector<Type>::vector()
{
    size_v = 0;

    capacity_v = 10; //default capacity

    elem = new Type[capacity_v];
}

//alternate constructor, pass in the capacity?
template <typename Type>
vector<Type>::vector(int s)
{
    size_v = 0;

    capacity_v = s;

    elem = new Type[capacity_v];
}

template <typename Type>
vector<Type>::vector(const vector &v)
{
    resize(v.size_v);

    reserve(v.capacity_v);

    for(int i = 0; i < v.size_v; i++)
    {
        elem[i] = v.elem[i];
    }
}

//copy assigment, not sure how to implement ***

/*
template <typename Type>
vector& vector<Type>::operator=vector(const vector& v)
{
    resize(v.size_v);

    reserve(v.capacity_v);

    for(int i = 0; i < v.size_v; i++)
    {
        elem[i] = v.elem[i];
    }

    return this;
}
*/

//move constructor

template <typename Type>
vector<Type>::vector(vector &&v)
{
    size_v = v.size_v;
    capacity_v = v.capacity_v;

    elem = v.elem;

    v.size_v = 0;
    v.elem = nullptr;
}

//move assignment, not sure how to implement ***

template <typename Type>
vector<Type>::~vector()
{
    delete [] elem;
}


template <typename Type>
int vector<Type>::size() const
{
    return size_v;
}

template <typename Type>
int vector<Type>::capacity() const
{
    return capacity_v;
}

//changes the size of the vector (only shrinks)
template <typename Type>
void vector<Type>::resize(int newSize)
{
    if(newSize < 0)
    {
        //throw negative size error
    }
    else if(newSize < size_v)
    {
        //update size
        size_v = newSize;
    }
    else if(newSize > size_v)
    {
        //throw cannot increase size of vector error
    }
}

template <typename Type>
void vector<Type>::push_back(Type val)
{
   //if vector is full
    if(size_v == capacity_v)
    {
        //reserve 10 more elements to the vector
        reserve(capacity_v + 10);
    }
    elem[size_v] = val;
    size_v++;
}

//increases capacity of vector
template <typename Type>
void vector<Type>::reserve(int newCapacity)
{
    if(newCapacity < 0)
    {
        //throw error
    }
    else if(newCapacity <= capacity_v)
    {
        //decrease capacity
        capacity_v = newCapacity;
        //call resize function?
    }
    else if(newCapacity > capacity_v)
    {
        //increase capacity

        capacity_v = newCapacity;

        Type* tempElem = new Type[newCapacity];

        for(int i = 0; i < size_v ; i++)
        {
            tempElem[i] = elem[i];
        }

        delete [] elem;

        elem = tempElem;
    }
}

//***********************************************************************
// below here are iterator methods


template <typename Type>
iterator<Type> vector<Type>::begin()
{
    //Type* begin = &elem[0];
    return &elem[0];
}

template <typename Type>
const_iterator<Type> vector<Type>::begin() const
{
    return &elem[0]; //not sure if this is right
}

template <typename Type>
iterator<Type> vector<Type>::end()
{
    return &elem[size_v - 1];
}

template <typename Type>
const_iterator<Type> vector<Type>::end() const
{
    return &elem[size_v - 1];
}


//inserts v at the element before p
template <typename Type>
iterator<Type> vector<Type>::insert(iterator p, const Type &v)
{
    //make sure to check here for overloading the vector

    Type *tempIterator = end();
    Type item;

    //if vector is full, reserve 10 more spots
    if(size_v == capacity_v)
    {
        reserve(capacity_v + 10);
    }

    //shift contents up 1 index by moving from back to p
    while(tempIterator != (p - 1))
    {
        item = *tempIterator;
        ++tempIterator;

        *tempIterator = item;

        ----tempIterator;
    }

    //place v in p
    *p = v;
    size_v++;

    return p;
}

template <typename Type>
iterator<Type> vector<Type>::erase(iterator p)
{
    //replaces contents at posistion p, by shifting everything "above", down one index

    Type *tempIterator = p + 1;
    Type item;

    while(tempIterator != end() + 1)
    {
        item = *tempIterator;
        --tempIterator;

        *tempIterator = item;

        ++++tempIterator;
    }
    size_v--;

    return p;
}

#endif
