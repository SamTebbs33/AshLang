namespace ash.tests

public class Constants {

	// The first eleven digits of Pi. The type inferred is float64
	public static const pi = 3.14159265359
	// Euler's constant
	public static const e : float64 = 0.5772156649
	// Speed of light in ms^-1
	public static const c : int = 299792458

}

// A named object
public protocol PNamed {
	public var name : String
}

public protocol PAged {
	public var age : uint
}

// Person implements PNamed's name variable via the default constructor
public class Person(name : String, age : uint) : PAged, PNamed {

	public func getFullName() : String {
		return name + " " + surname
	}

}

public class Teacher(name : String, age : uint, title : String) : Person {

	override public getFullName() : String {
		return title + " " + super.getFullName()
	}

}
