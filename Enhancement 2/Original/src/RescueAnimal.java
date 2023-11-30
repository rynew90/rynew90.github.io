/*
 * Author: Ryne Williams
 * Date: 11/18/2023
 * File: RescueAnimal.java
 * Version: 1.0
 * Description: This file holds the global getters and setters for the animal types
 */

import java.lang.String;

public class RescueAnimal {

    // Instance variables
    private String name;
    private String animalType;
    private String gender;
    private String age;
    private String weight;
    private String acquisitionDate;
    private String acquisitionCountry;
	private String trainingStatus;
    private boolean reserved;
	private String inServiceCountry;

	// Constructor
    public RescueAnimal() {
    }
    
    // Accessor methods
	public String getName() {
		return name;
	}
	public String getAnimalType() {
		return animalType;
	}
	public String getGender() {
		return gender;
	}
	public String getAge() {
		return age;
	}
	public String getWeight() {
		return weight;
	}
	public String getAcquisitionDate() {
		return acquisitionDate;
	}
	public String getAcquisitionLocation() {
		return acquisitionCountry;
	}
	public boolean getReserved() {
		return reserved;
	}
	public String getInServiceLocation() {
		return inServiceCountry;
	}
	public String getTrainingStatus() {
		return trainingStatus;
	}
	
	// Mutator methods
	public void setName(String name) {
		this.name = name;
	}
	public void setAnimalType(String animalType) {
		this.animalType = animalType;
	}
	public void setGender(String gender) {
		this.gender = gender;
	}
	public void setAge(String age) {
		this.age = age;
	}
	public void setWeight(String weight) {
		this.weight = weight;
	}
	public void setAcquisitionDate(String acquisitionDate) {
		this.acquisitionDate = acquisitionDate;
	}
	public void setAcquisitionLocation(String acquisitionCountry) {
		this.acquisitionCountry = acquisitionCountry;
	}
	public void setReserved(boolean reserved) {
		this.reserved = reserved;
	}
	public void setInServiceCountry(String inServiceCountry) {
		this.inServiceCountry = inServiceCountry;
	}
	public void setTrainingStatus(String trainingStatus) {
		this.trainingStatus = trainingStatus;
	}
}