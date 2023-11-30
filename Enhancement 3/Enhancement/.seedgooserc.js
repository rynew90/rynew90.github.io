/*
 * Author: Ryne Williams
 * Date: 11/26/2023
 * File: .seedgooserc.js
 * Version: 1.0
 * Description: This file is used to seed data to the MongoDB database.
 */

module.exports = {
  modelBaseDirectory: "app_api/database/models", // path for model directory
  models: ["*.js", "!db.js"], // use .js files except for db.js
  data: "data",
  db: "mongodb://127.0.0.1:27017/animal_shelter" // database link path
};
