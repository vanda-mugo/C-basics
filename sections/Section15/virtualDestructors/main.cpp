class Base {
public:
 Base();
 ~Base();
};

class Derived : public Base {
private:
  double val;
public:
 Derived(const double& _val);
 ~Derived();
}

void do_something() {
 Base* p = new Derived;
 // Derived destructor not called!!
 delete p;  
}

/*
The destructors are NOT set to virtual. In our do_something() function, a pointer p to a Base class is created and a reference to a new Derived class is assigned to it. 
This is legal as Derived is a Base.however when p is deleted the compiler only knows how to call the base destructor as the pointer is pointing to base class . the destructor 
 associated to the derived class is not deallocated and hence in this case the attribute val is not deallocated which leads to a memory leak 
 */
 
 