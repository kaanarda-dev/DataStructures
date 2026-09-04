cmake_minimum_required(VERSION 3.10)

project(DataStructures C)

set(CMAKE_C_STANDARD 11)

add_executable(binarySearchTree
        BinarySearchTree/main.c
        BinarySearchTree/binarySearchTree.c
        BinarySearchTree/binarySearchTree.h
)