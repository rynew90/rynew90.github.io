package ContactService;

public class Contact {
	
	private String contactId;
	private String firstName;
	private String lastName;
	private String phoneNum;
	private String address;
	
	public Contact (String contactId, String firstName, String lastName, String phoneNum, String address) {
		//contact ID error handling
		if (contactId == null || contactId.length() > 10) {
			throw new IllegalArgumentException("Invalid Contact ID");
		}
		
		//First Name error handling
		if (firstName ==  null || firstName.length() > 10) {
			throw new IllegalArgumentException("Invalid First Name");
		}
		
		//Last Name error handling
		if (lastName ==  null || lastName.length() > 10) {
			throw new IllegalArgumentException("Invalid Last Name");
		}
		
		//Phone Number error handling
		if (phoneNum ==  null || phoneNum.length() != 10) {
			throw new IllegalArgumentException("Invalid Phone Number");
		}
		
		//Address error handling
		if (address ==  null || address.length() > 30) {
			throw new IllegalArgumentException("Invalid Address");
		}
		
		//Variable instantiation
		this.contactId = contactId;
		this.firstName = firstName;
		this.lastName = lastName;
		this.phoneNum = phoneNum;
		this.address = address;
	}
	
	//contact ID getter
	public String getContactId() {
		return contactId;
	}
	
	//First Name getter
	public String getFirstName() {
		return firstName;
	}

	//First Name setter
	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}
	
	//Last Name getter
	public String getLastName() {
		return lastName;
	}

	//Last Name setter
	public void setLastName(String lastName) {
		this.lastName = lastName;
	}
	
	//Phone Number getter
	public String getPhoneNum() {
		return phoneNum;
	}
	
	//Phone Number setter
	public void setPhoneNum(String phoneNum) {
		this.phoneNum = phoneNum;
	}
	
	//Address getter
	public String getAddress() {
		return address;
	}

	//Address setter
	public void setAddress(String address) {
		this.address = address;
	}
	
}
