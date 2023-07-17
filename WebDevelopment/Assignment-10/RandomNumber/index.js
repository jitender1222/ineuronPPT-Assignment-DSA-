const express = require("express");
const app = express();

app.get("/random", (req, res) => {
  const randomNumber = Math.floor(Math.random() * 100);
  res.json({ random: randomNumber });
});

app.listen(3000, () => {
  console.log("Server is running on port 3000");
});
