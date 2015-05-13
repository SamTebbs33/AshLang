namespace ash

protocol Throwable {
    func throw()
}

class SyntaxTest {

    // A function that returns an object of SyntaxTest and throws an object of Exception
    func foo(a : SyntaxTest) : SyntaxTest => Exception {

    }
}

class Exception : Throwable{

}
