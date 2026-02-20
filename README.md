# Heap of Students Documentation

## UML diagram

```mermaid
classDiagram
direction TB
    class Student {
        - string name
        + Student()
        + Student(name)
        + printStudent()
    }

    class Address {
        - string fullAddress
        - int zipCode
        - string street
        - string city
        - string state
        + Adress()
        + Address(fullAddress)
    }

    class Dates {
        - int fullDate
        - int Day
        - int Month 
        - int Year
        + Dates()
        + Dates(fullDate)
        + DatesDestructor()
        + printDate(int Day, int Month, int Year)
        
        
    }

    Address --|> Student
    Dates --|> Student
```

