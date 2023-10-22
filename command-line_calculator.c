//*****************************************************************************
//*                                                                           *
//* Name:         Alyssa Cabana                                               *
//* Student ID:   110108861                                                   *
//* Program Name: command-line_calculator.c                                                    *
//* Date:         2022-11-30                                                  *
//* Desc:         Command-line calculator that completes binary and unary     *
//*               mathematical operations, and allows the user to create      *
//*               variables to use throughout the code.                       *
//*                                                                           *
//*****************************************************************************
#include <math.h>  // C standard library for basic mathematical operations.
#include <stdio.h> // C standard library. Allows the use of printf or scanf functions in the program.
#include <stdlib.h> // C General purpose standard library. This includes functions involving memory allocation.
#include <string.h> // C standard library.

//*****************************************************************************
//*                                                                           *
//* Method Name:    num_validator()                                           *
//* Method Inputs:  None                                                      *
//* Method Outputs: float                                                     *
//* Desc:           This method validates the users input. In other word      *
//*                 it makes sure that it is a float.                         *
//*                                                                           *
//*****************************************************************************
float num_validator() {
  char output = '?';
  float num;
  while (output == '?') {
    int decimal = 0, character = 0, negative = 0;
    char str[1000];
    printf("Please enter the first number:\n");
    scanf("%s", str);
    num = atof(str);

    for (int i = 0; i < strlen(str); i++) {
      if (!((str[i] >= '0') && str[i] <= '9')) {
        if (str[i] == '.') {
          decimal++;
        } else if (str[i] == '-') {
          negative++;
        } else {
          character++;
        }
      }
    }
    if (character || decimal > 1) {
      printf("Your input is invalid. ");
    } else if (negative > 1) {
      printf("Your input is invalid. ");
    } else {
      output = '!';
    }
  }
  return num;
}

//*****************************************************************************
//*                                                                           *
//* Method Name:    operation_validator_b()                                   *
//* Method Inputs:  None                                                      *
//* Method Outputs: char                                                      *
//* Desc:           This method validates the users input. In other word      *
//*                 it makes sure that it is a char for the method B.         *
//*                                                                           *
//*****************************************************************************
char operation_validator_b() {
  char operation;
  int check = 0;
  while (check == 0) {
    printf("Please enter the operation ( + , - , * , / , % , P (power), X "
           "(maximum), I (minimum)):\n");
    scanf("%s", &operation);
    if (sizeof(operation) == 1) {
      switch (operation) {
      case '+':
        check = 1;
        break;
      case '-':
        check = 1;
        break;
      case '*':
        check = 1;
        break;
      case '/':
        check = 1;
        break;
      case '%':
        check = 1;
        break;
      case 'P':
        check = 1;
        break;
      case 'X':
        check = 1;
        break;
      case 'I':
        check = 1;
        break;
      default:
        printf("Your input is invalid. Please keep in mind that letters must "
               "be capitalized.\n");
        break;
      }
    } else {
      printf("Your input is invalid. ");
    }
  }
  return operation;
}

//*****************************************************************************
//*                                                                           *
//* Method Name:    operation_validator_u()                                   *
//* Method Inputs:  None                                                      *
//* Method Outputs: char                                                      *
//* Desc:           This method validates the users input. In other word      *
//*                 it makes sure that it is a char for the method U.         *
//*                                                                           *
//*****************************************************************************
char operation_validator_u() {
  char operation;
  int check = 0;
  while (check == 0) {
    printf("Please enter the operation ( S (for square root), L (for "
           "logarithm), E (for exponential), C (for ceil), F (for floor):\n");
    scanf("%s", &operation);
    if (sizeof(operation) == 1) {
      switch (operation) {
      case 'S':
        check = 1;
        break;
      case 'L':
        check = 1;
        break;
      case 'E':
        check = 1;
        break;
      case 'C':
        check = 1;
        break;
      case 'F':
        check = 1;
        break;
      default:
        printf("Your input is invalid. Please keep in mind that letters must "
               "be capitalized.\n");
        break;
      }
    } else {
      printf("Your input is invalid. ");
    }
  }
  return operation;
}

