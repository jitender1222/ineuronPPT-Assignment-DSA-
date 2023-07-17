const http = require("http");

const server = http.createServer((req, res) => {
  if (req.url === "/") {
    res.writeHead(200, { "Content-Type": "text/plain" });
    res.end("Welcome to Men & Women Dummy Data");
  } else if (req.url === "/men") {
    res.writeHead(200, { "Content-Type": "application/json" });
    const menProducts = [
      // Add your men's products data here
    ];
    res.end(JSON.stringify(menProducts));
  } else if (req.url === "/women") {
    res.writeHead(200, { "Content-Type": "application/json" });
    const womenProducts = [
      // Add your women's products data here
    ];
    res.end(JSON.stringify(womenProducts));
  } else {
    res.writeHead(404, { "Content-Type": "text/plain" });
    res.end("Page not found");
  }
});

server.listen(3000, () => {
  console.log("Server is running on port 3000");
});
