/*
 * Author: Ryne Williams
 * Date: 11/26/2023
 * File: main.js
 * Version: 1.0
 * Description: This file is intended to handle requests to view the home page for the web application.
 */

/* GET homepage */
const index = (req, res) => {
    res.render('index', { title: 'Grazioso Salvare' });
};

module.exports = {
    index
};