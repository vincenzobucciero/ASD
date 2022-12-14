cmake_minimum_required(VERSION 3.24)
project(ASD)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(cmake-build-debug)
include_directories(HelloWorld)
include_directories(ExOverloading)
include_directories(IOstring)
include_directories(Indovinello)
include_directories(ExAlias)
include_directories(ExString)
include_directories(RispettaiVersi)
include_directories(Polimorfismo)
include_directories(OverloadOperator)
include_directories(LinkedList)
include_directories(Template)
include_directories(BlockChain)
include_directories(ExVector)
include_directories(ExIterator)
include_directories(ExList)
include_directories(ExMap)

add_executable(ASD
        Indovinello/Contenitore.h Indovinello/Anfora.h Indovinello/Indovinello.h
        RispettaiVersi/Checker.h
        Polimorfismo/Polymorf.h
        Polimorfismo/Persona.h
        OverloadOperator/Operator+.h
        LinkedList/Node.h LinkedList/LinkedList.h LinkedList/Impiegato.h LinkedList/Manager.h
        Template/Stack.h
        BlockChain/Transazione.h BlockChain/Node.h BlockChain/LinkedList.h BlockChain/Block.h
        ExVector/Vector.cpp
        ExIterator/Iterator.cpp
        ExList/List.cpp
        ExMap/Map.cpp
        GiocoDel15/Gioco.cpp GiocoDel15/Checker.h GiocoDel15/fileOne.txt GiocoDel15/fileTwo.txt)
