#include <iostream>


// Encapsulation, Inheritecne and polymorphism (virtual functions)
class Dog 
{
	public:
	bool bark = false;
	virtual void foo() 
	{
		std::cout << "This comes from dog" << std::endl;
	}
	
	virtual ~Dog(){}; // virtual desctructor for proper clean up
	
	protected:
	int height = 10;
	
	
	private:
	double color = 22.1;
};

class Tommy:public Dog
{
	public:
	
	bool bark = true;
	
	void foo() override
	{
		std::cout << "This comes from Tommy, overriden" << std::endl;
	}
	
	virtual ~Tommy(){};
};


// abstraction
class Shape
{
public:
	virtual void draw() = 0; // pure virtual function
	virtual ~Shape(){}
};

class Square:public Shape
{
	void draw() override
	{
		std::cout << "Drawing a square" << std::endl;
	}
	
	~Square(){}
};



// static outside class is used to declare variables locked to the same TU.
// static variables inside the class shares the same memory with all the instances of the class. 
	// it can be used, for example, to calculate all the instances of the class. 

class InstanceCounter
{
	public:
		static int counter;
		bool wow =  true;
		int* ptr = new int(5);
		
	private:
		int id;
	
	public:
	InstanceCounter()
	{
		id = counter;
		std::cout << " Object ID:  " << id << std::endl; 
		counter++; // so whenever an object is instanstiated then this block of code will run. 
	}
	
	~InstanceCounter()
	{
		std::cout<<"this is the mothefucking class destroyer of object ID: "<< id <<std::endl;
		delete ptr;
		ptr = nullptr;
	}
	
	void staticMethod();
	
	int addition(int& var1, int& var2) // pass by rference usiong reference
	{
		
		int sum = var1 + var2;
		var1 = sum;
		return sum;
	}
	
	
	int substraction(int* var1, int* var2) // pass by rference usiong ptr
	{
		int sub = *(var1) - *(var2);
		*var1 = sub;
		
		return sub;
	}
	
	
};


// static method
	void InstanceCounter::staticMethod()
	{
	std::cout << "internal method called" << std::endl;
	}	


// initialising the magic of static mem variables, they allocate memory independently (even before object initiated)
// and hence they are accessible to all instances.
int InstanceCounter::counter = 0;





int main()
{

	int a = 10;
	int b = 20;
	
	
	// POINTERS
	int* ptr = &a; // this ptr now store the addres of abort
	std::cout << "the original value of a is:  " << a << std::endl;
	
	(*ptr)++; // basically *ptr is the int5 itself. lol dereferemcong ptr leads to value.
	std::cout << "the new value of a is:  " << a << std::endl;
	
	//I can also store the value , which is stored in the ptr, to some other variable by making a copy of it. 
	// NOTE: its a copy process and wont affect the original value of the ptr;
	int valuePtr = *ptr;
	std::cout << "the copied value stored in the  " << ptr << std::endl; 
	std::cout << "the address of a is:  " << ptr << std::endl; // gives its mem address
	int* ptr2 = &b;
	std::cout << "the value stored in mem address of ptr2 is :" << *ptr << std::endl;
	
	// STATIC
	InstanceCounter obj1;
	InstanceCounter obj2;
	InstanceCounter obj3; 
	InstanceCounter* obj4 = new InstanceCounter(); // allocated on heap.
	
	
	// REFERENCES
	int&  ref = b;
	std::cout << "the ref value is:  " << ref << std::endl;
	ref++;
	std::cout << "the new ref value is:  " << ref << std::endl;
	
	//Pass by reference
	std::cout<< "Pass by refernce test : " << obj1.addition(a, b) << std::endl;
	std::cout << "new value of A from 10 to : " << a << std::endl; // void fun(int& var1, int& var2) by reference
	//pass by reference using ptr
	std::cout << "pass by refence using ptr " << obj1.substraction(&a, &b) << std::endl;
	std::cout << "new value of a after subs " << a << std::endl;
	

	// Classes
	obj1.staticMethod();
	obj2.staticMethod();
	obj1.wow = false;
	if (obj1.wow)
	{
		std::cout << "It is true"<< std::endl;
	}
	else
	{
		std::cout << "It is false"<< std::endl;
	}
	std::cout << "TEST PTR : " << *(obj1.ptr) << std::endl;
	std::cout << "TEST PTR but object allocated on heap" << *(obj4->ptr) <<std::endl;
	delete obj4;	
	std::cout << "Total instances/objects of class are: " << InstanceCounter::counter << std::endl;

	
	// OOPs - Encapsulation, Inheritence, Polymorphism
	// Dog dog;
	// Tommy tom;
	
	// if (tom.bark)
	// {
		// std::cout << "the dog barks" << std::endl;
	// }
	// else
	// {
		// std::cout << "the dog doesnt barks" << std::endl;
	// }
	
		// for polymorphism to work, call the base class on heap, as Vtable will resolve to currect function during runtime.
		// if u call them on stack like 
			// Dog dog;
			// Tommy tom; then they will loose the child class features and will only have parent class features.
		
		Dog* dog = new Dog();  
		Dog* tom = new Tommy(); // Base ptr to the child class. 
		
		dog->foo();
		tom->foo();
		delete tom;
		delete dog;
		
		
	// OOPs: Abstraction
	Shape* square = new Square(); // base class pointer to the child class
	square->draw(); // draws a square.
	
	std::cin.get();
}
