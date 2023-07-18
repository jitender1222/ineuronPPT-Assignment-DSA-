var editModal = document.getElementById("editModal");
var editTaskInput = document.getElementById("editTaskInput");
var selectedTask = null;

function addTask() {
  var input = document.getElementById("taskInput");
  var task = input.value;

  if (task !== "") {
    var taskList = document.getElementById("taskList");
    var newTask = document.createElement("li");
    newTask.appendChild(document.createTextNode(task));

    var updateStatusBtn = document.createElement("button");
    updateStatusBtn.appendChild(document.createTextNode("Update Status"));
    updateStatusBtn.onclick = function () {
      updateTaskStatus(newTask);
    };

    var editTodoBtn = document.createElement("button");
    editTodoBtn.appendChild(document.createTextNode("Edit"));
    editTodoBtn.onclick = function () {
      openModal(newTask);
    };

    var deleteTodoBtn = document.createElement("button");
    deleteTodoBtn.appendChild(document.createTextNode("Delete Todo"));
    deleteTodoBtn.onclick = function () {
      deleteTask(newTask);
    };

    newTask.appendChild(updateStatusBtn);
    newTask.appendChild(editTodoBtn);
    newTask.appendChild(deleteTodoBtn);
    taskList.appendChild(newTask);

    input.value = "";
  }
}

function updateTaskStatus(task) {
  task.classList.toggle("completed");
}

function deleteTask(task) {
  task.classList.add("deleted");
}

function openModal(task) {
  selectedTask = task;
  editTaskInput.value = task.firstChild.textContent;
  editModal.style.display = "block";
}

function closeModal() {
  editModal.style.display = "none";
}

function updateTask() {
  if (selectedTask) {
    var updatedTask = editTaskInput.value;

    if (updatedTask !== "") {
      selectedTask.firstChild.textContent = updatedTask;
      closeModal();
    }
  }
}
