Q.1 What are hooks in react? how to identify hooks?

Hooks are functions that help you use state and other React features without writing a class. They are a relatively new addition to React, but they have quickly become popular because they make code more concise and easier to understand.

To identify hooks, you can look for the use keyword at the beginning of the function. For example, the useState hook is used to manage state in a component.

Q.2 Explain useState Hook & what can you achieve with it?

The useState hook is used to manage state in a React component. It takes two arguments: the initial state value and a function that is called whenever the state needs to be updated.

The useState hook can be used to achieve a variety of things, such as:

Storing the current value of a form input
Keeping track of the number of items in a list
Managing the state of a game
Q.3 How to pass data from one component to another component

There are a few ways to pass data from one component to another component in React. One way is to use props. Props are passed down from parent components to child components, and they can be used to share data between components.

Another way to pass data from one component to another component is to use context. Context is a way to share data between components that are not directly related to each other.

Q.4 What is the significance of the "key" prop in React lists, and why is it important to use it correctly?

The key prop in React lists is used to identify the individual elements in the list. It is important to use the key prop correctly because it helps React to efficiently update the list when the data changes.

If you do not use the key prop, React will have to re-render the entire list every time the data changes. This can be inefficient, especially if the list is large.

Q.5 What is the significance of using "setState" instead of modifying state directly in React?

The setState function is used to update the state of a React component. It is important to use the setState function instead of modifying state directly because it helps React to track the changes to the state.

If you modify state directly, React will not be able to track the changes, and this can lead to unexpected behavior.

Q.6 Explain the concept of React fragments and when you should use them.

React fragments are a way to group multiple elements together without creating a new component. They are useful when you want to group elements together that do not need to be treated as a separate component.

For example, you could use a react fragment to group together a list of buttons. The buttons would still be separate elements, but they would be grouped together so that they could be styled as a single unit.

Q.7 How do you handle conditional rendering in React?

Conditional rendering is a way to show or hide elements based on the value of a condition. It is used to improve the performance of React applications by only rendering the elements that are visible.

There are a few different ways to handle conditional rendering in React. One way is to use the if statement. Another way is to use the ternary operator.
