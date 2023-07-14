import React, { useState } from "react";
import "./App.css";

function GithubUserFinder() {
  const [username, setUsername] = useState("");
  const [userData, setUserData] = useState(null);
  const [error, setError] = useState(null);

  const handleSearch = async () => {
    try {
      const response = await fetch(`https://api.github.com/users/${username}`);
      if (response.ok) {
        const data = await response.json();
        setUserData(data);
        setError(null);
      } else {
        setUserData(null);
        setError("User not found");
      }
    } catch (error) {
      console.error(error);
      setUserData(null);
      setError("Error occurred while fetching user data");
    }
  };

  return (
    <div className="container">
      <h1 className="title">GitHub User Finder</h1>
      <div className="search-container">
        <input
          type="text"
          value={username}
          onChange={(e) => setUsername(e.target.value)}
          placeholder="Enter a GitHub username"
          className="search-input"
        />
        <button onClick={handleSearch} className="search-button">
          Search
        </button>
      </div>
      {error && <p className="error">{error}</p>}
      {userData && (
        <div className="user-container">
          <img className="avatar" src={userData.avatar_url} alt="User Avatar" />
          <div className="user-info">
            <h2 className="username">{userData.name}</h2>
            <p className="location">{userData.location}</p>
            <p className="bio">{userData.bio}</p>
            <div className="stats">
              <p>
                Followers: <span className="stat">{userData.followers}</span>
              </p>
              <p>
                Public Repositories:{" "}
                <span className="stat">{userData.public_repos}</span>
              </p>
            </div>
          </div>
        </div>
      )}
    </div>
  );
}

export default GithubUserFinder;
