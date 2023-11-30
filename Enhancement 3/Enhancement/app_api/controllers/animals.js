/*
 * Author: Ryne Williams
 * Date: 11/26/2023
 * File: animals.js
 * Version: 1.0
 * Description: This file is intended to set up the GET methods for finding all animals in the collection or finding an animal by code in the collection.
 */

const mongoose = require('mongoose'); //.set('debug', true);
const model = mongoose.model('animals');

// GET: /animals - lists all animals
const animalsList = async (req, res) => {
    model
        .find({}) // empty filter for all
        .exec((err, animals) => { // executes animalList
            if (!animals) { // if no animals found
                return res // return response
                    .status(404) // 404: not found
                    .json({ "message": "animals not found"});
            }
            else if (err) { // if error occures
                return res // return response
                    .status(404) // 404: not found
                    .json(err);
            }
            else {
                return res // return response
                    .status(200) // 200: success
                    .json(animals);
            }
        });
};

// GET: /animals/:animalCode - returns a single animal
const animalsFindCode = async (req, res) => {
    model
        .find({ 'code': req.params.animalcode }) // find specific animal by code
        .exec((err, animal) => { // executes animalsFindCode
            if (!animal) { // if no animals found
                return res // return response
                    .status(404) // 404: not found
                    .json({ "message": 'animal not found' });
            }
            else if (err) { // if error occurs
                return res // return response
                    .status(404) // 404: not found
                    .json(err);
            }
            else {
                return res // return response
                    .status(200) // 200: success
                    .json(animal);
            }
        });
};

module.exports = { // exports animalsList and animalsFindCode
    animalsList,
    animalsFindCode
}