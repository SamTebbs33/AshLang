namespace ash

protocol Throwable {

    func throw()

}

class SyntaxTest {

    /**
     * [A function that takes a SyntaxTest, returns a manipulated version of it and throws an Exception]
     * @type {[SyntaxTest]}
     */
    func foo(a : SyntaxTest) : SyntaxTest => Exception {

    }

}

class Exception : Throwable {

}
