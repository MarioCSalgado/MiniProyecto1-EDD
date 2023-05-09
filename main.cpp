#include "ListArr.h"
#include <chrono>
#include <list>
#include <algorithm>
#include <iostream>


void tiempoListArrLeft(int numElements, int b, int reps){
  double total_time = 0;
    for (int i = 0; i < reps; i++) {
    ListArr listarr(b);
    auto start = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < numElements; j++) {
      listarr.insert_left(j);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    total_time += duration.count();
  }
  double average_time = total_time / reps;
  std::cout << "Tiempo promedio insert_left() con n=" << numElements << " y b=" << b
            << ": " << average_time << " microseconds" << std::endl;
}

void tiempoListArrRight(int numElements, int b, int reps){
  double total_time = 0;
    for (int i = 0; i < reps; i++) {
    ListArr listarr(b);
    auto start = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < numElements; j++) {
      listarr.insert_right(j);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    total_time += duration.count();
  }
  double average_time = total_time / reps;
  std::cout << "Tiempo promedio insert_right() con n=" << numElements << " y b=" << b
            << ": " << average_time << " microseconds" << std::endl;
}

void tiempoListArrFind(int numElements, int b, int reps, int buscar){
  double total_time = 0;
    for (int i = 0; i < reps; i++) {
    ListArr listarr(b);
    for (int j = 0; j < numElements; j++) {
      listarr.insert_right(j);
    }
    auto start = std::chrono::high_resolution_clock::now();
      listarr.find(buscar);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    total_time += duration.count();
  }
  double average_time = total_time / reps;
  std::cout << "Tiempo promedio find() con n=" << numElements << " y b=" << b
            << ": " << average_time << " microseconds" << std::endl;
}

/*********************************************************************/

void tiempoArregloLeft(int numElements, int reps){
  double total_time = 0;
    for (int i = 0; i < reps; i++) {
    int Arr[numElements];
    auto start = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < numElements; j++) {
      Arr[j]=j;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    total_time += duration.count();
  }
  double average_time = total_time / reps;
  std::cout << "Tiempo promedio Arreglo ingresando elementos por la izquierda con n=" << numElements<< ": "  << average_time << " microseconds" << std::endl;
}

void tiempoArregloRight(int numElements, int reps){
  double total_time = 0;
    for (int i = 0; i < reps; i++) {
    int Arr[numElements];
    auto start = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < numElements; j++) {
      Arr[numElements-j-1]=j;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    total_time += duration.count();
  }
  double average_time = total_time / reps;
  std::cout << "Tiempo promedio Arreglo ingresando elementos por la derecha con n=" << numElements << ": " << average_time << " microseconds" << std::endl;
}

void tiempoArregloFind(int numElements, int reps, int buscar) {
    double total_time = 0;

    for (int i = 0; i < reps; i++) {
        int Arr[numElements];
        for (int j = 0; j < numElements; j++) {
            Arr[j] = j;
        }

        auto start = std::chrono::high_resolution_clock::now();
        bool found = false;
        for (int j = 0; j < numElements && !found; j++) {
            if (Arr[j] == buscar) {
                found = true;
            }
        }
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        total_time += duration.count();
    }

    double average_time = total_time / reps;
    std::cout << "Tiempo promedio en el arreglo para buscar con n=" << numElements << ": " << average_time << "  microseconds" << std::endl;


}


/*******************************************************************************************/


void tiempoLkListLeft(int numElements, int reps){
  double total_time = 0;
    for (int i = 0; i < reps; i++) {
    std::list<int> linked_list;

    auto start = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < numElements; j++) {
      linked_list.push_front(j);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    total_time += duration.count();
  }
  double average_time = total_time / reps;
  std::cout << "Tiempo promedio en la LinkedList ingresando elementos por la izquierda con n=" << numElements << ": "  << average_time << "  microseconds" << std::endl;
}

