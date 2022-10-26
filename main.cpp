#include <sstream>
#include <fstream>
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(int argc, char* argv[]) {

    ifstream in(argv[1]);
    ofstream out(argv[2]);
    LinkedList<string> linkedList;
  


    for (string line; getline(in, line);) {
        try {
            string item1, item2;
            if (line.size() == 0) continue;
            out << endl << line << " ";
            istringstream iss(line);
            iss >> item1;
            if (item1 == "Insert") {
                while (iss >> item2) {
                    linkedList.push_front(item2);
                }
            }
            else if (item1 == "Clear") {
                linkedList.clear();
                if (linkedList.empty() == true) {
                    out << "OK" << endl;
                }
                else {
                    out << "Error clearing up the list" << endl; 
                }
            }
            else if (item1 == "Empty") {
                if (linkedList.empty() == true) {
                    out << "true" << endl;
                }
                else {
                    out << "false" << endl;
                }
            }
            else if (item1 == "PrintList") {
                if (linkedList.empty() == true) {
                    out << "Empty!" << endl;
                }
                else {
                    out << linkedList.toString() << endl;
                }
            }
            else if (item1 == "Iterate") {
                if (linkedList.empty() == true) {
                    out << "Empty!" << endl;
                }
                else {
                    LinkedList<string>::Iterator iter = linkedList.begin();
                    while (iter != linkedList.end()) {
                        out << endl << " [" << *iter << "]";
                        ++iter;
                    }
                }
            }
            else if (item1 == "Find") {
                iss >> item2;
                linkedList.find(linkedList.begin(), linkedList.end(), item2);
                out << "OK" << endl;
            }
            else if (item1 == "InsertAfter") {
                string temp;
                iss >> temp;
                iss >> item2;
                LinkedList<string>::Iterator position = linkedList.find(linkedList.begin(), linkedList.end(), item2);
                linkedList.insert_after(position, temp);
                out << "OK" << endl;
            }
            else if (item1 == "InsertBefore") {
                iss >> item2;
                string temp;
                iss >> temp;
                LinkedList<string>::Iterator position = linkedList.find(linkedList.begin(), linkedList.end(), temp);
                linkedList.insert(position, item2);
                out << "OK" << endl;

            }
            else if (item1 == "Remove") {
                iss >> item2;
                LinkedList<string>::Iterator position = linkedList.find(linkedList.begin(), linkedList.end(), item2);
                linkedList.remove(position);
                //out << "OK" << endl;
            }
            else if (item1 == "Replace") {
                string item3;
                iss >> item2;
                iss >> item3;
                if (linkedList.empty() == true) {
                    out << "Empty!" << endl;
                }
                else {
                    linkedList.replace(linkedList.begin(), linkedList.end(), item2, item3);
                    out << "OK" << endl;
                }
            }
            else if (item1 == "First") {
                if (linkedList.empty() == true) {
                    out << "Empty!"<< endl;
                }
                else {
                    out << linkedList.first() << endl;
                }
            }
            else if (item1 == "Reverse") {
                if (linkedList.empty() == true) {
                    out << "Empty!" << endl;
                }
                else {
                    linkedList.reverse();
                    out << "OK" << endl;
                }
            }
            else if (item1 == "Delete") {
                if (linkedList.empty() == true) {
                    out << "Empty!" << endl;
                }
                else {
                    
                    LinkedList<string>::Iterator position = linkedList.begin();
                    linkedList.remove(position);
                    out << "OK" << endl;
                }
            }
            else if (item1 == "Size") {
                if (linkedList.empty() == true) {
                    out << "0" << endl;
                }
                else {
                    out << linkedList.size() << endl;
                }
            }



        }
        catch (string bad) {
            out << bad << endl;
        }
    }
    return 0;
}