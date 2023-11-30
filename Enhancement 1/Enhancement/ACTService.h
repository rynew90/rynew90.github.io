/*
 * Author: Ryne Williams
 * Date: 11/11/2023
 * File: ACTService.h
 * Version: 1.0
 * Description: This file declares the classes for the ACTService.cpp file.
 */

#pragma once

#include <vector>
#include <string>
#include "ACT.cpp"


#ifndef APPOINTMENTSERVICE_H
#define APPOINTMENTSERVICE_H

class AppointmentService {
public:
    static std::vector<Appointment> appointmentList;

    static void displayAppointment(std::string appointmentId);
    static void addAppointment(std::string appointmentId, std::tm appointmentDate, std::string appointmentDesc);
    static void deleteAppointment(std::string appointmentId);
};

#endif // APPOINTMENTSERVICE_H

#ifndef CONTACTSERVICE_H
#define CONTACTSERVICE_H

class ContactService {
public:
    static std::vector<Contact> contactList;

    static void displayContact(std::string contactId);
    static void addContact(std::string contactId, std::string firstName, std::string lastName, std::string phoneNum, std::string address);
    static void deleteContact(std::string contactId);
    static void modifyContact(std::string item, std::string input);
};

#endif // CONTACTSERVICE_H

#ifndef TASKSERVICE_H
#define TASKSERVICE_H

class TaskService {
public:
    static std::vector<Task> taskList;

    static void displayTask(std::string taskId);
    static void addTask(std::string taskId, std::string taskName, std::string taskDesc);
    static void deleteTask(std::string taskId);
    static void modifyTask(std::string item, std::string input);
};

#endif //TASKSERVICE_H