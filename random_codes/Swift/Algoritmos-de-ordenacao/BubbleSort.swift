
/*
 The Bubble sort algorithm always traverses elements from left and moves the largest element
 to its correct position in first iteration and second largest in second iteration and so on.
 
 ****
 
  O algoritmo Bubble Sort é um algoritmo de ordenação que varre os elementos começando pela esquerda e movendo o maior valor para sua posição
 correta, depois repete o processo com o segundo maior elemento e assim por diante.
*/

import Foundation

func bubbleSort(_ array: [Int]) -> [Int] {
    var list = array
    for i in 0..<list.count {
        for j in 1..<list.count - i {
            if list[j] < list[j-1] {
                list.swapAt(j, j-1)
            }
        }
    }
    return list
}

// The code below can be used for testing

//var numbers = [2, -4, 4, 6, 1, 12, 9, 0]
//numbers = bubbleSort(numbers)
//print(numbers)
