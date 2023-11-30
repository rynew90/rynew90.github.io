<<<<<<< HEAD
/* 
 * Author: Ryne Williams
 * Date: 11/11/2023
 * File: ACTService_Test.cpp
 * Version: 1.0
 * Description: This file tests the functionality and error handling for the ACT.cpp and ACTService.cpp files to ensure that methods work properly,
 * that errors are handled when fields are left blank or are too long, and that Arraylists are initilized properly.
 *  
 * Testing file for:
 *     Appointment class
 *     Appointment Service class
 *     Contact class
 *     Contact Service class
 *     Task class
 *     Task Service class
 */

#include "pch.h"
#include "ACTService.h"

// Initializing class for testing framework.
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// Create test class for Appointment
class AppointmentTest : public ::testing::Test
{
protected:
    // create a smart point to hold collection
    std::unique_ptr<std::vector<int>> appointment;

    void SetUp() override
    { 
        // create a new collection to be used in the test
        appointment.reset(new std::vector<int>);
    }

    void TearDown() override
    { 
        //  erase all elements in the collection, if any remain
        appointment->clear();

        // free the pointer
        appointment.reset(nullptr);
    }
};

// Create test class for Appointment Service
class AppointmentServiceTest : public ::testing::Test
{
protected:
    void SetUp() override {
        AppointmentService::appointmentList.clear();
    }
};

// Create test class for Contact
class ContactTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> contact;

    void SetUp() override
    {
        // create a new collection to be used in the test
        contact.reset(new std::vector<int>);
    }

    void TearDown() override
    {
        //  erase all elements in the collection, if any remain
        contact->clear();

        // free the pointer
        contact.reset(nullptr);
    }
};

// Create test class for Contact Service
class ContactServiceTest : public ::testing::Test
{
protected:
    void SetUp() override {
        ContactService::contactList.clear();
    }
};

// Create test class for Task
class TaskTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> task;

    void SetUp() override
    {
        // create a new collection to be used in the test
        task.reset(new std::vector<int>);
    }

    void TearDown() override
    {
        //  erase all elements in the collection, if any remain
        task->clear();

        // free the pointer
        task.reset(nullptr);
    }
};

// Create test class for Task Service
class TaskServiceTest : public ::testing::Test
{
protected:
    void SetUp() override {
        TaskService::taskList.clear();
    }
};

// Tests for Appointment class
TEST_F(AppointmentTest, TestAppointment) 
{
    // Test to check if  appointment is present
    std::tm date = {};
    std::istringstream ss("16/08/2024");
    ss >> std::get_time(&date, "%d/%m/%Y");

    Appointment appointment("8675309", date, "Birthday Party");

	EXPECT_EQ(appointment.getAppointmentId(), "8675309");
}

TEST_F(AppointmentTest, testAppointmentIdTooLong) 
{
    // Test to check the length of the appointment ID
    std::tm date = {};
    std::istringstream ss("16/08/2024");
    ss >> std::get_time(&date, "%d/%m/%Y");

    ASSERT_THROW({
        
        try {
        Appointment appointment("68419735085", date, "Birthday Party");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid appointment ID.");
        throw;
    }

        }, std::invalid_argument);
}

