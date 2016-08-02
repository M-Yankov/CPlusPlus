#include <iostream>

template <class T>
class Container
{
private:
    int sizer;
    T * first;
public:
    Container(T * firstItem, int length)
    {
        this->first = firstItem;
        this->sizer = length;
    }

    T getMax()
    {
        T * largest = this->first;
        T * iterator = this->first;
        for (int i = 0; i < this->sizer; i++, iterator++)
        {
            if (*iterator > *largest)
            {
                largest = iterator;
            }
        }

        return *largest;
    }

    void print()
    {
        T * iterator = this->first;
        for (int i = 0; i < this->sizer; i++, iterator++)
        {
            std::cout << *iterator << std::endl;
        }
    }
};

template<class T>
class IComparable
{
    virtual int CompereTo(T & object) = 0;
};


template<class T> // where T : public  IComparable
class SampleList
{
public:
    SampleList<T>(int size)
    {
            //TODO: Finish this
    }
};

class calculate : public IComparable<calculate>
{
public:
    int value;
    calculate(int newvalue) : value(newvalue)
    {
    }

    // Inherited via IComparable
    virtual int CompereTo(calculate & object) override
    {
        return this->value > object.value;
    }

};

int main()
{
    calculate n = calculate(2);
    SampleList<calculate> a(2);


    int mYInst[10] = { 5, 2, 3, 25, 8, 11, 2, 3, 1, 18 };
    Container<int> acontainer = Container<int>(mYInst, 10);
    acontainer.print();
    std::acos(1.32);
    std::cout << "Largest: " << acontainer.getMax() << std::endl;

    return 0;
}

//class baseClass
//{
//public:
//    int value;
//};
//
//class derived : public baseClass
//{
//public:
//    int smaple;
//};
//
//
//template<class T: baseClass>
//class aClass
//{
//private:
//    T values[10];
//public :
//    void print()
//    {
//        for (int i = 0; i < 10; i++)
//        {
//            std::cout << value[i] << std::endl;
//        }
//    }
//};