public class Monkey extends RescueAnimal {
	
	 // Instance variable
    private String species;
    private String tailLength;
    private String height;
    private String bodyLength;

    // Constructor
    public Monkey(String name, String species, String tailLength, String height, String bodyLength, String gender, String age,
    String weight, String acquisitionDate, String acquisitionCountry,
	String trainingStatus, boolean reserved, String inServiceCountry) {
        setName(name);
        setSpecies(species);
        setTailLength(tailLength);
        setHeight(height);
        setBodyLength(bodyLength);
        setGender(gender);
        setAge(age);
        setWeight(weight);
        setAcquisitionDate(acquisitionDate);
        setAcquisitionLocation(acquisitionCountry);
        setTrainingStatus(trainingStatus);
        setReserved(reserved);
        setInServiceCountry(inServiceCountry);
       
    }

	public String getSpecies() {
		return species;
	}

	public void setSpecies(String monkeySpecies) {
		species = monkeySpecies;
	}

	public String getTailLength() {
		return tailLength;
	}

	public void setTailLength(String monkeyTailLength) {
		tailLength = monkeyTailLength;
	}

	public String getHeight() {
		return height;
	}

	public void setHeight(String monkeyHeight) {
		height = monkeyHeight;
	}

	public String getBodyLength() {
		return bodyLength;
	}

	public void setBodyLength(String monkeyBodyLength) {
		bodyLength = monkeyBodyLength;
	}
}