TEST_F(AppointmentTest, testAppointmentIdNull) 
{
    // Test to check if appointment ID field is empty
    std::tm date = {};
    std::istringstream ss("16/08/2024");
    ss >> std::get_time(&date, "%d/%m/%Y");

    ASSERT_THROW({
        
        try {
        Appointment appointment("", date, "Birthday Party");
    }
    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid appointment ID.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(AppointmentTest, testAppointmentDatePast) 
{
    // Test to check if the appointment date is set in the past
    std::tm date = {};
    std::istringstream ss("16/08/1990");
    ss >> std::get_time(&date, "%d/%m/%Y");

    ASSERT_THROW({
        
        try {
        Appointment appointment("8675309", date, "Birthday Party");
    }
    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid appointment Date.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(AppointmentTest, testAppointmentDateNull) 
{
    // Test to check if the date field is empty
    ASSERT_THROW({
        
        try {
        Appointment appointment("8675309", {}, "Birthday Party");
    }
    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid appointment Date.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(AppointmentTest, testAppointmentDescTooLong) 
{
    // Test to check the length of the appointment description
    // Must me less than 50 characters
    std::tm date = {};
    std::istringstream ss("16/08/2024");
    ss >> std::get_time(&date, "%d/%m/%Y");

    ASSERT_THROW({
        
        try {
        Appointment appointment("8675309", date, "Go to Birthday Party, take gifts purchased for friend who is having a birthday.");
    }
    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid appointment description.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(AppointmentTest, testAppointmentDescNull) 
{
    // Test to check if appointment description is empty
    std::tm date = {};
    std::istringstream ss("16/08/2024");
    ss >> std::get_time(&date, "%d/%m/%Y");

    ASSERT_THROW({
        try {
        Appointment appointment("8675309", date, "");
    }
    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid appointment description.");
        throw;
    }
        }, std::invalid_argument);
}

// Tests for Appointment Service class
TEST_F(AppointmentServiceTest, TestDisplayAppointment) 
{
    // Test to check if displayAppointment() method displays appointments
    std::tm date = {}; // Initialize to a valid date
    std::istringstream ss("16/08/2024");
    ss >> std::get_time(&date, "%d/%m/%Y");

    AppointmentService::addAppointment("8675309", date, "Birthday Party");

    ASSERT_NO_THROW(AppointmentService::displayAppointment("8675309"));
}

TEST_F(AppointmentServiceTest, TestAddAppointment) 
{
    // Test adding an appointment
    std::tm date = {}; // Initialize to a valid date
    std::istringstream ss("16/08/2024");
    ss >> std::get_time(&date, "%d/%m/%Y");
    ASSERT_NO_THROW(AppointmentService::addAppointment("8675309", date, "Birthday Party"));
    ASSERT_EQ(AppointmentService::appointmentList.size(), 1);

    // Test adding multiple appointments
    ASSERT_NO_THROW(AppointmentService::addAppointment("0814256", date, "Birthday Party"));
    ASSERT_NO_THROW(AppointmentService::addAppointment("4656231", date, "Office Christmas Party"));
    ASSERT_EQ(AppointmentService::appointmentList.size(), 3);

    // Test to check if appointment ID already in use
    ASSERT_THROW({
        try {
        AppointmentService::addAppointment("8675309", date, "Valentine's Party");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Error: Appointment ID already in use.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(AppointmentServiceTest, TestDeleteAppointment) 
{
    // Test to check if appointment is deleted.
    std::tm date = {}; // Initialize to a valid date
    std::istringstream ss("16/08/2024");
    ss >> std::get_time(&date, "%d/%m/%Y");

    AppointmentService::addAppointment("12345", date, "Meeting");

    ASSERT_NO_THROW(AppointmentService::deleteAppointment("12345"));
    ASSERT_EQ(AppointmentService::appointmentList.size(), 0);
}

// Tests for Contact class
TEST_F(ContactTest, TestContact) 
{
    // Test to check if contact is present
    Contact contact("14532", "John", "Smith", "5557894321", "55 Madison Blvd");

    EXPECT_EQ(contact.getContactId(), "14532");
    EXPECT_EQ(contact.getFirstName(), "John");
    EXPECT_EQ(contact.getLastName(), "Smith");
    EXPECT_EQ(contact.getPhoneNum(), "5557894321");
    EXPECT_EQ(contact.getAddress(), "55 Madison Blvd");
}

TEST_F(ContactTest, ContactIdTooLong)
{
    // Test to check if contact ID is too long. Must be no more than 10 characters.
    ASSERT_THROW({
        try {
        Contact contact("01234567890", "John", "Smith", "5557894321", "55 Madison Blvd");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Contact ID.");
        throw;
    }

        }, std::invalid_argument);
}

TEST_F(ContactTest, ContactIdNull)
{
    // Test to check if contact ID is null
    ASSERT_THROW({
        try {
        Contact contact("", "John", "Smith", "5557894321", "55 Madison Blvd");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Contact ID.");
        throw;
    }

        }, std::invalid_argument);
}

TEST_F(ContactTest, FirstNameTooLong)
{
    // Test to check if first name is too long. Must be no more than 10 characters.
    ASSERT_THROW({
        try {
        Contact contact("14532", "Bartholemew", "Smith", "5557894321", "55 Madison Blvd");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid First Name.");
        throw;
    }

        }, std::invalid_argument);
}

TEST_F(ContactTest, FirstNameNull)
{
    // Test to check if first name field is empty
    ASSERT_THROW({
        try {
        Contact contact("14532", "", "Smith", "5557894321", "55 Madison Blvd");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid First Name.");
        throw;
    }

        }, std::invalid_argument);
}

TEST_F(ContactTest, LastNameTooLong)
{
    // Test to check if last name is too long. Must be no more than 10 characters.
    ASSERT_THROW({
        try {
        Contact contact("14532", "John", "Hendrickson", "5557894321", "55 Madison Blvd");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Last Name.");
        throw;
    }

        }, std::invalid_argument);
}

TEST_F(ContactTest, LastNameNull)
{
    // Test to check if last name field is empty
    ASSERT_THROW({
        try {
        Contact contact("14532", "John", "", "5557894321", "55 Madison Blvd");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Last Name.");
        throw;
    }

        }, std::invalid_argument);
}

TEST_F(ContactTest, PhoneNumNot10Digits)
{
    // Test to check if phone number is greater than than 10 characters.
    ASSERT_THROW({
        try {
        Contact contact("14532", "John", "Smith", "15557894321", "55 Madison Blvd");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Phone Number.");
        throw;
    }

        }, std::invalid_argument);

    // Test to check if phone number is less than than 10 characters.
    ASSERT_THROW({
        try {
        Contact contact("14532", "John", "Smith", "7894321", "55 Madison Blvd");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Phone Number.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(ContactTest, PhoneNumNull)
{
    // Test to check if phone number field is empty.
    ASSERT_THROW({
        try {
        Contact contact("14532", "John", "Smith", "", "55 Madison Blvd");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Phone Number.");
        throw;
    }

        }, std::invalid_argument);
}

TEST_F(ContactTest, AddressTooLong)
{
    // Test to check if address is too long. Must be no more than 30 characters
    ASSERT_THROW({
        try {
        Contact contact("14532", "John", "Smith", "5557894321", "4223 Jean Baptiste Point du Sable Lake Shore Drive");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Address.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(ContactTest, AddressNull)
{
    // Test to check if address field is empty.
    ASSERT_THROW({
        try {
        Contact contact("14532", "John", "Smith", "5557894321", "");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Address.");
        throw;
    }
        }, std::invalid_argument);
}

// Tests for Contact Service class
TEST_F(ContactServiceTest, TestDisplayContact)
{
    // Test to check displayContact() method.
    ContactService::addContact("14532", "John", "Smith", "5557894321", "55 Madison Blvd");

    ASSERT_NO_THROW(ContactService::displayContact("14532"));
}

TEST_F(ContactServiceTest, TestAddContact)
{
    // Test adding a contact
    ASSERT_NO_THROW(ContactService::addContact("14532", "John", "Smith", "5557894321", "55 Madison Blvd"));
    ASSERT_EQ(ContactService::contactList.size(), 1);

    // Test adding multiple contacts
    ASSERT_NO_THROW(ContactService::addContact("98542", "Tom", "Chambers", "5559876541", "37 Governors Drive"));
    ASSERT_NO_THROW(ContactService::addContact("86427", "Cameron", "Anderson", "5552461379", "64 Memorial Pkwy"));
    ASSERT_EQ(ContactService::contactList.size(), 3);

    // Test that Contact ID must be unique
    ASSERT_THROW({
        try {
            ContactService::addContact("14532", "Amanda", "Sanders", "5558315645", "715 Capshaw Road");
        }
        catch (const std::invalid_argument& e) {
            EXPECT_STREQ(e.what(), "Error: Contact ID already in use.");
            throw;
        } 
    }, std::invalid_argument);
}

TEST_F(ContactServiceTest, TestDeleteContact)
{
    // Test to check if contact is successfully deleted.
    ContactService::addContact("14532", "John", "Smith", "5557894321", "55 Madison Blvd");

    ASSERT_NO_THROW(ContactService::deleteContact("14532"));
    ASSERT_EQ(ContactService::contactList.size(), 0);
}

TEST_F(ContactServiceTest, TestModifyContact)
{
    // Test to check if contact is successfully modified.
    ContactService::addContact("14532", "John", "Smith", "5557894321", "55 Madison Blvd");

    ASSERT_NO_THROW(ContactService::modifyContact("1", "Jack"));
    ASSERT_EQ(ContactService::contactList[0].getFirstName(), "Jack");

    ASSERT_NO_THROW(ContactService::modifyContact("2", "Adams"));
    ASSERT_EQ(ContactService::contactList[0].getLastName(), "Adams");

    ASSERT_NO_THROW(ContactService::modifyContact("3", "5554563210"));
    ASSERT_EQ(ContactService::contactList[0].getPhoneNum(), "5554563210");

    ASSERT_NO_THROW(ContactService::modifyContact("4", "32 Greenbrier Pkwy"));
    ASSERT_EQ(ContactService::contactList[0].getAddress(), "32 Greenbrier Pkwy");
}

// Tests for Task class
TEST_F(TaskTest, TestTask)
{
    // Test to check if task is present.
    Task task("546897", "Create Report", "Generate report for budget management.");

    EXPECT_EQ(task.getTaskId(), "546897");
    EXPECT_EQ(task.getTaskName(), "Create Report");
    EXPECT_EQ(task.getTaskDesc(), "Generate report for budget management.");
}

TEST_F(TaskTest, TestTaskIdTooLong)
{
    // Test to check if task ID is too long. Must be no more than 10 characters.
    ASSERT_THROW({
        try {
        Task task("01234567890", "Create Report", "Generate report for budget management.");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Task ID.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(TaskTest, TestTaskIdNull)
{
    // Test to check if task field is empty.
    ASSERT_THROW({
        try {
        Task task("", "Create Report", "Generate report for budget management.");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Task ID.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(TaskTest, TestTaskNameTooLong)
{
    // Test to check if task name is too long. Must be no more than 20 characters.
    ASSERT_THROW({
        try {
        Task task("546897", "Create Monthly Budget Report", "Generate report for budget management.");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Task Name.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(TaskTest, TestTaskNameNull)
{
    // Test to check if task name field is empty.
    ASSERT_THROW({
        try {
        Task task("546897", "", "Generate report for budget management.");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Task Name.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(TaskTest, TestTaskDescTooLong)
{
    // Test to check if task description is too long. Must be no longer than 50 characters.
    ASSERT_THROW({
        try {
        Task task("546897", "Create Report", "Generate a monthly budget report and submit to budget management spreadsheet.");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Task Description.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(TaskTest, TestTaskDescNull)
{
    // Test to check if task description is empty.
    ASSERT_THROW({
        try {
        Task task("546897", "Create Report", "");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Task Description.");
        throw;
    }
        }, std::invalid_argument);
}

// Tests for Task Service class
TEST_F(TaskServiceTest, TestTaskService)
{
    // Test to check displayTask() method.
    TaskService::addTask("546897", "Create Report", "Generate report for budget management.");

    ASSERT_NO_THROW(TaskService::displayTask("546879"));
}

TEST_F(TaskServiceTest, TestAddTask)
{
    // Test adding one task
    ASSERT_NO_THROW(TaskService::addTask("546897", "Create Report", "Generate report for budget management."));
    ASSERT_EQ(TaskService::taskList.size(), 1);

    // Test adding multiple tasks
    ASSERT_NO_THROW(TaskService::addTask("265742", "Complete Timesheet", "Review timesheets and submit timecards."));
    ASSERT_NO_THROW(TaskService::addTask("398421", "Review Inventory", "Inventory stock and reorder needed items."));
    ASSERT_EQ(TaskService::taskList.size(), 3);

    // Test that Task ID must be unique
    ASSERT_THROW({
        try {
        TaskService::addTask("546897", "Create Report", "Generate report for budget management.");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Error: Task ID already in use.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(TaskServiceTest, TestDeleteTask)
{
    // Test to check if task is successfully deleted.
    TaskService::addTask("546897", "Create Report", "Generate report for budget management.");

    ASSERT_NO_THROW(TaskService::deleteTask("546897"));
    ASSERT_EQ(TaskService::taskList.size(), 0);
}

TEST_F(TaskServiceTest, TestModifyTask)
{
    // Test to check if task is successfully modified.
    TaskService::addTask("546897", "Create Report", "Generate report for budget management.");

    ASSERT_NO_THROW(TaskService::modifyTask("1", "Contact Customer"));
    ASSERT_EQ(TaskService::taskList[0].getTaskName(), "Contact Customer");

    ASSERT_NO_THROW(TaskService::modifyTask("2", "Contact customer for clarification on product ordered"));
    ASSERT_EQ(TaskService::taskList[0].getTaskDesc(), "Contact customer for clarification on product ordered");
}
=======
#include "pch.h"
#include "ACTService.h"

class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class for Appointment
class AppointmentTest : public ::testing::Test
{
protected:
    // create a smart point to hold collection
    std::unique_ptr<std::vector<int>> appointment;

    void SetUp() override
    { 
        // create a new collection to be used in the test
        appointment.reset(new std::vector<int>);
    }

    void TearDown() override
    { 
        //  erase all elements in the collection, if any remain
        appointment->clear();

        // free the pointer
        appointment.reset(nullptr);
    }
};

// create our test class for Appointment Service
class AppointmentServiceTest : public ::testing::Test
{
protected:
    void SetUp() override {
        AppointmentService::appointmentList.clear();
    }
};

// create our test class for Contact
class ContactTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> contact;

    void SetUp() override
    {
        // create a new collection to be used in the test
        contact.reset(new std::vector<int>);
    }

    void TearDown() override
    {
        //  erase all elements in the collection, if any remain
        contact->clear();

        // free the pointer
        contact.reset(nullptr);
    }
};

// create our test class for Contact Service
class ContactServiceTest : public ::testing::Test
{
protected:
    void SetUp() override {
        ContactService::contactList.clear();
    }
};

// create our test class for Task
class TaskTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> task;

    void SetUp() override
    {
        // create a new collection to be used in the test
        task.reset(new std::vector<int>);
    }

    void TearDown() override
    {
        //  erase all elements in the collection, if any remain
        task->clear();

        // free the pointer
        task.reset(nullptr);
    }
};

// create our test class for Task Service
class TaskServiceTest : public ::testing::Test
{
protected:
    void SetUp() override {
        TaskService::taskList.clear();
    }
};

// Tests for Appointment class
TEST_F(AppointmentTest, TestAppointment) 
{
    std::tm date = {};
    std::istringstream ss("16/08/2024");
    ss >> std::get_time(&date, "%d/%m/%Y");

    Appointment appointment("8675309", date, "Birthday Party");

	EXPECT_EQ(appointment.getAppointmentId(), "8675309");
}

TEST_F(AppointmentTest, testAppointmentIdTooLong) 
{
    std::tm date = {};
    std::istringstream ss("16/08/2024");
    ss >> std::get_time(&date, "%d/%m/%Y");

    ASSERT_THROW({
        
        try {
        Appointment appointment("68419735085", date, "Birthday Party");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid appointment ID.");
        throw;
    }

        }, std::invalid_argument);
}

TEST_F(AppointmentTest, testAppointmentIdNull) 
{
    std::tm date = {};
    std::istringstream ss("16/08/2024");
    ss >> std::get_time(&date, "%d/%m/%Y");

    ASSERT_THROW({
        
        try {
        Appointment appointment("", date, "Birthday Party");
    }
    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid appointment ID.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(AppointmentTest, testAppointmentDatePast) {
    std::tm date = {};
    std::istringstream ss("16/08/1990");
    ss >> std::get_time(&date, "%d/%m/%Y");

    ASSERT_THROW({
        
        try {
        Appointment appointment("8675309", date, "Birthday Party");
    }
    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid appointment Date.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(AppointmentTest, testAppointmentDateNull) {
    ASSERT_THROW({
        
        try {
        Appointment appointment("8675309", {}, "Birthday Party");
    }
    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid appointment Date.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(AppointmentTest, testAppointmentDescTooLong) {
    std::tm date = {};
    std::istringstream ss("16/08/2024");
    ss >> std::get_time(&date, "%d/%m/%Y");

    ASSERT_THROW({
        
        try {
        Appointment appointment("8675309", date, "Go to Birthday Party, take gifts purchased for friend who is having a birthday.");
    }
    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid appointment description.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(AppointmentTest, testAppointmentDescNull) {
    std::tm date = {};
    std::istringstream ss("16/08/2024");
    ss >> std::get_time(&date, "%d/%m/%Y");

    ASSERT_THROW({
        try {
        Appointment appointment("8675309", date, "");
    }
    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid appointment description.");
        throw;
    }
        }, std::invalid_argument);
}

// Tests for Appointment Service class
TEST_F(AppointmentServiceTest, TestDisplayAppointment) 
{
    std::tm date = {}; // Initialize to a valid date
    std::istringstream ss("16/08/2024");
    ss >> std::get_time(&date, "%d/%m/%Y");

    AppointmentService::addAppointment("8675309", date, "Birthday Party");

    ASSERT_NO_THROW(AppointmentService::displayAppointment("8675309"));
}

TEST_F(AppointmentServiceTest, TestAddAppointment) 
{
    // Test adding an appointment
    std::tm date = {}; // Initialize to a valid date
    std::istringstream ss("16/08/2024");
    ss >> std::get_time(&date, "%d/%m/%Y");
    ASSERT_NO_THROW(AppointmentService::addAppointment("8675309", date, "Birthday Party"));
    ASSERT_EQ(AppointmentService::appointmentList.size(), 1);

    // Test adding multiple appointments
    ASSERT_NO_THROW(AppointmentService::addAppointment("0814256", date, "Birthday Party"));
    ASSERT_NO_THROW(AppointmentService::addAppointment("4656231", date, "Office Christmas Party"));
    ASSERT_EQ(AppointmentService::appointmentList.size(), 3);

    // Test to check if appointment ID already in use
    ASSERT_THROW({
        try {
        AppointmentService::addAppointment("8675309", date, "Valentine's Party");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Error: Appointment ID already in use.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(AppointmentServiceTest, TestDeleteAppointment) 
{
    std::tm date = {}; // Initialize to a valid date
    std::istringstream ss("16/08/2024");
    ss >> std::get_time(&date, "%d/%m/%Y");

    AppointmentService::addAppointment("12345", date, "Meeting");

    ASSERT_NO_THROW(AppointmentService::deleteAppointment("12345"));
    ASSERT_EQ(AppointmentService::appointmentList.size(), 0);
}

// Tests for Contact class
TEST_F(ContactTest, TestContact) 
{
    Contact contact("14532", "John", "Smith", "5557894321", "55 Madison Blvd");

    EXPECT_EQ(contact.getContactId(), "14532");
    EXPECT_EQ(contact.getFirstName(), "John");
    EXPECT_EQ(contact.getLastName(), "Smith");
    EXPECT_EQ(contact.getPhoneNum(), "5557894321");
    EXPECT_EQ(contact.getAddress(), "55 Madison Blvd");
}

TEST_F(ContactTest, ContactIdTooLong)
{
    ASSERT_THROW({
        try {
        Contact contact("01234567890", "John", "Smith", "5557894321", "55 Madison Blvd");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Contact ID.");
        throw;
    }

        }, std::invalid_argument);
}

TEST_F(ContactTest, ContactIdNull)
{
    ASSERT_THROW({
        try {
        Contact contact("", "John", "Smith", "5557894321", "55 Madison Blvd");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Contact ID.");
        throw;
    }

        }, std::invalid_argument);
}

TEST_F(ContactTest, FirstNameTooLong)
{
    ASSERT_THROW({
        try {
        Contact contact("14532", "Bartholemew", "Smith", "5557894321", "55 Madison Blvd");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid First Name.");
        throw;
    }

        }, std::invalid_argument);
}

TEST_F(ContactTest, FirstNameNull)
{
    ASSERT_THROW({
        try {
        Contact contact("14532", "", "Smith", "5557894321", "55 Madison Blvd");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid First Name.");
        throw;
    }

        }, std::invalid_argument);
}

TEST_F(ContactTest, LastNameTooLong)
{
    ASSERT_THROW({
        try {
        Contact contact("14532", "John", "Hendrickson", "5557894321", "55 Madison Blvd");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Last Name.");
        throw;
    }

        }, std::invalid_argument);
}

TEST_F(ContactTest, LastNameNull)
{
    ASSERT_THROW({
        try {
        Contact contact("14532", "John", "", "5557894321", "55 Madison Blvd");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Last Name.");
        throw;
    }

        }, std::invalid_argument);
}

TEST_F(ContactTest, PhoneNumNot10Digits)
{
    ASSERT_THROW({
        try {
        Contact contact("14532", "John", "Smith", "15557894321", "55 Madison Blvd");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Phone Number.");
        throw;
    }

        }, std::invalid_argument);

    ASSERT_THROW({
        try {
        Contact contact("14532", "John", "Smith", "7894321", "55 Madison Blvd");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Phone Number.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(ContactTest, PhoneNumNull)
{
    ASSERT_THROW({
        try {
        Contact contact("14532", "John", "Smith", "", "55 Madison Blvd");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Phone Number.");
        throw;
    }

        }, std::invalid_argument);
}

TEST_F(ContactTest, AddressTooLong)
{
    ASSERT_THROW({
        try {
        Contact contact("14532", "John", "Smith", "5557894321", "4223 Jean Baptiste Point du Sable Lake Shore Drive");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Address.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(ContactTest, AddressNull)
{
    ASSERT_THROW({
        try {
        Contact contact("14532", "John", "Smith", "5557894321", "");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Address.");
        throw;
    }
        }, std::invalid_argument);
}

// Tests for Contact Service class
TEST_F(ContactServiceTest, TestDisplayContact)
{
    ContactService::addContact("14532", "John", "Smith", "5557894321", "55 Madison Blvd");

    ASSERT_NO_THROW(ContactService::displayContact("14532"));
}

TEST_F(ContactServiceTest, TestAddContact)
{
    // Test adding a contact
    ASSERT_NO_THROW(ContactService::addContact("14532", "John", "Smith", "5557894321", "55 Madison Blvd"));
    ASSERT_EQ(ContactService::contactList.size(), 1);

    // Test adding multiple contacts
    ASSERT_NO_THROW(ContactService::addContact("98542", "Tom", "Chambers", "5559876541", "37 Governors Drive"));
    ASSERT_NO_THROW(ContactService::addContact("86427", "Cameron", "Anderson", "5552461379", "64 Memorial Pkwy"));
    ASSERT_EQ(ContactService::contactList.size(), 3);

    // Test that Contact ID must be unique
    ASSERT_THROW({
        try {
            ContactService::addContact("14532", "Amanda", "Sanders", "5558315645", "715 Capshaw Road");
        }
        catch (const std::invalid_argument& e) {
            EXPECT_STREQ(e.what(), "Error: Contact ID already in use.");
            throw;
        } 
    }, std::invalid_argument);
}

TEST_F(ContactServiceTest, TestDeleteContact)
{
    ContactService::addContact("14532", "John", "Smith", "5557894321", "55 Madison Blvd");

    ASSERT_NO_THROW(ContactService::deleteContact("14532"));
    ASSERT_EQ(ContactService::contactList.size(), 0);
}

TEST_F(ContactServiceTest, TestModifyContact)
{
    ContactService::addContact("14532", "John", "Smith", "5557894321", "55 Madison Blvd");

    ASSERT_NO_THROW(ContactService::modifyContact("1", "Jack"));
    ASSERT_EQ(ContactService::contactList[0].getFirstName(), "Jack");

    ASSERT_NO_THROW(ContactService::modifyContact("2", "Adams"));
    ASSERT_EQ(ContactService::contactList[0].getLastName(), "Adams");

    ASSERT_NO_THROW(ContactService::modifyContact("3", "5554563210"));
    ASSERT_EQ(ContactService::contactList[0].getPhoneNum(), "5554563210");

    ASSERT_NO_THROW(ContactService::modifyContact("4", "32 Greenbrier Pkwy"));
    ASSERT_EQ(ContactService::contactList[0].getAddress(), "32 Greenbrier Pkwy");
}

// Tests for Task class
TEST_F(TaskTest, TestTask)
{
    Task task("546897", "Create Report", "Generate report for budget management.");

    EXPECT_EQ(task.getTaskId(), "546897");
    EXPECT_EQ(task.getTaskName(), "Create Report");
    EXPECT_EQ(task.getTaskDesc(), "Generate report for budget management.");
}

TEST_F(TaskTest, TestTaskIdTooLong)
{
    ASSERT_THROW({
        try {
        Task task("01234567890", "Create Report", "Generate report for budget management.");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Task ID.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(TaskTest, TestTaskIdNull)
{
    ASSERT_THROW({
        try {
        Task task("", "Create Report", "Generate report for budget management.");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Task ID.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(TaskTest, TestTaskNameTooLong)
{
    ASSERT_THROW({
        try {
        Task task("546897", "Create Monthly Budget Report", "Generate report for budget management.");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Task Name.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(TaskTest, TestTaskNameNull)
{
    ASSERT_THROW({
        try {
        Task task("546897", "", "Generate report for budget management.");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Task Name.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(TaskTest, TestTaskDescTooLong)
{
    ASSERT_THROW({
        try {
        Task task("546897", "Create Report", "Generate a monthly budget report and submit to budget management spreadsheet.");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Task Description.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(TaskTest, TestTaskDescNull)
{
    ASSERT_THROW({
        try {
        Task task("546897", "Create Report", "");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Invalid Task Description.");
        throw;
    }
        }, std::invalid_argument);
}

// Tests for Task Service class
TEST_F(TaskServiceTest, TestTaskService)
{
    TaskService::addTask("546897", "Create Report", "Generate report for budget management.");

    ASSERT_NO_THROW(TaskService::displayTask("546879"));
}

TEST_F(TaskServiceTest, TestAddTask)
{
    // Test adding one task
    ASSERT_NO_THROW(TaskService::addTask("546897", "Create Report", "Generate report for budget management."));
    ASSERT_EQ(TaskService::taskList.size(), 1);

    // Test adding multiple tasks
    ASSERT_NO_THROW(TaskService::addTask("265742", "Complete Timesheet", "Review timesheets and submit timecards."));
    ASSERT_NO_THROW(TaskService::addTask("398421", "Review Inventory", "Inventory stock and reorder needed items."));
    ASSERT_EQ(TaskService::taskList.size(), 3);

    // Test that Task ID must be unique
    ASSERT_THROW({
        try {
        TaskService::addTask("546897", "Create Report", "Generate report for budget management.");
    }

    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Error: Task ID already in use.");
        throw;
    }
        }, std::invalid_argument);
}

TEST_F(TaskServiceTest, TestDeleteTask)
{
    TaskService::addTask("546897", "Create Report", "Generate report for budget management.");

    ASSERT_NO_THROW(TaskService::deleteTask("546897"));
    ASSERT_EQ(TaskService::taskList.size(), 0);
}

TEST_F(TaskServiceTest, TestModifyTask)
{
    TaskService::addTask("546897", "Create Report", "Generate report for budget management.");

    ASSERT_NO_THROW(TaskService::modifyTask("1", "Contact Customer"));
    ASSERT_EQ(TaskService::taskList[0].getTaskName(), "Contact Customer");

    ASSERT_NO_THROW(TaskService::modifyTask("2", "Contact customer for clarification on product ordered"));
    ASSERT_EQ(TaskService::taskList[0].getTaskDesc(), "Contact customer for clarification on product ordered");
}
>>>>>>> e523f0524c9b8961eff40e9b034290686a443911
