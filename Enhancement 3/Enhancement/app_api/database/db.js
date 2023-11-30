/*
 * Author: Ryne Williams
 * Date: 11/26/2023
 * File: db.js
 * Version: 1.0
 * Description: This file holds the code that links the database to the web application
 */

const mongoose = require('mongoose');
const host = process.env.DB_HOST || '127.0.0.1';
const dbURI = `mongodb://${host}/animal_shelter`;
const readLine = require('readline');

// avoid 'current Server Discovery and Monitoring engine is deprecated'
mongoose.set('useUnifiedTopology', true);

const connect = () => { // anonymous function to create a connection to the database
    setTimeout(() => mongoose.connect(dbURI, {
        useNewUrlParser: true,
        useCreateIndex: true
    }), 1000);
}

// checks for successful connection
mongoose.connection.on('connected', () => { 
  console.log(`Mongoose connected to ${dbURI}`);
});

// checks for error in connection
mongoose.connection.on('error', err => { 
  console.log(`Mongoose connection error: ${err}`);
});

// checks for disconnection from the database
mongoose.connection.on('disconnected', () => { 
  console.log('Mongoose disconnected');
});

// allows for safe shutdown of database
const gracefulShutdown = (msg, callback) => {
  mongoose.connection.close( () => {
    console.log(`Mongoose disconnected through ${msg}`);
    callback();
  });
};

// For nodemon restarts
process.once('SIGUSR2', () => {
  gracefulShutdown('nodemon restart', () => {
    process.kill(process.pid, 'SIGUSR2');
  });
});

// For app termination
process.on('SIGINT', () => {
  gracefulShutdown('app termination', () => {
    process.exit(0);
  });
});

// For Heroku app termination
process.on('SIGTERM', () => {
  gracefulShutdown('Heroku app shutdown', () => {
    process.exit(0);
  });
});

connect();

// bring in the Mongoose schema
require('./models/animal_shelter');