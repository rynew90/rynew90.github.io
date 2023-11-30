<<<<<<< HEAD
/*
 * Author: Ryne Williams
 * Date: 11/11/2023
 * File: ACTService.cpp
 * Version: 1.0
 * Description: This file implements the AppointmentService, ContactService, and TaskService classes and contains the logic for the add, display, delete, and modify
 * methods held within each class.
 */

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>

#include "pch.h"
#include "ACTService.h"

// Appointment Service methods implementations
// Method to display appointments.
void AppointmentService::displayAppointment(std::string appointmentId)
{
    for (const Appointment& appointment : appointmentList) // For appointment in appointment list
    {
        if (appointment.getAppointmentId() == appointmentId) // If appointment ID matches appointment ID in arraylist
        {
            std::cout << appointment.getAppointmentId() << std::endl; // get appointment ID
            std::cout << asctime(&appointment.getAppointmentDate()) << std::endl; //get appointment date
            std::cout << appointment.getAppointmentDesc() << std::endl; // get appointment description
        }
    }
}

// Method to add appointments.
void AppointmentService::addAppointment(std::string appointmentId, std::tm appointmentDate, std::string appointmentDesc)
{
    for (const Appointment& appointment : appointmentList) // For appointment in appointment list
    {
        if (appointment.getAppointmentId() == appointmentId) // If appointment ID matches appointment ID in arraylist
        {
            throw std::invalid_argument("Error: Appointment ID already in use."); // Throw fault, only unique IDs allowed.
        }
    }

    Appointment appointment(appointmentId, appointmentDate, appointmentDesc); // add user input into arrayList
    appointmentList.push_back(appointment); // add appointment
}

void AppointmentService::deleteAppointment(std::string appointmentId)
{
    for (auto it = appointmentList.begin(); it != appointmentList.end(); ++it) //Starting at beginning of arraylist until reaching the end.
    {
        if (it->getAppointmentId() == appointmentId) // if appointment matches appointment ID in arraylist
        {
            appointmentList.erase(it); // delete appointment
            return;
        }
    }
}

// Static vector to store a collection of Appointment objects in the AppointmentService class.
std::vector<Appointment> AppointmentService::appointmentList;

// Contact Service methods implementations
// Method to display contacts.
void ContactService::displayContact(std::string contactId)
{
    for (const Contact& contact : contactList) // For contact in contact list
    {
        if (contact.getContactId() == contactId) // If contact ID matches contact ID in arraylist
        {
            std::cout << contact.getContactId() << std::endl; // get contact ID
            std::cout << contact.getFirstName() << std::endl; // get contact first name
            std::cout << contact.getLastName() << std::endl; // get contact last name
            std::cout << contact.getPhoneNum() << std::endl; // get contact phone number
            std::cout << contact.getAddress() << std::endl; // get contact address
        }
    }
}

// Method to add contacts.
void ContactService::addContact(std::string contactId, std::string firstName, std::string lastName, std::string phoneNum, std::string address)
{
    for (const Contact& contact : contactList) // For contact in contact list
    {
        if (contact.getContactId() == contactId) // If contact ID matches contact ID in arraylist
        {
            throw std::invalid_argument("Error: Contact ID already in use."); // Throw fault, only unique IDs allowed.
        }
    }

    Contact contact(contactId, firstName, lastName, phoneNum, address); // add user input into arrayList
    contactList.push_back(contact); // add contact
}

// Method to delete contacts.
void ContactService::deleteContact(std::string contactId)
{
    for (auto i = contactList.begin(); i != contactList.end(); ++i) //Starting at beginning of arraylist until reaching the end.
    {
        if (i->getContactId() == contactId) // if contact matches contact ID in arraylist
        {
            contactList.erase(i); // delete contact
            return;
        }
    }
}

// Method to modify contacts.
void ContactService::modifyContact(std::string item, std::string input)
{
    for (Contact& contact : contactList) // For contact in contact list
    {
        if (item == "1") // If user input is 1
        {
            contact.setFirstName(input); // Set first name to new first name
        }

        if (item == "2") // If user input is 2
        {
            contact.setLastName(input); // Set last name to new last name
        }

        if (item == "3") // If user input is 3
        {
            contact.setPhoneNum(input); // Set phone number to new phone number
        }

        if (item == "4") // If user input is 4
        {
            contact.setAddress(input); // Set address to new address
        }
        else
        {
            std::cout << "Invalid Input." << std::endl;
        }
    }
}

// Static vector to store a collection of Contact objects in the ContactService class.
std::vector<Contact> ContactService::contactList;

// Task Service method implementations
// Method to display tasks.
void TaskService::displayTask(std::string taskId)
{
    for (const Task& task : taskList) // For task in task list
    {
        if (task.getTaskId() == taskId) // If task ID matches task ID in arraylist
        {
            std::cout << task.getTaskId() << std::endl; // get task ID
            std::cout << task.getTaskName() << std::endl; // get task name
            std::cout << task.getTaskDesc() << std::endl; // get task description
        }
    }
}

// Method to add tasks.
void TaskService::addTask(std::string taskId, std::string taskName, std::string taskDesc)
{
    for (const Task& task : taskList) // For task in task list
    {
        if (task.getTaskId() == taskId) // If task ID matches task ID in arraylist
        {
            throw std::invalid_argument("Error: Task ID already in use."); // Throw fault, only unique IDs allowed.
        }
    }

    Task task(taskId, taskName, taskDesc); // add user input into arrayList
    taskList.push_back(task); // add task
}

