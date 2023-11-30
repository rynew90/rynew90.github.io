import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;
import java.util.InputMismatchException;

public class Driver {
	
    private static ArrayList<Dog> dogList = new ArrayList<Dog>(); //This array list will store the dogs
    private static ArrayList<Monkey> monkeyList = new ArrayList<Monkey>(); //This array list will store the monkeys
    private static Scanner scnr = new Scanner(System.in); //initializing scanner
    
    // Main method
    public static void main(String[] args) {
        	
    	// Add a loop that displays the menu, accepts the users input
        boolean exit = false; //sentinel variable. will terminate the program when value is true
        
        while(!exit){ //this loop will keep displaying the menu and asking the user's input until user has entered 'q'
        	displayMenu();
            char option = scnr.next().charAt(0);
            if(option=='1'){ // Intake new dog option
                intakeNewDog();
            }else if(option=='2'){ // Intake new monkey option
                intakeNewMonkey();
            }else if(option=='3'){ // Reserve animal option
                reserveAnimal();
            }else if(option=='4'){ // Print sorted list of dogs
                printAnimals("dog");
            }else if(option=='5'){ // Print sorted list of monkeys
                printAnimals("monkey");
            }else if(option=='6'){ // Print sorted list of available animals
                printAnimals("available");
            }else if(option=='q'){ // quit application
                exit = true;
            }
            else {
         	   System.out.print("Enter a valid input.");
            }
        }
    }
    
    // This method prints the menu options
    public static void displayMenu() {
        System.out.println("\n");
        System.out.println("\t\t\tRescue Animal System Menu");
        System.out.println("[1] Intake a new dog");
        System.out.println("[2] Intake a new monkey");
        System.out.println("[3] Reserve an animal");
        System.out.println("[4] Print a list of all dogs");
        System.out.println("[5] Print a list of all monkeys");
        System.out.println("[6] Print a list of all animals that are not reserved");
        System.out.println("[q] Quit application");
        System.out.println();
        System.out.println("Enter a menu selection");
    }

    // Method to intake new dog instance
    public static void intakeNewDog() {
    	boolean reserved = false;
    	String validInput = ""; //for InputMismatchException handling
    	
        System.out.println("Enter dog's name: ");
        String name = scnr.nextLine(); // Input for dog name
        
        for (Dog dog : dogList) {
            if (dog.getName().equalsIgnoreCase(name)) {
                System.out.println("\n\nThis dog is already in our system\n\n");
                return; //returns to menu
            }
        }        
        
        // Code to instantiate a new dog and add it to the list
        System.out.println("Enter dog's breed: ");
        String breed = scnr.nextLine(); // Input for monkey name
        
        System.out.println("Enter dog's gender: ");
        String gender = scnr.nextLine(); // Input for monkey name
        
        try { // Exception handling for invalid input.
        	if (!gender.equals("male") && !gender.equals("female")) { // Only male and female acceptable
        		throw new Exception ("Enter male or female.");
        	}
        }
        catch (Exception exc) {
        	System.out.println(exc.getMessage());
        	scnr.nextLine();
        }
        
        System.out.println("Enter dog's age: ");
        String age = scnr.nextLine(); // Input for age
        
        System.out.println("Enter dog's weight: ");
        String weight = scnr.nextLine(); // Input for weight
        
        System.out.println("Enter dog's acquisition date: ");
        String acquisitionDate = scnr.nextLine(); // Input for acquisition date
        
        System.out.println("Enter dog's acquisition country: ");
        String acquisitionCountry = scnr.nextLine(); // Input for acquisition country
        
        System.out.println("Enter dog's training status: ");
        String trainingStatus = scnr.nextLine(); // Input for training status
        
        if (!trainingStatus.equals("intake") && !trainingStatus.equals("Phase I") && !trainingStatus.equals("Phase II") && !trainingStatus.equals("Phase III") &&
        		!trainingStatus.equals("Phase IV") && !trainingStatus.equals("Phase V")) { // Acceptable training status types
        	System.out.println("Enter a valid training status.");
        	scnr.next();
        }
        
        System.out.println("Enter dog's reservation status [true or false]: ");
        validInput = scnr.next(); // Input for reservation status
        
        try { //Exception handling for InputMismatchException
        	if (!validInput.equals("true") && !validInput.equals("false")) { // Only boolean values acceptable  	
        		throw new InputMismatchException("Enter true or false."); 
        	}
        	reserved = Boolean.parseBoolean(validInput);
        }
        catch (InputMismatchException exc) { 
        	System.out.println(exc.getMessage());
        	reserved = scnr.nextBoolean();
        }        
        
        System.out.println("Enter dog's service country: ");
        String inServiceCountry = scnr.next(); // Input for monkey name
        
        // Add new dog to the ArrayList
        dogList.add(new Dog(name, breed, gender, age, weight, acquisitionDate, acquisitionCountry, trainingStatus, reserved, inServiceCountry));        	               
             
    }
    
