/*
 * Author: Ryne Williams
 * Date: 11/26/2023
 * File: animal.js
 * Version: 1.0
 * Description: This file is intended to define the controller for handling animal data from the database.
 */

const request = require('request');
const apiOptions = {
    server: 'http://localhost:3000'
}

/* render animal list view */
const renderAnimalList = (req, res, responseBody) => {
    let message = null;
    let pageTitle = process.env.npm_package_description + ' - Animal';

    if (!(responseBody instanceof Array)) { // if response body is not an instance of Arrays
        message = 'API lookup error'; // error message
        responseBody = []; // empty response body
    }
    else {
        if (!responseBody.length) { // if response body has no length
            message = 'No animals exist in database!'; // error message
        }
    }

    res.render('animal', { // render animal with title, response body, and message
        title: pageTitle,
        animals: responseBody,
        message
    });
};

/* GET animal view */
const animalList = (req, res) => {
    const path = '/api/animals';
    const requestOptions = {
        url: `${apiOptions.server}${path}`,
        method: 'GET',
        json: {}
    };

    console.info('>> animalController.animalList calling ' + requestOptions.url); // prints to console when retrieving data from the database

    request(
        requestOptions,
        (err, { statusCode }, body) => {
            if (err) {
                console.error(err);
            }
            renderAnimalList(req, res, body);
        }
    )
};

module.exports = {
    animalList
};