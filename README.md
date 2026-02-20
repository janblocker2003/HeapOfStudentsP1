# Heap of Students Documentation

## UML diagram

```mermaid
classDiagram
direction TB
    class Address {
	    - string street
	    - string city
	    - string state
	    - int zip
	    + Adress()
	    + init(street, city, state, zip)
	    + void printAddress()
    }

    class Date {
	    - int Month
        - int Day
	    - int Year
	    + Date()
	    + init(dateString)
	    + void printDate()
    }

    class Student {
	    - string firstName
	    - string lastName
        - Address: address
	    - Date: birthDate
	    - Date: gradDate
	    - int creditHours
	    + Student()
	    + init(string studentString)
	    + void printStudent()
	    + void getLastFirst() return string
    }

    Address <|-- Student
    Date <|-- Student
```

