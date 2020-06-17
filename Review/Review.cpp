#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

// pointer swap (4a)
void swap(int* ptr1, int* ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

// reference swap (7a)
void swap(int& v1, int& v2)
{
	int temp = v1;
	v1 = v2;
	v2 = temp;
}

// template (11)
template<typename T>
T max_value(T v1, T v2)
{
	return (v1 > v2) ? v1 : v2;
}

class Animal
{
public:
	Animal() : name{}, lifespan{ 0 } {}
	Animal(string name, int lifespan) : name(name), lifespan(lifespan) {}

	string GetName() { return name; }
	void SetName(string name) { this->name = name; }

	int GetLifespan() { return lifespan; }
	void SetLifespan(int lifespan) { this->lifespan = lifespan; }

	virtual string Say() { return ""; }

	bool operator == (string& name)
	{
		return (this->name == name);
	}

	friend bool operator == (Animal* animal, const string& name)
	{
		return (animal->name == name);
	}

	friend ostream& operator << (ostream& stream, const Animal& animal)
	{
		stream << "name: " << animal.name << endl;
		stream << "lifespan: " << animal.lifespan << endl;
		return stream;
	}

protected:
	string name;
	int lifespan;
};

class Duck : public Animal
{
public:
	Duck() {}
	Duck(string name, int lifespan) : Animal(name, lifespan) {}

	string Say() override { return "Quack!"; }
};

class Cat : public Animal
{
public:
	Cat() {}
	Cat(string name, int lifespan) : Animal(name, lifespan) {}

	string Say() override { return "Meow!"; }
};

int main()
{
	// POINTER

	// 1) create a pointer (ptr1) that points to i1
	int i1 = 10;
	int* ptr1 = &i1;

	// 2a) change the value of i1 to 20 by a pointer dereference * of ptr1 
	*ptr1 = 20;

	// 2b) print the dereference of ptr1
	cout << *ptr1 << endl;

	// 3) create a pointer (ptr2) and set it to point at what ptr1 points at
	int* ptr2 = ptr1;

	// 4a) create a function to swap i2 and i3 with pointers
	// 4b) print the values of i2 and i3 after the swap
	int i2 = 23;
	int i3 = 45;
	swap(&i2, &i3);
	cout << "i2: " << i2 << " i3: " << i3 << endl;

	// REFERENCE

	// 5) create a reference (ref1) that references i5
	int i5 = 30;
	int& ref1 = i5;
	// 6a) change the value of i5 using the reference variable
	ref1 = 22;
	// 6b) print i5 to show that a change was made
	cout << "i5: " << i5 << endl;
	// 7a) create a function to swap i2 and i3 with references
	// 7b) print the values of i2 and i3 after the swap
	swap(i2, i3);
	cout << "i2: " << i2 << " i3: " << i3 << endl;

	// DYNAMIC MEMORY (HEAP)

	// 8) create a pointer (ptr3) that points to an array of 10 ints that are created on the heap (new)
	int* ptr3 = new int[10];
	// 9a) iterate through the array with the pointer (ptr3[]) and set them to a random number between 1 and 10
	for (int i = 0; i < 10; i++)
	{
		ptr3[i] = rand() % 10;
	}
	// 9b) iterate through the array with the pointer (ptr3[]) and print out only even values (use the % to determine if it is even)
	for (int i = 0; i < 10; i++)
	{
		if (ptr3[i] % 2 == 0) cout << ptr3[i] << " ";
	}
	cout << endl;

	// 10) free the memory of ptr3
	delete[] ptr3;

	// TEMPLATE

	// 11a) create a template function to return the max value of two types
	// 11b) call the template function with two float values and display the answer
	cout << "max(23.5f, 6.7f): " << max_value<float>(23.5f, 6.7f) << endl;

	// INHERITANCE - create a class hierarchy using Animal as the base class and two different animals as the child class


	// BASE CLASS (Animal)
	// 12a) add protected members (string name, int lifespan)
	// 12b) create a default constructor
	// 12c) create a constructor that takes in the name and the lifespan
	// 12d) create accessor methods (get/set) for name and lifespan
	// 12e) in the base class have a function called Say() that returns a string literal of the noise the animal makes
	// 12f) allow the Say() function to be overridden by derived classes

	// DERIVED CLASS (Specific Animal)
	// create two derived classes of animals
	// 13a) create a default constructor
	// 13b) create a constructor that takes in the name and the lifespan and initialize the base class with parameters
	// 13c) allow the derived classes to override the Say() method, use override keyword also
	// example: string Say() { return "quack"; }

	// POLYMORPHISM
	// 14a) create a list<> of Animal* called animals
	// 14b) create an animal on the heap (new)

	std::list<Animal*> animals;
	Animal* animal;

	//Animal* animal;
	//animal = new SpecificAnimal(<name>, <lifespan>);

	// 14c) add animal to the list
	// 14d) create the other animal on the heap (new)
	// 14e) add the other animal to the list
	// 14f) iterate through the list using a for loop displaying the Say() on all the animals

	animal = new Duck("duck", 7);
	animals.push_back(animal);
	animal = new Cat("cat", 17);
	animals.push_back(animal);

	for (Animal* animal : animals)
	{
		cout << animal->Say() << endl;
	}

	// OPERATOR OVERLOADING
	// 15a) create an operator overload for the cout stream << to stream out the Animal classes
	// 15b) iterate through the animals list and display the animals using the << 
	for (Animal* animal : animals)
	{
		cout << *animal;
	}

	// TYPEDEF / AUTO / CONST
	// 16a) create a new type name currency_t to a double using typedef
	// 16b) create a new type name u8_t to an unsigned char using 'using'
	// 16c) use the auto keyword on a variable named 'value' assigned to a float value
	// 16d) define a constant float variable named PI to the value 3.1415f
	typedef double currency_t;
	using u8_t = unsigned char;
	auto value = 4.5f;
	const float PI = 3.1415f;

	// CONTAINERS
	// 17a) create a vector of ints called numbers and initialize it with { 43, 23, 12, 65, 8 }
	// 17b) add another int to the end of the vector, whatever value you'd like
	// 17c) display all the elements of the vector using a for range loop
	vector<int> numbers = { 43, 23, 12, 65, 8 };
	numbers.push_back(1);
	for (int number : numbers)
	{
		cout << number << " ";
	}
	cout << endl;

	// ALGORITHMS
	// 18a) reverse the order of the vector of ints (numbers) and display the vector
	// 18b) sort the order of the vector of ints and display the vector
	reverse(numbers.begin(), numbers.end());
	for (int number : numbers)
	{
		cout << number << " ";
	}
	cout << endl;

	sort(numbers.begin(), numbers.end());
	for (int number : numbers)
	{
		cout << number << " ";
	}
	cout << endl;

	// 18c) using the animals list above, use the find algorithm to find an animal by the name, this will pass back the iterator
	// 18d) display the animal that was returned above in the iterator
	// 18e) delete the animal from the heap
	// 18f) erase the animal from the animals list using the iterator
	auto iter = find(animals.begin(), animals.end(), string{ "cat" });
	cout << *(*iter) << endl;
	delete* iter;
	animals.erase(iter);

	// HEAP DEALLOCATION
	// 19a) iterate through the list of animals and call delete on them to free the memory
	// 19b) clear the animals list
	for (Animal* animal : animals)
	{
		delete animal;
	}
	animals.clear();

	// WELL-BEING
	// 20a) You are an awesome person who is capable of doing whatever you put your time and energy into.
	// 20b) Enjoy your day because now is the most important time!
}


