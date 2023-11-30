/*
 * Author: Ryne Williams
 * Date: 11/26/2023
 * File: animal.js
 * Version: 1.0
 * Description: This file is intended to handle  requests to the home page by calling the 'animalList' function.
 */

const express = require('express');
const router = express.Router();
const controller = require('../controllers/animal');

/* GET home page */
router.get('/', controller.animalList);

module.exports = router;
