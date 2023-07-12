Q.1 What’s Constructor And Its Purpose?

A constructor is a special type of function that is used to create new objects. It is called when an object is created, and it is responsible for initializing the object's properties and methods.

The purpose of a constructor is to ensure that all objects of a particular class are created with the same initial state. This can help to improve the readability and maintainability of your code.

Q.2 Explain This Keyword and Its Purpose?

The this keyword refers to the current object in JavaScript. It can be used to access the object's properties and methods.

The purpose of the this keyword is to make it easier to write code that interacts with objects. For example, the following code uses the this keyword to access the object's name property:

```
const person = {
  name: "John Doe",
  sayName() {
    // `this` refers to the `person` object
    console.log(this.name);
  }
};

person.sayName(); // "John Doe"

```

Q.3 What’s Call Apply Bind Method & Difference Between them

The call(), apply(), and bind() methods are all used to invoke a function with a different set of arguments.

The call() method takes the function to be invoked as its first argument, followed by the arguments to be passed to the function.

The apply() method takes the function to be invoked as its first argument, followed by an array of arguments to be passed to the function.

The bind() method takes the function to be invoked as its first argument, followed by the values to be bound to the this keyword.

The difference between the three methods is that the call() method takes the arguments as individual arguments, while the apply() method takes the arguments as an array. The bind() method takes the values to be bound to the this keyword as its second argument, followed by the arguments to be passed to the function.

For example, the following code uses the call() method to invoke the sayName() method with the "John Doe" argument:

```
const person = {
  name: "John Doe",
  sayName(name) {
    console.log(name);
  }
};

person.sayName.call(person, "John Doe"); // "John Doe"

```

The following code uses the apply() method to invoke the sayName() method with the "John Doe" argument:

```
const person = {
  name: "John Doe",
  sayName(name) {
    console.log(name);
  }
};

person.sayName.apply(person, ["John Doe"]); // "John Doe"

```

The following code uses the bind() method to invoke the sayName() method with the "John Doe" argument:

```
const person = {
  name: "John Doe",
  sayName(name) {
    console.log(name);
  }
};

const boundSayName = person.sayName.bind(person, "John Doe");
boundSayName(); // "John Doe"

```

Q.4 Explain OOPS ?

Object-Oriented Programming (OOP) is a programming paradigm that organizes code around the concept of objects, which are instances of classes. It provides a way to structure and design code by modeling real-world entities and their relationships.

Q.5 Whats Abstraction and Its Purpose?

Abstraction is a fundamental concept in object-oriented programming that allows us to model complex systems by focusing on the essential features while hiding unnecessary details. It involves creating abstract classes or interfaces that define a set of methods and properties without specifying their implementation.

The purpose of abstraction is:

Simplification: Abstraction simplifies the complexity of a system by breaking it down into smaller, more manageable components. It allows us to deal with high-level concepts rather than low-level details.

Encapsulation: Abstraction is closely related to encapsulation. By hiding the internal details of how a particular functionality is implemented, abstraction provides a clean interface for interacting with objects. It protects the internal state and implementation from external interference.

Modularity: Abstraction promotes modular design by separating the interface from the implementation. This separation allows different parts of a system to be developed independently, making the code more maintainable and easier to understand.

Flexibility: Abstraction provides flexibility in design and allows for changes to the internal implementation without affecting the external code that depends on it. It enables developers to modify or extend the system without impacting the overall functionality.

Q.6 Whats Polymorphism and Purpose of it?

Polymorphism is a concept in object-oriented programming that allows objects of different classes to be treated as objects of a common superclass. It enables a single interface to be used to represent different types of objects, providing flexibility and extensibility in code.

The purpose of polymorphism is:

Code Reusability: Polymorphism allows the reuse of code by defining common interfaces that can be implemented by multiple classes. By treating objects of different classes as instances of a common superclass, the same code can be used to work with different types of objects.

Flexibility and Extensibility: Polymorphism allows for easy extension and modification of code. New classes can be added that implement the same interface, providing additional functionality without impacting the existing code that depends on the interface.

Q.7 Whats Inheritance and Purpose of it?

Inheritance is a fundamental concept in object-oriented programming that allows classes to inherit properties and behaviors from other classes. It enables the creation of a hierarchical relationship between classes, where a subclass inherits the characteristics of a superclass.

The purpose of inheritance is:

Code Reusability: Inheritance promotes code reuse by allowing subclasses to inherit attributes and methods from their superclasses. This eliminates the need to duplicate code and reduces development time.

Hierarchy and Organization: Inheritance provides a way to organize classes into a hierarchical structure. It allows for the classification and categorization of objects based on their common characteristics, making the code more organized and easier to understand.

Method Overriding: Inheritance allows subclasses to override methods defined in their superclasses. This enables subclasses to provide their own implementation of a method while still inheriting the rest of the superclass's behavior. Method overriding is a key feature that enables polymorphism.

Q.8 Whats Encapsulation and Purpose of it ?

Encapsulation is a fundamental concept in object-oriented programming that involves bundling data (attributes) and methods (behaviors) together within a class and controlling their access through visibility modifiers. It allows for the protection of internal data and implementation details, providing a clean interface for interacting with objects.

The purpose of encapsulation is:

Data Protection: Encapsulation ensures that the internal data of an object is not directly accessible from outside the class. Data members can be made private or protected, preventing unauthorized access and manipulation. This helps maintain data integrity and ensures the object's internal state is consistent.

Information Hiding: Encapsulation hides the internal implementation details of an object and exposes only the necessary interface to interact with it. By concealing the complexity, it simplifies the usage of objects and protects them from external interference.

Modularity: Encapsulation promotes modular design by separating the implementation details from the external code that uses the object. This separation allows changes to be made to the internal implementation without affecting the external code, as long as the interface remains consistent.

Code Maintainability: Encapsulation makes code more maintainable by encapsulating related data and behaviors into a single unit. This reduces code complexity, improves code readability, and makes it easier to identify and fix issues.

Q.9 Explain Class in JavaScript?

In JavaScript, a class is a template or blueprint for creating objects. It defines the properties and methods that an object should have. The class serves as a blueprint, and objects created from the class are referred to as instances.

Q.10 What’s Super Keyword & What it does?

In JavaScript, the super keyword is used to call methods and access properties of a parent class within a subclass. It is primarily used in the context of inheritance, where a subclass extends the functionality of a superclass.

When a subclass defines its own constructor, it must call the super keyword inside its constructor before accessing this. This ensures that the superclass's constructor is executed, and the subclass inherits the properties and methods defined in the superclass. The super keyword can also be used to call specific methods from the superclass.