void tiempoLkListRight(int numElements, int reps){
  double total_time = 0;
    for (int i = 0; i < reps; i++) {
    std::list<int> linked_list;

    auto start = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < numElements; j++) {
      linked_list.push_back(j);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    total_time += duration.count();
  }
  double average_time = total_time / reps;
  std::cout << "Tiempo promedio en la LinkedList ingresando elementos por la derecha con n=" << numElements<< ": "  << average_time << " microseconds" << std::endl;
}

void tiempoLkListFind(int numElements, int reps, int buscar) {
  double total_time = 0;
  for (int i = 0; i < reps; i++) {

    std::list<int> linked_list;

    for (int j = 0; j < numElements; j++) {
      linked_list.push_back(j);
    }

    auto start = std::chrono::high_resolution_clock::now();

    std::list<int>::iterator it = std::find(linked_list.begin(), linked_list.end(), buscar);
    //usamos lo anterior para buscar el elemento desde el inicio de la linkedlist hasta su final.

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    total_time += duration.count();
  }
  double average_time = total_time / reps;
  std::cout << "Tiempo promedio para buscar un elemento en una LinkedList de " << numElements << ": " << average_time << " microseconds" << std::endl;
}



int main() {
  int n,b,repetitions=20;
  

  //n=10000 y b variados
  printf("\n\n");
  n=10000, b=1;
  tiempoListArrLeft(n,b,repetitions);
  tiempoListArrRight(n,b,repetitions);
  tiempoListArrFind(n,b,repetitions, n/2);
  
  printf("\n\n");
  n=10000, b=64;
  tiempoListArrLeft(n,b,repetitions);
  tiempoListArrRight(n,b,repetitions);
  tiempoListArrFind(n,b,repetitions, n/2);

  printf("\n\n");
  n=10000, b=128;
  tiempoListArrLeft(n,b,repetitions);
  tiempoListArrRight(n,b,repetitions);
  tiempoListArrFind(n,b,repetitions, n/2);

  printf("\n\n");
  n=10000, b=256;
  tiempoListArrLeft(n,b,repetitions);
  tiempoListArrRight(n,b,repetitions);
  tiempoListArrFind(n,b,repetitions, n/2);

  //n=10000, para arreglos y LinkedList
  printf("\n\n");
  tiempoArregloLeft(n,repetitions);
  tiempoArregloRight(n,repetitions);
  tiempoArregloFind(n,repetitions,n/2);

  printf("\n\n");
  tiempoLkListLeft(n,repetitions);
  tiempoLkListRight(n,repetitions);
  tiempoLkListFind(n,repetitions,n/2);


  printf("\n\n\n");
  //n=100000 y b variados
  n=500000, b=1;
  tiempoListArrLeft(n,b,repetitions);
  tiempoListArrRight(n,b,repetitions);
  tiempoListArrFind(n,b,repetitions, n/2);

  printf("\n\n");
  n=500000, b=64;
  tiempoListArrLeft(n,b,repetitions);
  tiempoListArrRight(n,b,repetitions);
  tiempoListArrFind(n,b,repetitions, n/2);

  printf("\n\n");
  n=500000, b=128;
  tiempoListArrLeft(n,b,repetitions);
  tiempoListArrRight(n,b,repetitions);
  tiempoListArrFind(n,b,repetitions, n/2);

  printf("\n\n");
  n=500000, b=256;
  tiempoListArrLeft(n,b,repetitions);
  tiempoListArrRight(n,b,repetitions);
  tiempoListArrFind(n,b,repetitions, n/2);

  //n=100000, para arreglos y linkedlist
  printf("\n\n");
  tiempoArregloLeft(n,repetitions);
  tiempoArregloRight(n,repetitions);
  tiempoArregloFind(n,repetitions,n/2);

  printf("\n\n");
  tiempoLkListLeft(n,repetitions);
  tiempoLkListRight(n,repetitions);
  tiempoLkListFind(n,repetitions,n/2);

}
