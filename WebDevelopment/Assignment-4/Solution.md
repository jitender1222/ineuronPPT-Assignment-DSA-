💡 Q.1 Explain Hoisting in JavaScript.

Hoisting is a behavior in JavaScript where variable and function declarations are moved to the top of their containing scope during the compilation phase, before the code is executed. This means that you can use variables and functions before they are declared in the code.

However, it's important to note that only the declarations are hoisted, not the initializations or assignments. If you try to access a variable before it is declared and assigned a value, it will have the value undefined.

```
console.log(myVariable); // undefined
var myVariable = 10;

```

In the example, the variable myVariable is hoisted to the top, but its initialization (10) is not hoisted. Therefore, when you try to access myVariable before its declaration, it prints undefined.

Hoisting also applies to function declarations. Function declarations are completely hoisted, meaning you can call the function before it is declared in the code.

```

myFunction(); // "Hello, world!"
function myFunction() {
  console.log("Hello, world!");
}

```

Q.2 Explain Temporal Dead Zone.

The Temporal Dead Zone (TDZ) is a behavior in JavaScript that occurs when using variables declared with let and const before they are initialized. The TDZ is the period between the start of the block where the variable is declared and the point where it is initialized.

During the TDZ, accessing the variable will result in a ReferenceError. This behavior exists to catch and prevent accessing variables before they are ready to be used.

```
console.log(myVariable); // ReferenceError: Cannot access 'myVariable' before initialization
let myVariable = 10;

```

In the example, trying to access myVariable before its initialization within the same block leads to a ReferenceError due to the TDZ. The variable exists within the block but is not yet initialized.
Q.3 Difference between var and let.

The main differences between var and let in JavaScript are as follows:

Scope: Variables declared with var are function-scoped, meaning they are accessible within the entire function in which they are declared. On the other hand, variables declared with let are block-scoped, meaning they are accessible only within the block ({}) in which they are declared.

Hoisting: Variables declared with var are hoisted to the top of their containing scope during the compilation phase, which allows you to access them before they are declared. Variables declared with let are also hoisted, but they remain in the Temporal Dead Zone (TDZ) until they are declared, so accessing them before their declaration will result in a ReferenceError.

Re-Declaration: Variables declared with var can be re-declared within the same scope without causing an error. In contrast, variables declared with let cannot be re-declared within the same scope.

Block Scope: Variables declared with let have block scope, which means they are confined to the block ({}) in which they are declared. This allows for better control and avoids unintended variable access or modifications outside the intended block.

Q.4 What are the major features introduced in ECMAScript 6?

ECMAScript 6, also known as ES6 or ECMAScript 2015, introduced several major features and enhancements to JavaScript. Some of the key features include:

let and const declarations: The introduction of block-scoped variables using let and constants using const.

Arrow functions: A more concise syntax for defining anonymous functions using the arrow (=>) notation.

Template literals: Enhanced string literals that support multi-line strings and string interpolation using backticks ( ).

Destructuring assignment: A convenient way to extract values from arrays or objects into individual variables.

Default parameters: The ability to define default values for function parameters.

Rest and spread operators: The rest (...) operator allows capturing multiple function arguments as an array, while the spread (...) operator expands an array into individual elements.

Classes: A syntax for defining classes, constructors, and inheritance in a more object-oriented manner.

Modules: Built-in support for creating and using modules to organize and share code.

Promises: A standardized way to handle asynchronous operations, simplifying callback-based code.

Iterators and generators: The introduction of iterator objects and generator functions, providing a simpler way to iterate over collections.

Enhanced object literals: Additional syntax and features for defining objects, including shorthand property and method definitions.

Q.5 What is the difference between let and const in ES6?

The main difference between let and const in ES6 (ECMAScript 2015) lies in their reassignability:

let: Variables declared with let can be reassigned new values. Their values can be changed during the program execution.

```
let x = 10;
x = 20; // Reassigning 'x' to a new value
console.log(x); // Output: 20

```

const: Constants declared with const cannot be reassigned new values. They are read-only and their values remain constant throughout the program execution.

```
const y = 10;
y = 20; // Error: Assignment to constant variable
console.log(y);

```

In the example, attempting to reassign a new value to a constant y will result in an error.

It's important to note that while the value of a constant cannot be reassigned, it doesn't mean the value itself is immutable. For example, if a constant holds an object or an array, the properties or elements of that object or array can still be modified.

