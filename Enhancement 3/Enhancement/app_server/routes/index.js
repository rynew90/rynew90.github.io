/*
 * Author: Ryne Williams
 * Date: 11/26/2023
 * File: index.js
 * Version: 1.0
 * Description: This file uses a router to handle requests to home page from the main controller.
 */

const express = require('express');
const router = express.Router();
const ctrlMain = require('../controllers/main');

/* GET home page. */
router.get('/', ctrlMain.index);

module.exports = router;
