# Heap of Students Documentation

## UML diagram

```mermaid
classDiagram
direction TB
    class Student {
        - string name
    }

    class Address {
        - int zipCode
        - string street
        - string city
        - string state
    }

    class Dates {
        - int Day
        - int Month 
        - int Year
        + Dates()
        + DatesDestructor()
        + printDate(int Day, int Month, int Year)
        
        
    }

    Address --|> Student
    Dates --|> Student
```

