import React, { useState } from "react";
import "./App.css";

function Calculator() {
  const [display, setDisplay] = useState("");

  const handleNumberClick = (number) => {
    setDisplay(display + number);
  };

  const handleOperatorClick = (operator) => {
    if (display !== "") {
      setDisplay(display + operator);
    }
  };

  const handleEqualsClick = () => {
    if (display !== "") {
      try {
        const result = eval(display);
        setDisplay(result.toString());
      } catch (error) {
        setDisplay("Error");
      }
    }
  };

  const handleClearClick = () => {
    setDisplay("");
  };

  return (
    <div className="calculator">
      <div className="display">{display}</div>
      <div className="row">
        <button className="number" onClick={() => handleNumberClick("7")}>
          7
        </button>
        <button className="number" onClick={() => handleNumberClick("8")}>
          8
        </button>
        <button className="number" onClick={() => handleNumberClick("9")}>
          9
        </button>
        <button className="operator" onClick={() => handleOperatorClick("+")}>
          +
        </button>
      </div>
      <div className="row">
        <button className="number" onClick={() => handleNumberClick("4")}>
          4
        </button>
        <button className="number" onClick={() => handleNumberClick("5")}>
          5
        </button>
        <button className="number" onClick={() => handleNumberClick("6")}>
          6
        </button>
        <button className="operator" onClick={() => handleOperatorClick("-")}>
          -
        </button>
      </div>
      <div className="row">
        <button className="number" onClick={() => handleNumberClick("1")}>
          1
        </button>
        <button className="number" onClick={() => handleNumberClick("2")}>
          2
        </button>
        <button className="number" onClick={() => handleNumberClick("3")}>
          3
        </button>
        <button className="operator" onClick={() => handleOperatorClick("*")}>
          *
        </button>
      </div>
      <div className="row">
        <button className="number" onClick={() => handleNumberClick("0")}>
          0
        </button>
        <button className="number" onClick={() => handleNumberClick(".")}>
          .
        </button>
        <button className="equals" onClick={handleEqualsClick}>
          =
        </button>
        <button className="operator" onClick={() => handleOperatorClick("/")}>
          /
        </button>
      </div>
      <div className="row">
        <button className="clear" onClick={handleClearClick}>
          Clear
        </button>
      </div>
    </div>
  );
}

export default Calculator;
