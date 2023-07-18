function addTask() {
  var input = document.getElementById("taskInput");
  var task = input.value;

  if (task !== "") {
    var taskList = document.getElementById("taskList");
    var newTask = document.createElement("li");
    newTask.appendChild(document.createTextNode(task));
    taskList.appendChild(newTask);
    input.value = "";
  }
}
