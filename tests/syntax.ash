namespace stdlib.Tests
import stdlib.Tester

// Class that extends Object and implements PNamed
class Person(name : String, age : Int) : Object, PNamed{

	/* Public variable
	of type EAge */
	public var ageType : EAge
	var ch = 'c'
	
	// Function that throws and Exception
	public func toString() : String -> Exception{
		
	}

}

protocol PNamed {
	
	// Uninitialised protocol variables
	public var name : String
	public var age : Int

}

enum EAge {

	/* Instances if EAge */
	BABY, TODDLER, CHILD, TEEN, ADULT

	public static func toAgeType(age : Int){
		var temp = true ? 5+4 : 10
		var temp2 : Int
	}

}
