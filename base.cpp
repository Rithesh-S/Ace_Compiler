#include <iostream>
#include <vector>
#include <fstream>

using std::cout;

bool fileFormatChecker(std::string fileName) {
    int pos = fileName.find('.');
    if(fileName.substr(pos + 1) == "a") {
        return true;
    }
    return false;
}

bool checkFileExistance(const std::string& fileName, std::ifstream& inFile) {
    std::string filePath = "./src/" + fileName;
    inFile.open(filePath);
    return inFile.is_open();
}

int main(int argc,char* argv[]) {
    
    if(argc < 2) {
        std::cerr << "\033[31mERROR: Provide Input File: Obtained null\033[0m" << std::endl;
        return 1;
    }

    std::string fileName = argv[1];
    if(!fileFormatChecker(fileName)) {
        std::cerr << "\033[31mERROR: Unrecognizable File Format: " << fileName << "\033[0m" << std::endl;
        return 1;
    }

    std::ifstream inFile;
    
    if(!checkFileExistance(fileName, inFile)) {
        std::cerr << "\033[31mERROR: File does'nt exists in src folder: " << fileName << "\033[0m" << std::endl;
        return 1;
    } else {
        std::string line;
        while(std::getline(inFile, line)) {
            cout<<line<<std::endl;
        }
    }
}