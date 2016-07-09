#include <iostream>
#include <memory>

#include <string>

class MemeoryAllocator
{
public:
	MemeoryAllocator()
	{
		std::cout << "Allocated" << std::endl;
	}

	~MemeoryAllocator()
	{
		std::cout << "Deallocated" << std::endl;
	}
};

class Dog
{
public:
	Dog(std::string name) : name(name)
	{
	}

	std::string name;
	std::string breed;
};

class Person
{
public:
	Person(std::string personName) : name(personName)
	{
	}

	std::string name;
	std::shared_ptr<Dog> dog;
};

class Friend
{
public:
	Friend(std::string fname) : name(fname)
	{
	}

	std::string name;
	std::weak_ptr<Dog> dog;
};

int main()
{
	std::unique_ptr<Person> peson(new Person("Gosho"));
	std::unique_ptr<Friend> aFriend(new Friend("Ivan"));
	
	peson->dog = std::shared_ptr<Dog>(new Dog("Sharo"));
	aFriend->dog = peson->dog;

	std::cout << "Person " << peson->name << " has dog: " << peson->dog->name << std::endl;
	std::cout << "Friend " << aFriend->name << " has dog: " << peson->dog->name << std::endl;

	peson->dog = nullptr;

	// error
	std::cout << "Person " << peson->name << " has dog: " << peson->dog->name << std::endl;
	std::cout << "Friend " << aFriend->name << " has dog: " << peson->dog->name << std::endl;
	/*MemeoryAllocator * memoryAllocator = new MemeoryAllocator();

	std::cout << std::string(13, '-') << std::endl;
	delete memoryAllocator;

	std::cout << std::string(13, '#') << std::endl;*/
	return 0;
}