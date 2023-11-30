/*
 * Author: Ryne Williams
 * Date: 11/26/2023
 * File: index.js
 * Version: 1.0
 * Description: This file sets up the routes for the web application handling the animal data.
 */

const express = require('express');
const router = express.Router();

const animalsController = require('../controllers/animals');

// Route for listing all animals
router.route('/animals').get(animalsController.animalsList);

// Route for listing a specific animal by code
router.route('/animals/:animalCode').get(animalsController.animalsFindCode);

module.exports = router;