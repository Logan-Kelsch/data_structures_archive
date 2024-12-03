/*
Author: Don Spickler
Creation Date: 1/29/2024
Last Update: 1/29/2024
Description: Simple example on using the tiny file dialog library.  The readme
contains templates for invoking these and other system standard dialog boxes.
User Interface: The program will open several standard dialog boxes and process
the input.
Notes: These can be used with both C and C++ programs, a GUI
interface is not needed.
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "tinyfiledialogs.h"

using namespace std;

int main(int argc, char *argv[]) {

  // To do a simple message box.  See readme for template.
  int result = tinyfd_messageBox(
      "We have a problem.", "There is something wrong \nwith your computer...",
      "ok", "error", 1);

  cout << result << endl;

  result =
      tinyfd_messageBox("Call for Help?", "Do you wish to call a technician?",
                        "yesno", "question", 1);

  cout << result << endl;

  if (result) {
    result = tinyfd_messageBox("Phone Number", "The phone number is 555-HELP",
                               "okcancel", "question", 1);

    if (result)
      cout << "Call has been made." << endl;
    else
      cout << "Call canceled." << endl;

    if (result)
      tinyfd_notifyPopup("Calling the Geek Squad", "Call has been made.",
                         "info");
    else
      tinyfd_notifyPopup("No answer...", "You are on your own.", "error");
  }

  // File open dialog example.  See readme for template.
  char const *FilterPatterns[2] = {"*.txt", "*.text"};
  char const *filepath =
      tinyfd_openFileDialog("Select a text file.", NULL, 2, FilterPatterns,
                            "Text files (*.txt, *.text)", 0);

  if (filepath) {
    cout << filepath << endl;
    string commandstr = "cat ";
    commandstr += filepath;
    system(commandstr.c_str());
  } else
    cout << "Cancel was pressed on the file open." << endl;

  // File save dialog example.  See readme for template.
  filepath = tinyfd_saveFileDialog("Save Text File", NULL, 2, FilterPatterns,
                                   "Text files (*.txt, *.text)");

  if (filepath) {
    cout << "Saving to " << filepath << endl;
  } else
    cout << "Cancel was pressed on the file save." << endl;

  return 0;
}
