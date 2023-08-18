/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** hey. real programmers use vim
*/

#ifndef CSFML_VERSION_H_
#define CSFML_VERSION_H_


#include <SFML/System.h>

#if CSFML_VERSION_MAJOR != 2
    #if CSFML_VERSION_MINOR != 5
        #error "ERROR ! This project can only be built with CSFML 2.5\n"
    #endif
#endif

#endif