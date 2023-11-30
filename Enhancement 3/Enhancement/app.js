/*
 * Author: Ryne Williams
 * Date: 11/26/2023
 * File: app.js
 * Version: 1.0
 * Description: This file sets up the file paths, view engine, and app usage for the entire application.
 */

const createError = require('http-errors');
const express = require('express');
const path = require('path');
const cookieParser = require('cookie-parser');
const logger = require('morgan');
const hbs = require('hbs');
require('./app_api/database/db');

const indexRouter = require('./app_server/routes/index'); // requires index.js in the app_server file
const animalRouter = require('./app_server/routes/animal'); // requires animal.js in the app_server file
const apiRouter = require('./app_api/routes/index'); // requires index.js in the app_api file

const app = express(); // variable to use express method

// view engine setup
app.set('views', path.join(__dirname, 'app_server', 'views'));
app.set('view engine', 'hbs');

// register handlebars partials (https://www.npmjs.com/package/hbs)
hbs.registerPartials(path.join(__dirname, 'app_server', 'views/partials'));

// app usage set up
app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

// files to be used directly by the application
app.use('/index', indexRouter);
app.use('/animal', animalRouter);
app.use('/api', apiRouter);

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error');
});

module.exports = app;