import React, { useState } from "react";
import "./App.css";

function TodoApp() {
  const [tasks, setTasks] = useState([]);
  const [inputValue, setInputValue] = useState("");

  const handleInputChange = (event) => {
    setInputValue(event.target.value);
  };

  const handleFormSubmit = (event) => {
    event.preventDefault();
    if (inputValue.trim() !== "") {
      setTasks([...tasks, { text: inputValue, completed: false }]);
      setInputValue("");
    }
  };

  const handleTaskDelete = (index) => {
    const updatedTasks = [...tasks];
    updatedTasks.splice(index, 1);
    setTasks(updatedTasks);
  };

  const handleTaskStatusUpdate = (index) => {
    const updatedTasks = [...tasks];
    updatedTasks[index].completed = !updatedTasks[index].completed;
    setTasks(updatedTasks);
  };

  return (
    <div className="container">
      <h1 className="title">Todo App</h1>
      <form onSubmit={handleFormSubmit} className="form">
        <input
          type="text"
          placeholder="Enter a task"
          value={inputValue}
          onChange={handleInputChange}
          className="input"
        />
        <button type="submit" className="submit-button">
          Add Task
        </button>
      </form>
      <ul className="task-list">
        {tasks.map((task, index) => (
          <li
            key={index}
            className={`task ${task.completed ? "completed" : ""}`}
          >
            <span className="task-text">{task.text}</span>
            <span className="task-status">
              {task.completed ? "Completed" : "Pending"}
            </span>
            <div className="task-actions">
              <button
                onClick={() => handleTaskStatusUpdate(index)}
                className="status-button"
              >
                {task.completed ? "Mark Incomplete" : "Mark Complete"}
              </button>
              <button
                onClick={() => handleTaskDelete(index)}
                className="delete-button"
              >
                Remove Todo
              </button>
            </div>
          </li>
        ))}
      </ul>
    </div>
  );
}

export default TodoApp;
