#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <wincrypt.h>
#include "common.h"

void studentRegistration();
void studentLogin();
void md5Hash(char *input, char *output);
void searchStudent();
void updateStudent();
void deleteStudent();

#endif