/*************************************************************

NOMBRE: Roberto perez Zamora
FECHA: 26/02/24
PROGRAMA: Actividad de programacion - 8.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
DESCRIPCION:Elaborar un programa que realice las operaciones de dos conjuntos:

Inserción de valores por parte del usuario (arreglos o vectores)
Pueden ser textuales o numéricos
Borrado y edición de elementos
Vaciado de conjuntos
Operaciones de Unión, Intersección, Diferencia y complemento.

***************************/

// Librerias
#include <iostream>
#include <vector>
#include <algorithm>

// Funcion para insertar valores en un conjunto
void insertValues(std::vector<int>& set)
{
    int num;
    std::cout << "Valor a ingresar (0 para detener): ";
    while (std::cin >> num && num != 0)
    {
        set.push_back(num);
        std::cout << "Valor a ingresar (0 para detener): ";
    }
}


// Funcion para borrar elementos
void deleteElement(std::vector<int>& set, int element)
{
    auto it = std::find(set.begin(), set.end(), element);
    if (it != set.end())
    {
        set.erase(it);
        std::cout << "Elemento borrado." << std::endl;
    } else
    {
        std::cout << "Element no encontrado en este set." << std::endl;
    }
}


// Funcion para editar elementos
void editElement(std::vector<int>& set, int oldElement, int newElement)
{
    auto it = std::find(set.begin(), set.end(), oldElement);
    if (it != set.end())
    {
        *it = newElement;
        std::cout << "Elemento editado." << std::endl;
    } else
    {
        std::cout << "Elemento no encontrado en este set." << std::endl;
    }
}


// Funcion para vaciar un conjunto
void clearSet(std::vector<int>& set)
{
    set.clear();
    std::cout << "Set vaciado." << std::endl;
}


// Funcion paara imprimir conjunto
std::vector<int> unionSet(const std::vector<int>& set1, const std::vector<int>& set2)
{
    std::vector<int> result = set1;
    for (int num : set2)
    {
        if (std::find(result.begin(), result.end(), num) == result.end())
        {
            result.push_back(num);
        }
    }
    return result;
}


// Funcion para realizar la interseccion de dos conjuntos
std::vector<int> intersectionSet(const std::vector<int>& set1, const std::vector<int>& set2)
{
    std::vector<int> result;
    for (int num : set1)
    {
        if (std::find(set2.begin(), set2.end(), num) != set2.end())
        {
            result.push_back(num);
        }
    }
    return result;
}


// Funcion para realizar la diferencia de dos conjuntos
std::vector<int> differenceSet(const std::vector<int>& set1, const std::vector<int>& set2)
{
    std::vector<int> result;
    for (int num : set1)
    {
        if (std::find(set2.begin(), set2.end(), num) == set2.end())
        {
            result.push_back(num);
        }
    }
    return result;
}


// Funcion para realizar el complemento de un conjunto
std::vector<int> complementSet(const std::vector<int>& set, const std::vector<int>& universalSet)
{
    std::vector<int> result;
    for (int num : universalSet)
    {
        if (std::find(set.begin(), set.end(), num) == set.end())
        {
            result.push_back(num);
        }
    }
    return result;
}


// Funcion principal
int main()
{
    // Declarar conjuntos
    std::vector<int> set1, set2;
    std::vector<int> universalSet; // Replace with your own universal set if needed

    // Insertar valores en set1
    std::cout << "Insertar valor en primero set (set1):" << std::endl;
    insertValues(set1);

    // Insertar valores en set2
    std::cout << "Inertar valor en segundo set (set2):" << std::endl;
    insertValues(set2);

    // Ejecutar operaciones con los conjuntos
    std::vector<int> unionResult = unionSet(set1, set2);
    std::vector<int> intersectionResult = intersectionSet(set1, set2);
    std::vector<int> differenceResult = differenceSet(set1, set2);
    std::vector<int> complementResult = complementSet(set1, universalSet);

    // Mostrar resultados
    // Mostrar union
    std::cout << "Union: ";
    for (int num : unionResult)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Mostrar interseccion
    std::cout << "Interseccion: ";
    for (int num : intersectionResult)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Mostrar diferencia
    std::cout << "Diferencia (set1 - set2): ";
    for (int num : differenceResult)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Mostrar complemento
    std::cout << "Complemento de set1: ";
    for (int num : complementResult)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    //Regresar 0
    return 0;
}