//*****************************************************************************
//*                                                                           *
//* Method Name:    calculation_b                                             *
//* Method Inputs:  float, char, and float                                    *
//* Method Outputs: float                                                     *
//* Desc:           This method takes 2 numbers inputed by the user, and      *
//*                 either adds, subtracts, multiplies, or divides them. It   *
//*                 then prints the answer out on screen and the method ends. *
//*                 (I added this method to make the main method less         *
//*                 cluttered).                                               *
//*                                                                           *
//*****************************************************************************
float calculation_b(float num1, char operation,
                    float num2) { // Creates method calculation_b.
  float answer;                   // Creates the float answer.
  char output = '?'; // Creates the character output and sets it equal to '?'.
  int check = 0;     // Creates the integer check and sets it equal to 0.

  //*****************************************************************************
  //* *
  //*                             Calculations *
  //* *
  //*****************************************************************************
  switch (operation) {    // Creates switch for operation.
  case '+':               // Creates case for '+' (runs if operation ='s '+').
    answer = num1 + num2; // Sets answer = to num1+num2.
    printf("The result is %f\n", answer); // Prints out the statment "The result is", along with the float answer.
    break;  // Terminates the execution. In other words exits the switch.
  case '-': // Creates case for '-' (runs if operation ='s '-').
    answer = num1 - num2;                 // Sets answer = to num1-num2.
    printf("The result is %f\n", answer); // Prints out the statment "The result
                                          // is", along with the float answer.
    break;  // Terminates the execution. In other words exits the switch.
  case '*': // Creates case for '*' (runs if operation ='s '*').
    answer = num1 * num2;                 // Sets answer = to num1*num2.
    printf("The result is %f\n", answer); // Prints out the statment "The result
                                          // is", along with the float answer.
    break;         // Terminates the execution. In other words exits the switch.
  case '/':        // Creates case for '/' (runs if operation ='s '/').
    if (num2 == 0) // Create if statement that will run if num2 equals 0.
    {              // Start if statement.
      printf("0 is an invalid number when dividing. ");
      num2 = num_validator();
      answer = num1 / num2; // Sets answer = to num1/num2.
      printf("The result is %f\n",
             answer); // Prints out the statment "The result is", along with the
                      // float answer.
    }                 // Ends if statement.
    else              // Creates else statement.
    {                 // Starts else.
      answer = num1 / num2; // Sets answer = to num1/num2.
      printf("The result is %f\n",
             answer); // Prints out the statment "The result is", along with the
                      // float answer.
    }                 // Ends else.
    break;  // Terminates the execution. In other words exits the switch.
  case '%': // Creates case '%'.
    answer = remainder(num1, num2);       // Sets answer equal to the remainder.
    printf("The result is %f\n", answer); // Prints out the statment "The result
                                          // is", along with the float answer.
    break;  // Terminates the execution. In other words exits the switch.
  case 'P': // Creates case 'P'.
    answer = pow(num1, num2); // Sets answer equal to the power of num1 to num2.
    printf("The result is %f\n", answer); // Prints out the statment "The result
                                          // is", along with the float answer.
    break;  // Terminates the execution. In other words exits the switch.
  case 'X': // Creates case 'X'.
    answer = (num1 > num2) ? num1 : num2; // Sets answer to the maximum.
    printf("The result is %f\n", answer); // Prints out the statment "The result
                                          // is", along with the float answer.
    break;  // Terminates the execution. In other words exits the switch.
  case 'I': // Creates case 'I'.
    answer = (num1 > num2) ? num2 : num1; // Sets answer equal to the minimum.
    printf("The result is %f\n", answer); // Prints out the statment "The result
                                          // is", along with the float answer.
    break;       // Terminates the execution. In other words exits the switch.
  }              // Ends switch.
  return answer; // Returns nothing.
} // Ends method.

