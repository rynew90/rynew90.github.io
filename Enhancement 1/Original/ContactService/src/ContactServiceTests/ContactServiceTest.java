package ContactServiceTests;

import static org.junit.jupiter.api.Assertions.*;

import ContactService.ContactService;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;

class ContactServiceTest {
	
	@BeforeEach
	void setUp() {
		ContactService.contactList.clear();
	}
	
	@Test
	@DisplayName("Tests getting and displaying Contact Info")
	void TestDisplayContact() {
		ContactService.addContact("14532", "John", "Smith", "5557894321", "55 Madison Blvd");
		ContactService.displayContact("14532");
	}

	@Test
	@DisplayName("Tests for addContact method")
	void addContactTest() {
		//Test that addContact adds contact with unique ID
		ContactService.addContact("14532", "John", "Smith", "5557894321", "55 Madison Blvd");
		assertEquals(1, ContactService.contactList.size());
		
		ContactService.addContact("98542", "Tom", "Chambers", "5559876541", "37 Governors Drive");
		ContactService.addContact("86427", "Cameron", "Anderson", "5552461379", "64 Memorial Pkwy");
		assertEquals(3, ContactService.contactList.size());
		
		//Test that addContact does not allow non-unique ID
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			ContactService.addContact("14532", "Amanda", "Sanders", "5558315645", "715 Capshaw Road");
		});
	}
	
	@Test
	@DisplayName("Tests for deleteContact method")
	void deleteContactTest() {
		//Test to check that deleteContact deletes contact
		ContactService.addContact("14532", "John", "Smith", "5557894321", "55 Madison Blvd");
		ContactService.addContact("23541", "Jack", "Honer", "5558746321", "79 Wall Triana Hwy");
		
		ContactService.deleteContact("14532");
		Assertions.assertEquals(1, ContactService.contactList.size());
		
	}
	
	@Test
	@DisplayName("Tests for modifyContact method")
	void modifyContactTest() {
		ContactService.addContact("14532", "John", "Smith", "5557894321", "55 Madison Blvd");
		
		//Test to check that modifyContact modifies first name
		ContactService.modifyContact("1", "Jack");
		assertEquals("Jack", ContactService.contactList.get(0).getFirstName());
		
		//Test to check that modifyContact modifies last name
		ContactService.modifyContact("2", "Adams");
		assertEquals("Adams", ContactService.contactList.get(0).getLastName());
		
		//Test to check that modifyContact modifies phone number
		ContactService.modifyContact("3", "5554563210");
		assertEquals("5554563210", ContactService.contactList.get(0).getPhoneNum());
		
		//Test to check that modifyContact modifies address
		ContactService.modifyContact("4", "32 Greenbrier Pkwy");
		assertEquals("32 Greenbrier Pkwy", ContactService.contactList.get(0).getAddress());
		
	}

}