    // Method to intake new monkey instance
    public static void intakeNewMonkey() {
    	boolean reserved = false;
    	String validInput = ""; //for InputMismatchException handling
    	
        System.out.println("Enter monkey's name:");
        String name = scnr.nextLine(); // Input for monkey name
        
        for(Monkey monkey : monkeyList) { // Iterate through monkeyList ArrayList
            if(monkey.getName().equalsIgnoreCase(name)) { // If monkey name already exists
                System.out.println("\n\nThis monkey is already in our system\n\n");
                return; //returns to menu
            }
        }
        
        // Code to instantiate a new monkey and add it to the list 
        System.out.println("Enter monkey's species: ");
        String species = scnr.nextLine().toLowerCase(); // Input for monkey species
        
        if(!species.equals("capuchin") && !species.equals("guenon") && !species.equals("macaque")
                && !species.equals("marmoset") && !species.equals("squirrel monkey") && !species.equals("tamarin")){ // Acceptable species types
            System.out.println("\n\nThis monkey is not eligible for training\n\n");
            return;
        }
        
        System.out.println("Enter monkey's tail length: ");
        String tailLength = scnr.nextLine(); // Input for tail length
        
        System.out.println("Enter monkey's height: ");
        String height = scnr.nextLine(); // Input for tail length
        
        System.out.println("Enter monkey's body length: ");
        String bodyLength = scnr.nextLine(); // Input for tail length
        
        System.out.println("Enter monkey's gender: ");
        String gender = scnr.nextLine(); // Input for tail length
        
        try { //Error handling for input type
        	if (!gender.equals("male") && !gender.equals("female")) { // Only male and female acceptable
        		throw new Exception ("Enter male or female.");
        	}
        }
        catch (Exception exc) {
        	System.out.println(exc.getMessage());
        	scnr.nextLine();
        }
        
        System.out.println("Enter monkey's age: ");
        String age = scnr.nextLine(); // Input for tail length
        
        System.out.println("Enter monkey's weight: ");
        String weight = scnr.nextLine(); // Input for weight
        
        System.out.println("Enter monkey's acquisition date: ");
        String acquisitionDate = scnr.nextLine(); // Input for acquisition date
        
        System.out.println("Enter monkey's acquisition country: ");
        String acquisitionCountry = scnr.nextLine(); // Input for acquisition country
        
        System.out.println("Enter monkey's training status: ");
        String trainingStatus = scnr.nextLine(); // Input for training status
        
        if (!trainingStatus.equals("intake") && !trainingStatus.equals("Phase I") && !trainingStatus.equals("Phase II") && !trainingStatus.equals("Phase III") &&
        		!trainingStatus.equals("Phase IV") && !trainingStatus.equals("Phase V")) { // Error handling for acceptable training status
        	System.out.println("Enter a valid training status.");
        	scnr.next();
        }
        
        System.out.println("Enter monkey's reservation status [true or false]: ");
        validInput = scnr.next(); // Input for reservation status
        
        try { //Exception handling for InputMismatchException
        	if (!validInput.equals("true") && !validInput.equals("false")) { // Only boolean values acceptable       	
        		throw new InputMismatchException("Enter true or false."); 
        	}
        	reserved = Boolean.parseBoolean(validInput);
        }
        catch (InputMismatchException exc) { 
        	System.out.println(exc.getMessage());
        	reserved = scnr.nextBoolean();
        }
        
        System.out.println("Enter monkey's service country: ");
        String inServiceCountry = scnr.nextLine(); // Input for service country
        
        // Add new monkey to ArrayList
        monkeyList.add(new Monkey(name, species, tailLength, height, bodyLength, gender, age, weight, acquisitionDate, acquisitionCountry, trainingStatus, reserved, 
        		inServiceCountry)); 
        
    }
    
    // Method to reserve an animal
    public static void reserveAnimal() {
        System.out.println("Enter animal type: [Dog or Monkey]");
        String type = scnr.next().toLowerCase(); // Set input to lower case
        if(!type.equals("dog") && !type.equals("monkey")){ // If type is not dog or monkey
            System.out.println("Invalid input"); // Only dog and monkey are valid inputs
            return;
        }
        
        if(type.equals("dog")){ // If dog
        	System.out.println("Enter animal name: ");
            String name = scnr.next(); // Input for dog name
            for(int i=0; i<dogList.size(); i++){ // For loop to iterate over dogList ArrayList
                if(dogList.get(i).getName().equals(name) && !dogList.get(i).getReserved()){ // If dog name exists and is not reserved
                    System.out.println(dogList.get(i).getName() + " successfully reserved.");
                    dogList.get(i).setReserved(true); // Reserve dog successful
                    return;
                }
                else {
                	System.out.println("Animal not registered");
                }
            }
        }else if (type.equals("monkey")){ // If monkey
        	System.out.println("Enter animal name: ");
            String name = scnr.next(); // Input for monkey name
            for(int i=0; i<monkeyList.size(); i++){ // For loop to iterate over monkeyList ArrayList
                if(monkeyList.get(i).getName().equals(name) && !monkeyList.get(i).getReserved()){ // If monkey name exists and is not reserved
                    System.out.println(monkeyList.get(i).getName() + " successfully reserved.");
                    monkeyList.get(i).setReserved(true); // Reserve monkey successful
                    return;
                }
                else {
                	System.out.println("Animal not registered");
                }
            }
        }
    }
    
