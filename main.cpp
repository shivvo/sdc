#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::string *args = new std::string[argc];
  for (int i = 0; i < argc; i++) {
    args[i] = std::string(argv[i]);
  }

  if (argc < 2) {
    exit(1);
  }

  if (args[1] == "fraction") {
    if (argc >= 3) {
      if (args[2] == "round-robin") {

      } else if (args[2] == "simple-drain") {

      } else {

      }
    } else {

    }
  } else if (args[1] == "synthload") {
    if (argc >= 3) {
      if (args[2] == "round-robin") {

      } else if (args[2] == "simple-drain") {

      } else {

      }
    } else {

    }   
  } else if (args[1] == "plot") {
    if (argc >= 3) {
      if (args[2] == "fraction") {

      } else if (args[2] == "synthload") {

      } else {

      }
    } else {

    }        
  } else if (args[1] == "synthgen") {
    
  } else {

  }
  return 0;
}