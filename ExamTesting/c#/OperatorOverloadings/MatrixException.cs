using System;

namespace OperatorOverloadings
{
    class MatrixException : Exception
    {
        public MatrixException(){}
        public MatrixException(string text) : base(text){}
        public MatrixException(string text, Exception inner) : base(text,inner){}
    }
}