//*****************************************************************************
//*                                                                           *
//* Method Name:    calculation_u                                             *
//* Method Inputs:  None                                                      *
//* Method Outputs: float                                                     *
//* Desc:           This method takes 1 number input and performs unary       *
//*                 operations.                                               *
//*                                                                           *
//*****************************************************************************
float calculation_u(float num, char operation) { // Creates method calculation_u.
  float answer;           // Creates the float answer.
  char output = '?'; // Creates the character output and sets it equal to '?'.
  int check = 0;     // Creates the integer check and sets it equal to 0.

  //*****************************************************************************
  //* *
  //*                             Calculations *
  //* *
  //*****************************************************************************
  switch (operation) {
  case 'S':
    if (num < 0) {
      printf("Negative numbers are invalid when using square root. ");
      output = '?';
      while (output == '?') {
        int decimal = 0, character = 0, negative = 0;
        char str[1000];
        printf("Please enter another number:\n");
        scanf("%s", str);
        num = atof(str);

        for (int i = 0; i < strlen(str); i++) {
          if (!((str[i] >= '0') && str[i] <= '9')) {
            if (str[i] == '.') {
              decimal++;
            } else if (str[i] == '-') {
              negative++;
            } else {
              character++;
            }
          }
        }
        if (character || decimal > 1) {
          printf("Your input is invalid. ");
        } else if (negative > 0) {
          printf("Your input is invalid. ");
        } else {
          output = '!';
        }
        answer = sqrt(num);
        printf("The result is %f\n", answer);
      }
    } else {
      answer = sqrt(num);
      printf("The result is %f\n", answer);
    }
    break;
  case 'L':
    if (num <= 0) {
      printf("Negative numbers and 0 are invalid when using logarithms. ");
      output = '?';
      while (output == '?') {
        int decimal = 0, character = 0, negative = 0;
        char str[1000];
        printf("Please enter another number:\n");
        scanf("%s", str);
        num = atof(str);

        for (int i = 0; i < strlen(str); i++) {
          if (!((str[i] >= '1') && str[i] <= '9')) {
            if (str[i] == '.') {
              decimal++;
            } else if (str[i] == '-') {
              negative++;
            } else {
              character++;
            }
          }
        }
        if (character || decimal > 1) {
          printf("Your input is invalid. ");
        } else if (negative > 0) {
          printf("Your input is invalid. ");
        } else {
          output = '!';
        }
        answer = log10(num);
        printf("The result is %f\n", answer);
      }
    } else {
      answer = log10(num);
      printf("The result is %f\n", answer);
    }
    break;
  case 'E':
    answer = exp(num);
    printf("The result is %f\n", answer);
    break;
  case 'C':
    answer = ceil(num);
    printf("The result is %f\n", answer);
    break;
  case 'F':
    answer = floor(num);
    printf("The result is %f\n", answer);
    break;
  }
  return answer;
}

//*****************************************************************************
//*                                                                           *
//* Method Name:    calculation_v                                             *
//* Method Inputs:  float, and char                                           *
//* Method Outputs: float                                                     *
//* Desc:           Get a single alphabetic character for the name of a       *
//*                 variable and a number as its initial value.               *
//*                                                                           *
//*****************************************************************************
float calculation_v(void) { // Creates method calculation_v.
  float num;              // Creates the float num.
  char name;              // Creates the character name.
  char output = '?'; // Creates the character output and sets it equal to '?'.
  int check = 0;     // Creates the integer check and sets it equal to 0.

  //*****************************************************************************
  //* *
  //*                             Name Validation *
  //* *
  //*****************************************************************************
  while (check == 0) {
    printf("Please enter the variable name, which should be a single "
           "alphabetic character between 'a' to 'e':\n");
    scanf("%s", &name);
    if (sizeof(name) == 1) {
      switch (name) {
      case 'a':
        check = 1;
        break;
      case 'b':
        check = 1;
        break;
      case 'c':
        check = 1;
        break;
      case 'd':
        check = 1;
        break;
      case 'e':
        check = 1;
        break;
      default:
        printf("Your input is invalid. Please keep in mind that letters are "
               "not capitalized.\n");
        break;
      }
    } else {
      printf("Your input is invalid. ");
    }
  }

  //*****************************************************************************
  //* *
  //*                             Num Validation *
  //* *
  //*****************************************************************************
  while (output == '?') {
    int decimal = 0, character = 0, negative = 0;
    char str[1000];
    printf("Please enter a number as the initial value of your variable:\n");
    scanf("%s", str);
    num = atof(str);

    for (int i = 0; i < strlen(str); i++) {
      if (!((str[i] >= '0') && str[i] <= '9')) {
        if (str[i] == '.') {
          decimal++;
        } else if (str[i] == '-') {
          negative++;
        } else {
          character++;
        }
      }
    }
    if (character || decimal > 1) {
      printf("Your input is invalid. ");
    } else if (negative > 1) {
      printf("Your input is invalid. ");
    } else {
      output = '!';
    }
  }

  printf("%c is set to %f\n", name, num);
  return num;
}

