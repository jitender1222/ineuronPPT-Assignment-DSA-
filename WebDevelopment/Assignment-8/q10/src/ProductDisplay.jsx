import React, { useState, useEffect } from "react";
import "./App.css";

function ProductDisplay() {
  const [products, setProducts] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);

  useEffect(() => {
    const fetchProducts = async () => {
      try {
        const response = await fetch("https://fakestoreapi.com/products");
        if (response.ok) {
          const data = await response.json();
          setProducts(data);
          setLoading(false);
          setError(null);
        } else {
          setLoading(false);
          setError("Failed to fetch products");
        }
      } catch (error) {
        console.error(error);
        setLoading(false);
        setError("Error occurred while fetching products");
      }
    };

    fetchProducts();
  }, []);

  if (loading) {
    return <p>Loading...</p>;
  }

  if (error) {
    return <p className="error">{error}</p>;
  }

  return (
    <div className="container">
      <h1 className="title">Product Display</h1>
      <div className="product-list">
        {products.map((product) => (
          <div key={product.id} className="product-card">
            <img
              className="product-image"
              src={product.image}
              alt={product.title}
            />
            <div className="product-details">
              <h2 className="product-title">{product.title}</h2>
              <p className="product-price">${product.price}</p>
              <p className="product-category">{product.category}</p>
            </div>
          </div>
        ))}
      </div>
    </div>
  );
}

export default ProductDisplay;
