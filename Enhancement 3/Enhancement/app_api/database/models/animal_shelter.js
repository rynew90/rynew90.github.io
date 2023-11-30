/*
 * Author: Ryne Williams
 * Date: 11/26/2023
 * File: animal_shelter.js
 * Version: 1.0
 * Description: This file contains the database schema for the data being held in the database.
 */

const mongoose = require('mongoose');

// Define the animal schema
const animalSchema = new mongoose.Schema({
    rec_num: { // record number
        type: Number,
        required: true,
        index: true
    },
    code: { //animal ID
        type: String,
        required: true,
        index: true
    },
    name: { // animal's name
        type: String,
        required: true,
        index: true
    },
    sex_upon_outcome: { // gender of animal
        type: String,
        required: true,
    },
    animal_type: { // cat or dog
        type: String,
        required: true,
    },
    breed: { // breed of animal
        type: String,
        required: true,
    },
    age_upon_outcome: { // age when animal is ready for service
        type: String,
        required: true,
    },
    color: { // color of animal fur
        type: String,
        required: true,
    },
    outcome_type: { // any ailments or issues the animal may have developed
        type: String,
        required: true,
    },
    rescue_type: { // Water, Mountain/Wilderness, Disaster, or none
        type: String,
        required: true,
        index: true
    }
});

//mongoose.model('animals', animalSchema);
module.exports = mongoose.model('animals', animalSchema); // exports model to be used in other application files