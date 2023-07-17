const express = require("express");
const app = express();

// Dummy database of todos
let todos = [];

// Middleware to validate the task input
const validateTask = (req, res, next) => {
  const { task } = req.body;
  if (!task) {
    res.status(400).json({ msg: "Validation failed. Task is required." });
  } else {
    next();
  }
};

// Middleware to log requests
const logRequests = (req, res, next) => {
  console.log(`Received ${req.method} request for ${req.url}`);
  next();
};

app.use(express.json()); // Middleware to parse JSON bodies
app.use(logRequests);

app.get("/", (req, res) => {
  res.json(todos);
});

app.post("/add", validateTask, (req, res) => {
  const { task } = req.body;
  const newTodo = {
    id: Date.now(),
    task,
  };
  todos.push(newTodo);
  res.json({ msg: "Todo created successfully", data: todos });
});

app.put("/update/:id", validateTask, (req, res) => {
  const { id } = req.params;
  const { task } = req.body;
  const todoIndex = todos.findIndex((todo) => todo.id === parseInt(id));
  if (todoIndex === -1) {
    res.status(404).json({ msg: "Todo not found" });
  } else {
    todos[todoIndex].task = task;
    res.json({ msg: "Todo updated successfully", data: todos });
  }
});

app.delete("/delete/:id", (req, res) => {
  const { id } = req.params;
  const todoIndex = todos.findIndex((todo) => todo.id === parseInt(id));
  if (todoIndex === -1) {
    res.status(404).json({ msg: "Todo not found" });
  } else {
    todos.splice(todoIndex, 1);
    res.json({ msg: "Todo deleted", data: todos });
  }
});

app.listen(3000, () => {
  console.log("Server is running on port 3000");
});
