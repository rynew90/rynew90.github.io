/*
 * Author: Ryne Williams
 * Date: 11/11/2023
 * File: ACT.cpp
 * Version: 1.0
 * Description: This file sets up the getters and setters for the ACTService classes, creates error handling for the user inputs
 * to ensure that inputs are not null and below a specified character length.
 */

#include <iostream>

#include "pch.h"

class Appointment
{
private:
    // Declare variables for Appointment class
    std::string appointmentId;
    std::tm appointmentDate;
    std::string appointmentDesc;

public:
    // Error Handling, Getters and Setters
    Appointment(std::string appointmentId, std::tm appointmentDate, std::string appointmentDesc)
    {
        // Checks for proper format for appointment ID
        if (appointmentId.empty() || appointmentId.length() > 10)
        {
            throw std::invalid_argument("Invalid appointment ID.");
        }

        std::time_t now = std::time(0);
        std::tm* current = std::localtime(&now);

        // Checks for proper format for appointment date
        if (std::mktime(&appointmentDate) <= std::mktime(current))
        {
            throw std::invalid_argument("Invalid appointment Date.");
        }

        // Checks for proper format for appointment description
        if (appointmentDesc.empty() || appointmentDesc.length() > 50)
        {
            throw std::invalid_argument("Invalid appointment description.");
        }

        // Variable instantiation
        this->appointmentId = appointmentId;
        this->appointmentDate = appointmentDate;
        this->appointmentDesc = appointmentDesc;
    }

    // Appointment ID getter
    std::string getAppointmentId() const
    {
        return appointmentId;
    }

    // Appointment Date getter
    std::tm getAppointmentDate() const
    {
        return appointmentDate;
    }

    // Appointment Date setter
    void setAppointmentDate(std::tm appointmentDate)
    {
        this->appointmentDate = appointmentDate;
    }

    // Appointment Description getter
    std::string getAppointmentDesc() const
    {
        return appointmentDesc;
    }

    // Appointment Description setter
    void setAppointmentDesc(std::string appointmentDesc)
    {
        this->appointmentDesc = appointmentDesc;
    }
};

class Contact // Contact class
{
private:
    // Declare variables for Contact class
    std::string contactId;
    std::string firstName;
    std::string lastName;
    std::string phoneNum;
    std::string address;

public:
    // Error handling
    Contact(std::string contactId, std::string firstName, std::string lastName, std::string phoneNum, std::string address)
    {
        // Checks for proper format for contact ID
        if (contactId.empty() || contactId.length() > 10)
        {
            throw std::invalid_argument("Invalid Contact ID.");
        }

        // Checks for proper format for first name
        if (firstName.empty() || firstName.length() > 10)
        {
            throw std::invalid_argument("Invalid First Name.");
        }

        // Checks for proper format for last name
        if (lastName.empty() || lastName.length() > 10)
        {
            throw std::invalid_argument("Invalid Last Name.");
        }

        // Checks for proper format for phone number
        if (phoneNum.empty() || phoneNum.length() != 10)
        {
            throw std::invalid_argument("Invalid Phone Number.");
        }

        // Checks for proper format for address
        if (address.empty() || address.length() > 30) {
            throw std::invalid_argument("Invalid Address.");
        }

        // Variable Instantiation
        this->contactId = contactId;
        this->firstName = firstName;
        this->lastName = lastName;
        this->phoneNum = phoneNum;
        this->address = address;
    }

    // Contact ID getter
    std::string getContactId() const
    {
        return contactId;
    }

    // First Name getter
    std::string getFirstName() const
    {
        return firstName;
    }

    // First Name setter
    void setFirstName(std::string firstName)
    {
        this->firstName = firstName;
    }

    // Last Name getter
    std::string getLastName() const
    {
        return lastName;
    }

    // Last Name setter
    void setLastName(std::string lastName)
    {
        this->lastName = lastName;
    }

    // Phone Number getter
    std::string getPhoneNum() const
    {
        return phoneNum;
    }

    // Phone Number setter
    void setPhoneNum(std::string phoneNum)
    {
        this->phoneNum = phoneNum;
    }

    // Address getter
    std::string getAddress() const
    {
        return address;
    }

    // Address setter
    void setAddress(std::string address)
    {
        this->address = address;
    }
};

class Task
{
private:
    // Declare variables for task class
    std::string taskId;
    std::string taskName;
    std::string taskDesc;

public:
    //Error Handling
    Task(std::string taskId, std::string taskName, std::string taskDesc)
    {
        // Checks for proper format for task ID
        if (taskId.empty() || taskId.length() > 10)
        {
            throw std::invalid_argument("Invalid Task ID.");
        }

        // Checks for proper format for task name
        if (taskName.empty() || taskName.length() > 20)
        {
            throw std::invalid_argument("Invalid Task Name.");
        }

        // Checks for proper format for task description
        if (taskDesc.empty() || taskDesc.length() > 50)
        {
            throw std::invalid_argument("Invalid Task Description.");
        }

        // Variable Instantiation
        this->taskId = taskId;
        this->taskName = taskName;
        this->taskDesc = taskDesc;
    }

    // Task ID getter 
    std::string getTaskId() const
    {
        return taskId;
    }

    // Task Name getter
    std::string getTaskName() const
    {
        return taskName;
    }

    // Task Name setter
    void setTaskName(std::string taskName)
    {
        this->taskName = taskName;
    }

    // Task Description getter
    std::string getTaskDesc() const
    {
        return taskDesc;
    }

    // Task Description setter
    void setTaskDesc(std::string taskDesc)
    {
        this->taskDesc = taskDesc;
    }
};