Another difference between let and const is that variables declared with let have block scope, meaning they are accessible only within the block in which they are defined. On the other hand, const variables also have block scope but are additionally subject to the rules of immutability.

Q.6 What are template literals in ES6, and how do you use them?

Template literals, introduced in ES6 (ECMAScript 2015), provide an improved syntax for creating strings in JavaScript. They are enclosed by backticks (`) instead of single or double quotes.

Template literals offer the following features:

String interpolation: Template literals allow you to embed expressions inside the string using ${expression} syntax. The expression is evaluated and its value is inserted into the string.

```
const name = "Alice";
console.log(`Hello, ${name}!`); // Output: Hello, Alice!

```

Multi-line strings: Template literals can span multiple lines without the need for escape characters or concatenation.

```
const message = `
  This is a multi-line string.
  It can contain line breaks and preserve indentation.
`;
console.log(message);

```

Embedded expressions: You can include any valid JavaScript expression inside ${} within a template literal.
Example:

```
const a = 5;
const b = 10;
console.log(`The sum of ${a} and ${b} is ${a + b}.`); // Output: The sum of 5 and 10 is 15.
```

Template literals provide a more concise and readable way to create dynamic strings in JavaScript, especially when dealing with variable interpolation and multiline content.

Q.7 What's the difference between map and forEach?

Both map and forEach are array methods in JavaScript used to iterate over arrays and perform operations on their elements. However, there are some differences between them:

Return value: map returns a new array with the results of applying a provided function to each element of the original array. It creates a new array, leaving the original array unchanged. On the other hand, forEach does not return anything. It simply iterates over the array and executes a provided function for each element.

```
const numbers = [1, 2, 3, 4, 5];
const doubledNumbers = numbers.map((num) => num * 2);
console.log(doubledNumbers); // Output: [2, 4, 6, 8, 10]

```

```
const numbers = [1, 2, 3, 4, 5];
numbers.forEach((num) => {
  console.log(num * 2);
});
// Output:
// 2
// 4
// 6
// 8
// 10

```

Q.8 How can you destructure objects and arrays in ES6?

Destructuring is a feature introduced in ES6 (ECMAScript 2015) that allows you to extract values from arrays or properties from objects into distinct variables. It provides a concise and convenient way to assign values.

Here are examples of destructuring objects and arrays:

```
const person = {
  name: "Alice",
  age: 25,
  country: "USA",
};

const { name, age } = person;
console.log(name); // Output: "Alice"
console.log(age); // Output: 25

```

In this example, the values of name and age are extracted from the person object using object destructuring.

Destructuring Arrays:

```
const numbers = [1, 2, 3, 4, 5];

const [first, second, ...rest] = numbers;
console.log(first); // Output: 1
console.log(second); // Output: 2
console.log(rest); // Output: [3, 4, 5]

```

Here, the values of the first two elements (first and second) are extracted from the numbers array using array destructuring. The rest of the elements are assigned to the rest variable using the rest operator (...).

Q.9 How can you define default parameter values in ES6 functions?

In ES6 (ECMAScript 2015) and later versions, we can define default parameter values for function parameters. Default parameter values allow us to specify fallback values that will be used if the arguments are not provided or are undefined.

```
function greet(name = "Anonymous") {
  console.log(`Hello, ${name}!`);
}

greet(); // Output: Hello, Anonymous!
greet("Alice"); // Output: Hello, Alice!

```

Q.10 What is the purpose of the spread operator (...) in ES6?

In ES6 (ECMAScript 2015) and later versions, the spread operator (...) allows for the expansion or spreading of elements from arrays, objects, or iterables into various contexts.

Here are some common use cases of the spread operator:

Expanding elements of an array:

```
const numbers = [1, 2, 3];
const combined = [...numbers, 4, 5, 6];
console.log(combined); // Output: [1, 2, 3, 4, 5, 6]

```

In this example, the spread operator is used to expand the elements of the numbers array within a new array. This allows you to concatenate arrays or create new arrays based on existing ones.

Copying arrays and objects:

```
const originalArray = [1, 2, 3];
const copyArray = [...originalArray];
console.log(copyArray); // Output: [1, 2, 3]

const originalObject = { name: "Alice", age: 25 };
const copyObject = { ...originalObject };
console.log(copyObject); // Output: { name: "Alice", age: 25 }

```