//*****************************************************************************
//*                                                                           *
//* Method Name:    calculation_a                                             *
//* Method Inputs:  None                                                      *
//* Method Outputs: None                                                      *
//* Desc:           Accepts numbers or allows the user to create variables    *
//*                 and then performs binary or unary operations.             *
//*                                                                           *
//*****************************************************************************
float calculation_a(void) { // Creates method calculation_a.
  char option;            // Creates the character option.
  int check = 0;          // Creates the integer check and sets it equal to 0.
  float num1;             // Creates the float num1.
  float num2;             // Creates the float num2.
  float num;              // Creates the float num.
  float answer;           // Creates the float answer.
  char name = 'f';   // Creates the character name and sets it equal to 'f'.
  char output = '?'; // Creates the character output and sets it equal to '?'.
  char operation;

  //*****************************************************************************
  //* *
  //*                            Option Validation *
  //* *
  //*****************************************************************************
  while (check == 0) {
    printf("Please select your option ( B , U , E )\n");
    scanf("%s", &option);
    if (sizeof(option) == 1) {
      switch (option) {
      case 'B':
        check = 1;
        break;
      case 'U':
        check = 1;
        break;
      case 'E':
        check = 1;
        break;
      default:
        printf("Your input is invalid. Please keep in mind that letters are "
               "capitalized.\n");
        break;
      }
    } else {
      printf("Your input is invalid. ");
    }
  }

  if (option == 'B') {
    //*****************************************************************************
    //* *
    //*                            Num1 Validation *
    //* *
    //*****************************************************************************
    while (output == '?') {
      int decimal = 0, character = 0, negative = 0, i = 0;
      char str[1000];
      printf("Please enter the first number or the name of a variable, which "
             "should be a single lowercase alphabetic character between 'a' to "
             "'e':\n");
      scanf("%s", str);
      num1 = atof(str);
      if (i + 1 == strlen(str)) {
        switch (str[0]) {
        case 'a':
          name = str[0];
          output = '!';
          break;
        case 'b':
          name = str[0];
          output = '!';
          break;
        case 'c':
          name = str[0];
          output = '!';
          break;
        case 'd':
          name = str[0];
          output = '!';
          break;
        case 'e':
          name = str[0];
          output = '!';
          break;
        default:
          for (i = 0; i < strlen(str); i++) {
            if (!((str[i] >= '0') && str[i] <= '9')) {
              if (str[i] == '.') {
                decimal++;
              } else if (str[i] == '-') {
                negative++;
              } else {
                character++;
              }
            }
          }
          if (character || decimal > 1) {
            printf("Your input is invalid. ");
          } else if (negative > 1) {
            printf("Your input is invalid. ");
          } else {
            output = '!';
          }
          break;
        }
      } else {
        for (i = 0; i < strlen(str); i++) {
          if (!((str[i] >= '0') && str[i] <= '9')) {
            if (str[i] == '.') {
              decimal++;
            } else if (str[i] == '-') {
              negative++;
            } else {
              character++;
            }
          }
        }
        if (character || decimal > 1) {
          printf("Your input is invalid. ");
        } else if (negative > 1) {
          printf("Your input is invalid. ");
        } else {
          output = '!';
        }
      }
    }
    if (name == 'a' || name == 'b' || name == 'c' || name == 'd' ||
        name == 'e') {
      num1 = num_validator();
    }
    operation = operation_validator_b();
    //*****************************************************************************
    //* *
    //*                            Num2 Validation *
    //* *
    //*****************************************************************************
    output = '?';
    while (output == '?') {
      int decimal = 0, character = 0, negative = 0, i = 0;
      char str[1000];
      printf("Please enter the second number or the name of a variable, which "
             "should be a single lowercase alphabetic character between 'a' to "
             "'e':\n");
      scanf("%s", str);
      num2 = atof(str);
      if (i + 1 == strlen(str)) {
        switch (str[0]) {
        case 'a':
          name = str[0];
          output = '!';
          break;
        case 'b':
          name = str[0];
          output = '!';
          break;
        case 'c':
          name = str[0];
          output = '!';
          break;
        case 'd':
          name = str[0];
          output = '!';
          break;
        case 'e':
          name = str[0];
          output = '!';
          break;
        default:
          for (i = 0; i < strlen(str); i++) {
            if (!((str[i] >= '0') && str[i] <= '9')) {
              if (str[i] == '.') {
                decimal++;
              } else if (str[i] == '-') {
                negative++;
              } else {
                character++;
              }
            }
          }
          if (character || decimal > 1) {
            printf("Your input is invalid. ");
          } else if (negative > 1) {
            printf("Your input is invalid. ");
          } else {
            output = '!';
          }
          break;
        }
      } else {
        for (i = 0; i < strlen(str); i++) {
          if (!((str[i] >= '0') && str[i] <= '9')) {
            if (str[i] == '.') {
              decimal++;
            } else if (str[i] == '-') {
              negative++;
            } else {
              character++;
            }
          }
        }
        if (character || decimal > 1) {
          printf("Your input is invalid. ");
        } else if (negative > 1) {
          printf("Your input is invalid. ");
        } else {
          output = '!';
        }
      }
    }
    if (name == 'a' || name == 'b' || name == 'c' || name == 'd' ||
        name == 'e') {
      num2 = num_validator();
    }
    //*****************************************************************************
    //* *
    //*                             Calculations *
    //* *
    //*****************************************************************************
    switch (operation) {    // Creates switch for operation.
    case '+':               // Creates case for '+' (runs if operation ='s '+').
      answer = num1 + num2; // Sets answer = to num1+num2.
      printf("The result is %f\n",
             answer); // Prints out the statment "The result is", along with the
                      // float answer.
      break;  // Terminates the execution. In other words exits the switch.
    case '-': // Creates case for '-' (runs if operation ='s '-').
      answer = num1 - num2; // Sets answer = to num1-num2.
      printf("The result is %f\n",
             answer); // Prints out the statment "The result is", along with the
                      // float answer.
      break;  // Terminates the execution. In other words exits the switch.
    case '*': // Creates case for '*' (runs if operation ='s '*').
      answer = num1 * num2; // Sets answer = to num1*num2.
      printf("The result is %f\n",
             answer); // Prints out the statment "The result is", along with the
                      // float answer.
      break;  // Terminates the execution. In other words exits the switch.
    case '/': // Creates case for '/' (runs if operation ='s '/').
      if (num2 == 0) // Create if statement that will run if num2 equals 0.
      {              // Start if statement.
        printf("0 is an invalid number when dividing. ");
        num2 = num_validator();
        answer = num1 / num2; // Sets answer = to num1/num2.
        printf("The result is %f\n",
               answer); // Prints out the statment "The result is", along with
                        // the float answer.
      }                 // Ends if statement.
      else              // Creates else statement.
      {                 // Starts else.
        answer = num1 / num2; // Sets answer = to num1/num2.
        printf("The result is %f\n",
               answer); // Prints out the statment "The result is", along with
                        // the float answer.
      }                 // Ends else.
      break; // Terminates the execution. In other words exits the switch.
    case '%':
      answer = remainder(num1, num2);
      printf("The result is %f\n",
             answer); // Prints out the statment "The result is", along with the
                      // float answer.
      break;
    case 'P':
      answer = pow(num1, num2);
      printf("The result is %f\n",
             answer); // Prints out the statment "The result is", along with the
                      // float answer.
      break;
    case 'X':
      answer = (num1 > num2) ? num1 : num2;
      printf("The result is %f\n",
             answer); // Prints out the statment "The result is", along with the
                      // float answer.
      break;
    case 'I':
      answer = (num1 > num2) ? num2 : num1;
      printf("The result is %f\n",
             answer); // Prints out the statment "The result is", along with the
                      // float answer.
      break;
    } // Ends switch.
  } else if (option == 'U') {
    //*****************************************************************************
    //* *
    //*                             Num Validation *
    //* *
    //*****************************************************************************
    while (output == '?') {
      int decimal = 0, character = 0, negative = 0, i = 0;
      char str[1000];
      printf("Please enter the first number or the name of a variable, which "
             "should be a single lowercase alphabetic character between 'a' to "
             "'e':\n");
      scanf("%s", str);
      num = atof(str);
      if (i + 1 == strlen(str)) {
        switch (str[0]) {
        case 'a':
          name = str[0];
          output = '!';
          break;
        case 'b':
          name = str[0];
          output = '!';
          break;
        case 'c':
          name = str[0];
          output = '!';
          break;
        case 'd':
          name = str[0];
          output = '!';
          break;
        case 'e':
          name = str[0];
          output = '!';
          break;
        default:
          for (i = 0; i < strlen(str); i++) {
            if (!((str[i] >= '0') && str[i] <= '9')) {
              if (str[i] == '.') {
                decimal++;
              } else if (str[i] == '-') {
                negative++;
              } else {
                character++;
              }
            }
          }
          if (character || decimal > 1) {
            printf("Your input is invalid. ");
          } else if (negative > 1) {
            printf("Your input is invalid. ");
          } else {
            output = '!';
          }
          break;
        }
      } else {
        for (i = 0; i < strlen(str); i++) {
          if (!((str[i] >= '0') && str[i] <= '9')) {
            if (str[i] == '.') {
              decimal++;
            } else if (str[i] == '-') {
              negative++;
            } else {
              character++;
            }
          }
        }
        if (character || decimal > 1) {
          printf("Your input is invalid. ");
        } else if (negative > 1) {
          printf("Your input is invalid. ");
        } else {
          output = '!';
        }
      }
    }
    if (name == 'a' || name == 'b' || name == 'c' || name == 'd' ||
        name == 'e') {
      num = num_validator();
    }
    operation = operation_validator_u();
    //*****************************************************************************
    //* *
    //*                             Calculations *
    //* *
    //*****************************************************************************
    switch (operation) {
    case 'S':
      if (num < 0) {
        printf("Negative numbers are invalid when using square root. ");
        output = '?';
        while (output == '?') {
          int decimal = 0, character = 0, negative = 0;
          char str[1000];
          printf("Please enter the second number:\n");
          scanf("%s", str);
          num = atof(str);

          for (int i = 0; i < strlen(str); i++) {
            if (!((str[i] >= '0') && str[i] <= '9')) {
              if (str[i] == '.') {
                decimal++;
              } else if (str[i] == '-') {
                negative++;
              } else {
                character++;
              }
            }
          }
          if (character || decimal > 1) {
            printf("Your input is invalid. ");
          } else if (negative > 0) {
            printf("Your input is invalid. ");
          } else {
            output = '!';
          }
          answer = sqrt(num);
          printf("The result is %f\n", answer);
        }
      } else {
        answer = sqrt(num);
        printf("The result is %f\n", answer);
      }
      break;
    case 'L':
      if (num <= 0) {
        printf("Negative numbers and 0 are invalid when using logarithms. ");
        output = '?';
        while (output == '?') {
          int decimal = 0, character = 0, negative = 0;
          char str[1000];
          printf("Please enter the second number:\n");
          scanf("%s", str);
          num = atof(str);

          for (int i = 0; i < strlen(str); i++) {
            if (!((str[i] >= '1') && str[i] <= '9')) {
              if (str[i] == '.') {
                decimal++;
              } else if (str[i] == '-') {
                negative++;
              } else {
                character++;
              }
            }
          }
          if (character || decimal > 1) {
            printf("Your input is invalid. ");
          } else if (negative > 0) {
            printf("Your input is invalid. ");
          } else {
            output = '!';
          }
          answer = log10(num);
          printf("The result is %f\n", answer);
        }
      } else {
        answer = log10(num);
        printf("The result is %f\n", answer);
      }
      break;
    case 'E':
      answer = exp(num);
      printf("The result is %f\n", answer);
      break;
    case 'C':
      answer = ceil(num);
      printf("The result is %f\n", answer);
      break;
    case 'F':
      answer = floor(num);
      printf("The result is %f\n", answer);
      break;
    }
  }
  return answer;
}

