namespace stdlib.Tests
import stdlib.Tester

class Person(name : String, age : Int) : Object, PNamed{

	public var ageType : EAge
	
	public func toString() : String{
		
	}

}

protocol PNamed {

	public var name : String
	public var age : Int

}

enum EAge {
	BABY, TODDLER, CHILD, TEEN, ADULT

	public static func toAgeType(age : Int){
		var temp = true ? 5+4 : 10
		var temp2 : Int
	}

}
