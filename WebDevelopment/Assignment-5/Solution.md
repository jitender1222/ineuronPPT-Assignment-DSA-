Q.1 What’s the difference between Synchronous and Asynchronous?

Synchronous operations in JavaScript are executed one at a time, in a sequential manner. Each operation must complete before the next one starts. It blocks the execution of the program until the operation finishes.

Asynchronous operations, on the other hand, allow the program to continue executing while waiting for an operation to complete. The program doesn't wait for the operation to finish and can move on to execute other tasks. Once the asynchronous operation is completed, a callback function or a promise is used to handle the result.

Q.2 Explain Web APIs.

Web APIs (Application Programming Interfaces) provide functionality and capabilities to interact with various web technologies, such as the Document Object Model (DOM), AJAX, Fetch API, Geolocation, Web Storage, and more. Web APIs enable developers to access and manipulate web browser features and services through JavaScript code.

Web APIs are typically provided by web browsers, and they allow developers to perform tasks like manipulating HTML elements, making HTTP requests, storing data locally, accessing device features (e.g., camera, microphone), and much more. These APIs provide a way for JavaScript code to interact with the browser environment and extend the capabilities of web applications.

Q.3 Explain setTimeout and setInterval.

setTimeout is a function in JavaScript that executes a specified function or a piece of code once after a specified delay (in milliseconds). It schedules the execution of the code and returns a unique identifier (timeout ID) that can be used to cancel the execution before it occurs.

```
setTimeout(() => {
  console.log('This code will run after 2 seconds.');
}, 2000);

```

setInterval is a function in JavaScript that executes a specified function or a piece of code repeatedly at a specified interval (in milliseconds). It repeatedly schedules the execution of the code until it is cancelled or the window is closed.

```
let counter = 0;
const intervalId = setInterval(() => {
  console.log(`Counter: ${counter}`);
  counter++;
}, 1000);

// To stop the interval after a certain number of iterations
if (counter === 5) {
  clearInterval(intervalId);
}

```

Q.4 What are the ways we have to handle Async Code in JavaScript?

JavaScript provides several ways to handle asynchronous code:

Callbacks: Functions that are passed as arguments to other functions and get called once an asynchronous operation completes.

Promises: Objects that represent the eventual completion or failure of an asynchronous operation. They allow chaining multiple asynchronous operations and handling success or failure using then() and catch() methods.

Async/await: A modern approach that allows writing asynchronous code in a more synchronous-like manner. It uses the async keyword to define asynchronous functions and the await keyword to pause the execution until a promise settles.

Event listeners: Using event-driven programming, where callbacks are triggered by specific events and executed when those events occur.

Q.5 What are Callbacks & Explain Callback Hell?

Callbacks are functions that are passed as arguments to other functions and are executed once a particular task or operation is completed. They are commonly used in asynchronous JavaScript to handle the results of operations that take time, such as AJAX requests or file I/O.

Callback Hell refers to a situation where multiple callbacks are nested within each other, making the code difficult to read and maintain. This occurs when there are multiple asynchronous operations that depend on each other, and each operation requires a callback to handle its result. As more callbacks are added, the code indentation and complexity increase, resulting in a pyramid-like structure.

Example of Callback Hell:

```
asyncOperation1((result1) => {
  asyncOperation2(result1, (result2) => {
    asyncOperation3(result2, (result3) => {
      // More nested callbacks...
    });
  });
});

```

To avoid callback hell, alternative approaches like Promises, async/await, or libraries like Async.js or Bluebird can be used to handle asynchronous operations in a more structured and readable manner.

Q.6 What are Promises & Explain Three Methods of Promise?

Promises are objects in JavaScript that represent the eventual completion or failure of an asynchronous operation. They provide a cleaner and more structured way to handle asynchronous code compared to callbacks.

Three important methods of Promise are:

then(): The then() method is used to handle the successful completion of a promise. It takes one or two callback functions as arguments. The first callback is executed when the promise is fulfilled, and it receives the resolved value. The second callback (optional) is executed when the promise is rejected.

catch(): The catch() method is used to handle the rejection of a promise. It is called when the promise is rejected, and it receives the reason for rejection as an argument. It is commonly used to handle errors in promises.

finally(): The finally() method is used to specify a callback that is executed regardless of whether the promise is fulfilled or rejected. It is useful for performing cleanup operations or executing code that should be run regardless of the promise's outcome.

Q.7 What's the async and await keyword in JavaScript?

The async keyword is used to define an asynchronous function in JavaScript. It allows the function to use the await keyword within its body. An asynchronous function always returns a promise, and the value it resolves to is the value returned by the function or the value that the function awaits.

The await keyword is used inside an asynchronous function to pause the execution of the function until a promise settles (fulfilled or rejected) and returns the resolved value. It can only be used inside an async function.

Q.8 Explain the purpose of the try and catch block.

The try and catch blocks are used in JavaScript for error handling within synchronous or asynchronous code. The purpose of the try block is to enclose a section of code where an error might occur. If an error occurs within the try block, it is thrown, and the execution is immediately transferred to the catch block.

The catch block is used to handle the thrown error. It receives the error object as a parameter, which can be used to extract information about the error, such as the error message or stack trace. The catch block allows you to gracefully handle the error by providing fallback logic, displaying error messages, or taking any other appropriate action.

The try-catch block ensures that if an error occurs, it is caught and does not crash the entire program. It provides a way to handle errors and maintain control over the execution flow.

Q.9 What is fetch in JavaScript?

fetch is a built-in function in modern JavaScript that allows making HTTP requests to fetch resources from a network. It provides a simpler and more powerful alternative to traditional methods like XMLHttpRequest. fetch returns a Promise that resolves to the Response object representing the response to the request.

Q.10 How do you define an asynchronous function in JavaScript using async/await?

To define an asynchronous function using async/await, you use the async keyword before the function declaration. This indicates that the function will contain asynchronous operations and can use the await keyword to pause the execution until promises settle.

Here's an example of defining an asynchronous function using async/await:

```
async function getData() {
  try {
    const response = await fetch('https://api.example.com/data');
    const data = await response.json();
    return data;
  } catch (error) {
    throw new Error('Failed to fetch data');
  }
}

```

In the example, the getData function is declared as an asynchronous function using the async keyword. Within the function, the await keyword is used to pause the execution until the fetch request is resolved, and the response is received. The response is then parsed as JSON using response.json(). If any error occurs during the execution, it is caught in the catch block and handled appropriately.

To call this asynchronous function, you can use await or chain it with .then() and .catch() methods:

```

(async () => {
  try {
    const data = await getData();
    console.log(data);
  } catch (error) {
    console.error(error);
  }
})();

```

In this example, an immediately-invoked async function expression (IIFE) is used to call the getData function. The result is then logged to the console or any error is caught and logged.
