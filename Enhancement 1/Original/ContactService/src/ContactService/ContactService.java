package ContactService;

import java.util.*;

public class ContactService {
	
	public static ArrayList<Contact> contactList = new ArrayList<Contact>();
	
	public static void displayContact (String contactId) {
		for (Contact contact : contactList) {
			if (contact.getContactId().equals(contactId)) {
				System.out.println(contact.getContactId());
				System.out.println(contact.getFirstName());
				System.out.println(contact.getLastName());
				System.out.println(contact.getPhoneNum());
				System.out.println(contact.getAddress());
			}
		}
	}
	
	public static void addContact (String contactId, String firstName, String lastName, String phoneNum, String address) {
		
		for (Contact contact : contactList) {
			if (contact.getContactId().equals(contactId)) {
				throw new IllegalArgumentException ("Error: Contact ID already in use.");
			}
		}
		
		Contact contact = new Contact(contactId, firstName, lastName, phoneNum, address);
		contactList.add(contact);
		
	}
	
	public static void deleteContact(String contactId) {		
		
		for (int i = 0; i < contactList.size(); i++) {
			if (contactList.get(i).getContactId() == contactId) {
				contactList.remove(i);
				return;
			}
		}
	}
	
	public static void modifyContact(String item, String input) {
		
		for (Contact contact : contactList) {
			if (item == "1") {
				contact.setFirstName(input);
			}
			else if (item == "2") {
				contact.setLastName(input);
			}
			else if (item == "3") {
				contact.setPhoneNum(input);
			}
			else if (item == "4") {
				contact.setAddress(input);			
			}
			else {
				System.out.println("Invalid Input");
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner scnr = new Scanner(System.in);
		
		String contactId;
		String firstName;
		String lastName;
		String phoneNum;
		String address;
		
		int choice = 0;
		while (choice != 9) {
			//Print Menu
			System.out.println("--Menu--");
			System.out.println("1: Add Contact");
			System.out.println("2: Delete Contact");
			System.out.println("3: Update Contact Info");
			System.out.println("9: Exit");
			System.out.print("Please select an option:");
			
			//Accept user input
			choice = scnr.nextInt();
			
			//Switch statement to handle user input
			switch (choice) {
			
			case 1:
				System.out.print("Enter Contact Id: ");
				contactId = scnr.nextLine();
				
				displayContact(contactId);
				
				break;
			
			case 2:
				System.out.print("Enter New Contact ID: ");
				contactId = scnr.nextLine();

				System.out.print("First Name: ");
				firstName = scnr.nextLine();
				
				System.out.print("Lasat Name: ");
				lastName = scnr.nextLine();
				
				System.out.print("Phone Number: ");
				phoneNum = scnr.nextLine();
				
				System.out.print("Address: ");
				address = scnr.nextLine();
				
				addContact(contactId, firstName, lastName, phoneNum, address);
				break;
				
			case 3:
				System.out.print("Enter contact ID to delete: ");
				contactId = scnr.nextLine();
				
				deleteContact(contactId);
				break;
				
			case 4:
				
				
				System.out.print("Enter contact ID to modify: ");
				contactId = scnr.nextLine();
				
				for (Contact contact : contactList) {
					if (contact.getContactId().equals(contactId)) {
						System.out.println("--Enter item to update--");
						System.out.println("1t First Name");
						System.out.println("2: Last Name");
						System.out.println("3: Phone Number");
						System.out.println("4: Address");
						String item = scnr.nextLine();
						String input;
						
						if (item.equals("1")) {
							System.out.print("Enter new First Name: ");
							input = scnr.nextLine();
							modifyContact(item, input);
						}
						
						else if (item.equals("2")) {
							System.out.print("Enter new last Name: ");
							input = scnr.nextLine();
							modifyContact(item, input);
						}
						
						else if (item.equals("3")) {
							System.out.print("Enter new Phone Number: ");
							input = scnr.nextLine();
							modifyContact(item, input);
						}
						
						else if (item.equals("4")) {
							System.out.print("Enter new Address: ");
							input = scnr.nextLine();
							modifyContact(item, input);
						}
						
						else {
							System.out.println("Invalid input.");
						}
					}
					else {
						System.out.println("Contact Not Found.");
					}
				}
				
				break;
				
			case 9:
				System.out.println("Closing Contact Service App.");
				
			default:
				System.out.println("Invalid Input.");
			}
			
			System.out.println();
			
			scnr.close();
		}
	}

}
