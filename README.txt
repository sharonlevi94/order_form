1. OOP 2 ex. 2:
//----------------------------------------------------------------------------
2. Creators:
a- Sharon Levi  
b- Bar Ifrah      
//----------------------------------------------------------------------------
3. General ideas and goals of the project
The main goal here is to work with Templates. Here, we create a hotel order,
via Terminal, that takes input from the user- such as name, id, arrival etc..
validates the data, and if something's wrong, it tells the user what's wrong
and where, and gives the user the opportunity to fix it (over and over until
its ok) and will show an error regarding the invalid field.
when all user input fields are ok, the program prints all of the
order data, and exits.

input example:
marked with '#' is the input.
marked with '*' is an example of an error.
-------------------------------------------------------------------------
What is your name? = #Keren
-------------------------------------------------------------------------
-------------------------------------------------------------------------
What is your ID? = #543700421
-------------------------------------------------------------------------
-------------------------------------------------------------------------
What is your year of birth? = #1990
-------------------------------------------------------------------------
-------------------------------------------------------------------------
What is the date on which you wish to start your vacation? (dd/mm/yyyy) = #01062021
-------------------------------------------------------------------------
-------------------------------------------------------------------------
How many nights do you wish to invite? = #4
-------------------------------------------------------------------------
-------------------------------------------------------------------------
How many pair rooms do you want? = #2    **The maximum is 10 rooms
-------------------------------------------------------------------------
-------------------------------------------------------------------------
How many family rooms do you want? = #2
-------------------------------------------------------------------------
-------------------------------------------------------------------------
How many people? = #14
-------------------------------------------------------------------------
-------------------------------------------------------------------------
Number of children under 18? = #6
-------------------------------------------------------------------------
-------------------------------------------------------------------------
Number of adults over 18? = #8
-------------------------------------------------------------------------


//----------------------------------------------------------------------------
4. Files:
-main.cpp
Headers:
-Form.h - form controller
-FieldBase.h Template class to use in the vector of fields (IN FORM.H)
-Field.h

-Validator.h    all classes below inherits from this class.
-IDValidator.h
-NoDigitValidator.h
-NonNegativeValidator.h
-NotGreaterThanValidator.h
-RangeValidator.h
-DateValidator.h

-FormValidator.h    all classes below inherits from this class.
-RoomValidator.h
-SumValidator.h

macros.h

-CMakeLists.txt - To all headers

Resources:

-Form.h - form controller
-Field.h

-Validator.cpp    all classes below inherits from this class.
-IDValidator.cpp
-NoDigitValidator.cpp
-NonNegativeValidator.cpp
-NotGreaterThanValidator.cpp
-RangeValidator.cpp
-DateValidator.cpp

-FormValidator.cpp    all classes below inherits from this class.
-RoomValidator.cpp
-SumValidator.cpp
//----------------------------------------------------------------------------
5. Data structures :
vectors of unique pointers. holds all field pointers in "Form" class

//----------------------------------------------------------------------------
6. Algorithms that are worth mentioning:
-NONE
//----------------------------------------------------------------------------
7. Known bugs:
//----------------------------------------------------------------------------
8. Other notes:
this program runs only via terminal. if you really wanna book an hotel-
go to Hotels.com. prices are cheaper than here too.
