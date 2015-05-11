# Language ideas
* Default function parameter values
    * **func add(x : int, y : int = 1) = x + y**
* Single-statement functions
    * **func square(x : int) : int = x * x**
    * Type inferred: **func double(x : int) = x * 2**
* Variable parameters
    * **func print(names : String...)**
* Functions as first-class citizens
    * **func foo(fn : (int) -> int, x : int)**
    * **fn** is used in place of a func that takes an int and returns an in
* Type extensions
* Boolean expressions and sequences in case statements
    * **case > 0:**
    * **case 3..9:**
    * **case 'a'..'z':**
* Not-null operator
    * **var a = b ?? c**
    * If b is not null, it is assigned to a. Otherwise, c is assigned to a
* Optional types
    * **var name : String = "Sam"**
    * name cannot be null
    * **var otherName : String?**
    * otherName can be null
* Closed-blocks that take a variable and at the end of the block, call .close() on the variable.