// Method to delete tasks.
void TaskService::deleteTask(std::string taskId)
{
    for (auto i = taskList.begin(); i != taskList.end(); ++i) //Starting at beginning of arraylist until reaching the end.
    {
        if (i->getTaskId() == taskId) // if task matches task ID in arraylist
        {
            taskList.erase(i); // delete task
            return;
        }
    }
}

// Method to modify tasks.
void TaskService::modifyTask(std::string item, std::string input)
{
    for (Task& task : taskList) // For task in task list
    {
        if (item == "1") // If user input is 1
        {
            task.setTaskName(input); //Set task name to new task name
        }

        if (item == "2") // If user input is 2
        {
            task.setTaskDesc(input); //Set task description to new description
        }

        else
        {
            std::cout << "Invalid Input." << std::endl;
        }
    }
}

// Static vector to store a collection of Task objects in the TaskService class.
std::vector<Task> TaskService::taskList;
=======
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>

#include "pch.h"
#include "ACTService.h"

// Appointment Service methods implementations
void AppointmentService::displayAppointment(std::string appointmentId)
{
    for (const Appointment& appointment : appointmentList)
    {
        if (appointment.getAppointmentId() == appointmentId)
        {
            std::cout << appointment.getAppointmentId() << std::endl;
            std::cout << asctime(&appointment.getAppointmentDate()) << std::endl;
            std::cout << appointment.getAppointmentDesc() << std::endl;
        }
    }
}

void AppointmentService::addAppointment(std::string appointmentId, std::tm appointmentDate, std::string appointmentDesc)
{
    for (const Appointment& appointment : appointmentList)
    {
        if (appointment.getAppointmentId() == appointmentId)
        {
            throw std::invalid_argument("Error: Appointment ID already in use.");
        }
    }

    Appointment appointment(appointmentId, appointmentDate, appointmentDesc);
    appointmentList.push_back(appointment);
}

void AppointmentService::deleteAppointment(std::string appointmentId)
{
    for (auto it = appointmentList.begin(); it != appointmentList.end(); ++it)
    {
        if (it->getAppointmentId() == appointmentId)
        {
            appointmentList.erase(it);
            return;
        }
    }
}

std::vector<Appointment> AppointmentService::appointmentList;

// Contact Service methods implementations
void ContactService::displayContact(std::string contactId)
{
    for (const Contact& contact : contactList)
    {
        if (contact.getContactId() == contactId)
        {
            std::cout << contact.getContactId() << std::endl;
            std::cout << contact.getFirstName() << std::endl;
            std::cout << contact.getLastName() << std::endl;
            std::cout << contact.getPhoneNum() << std::endl;
            std::cout << contact.getAddress() << std::endl;
        }
    }
}

void ContactService::addContact(std::string contactId, std::string firstName, std::string lastName, std::string phoneNum, std::string address)
{
    for (const Contact& contact : contactList)
    {
        if (contact.getContactId() == contactId) 
        {
            throw std::invalid_argument("Error: Contact ID already in use.");
        }
    }

    Contact contact(contactId, firstName, lastName, phoneNum, address);
    contactList.push_back(contact);
}

void ContactService::deleteContact(std::string contactId)
{
    for (auto i = contactList.begin(); i != contactList.end(); ++i)
    {
        if (i->getContactId() == contactId)
        {
            contactList.erase(i);
            return;
        }
    }
}

void ContactService::modifyContact(std::string item, std::string input)
{
    for (Contact& contact : contactList)
    {
        if (item == "1")
        {
            contact.setFirstName(input);
        }

        if (item == "2")
        {
            contact.setLastName(input);
        }

        if (item == "3")
        {
            contact.setPhoneNum(input);
        }

        if (item == "4")
        {
            contact.setAddress(input);
        }
        else
        {
            std::cout << "Invalid Input." << std::endl;
        }
    }
}

std::vector<Contact> ContactService::contactList;

// Task Service method implementations
void TaskService::displayTask(std::string taskId)
{
    for (const Task& task : taskList)
    {
        if (task.getTaskId() == taskId)
        {
            std::cout << task.getTaskId() << std::endl;
            std::cout << task.getTaskName() << std::endl;
            std::cout << task.getTaskDesc() << std::endl;
        }
    }
}

void TaskService::addTask(std::string taskId, std::string taskName, std::string taskDesc)
{
    for (const Task& task : taskList)
    {
        if (task.getTaskId() == taskId)
        {
            throw std::invalid_argument("Error: Task ID already in use.");
        }
    }

    Task task(taskId, taskName, taskDesc);
    taskList.push_back(task);
}

void TaskService::deleteTask(std::string taskId)
{
    for (auto i = taskList.begin(); i != taskList.end(); ++i)
    {
        if (i->getTaskId() == taskId)
        {
            taskList.erase(i);
            return;
        }
    }
}

void TaskService::modifyTask(std::string item, std::string input)
{
    for (Task& task : taskList)
    {
        if (item == "1")
        {
            task.setTaskName(input);
        }

        if (item == "2")
        {
            task.setTaskDesc(input);
        }

        else
        {
            std::cout << "Invalid Input." << std::endl;
        }
    }
}

std::vector<Task> TaskService::taskList;
>>>>>>> e523f0524c9b8961eff40e9b034290686a443911