char option_validator(int check) {
  char option;
  while (check == 0 || check == 1) {
    if (check == 0) {
      scanf(" %c", &option);
      if (sizeof(option) == 1) {
        switch (option) {
        case 'B':
          check = 2;
          break;
        case 'U':
          check = 2;
          break;
        case 'A':
          check = 2;
          break;
        case 'V':
          check = 2;
          break;
        case 'E':
          check = 2;
          break;
        default:
          printf("Your input is invalid. Please keep in mind that letters are capitalized.\n");
          break;
        }
      }
    } else if (check == 1) {
      printf("Please select your option ( B , U , A , V , E )\n");
      scanf("%s", &option);
      if (sizeof(option) == 1) {
        switch (option) {
        case 'B':
          check = 2;
          break;
        case 'U':
          check = 2;
          break;
        case 'A':
          check = 2;
          break;
        case 'V':
          check = 2;
          break;
        case 'E':
          check = 2;
          break;
        default:
          printf("Your input is invalid. Please keep in mind that letters are "
                 "capitalized.\n");
          break;
        }
      } else {
        printf("Your input is invalid. ");
      }
    }
  }
  return option;
}

//*****************************************************************************
//*                                                                           *
//*                              Main Method                                  *
//*                                                                           *
//*****************************************************************************
int main(void) { // Creates main method.
  char option;
  float num1;
  char operation;
  float num2;
  printf("Welcome to my Command-Line Calculator (CLC)\nDeveloper: Alyssa "                                  // Prints out a welcome statement, developer info, and the date due. Also moves to the next line.
         "Cabana\nVersion: 1\nDate: 2022-10-21");          
  printf("\n--------------------------------------------------");                                           // Prints out a series of '-' to seperate the welcome, developer, and date info from the rest of the information.
  printf("\n");                                                                                             // Moves to the next line (In other words prints a blank line).
  printf("\nSelect one of the following items:\nB) - Binary Mathematical "                                  // Prints out the different option availbe and what they do. Also moves to the next line.
         "Operations, such as addition and subtraction.\nU) - Unary "
         "Mathematical Operations, such as square root, and log.\nA) - "
         "Advances Mathematical Operations, using variables, arrays.\nV) – "
         "Define variables and assign them values.\nE) - Exit\n");

  option = option_validator(0);
  switch (option) {
  case 'B':
    num1 = num_validator();
    operation = operation_validator_b();
    num2 = num_validator();
    calculation_b(num1, operation, num2);
    break;
  case 'U':
    num1 = num_validator();
    operation = operation_validator_u();
    calculation_u(num1, operation);
    break;
  case 'A':
    calculation_a();
    break;
  case 'V':
    calculation_v();
    break;
  case 'E':
    break;
  }
  while (option != 'E') {
    option = option_validator(1);
    switch (option) {
    case 'B':
      num1 = num_validator();
      operation = operation_validator_b();
      num2 = num_validator();
      calculation_b(num1, operation, num2);
      break;
    case 'U':
      num1 = num_validator();
      operation = operation_validator_u();
      calculation_u(num1, operation);
      break;
    case 'A':
      calculation_a();
      break;
    case 'V':
      calculation_v();
      break;
    case 'E':
      break;
    }
  }

  printf("Thanks for using my Simple Calculator. Hope to see you again soon. "
         "Goodbye!"); // Prints out the statement "Thanks for using my Simple
                      // Calculator. Hope to see you again soon. Goodbye!".
  return 0;           // Returns nothing.
} // End main method.