#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/// @brief Compara dos enteros y retorna otro entero que permite saber
///        si son iguales
/// @param d1
/// @param d2
/// @return -1 si `d2` es mayor, 0 si son iguales, 1 si `d1` es mayor
int compararInt(void * d1, void * d2);

/// @brief Compara dos char* y retorna otro entero que permite saber
///        si son iguales
/// @param d1
/// @param d2
/// @return -1 si `d2` es mayor, 0 si son iguales, 1 si `d1` es mayor
int compararChar(void * d1, void * d2);

/// @brief Compara dos flotantes y retorna otro entero que permite saber
///        si son iguales
/// @param d1
/// @param d2
/// @return -1 si `d2` es mayor, 0 si son iguales, 1 si `d1` es mayor
int compararFloat(void * d1, void * d2);

/// @brief Valida si `d1` y `d2` tienen como valor `NULL`
/// @param d1
/// @param d2
void chequearParametros(void * d1, void * d2);

#endif // FUNCIONES_H_INCLUDED
