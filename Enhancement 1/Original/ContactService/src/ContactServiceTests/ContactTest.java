package ContactServiceTests;

import static org.junit.jupiter.api.Assertions.*;

import ContactService.Contact;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Assertions;

class ContactTest {
	
	@Test
	public void testContact() {
		Contact contact = new Contact("14532", "John", "Smith", "5557894321", "55 Madison Blvd");
		assertTrue(contact.getContactId().equals("14532"));
		assertTrue(contact.getFirstName().equals("John"));
		assertTrue(contact.getLastName().equals("Smith"));
		assertTrue(contact.getPhoneNum().equals("5557894321"));
		assertTrue(contact.getAddress().equals("55 Madison Blvd"));
	}

	@Test
	@DisplayName ("Test for Contact ID")
	public void ContactIdTooLong() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact("01234567890", "John", "Smith", "5557894321", "55 Madison Blvd");
		});
	}
	
	@Test
	public void ContactIdNull() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact(null, "John", "Smith", "5557894321", "55 Madison Blvd");
		});
	}
	
	@Test
	@DisplayName ("Test for First Name")
	public void FirstNameTooLong() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact("14532", "Bartholemew", "Smith", "5557894321", "55 Madison Blvd");
		});
	}
	
	@Test
	public void FirstNameNull() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact("14532", null, "Smith", "5557894321", "55 Madison Blvd");
		});
	}
	
	@Test
	@DisplayName ("Test for Last Name")
	public void LastNameTooLong() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact("14532", "John", "Hendrickson", "5557894321", "55 Madison Blvd");
		});
	}
	
	@Test
	public void LastNameNull() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact("14532", "John", null, "5557894321", "55 Madison Blvd");
		});
	}
	
	@Test
	@DisplayName ("Test for Phone Number")
	public void PhoneNumberNot10Digits() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact("01234567890", "John", "Smith", "15557894321", "55 Madison Blvd");
		});
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact("01234567890", "John", "Smith", "7894321", "55 Madison Blvd");
		});
	}
	
	@Test
	public void PhoneNumberNull() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact("14532", "John", "Smith", null, "55 Madison Blvd");
		});
	}
	
	@Test
	@DisplayName ("Test for Address")
	public void AddressTooLong() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact("01234567890", "John", "Smith", "5557894321", "4223 Jean Baptiste Point du Sable Lake Shore Drive");
		});
	}
	

	@Test
	public void AddressNull() {
		Assertions.assertThrows(IllegalArgumentException.class, () -> {
			new Contact("14532", "John", "Smith", "5557894321", null);
		});
	}

}