    // Method to call merge sorting algorithm and print sorted list of dogs
    public static void sortDogs() {
    	mergeSortList(dogList, Comparator.comparing(Dog::getName)); // Call mergeSortList() for dogs
    	
    	System.out.println("List of dogs: ");
        for(Dog dog: dogList){ // Iterate through monkeyList ArrayList
            System.out.println(dog.getName() + "\t" + dog.getTrainingStatus() + "\t" + dog.getAcquisitionLocation() + "\t" + dog.getReserved());
        }
    }
    
    // Method to call merge sorting algorithm and print sorted list of monkeys
    public static void sortMonkeys() {
    	mergeSortList(monkeyList, Comparator.comparing(Monkey::getName)); // Call mergeSortList() for monkeys
    	
    	System.out.println("List of monkeys: ");
        for(Monkey monkey: monkeyList){ // Iterate through monkeyList ArrayList
            System.out.println(monkey.getName() + "\t" + monkey.getTrainingStatus() + "\t" + monkey.getAcquisitionLocation() + "\t" + monkey.getReserved());
        }
    }
    
    // Method to call merge sorting algorithm and print sorted list of available animals
    public static void sortAvailable() {
    	mergeSortList(dogList, Comparator.comparing(Dog::getName)); // Call mergeSortList() for dogs
    	mergeSortList(monkeyList, Comparator.comparing(Monkey::getName)); // Call mergeSortList() for monkeys
    	
    	System.out.println("List of available animals: ");
    	System.out.println("Dogs:");
        for(Dog dog: dogList){ // Iterate through monkeyList ArrayList
            if(!dog.getReserved()) { // If dog is reserved
                System.out.println(dog.getName() + "\t" + dog.getTrainingStatus() + "\t" + dog.getAcquisitionLocation() + "\t" + dog.getReserved());
            }
        }
        
        System.out.println("Monkeys:");
        for(Monkey monkey: monkeyList){ // Iterate through monkeyList ArrayList
            if(!monkey.getReserved()) { // If monkey is reserved
                System.out.println(monkey.getName() + "\t" + monkey.getTrainingStatus() + "\t" + monkey.getAcquisitionLocation() + "\t" + monkey.getReserved());
            }
        }
    }

    //Method to print animals
    public static void printAnimals(String type) {

        if(type.toLowerCase().equals("dog")){ // If print dogs requested
        	sortDogs(); // Call sortDogs()
        }
        
        else if(type.toLowerCase().equals("monkey")){ // If print monkeys requested
        	sortMonkeys(); // Call sortMonkeys()
        }
        
        else if(type.toLowerCase().equals("available")){ // If print available animals requested
        	sortAvailable(); // Call sortAvailable()
        }
    }
    
    // Method to perform merge sort on a list of animals
    private static <T> void mergeSortList(ArrayList<T> list, Comparator<? super T> comparator) {
    	if (list.size() > 1) { // If list size is less than 1
            int mid = list.size() / 2; // Assign mid the value of half the list size

            ArrayList<T> leftList = new ArrayList<>(list.subList(0, mid)); // Left side of merge sort
            ArrayList<T> rightList = new ArrayList<>(list.subList(mid, list.size())); // Right side of merge sort
            
            // Recursively sorts left and right half of ArrayList
            mergeSortList(leftList, comparator);
            mergeSortList(rightList, comparator);

            merge(list, leftList, rightList, comparator); // merge both sorted halves of the ArrayList
        }
    }

    // Method to merge two lists of animals
    private static <T> void merge(ArrayList<T> arr, ArrayList<T> left, ArrayList<T> right, Comparator<? super T> comparator) {
    	int i = 0, j = 0, k = 0;

        while (i < left.size() && j < right.size()) { // Loop to merge elements from left and right half of ArrayList
            if (comparator.compare(left.get(i), right.get(j)) <= 0) {
                arr.set(k++, left.get(i++));
            } else {
                arr.set(k++, right.get(j++));
            }
        }
        
        // Merge remaining items from left side of ArrayList
        while (i < left.size()) {
            arr.set(k++, left.get(i++));
        }
        
        // Merge remaining items from right side of ArrayList
        while (j < right.size()) {
            arr.set(k++, right.get(j++));
        }
    }

}